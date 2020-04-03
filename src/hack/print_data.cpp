#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/regex.hpp>
	
#include "caffe/caffe.hpp"
#include "caffe/data_transformer.hpp"
#include "hack/print_data.h"

template<typename Dtype> void print_blob_dtype(FILE*fp,const char *  comment, const caffe::Blob<Dtype>& data)
{
	  int shape_len=data.shape().size();
	  fprintf(fp,"{\n{%d,",shape_len);
          if(shape_len)
	       fprintf(fp,"%s_shape",comment);
	  else 
               fprintf(fp,"NULL");

	  fprintf(fp,"},%d,",data.count());
          if (data.data_)fprintf(fp," %s_data,",comment);else fprintf(fp,"NULL,"); 
          if (data.diff_)fprintf(fp,"%s_diff,",comment);else fprintf(fp,"NULL,"); 
          fprintf(fp,"%s_data_flag,%s_diff_flag\n}",comment,comment);
          
}

void print_array(FILE*fp,const char *comment,const int * data,int count,int flag)
{
	   int i;
           if(flag>1)
	       fprintf(fp,"static int *%s=NULL;//[%d];\n",comment,count);
           else if (flag==1)
           {
        	   fprintf(fp,"static int %s[]={\n",comment);
        	   for( i=0;i<count;i++)
        	   { 
        	      fprintf(fp,"%d,",data[i]);
        	      if((i%5)==4) fprintf(fp,"\n");
        	   }
        	   fprintf(fp,"\n};\n");
           }
}
void print_array(FILE*fp,const char *comment,const float * data,int count,int flag)
{
	   int i;
           if(flag>1)
	       fprintf(fp,"static float *%s=NULL;//[%d];\n",comment,count);
           else if(flag==1)
           {
        	   fprintf(fp,"static float %s[]={\n",comment);
        	   for( i=0;i<count;i++)
        	   { 
        	      fprintf(fp,"%lf,",data[i]);
        	      if((i%5)==4) fprintf(fp,"\n");
        	   }
        	   fprintf(fp,"\n};\n");
           }
}
void print_array(FILE*fp,const char *comment,const double * data,int count,int flag)
{
	   int i;
           if(flag>1)
	       fprintf(fp,"static double *%s=NULL;//[%d];\n",comment,count);
           else if(flag==1)
           {
        	   fprintf(fp,"static double %s[]={\n",comment);
        	   for( i=0;i<count;i++)
        	   { 
        	      fprintf(fp,"%lf,",data[i]);
        	      if((i%5)==4) fprintf(fp,"\n");
        	   }
        	   fprintf(fp,"\n};\n");
           }
}
template<typename Dtype>int check_array(FILE*fp,const char *comment,const Dtype * data,int count)
{
       int i;
       int flag=0;
       if(data)
       { 
	   for( i=0;i<count;i++) if(data[i]!=0) break;
           if(i==count)
           {
               flag=3;
           }
           else {
	       for( i=0;i<count;i++) if(data[i]!=1) break;
               if(i==count) flag=2;
               else flag=1;
           }
      }     
      fprintf(fp,"#define %s_flag %d\n",comment,flag);
      return flag;
}
template<typename Dtype> void print_blob_dtype_data(FILE*fp,const char *  comment,const caffe::Blob<Dtype>& data)
{
       std::string s=comment+std::string("_data");
       
       const Dtype * d=data.data_?data.cpu_data():NULL;
       int flag=check_array(fp,s.c_str(),d,data.count());
 
       print_array(fp,s.c_str(),d,data.count(),flag);
       
       
       s=comment+std::string("_diff");

       d=data.diff_?data.cpu_diff():NULL;
       
       flag=check_array(fp,s.c_str(),d,data.count());
       print_array(fp,s.c_str(),d,data.count(),flag);
          
}

template<typename Dtype> void print_blob_dtype_shape_data(FILE*fp,const char *  comment, const caffe::Blob<Dtype>&data)
{
	  const std::vector<int>& data_shape = data.shape();
          if(data_shape.size())
          {
	          std::string s=comment+std::string("_shape");
	          print_array(fp,s.c_str(),data_shape.data(),data_shape.size(),1);
          }
}


template<typename Dtype> void print_vector_dtype(FILE*fp,const char *  comment, const std::vector<Dtype>& data)
{
	  int data_len=data.size();
	  fprintf(fp,"{\n%d,%s_data\n}",data_len,comment); 
}
template<typename Dtype> void print_vector_dtype_data(FILE*fp,const char *  comment, const std::vector<Dtype>&data)
{
	  std::string s=comment+std::string("_data");
	  print_array(fp,s.c_str(),data.data(),data.size(),1);
}

#if 0
	void print_transformer_param_data(FILE*fp,const char *  comment, const caffe::TransformationParameter&data)
	{
	    int mean_size;
	    float * mean_value;
	   std::string s=comment+std::string("_param_mean_value");
	   print_array(fp,s.c_str(),mean_value,mean_size,1);
	}

	void print_transformer_param(FILE*fp,const char *  comment, const caffe::TransformationParameter&data)
	{
	    int mean_size=data.mean_value_size();
	    
	    const char * mean_file=data.mean_file();
	    int crop_size;
	    bool mirror;
	    bool force_color;
	    bool force_gray;
	    float scale;
	    
	  fprintf(fp,"{\n%d,%s_param_mean_value,\"%s\",%d,%d,%d,%d,%lf \n}",
	    mean_size,
	    comment,
	    mean_file,
	    crop_size,
	    mirror,
	    force_color,
	    force_gray,
	    scale
	    );
	}
#endif

template<typename Dtype> void print_transformer_data(FILE*fp,const char *  comment, const caffe::DataTransformer<Dtype>&data)
{
	   std::string s=comment+std::string("_data_mean");
	   print_blob_dtype_data(fp,s.c_str(),data.data_mean_);
	   
	   s=comment+std::string("_mean_values");
	   print_array(fp,s.c_str(),data.mean_values_.data(),data.mean_values_.size(),1);   
}
template<typename Dtype> void print_transformer(FILE*fp,const char *  comment, const caffe::DataTransformer<Dtype>&data)
{
	    fprintf(fp,"{\n");
	    
	    //transformer_param_def param;
	    //print_transformer_param(fp,comment,data.param);
	    fprintf(fp,"%d,\n",data.phase_);
	    //blob_dtype_def<Dtype> data_mean_;
	    std::string s=comment+std::string("_data_mean");
	    print_blob_dtype(fp,s.c_str(),data.data_mean_);
	    fprintf(fp,",\n");    
	    //vector_dtype<Dtype> mean_values;
	    s=comment+std::string("_mean_values");
	    print_vector_dtype(fp,s.c_str(),data.mean_values_);
	    fprintf(fp,"\n}");    
}


void print_map_int_string_data(FILE*fp,const char * comment, const std::map<int,std::string>& m)
{
	    fprintf(fp,"static struct int_string_pair %s_data[]={\n",comment);
	   
	    std::map<int,std::string>::const_iterator iter=m.begin(); 
	    for(;iter!=m.end();iter++)
	    {
	       if(iter!=m.begin())fprintf(fp,",\n");  
	       fprintf(fp,"{%d,\"%s\"}",iter->first,iter->second.c_str());
	    }
	    
	    fprintf(fp,"\n};\n");    
}


void print_map_int_string(FILE*fp,const char *comment, const std::map<int,std::string>& m)
{
	    fprintf(fp,"{%d,%s_data}",m.size(), comment);
}


void print_vector_pair_int_int_data(FILE*fp,const char * comment, const std::vector<std::pair<int,int>>& m)
{
	    fprintf(fp,"static struct int_int_pair %s_data[]={\n",comment);
	    
	    for(int i=0;i<m.size();i++)
	    {
	       if(i!=0)fprintf(fp,",");  
	       if((i%5)==4)fprintf(fp,"\n");  
	       fprintf(fp,"{%d,%d}",m[i].first,m[i].second);
	    }
	    
	    fprintf(fp,"\n};\n");    
}

void print_vector_pair_int_int(FILE*fp,const char *comment, const std::vector<std::pair<int,int>>& m)
{
	    fprintf(fp,"{%d,%s_data}",m.size(), comment);
}


void print(FILE*fp,const char * comment,int data)
{
	  fprintf(fp,"%d /*%s*/",data,comment);
}
void print(FILE*fp,const char * comment,float data)
{
	  fprintf(fp,"%lf /*%s*/",data,comment);
}
void print(FILE*fp,const char * comment,double data)
{
	  fprintf(fp,"%lf /*%s*/",data,comment);
}
void print(FILE*fp,const char * comment,bool data)
{
	  fprintf(fp,"%s /*%s*/",data?"true":"false",comment);
}
void print(FILE* fp, const  float& data){ fprintf(fp,"%lf",data);}
void print(FILE* fp, const  int& data){ fprintf(fp,"%d",data);}
void print_data_r(FILE *fp,const char * comment,const google::protobuf::RepeatedField<int>& data)
{
   fprintf(fp,"static int %s[] ={\n",comment);
   for(int i=0;i<data.size();i++)
   {
       if(i!=0) fprintf(fp,",");
       if((i%5)==4) fprintf(fp,"\n");
       print(fp,data.Get(i));
   }

   fprintf(fp,"\n};\n");
}
void print_data_r(FILE *fp,const char * comment,const google::protobuf::RepeatedField<float>& data)
{
   fprintf(fp,"static float %s[] ={\n",comment);
   for(int i=0;i<data.size();i++)
   {
       if(i!=0) fprintf(fp,",");
       if((i%5)==4) fprintf(fp,"\n");
       print(fp,data.Get(i));
   }

   fprintf(fp,"\n};\n");
}
void print(FILE *fp,const char * comment,google::protobuf::uint32 data){fprintf(fp,"%d /*%s*/",data,comment);}

#define P_FIELD_R_DATA(x) { std::string s=std::string(comment)+std::string("_" #x "_data");print_data_r(fp,s.c_str(),data.x());}

#define P_FIELD(x) {print(fp,#x,data.x());fprintf(fp,",\n");}
#define P_FIELD_R(x) {fprintf(fp,"{%d,%s_" #x "_data},\n",data.x().size(),comment);}
#define P_FIELD_R_F(x) {fprintf(fp,"{%d,%s_" #x "_data}\n",data.x().size(),comment);}

void print_resize_param_data(FILE*fp,const char * comment,const caffe::ResizeParameter &data)
{
     P_FIELD_R_DATA(interp_mode)
     P_FIELD_R_DATA(pad_value)
}
void print(FILE*fp,const char * comment,const caffe::ResizeParameter &data)
{
   fprintf(fp,"{/*%s*/\n",comment);
   P_FIELD(height);
   P_FIELD(width);
   P_FIELD(height_scale);
   P_FIELD(width_scale);
   P_FIELD(resize_mode);
   P_FIELD_R(interp_mode);
   P_FIELD(pad_mode);
   P_FIELD_R_F(pad_value);
   fprintf(fp,"\n}");
}
void print(FILE*fp,const char * comment,const boost::property_tree::ptree &data)
{
   fprintf(fp,"{}/*%s*/\n",comment);
   
}

void print_vector_int_ptr(FILE*fp,const char *comment, const std::vector<int>* m)
{
   std::vector<int> t=*m;
   print_vector_dtype<int>(fp,comment,t); 
}
void print_vector_int_ptr_data(FILE*fp,const char * comment, const std::vector<int>* m)
{
   std::vector<int> t=*m;
   print_vector_dtype_data<int>(fp,comment,t); 
}

void print_vector_string(FILE*fp,const char * comment,const std::vector<std::string> &data)
{
    fprintf(fp,"{%d,%s_data}",data.size(),comment);
}
void print_vector_string_data(FILE*fp,const char * comment,const std::vector<std::string> &data)
{
     fprintf(fp,"static const char *%s_data[]={\n",comment);
     for(int i=0;i< data.size();i++)
     {
       if(i!=0) fprintf(fp,",");
       if((i%5)==4) fprintf(fp,"\n");
       fprintf(fp,"%s",data[i].c_str());
     }
     fprintf(fp,"\n};\n");
}


template<typename Dtype> void print_transformer(FILE*fp,const char *  comment, const boost::shared_ptr<caffe::DataTransformer<Dtype> >&data)
{
       if(data)
       {
         const caffe::DataTransformer<Dtype> &d=*data;
         print_transformer(fp,comment,d);
       }
      else fprintf(fp,"{}/*%s*/",comment);
}
template<typename Dtype> void print_transformer_data(FILE*fp,const char *  comment, const boost::shared_ptr<caffe::DataTransformer<Dtype> >&data)
{
       if(data)
       {
           const caffe::DataTransformer<Dtype> &d=*data;
           print_transformer_data(fp,comment,d);
       }
}
void print(FILE*fp,const char * comment,const std::string &data)
{
       fprintf(fp,"\"%s\" /*%s*/",data.c_str(),comment);
}
template<typename Dtype> void print(FILE*fp, const char*comment, const boost::shared_ptr<caffe::DataTransformer<Dtype> >&data) 
{
       if(data)
       {
         const caffe::DataTransformer<Dtype> &d=*data;
         print_transformer<Dtype>(fp,comment,d);
       }
      else fprintf(fp,"{}/*%s*/",comment);
}

template void print_blob_dtype<int>(FILE*fp,const char *  comment, const caffe::Blob<int>& data);
template void print_blob_dtype_data<int>(FILE*fp,const char *  comment,const caffe::Blob<int>& data);
template void print_blob_dtype_shape_data<int>(FILE*fp,const char *  comment, const caffe::Blob<int>&data);

template void print_blob_dtype<float>(FILE*fp,const char *  comment, const caffe::Blob<float>& data);
template void print_blob_dtype_data<float>(FILE*fp,const char *  comment,const caffe::Blob<float>& data);
template void print_blob_dtype_shape_data<float>(FILE*fp,const char *  comment, const caffe::Blob<float>&data);

template void print_vector_dtype<float>(FILE*fp,const char *  comment,const std::vector<float>& data);
template void print_vector_dtype_data<float>(FILE*fp,const char *  comment, const std::vector<float>&data);
template void print_vector_dtype<int>(FILE*fp,const char *  comment,const std::vector<int>& data);
template void print_vector_dtype_data<int>(FILE*fp,const char *  comment, const std::vector<int>&data);

template void print_transformer_data<float>(FILE*fp,const char *  comment, const caffe::DataTransformer<float>&data);
template void print_transformer<float>(FILE*fp,const char *  comment, const caffe::DataTransformer<float>&data);
template void print_transformer_data<float>(FILE*fp,const char *  comment, const boost::shared_ptr<caffe::DataTransformer<float> >&data);
template void print_transformer<float>(FILE*fp,const char *  comment, const boost::shared_ptr<caffe::DataTransformer<float> >&data);

template void print_transformer_data<double>(FILE*fp,const char *  comment, const caffe::DataTransformer<double>&data);
template void print_transformer<double>(FILE*fp,const char *  comment, const caffe::DataTransformer<double>&data);
template void print_transformer_data<double>(FILE*fp,const char *  comment, const boost::shared_ptr<caffe::DataTransformer<double> >&data);
template void print_transformer<double>(FILE*fp,const char *  comment, const boost::shared_ptr<caffe::DataTransformer<double> >&data);

template void print_blob_dtype<double>(FILE*fp,const char *  comment, const caffe::Blob<double>& data);
template void print_blob_dtype_data<double>(FILE*fp,const char *  comment,const caffe::Blob<double>& data);
template void print_blob_dtype_shape_data<double>(FILE*fp,const char *  comment, const caffe::Blob<double>&data);
 
template void print_vector_dtype<double>(FILE*fp,const char *  comment,const std::vector<double>& data);
template void print_vector_dtype_data<double>(FILE*fp,const char *  comment, const std::vector<double>&data);

template void print<float>(FILE*fp, const char*comment, const boost::shared_ptr<caffe::DataTransformer<float> >&data); 
template void print<double>(FILE*fp, const char*comment, const boost::shared_ptr<caffe::DataTransformer<double> >&data); 
 


