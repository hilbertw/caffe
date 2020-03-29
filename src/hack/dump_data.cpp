#include <string>
#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "caffe/data_transformer.hpp"
#include "hack/dump_data.h"
#if 0
void dump_data(FILE*fp,const char * comment,const int&){}
void dump_data(FILE*fp,const char * comment,const float&){}
void dump_data(FILE*fp,const char * comment,const double&){}
void dump_data(FILE*fp,const char * comment,const bool&){}
void dump_data(FILE*fp,const char * comment,const boost::property_tree::ptree &){}
void dump_data(FILE*fp,const char * comment,const std::string &){}
void dump_data(FILE*fp,const char * comment,const std::vector<int> * const){}
void dump_data(FILE*fp,const char * comment,const std::vector<int> &){}
void dump_data(FILE*fp,const char * comment,const std::vector<float> &){}
template <typename Dtype>void dump_data(FILE*fp,const char * comment,const caffe::Blob<Dtype>&){}
template <typename Dtype>void dump_data(FILE*fp,const char * comment,const boost::shared_ptr<caffe::DataTransformer<Dtype> >&){}
void dump_data(FILE*fp,const char * comment,const std::vector <std::string>&){}
void dump_data(FILE*fp,const char * comment,const std::map <int,std::string>&){}
void dump_data(FILE*fp,const char * comment,const std::vector<std::pair<int, int> >&){}
template void dump_data(FILE*fp,const char * comment,const caffe::Blob<int>&);
template void dump_data(FILE*fp,const char * comment,const caffe::Blob<float>&);
template void dump_data(FILE*fp,const char * comment,const caffe::Blob<double>&);
template void dump_data(FILE*fp,const char * comment,const boost::shared_ptr<caffe::DataTransformer<float> >&);
template void dump_data(FILE*fp,const char * comment,const boost::shared_ptr<caffe::DataTransformer<double> >&);
#endif

void dump_data(FILE *fp,int data){fprintf(fp,"%d",data);}
void dump_data_int(FILE *fp,const char * comment,google::protobuf::uint32 data){fprintf(fp,"%s=%d",comment,data);}
void dump_data(FILE *fp,float data){fprintf(fp,"%lf",data);}
void dump_data(FILE *fp,double data){fprintf(fp,"%lf",data);}
void dump_data(FILE *fp,const std::pair<int,int>& data){fprintf(fp,"{%d,%d}",data.first,data.second);}
void dump_data(FILE *fp,const std::string& data){fprintf(fp,"\"%s\"",data.c_str());}


void dump_data(FILE*fp,const char * comment,int data){fprintf(fp,"%s=%d;\n",comment,data);}
void dump_data(FILE*fp,const char * comment,float data){fprintf(fp,"%s=%lf;\n",comment,data);}
void dump_data(FILE*fp,const char * comment,double data){fprintf(fp,"%s=%lf;\n",comment,data);}
void dump_data(FILE*fp,const char * comment,bool data){fprintf(fp,"%s=%d;\n",comment,data);}
void dump_data(FILE*fp,const char * comment,const char * data){fprintf(fp,"%s=\"%s\";\n",comment,data);}
void dump_data(FILE*fp,const char * comment,const std::string &data){fprintf(fp,"%s=\"%s\";\n",comment,data.c_str());}

template<typename Dtype>void dump_data_r(FILE *fp,const char * comment,const google::protobuf::RepeatedField< Dtype>& data)
{
   fprintf(fp,"%s={\n",comment);
   for(int i=0;i<data.size();i++)
   {
       if(i!=0) fprintf(fp,",");   
       if((i%5)==4) fprintf(fp,"\n");          
       dump_data(fp,data.Get(i));
   }
         
   fprintf(fp,"\n}\n");
}


template void dump_data_r<int>(FILE *fp,const char * comment,const google::protobuf::RepeatedField<int>& data);
template void dump_data_r<float>(FILE *fp,const char * comment,const google::protobuf::RepeatedField<float>& data);
#define P_FIELD(x) dump_data_int(fp,#x,data.x())
#define P_FIELD_R(x) dump_data_r(fp,#x,data.x())

void dump_data(FILE*fp,const char * comment,const caffe::ResizeParameter & data)
{
//height,width,resize_mode,height_scale,width_scale,pad_mode,pad_value,iterp_mode
   fprintf(fp,"%s={\n",comment);
   P_FIELD(height);
   P_FIELD(width);   
   P_FIELD(height_scale);
   P_FIELD(width_scale);   
   P_FIELD(resize_mode);
   P_FIELD_R(interp_mode);   
   P_FIELD(pad_mode);
   P_FIELD_R(pad_value);   
   fprintf(fp,"\n}");     
}
void dump_data(FILE*fp,const char * comment,const boost::property_tree::ptree & data)
{
   fprintf(fp,"%s={\n",comment);
   fprintf(fp,"\n}");   
}

template <typename Dtype>void dump_array(FILE*fp,const char *  comment,const Dtype * data,int len)
{

   fprintf(fp,"%s={\n",comment);
   for(int i=0;i<len;i++)
   {
       if(i!=0) fprintf(fp,",");   
       if((i%5)==4) fprintf(fp,"\n");          
       dump_data(fp,data[i]);
   }
   fprintf(fp,"\n}");
}

template <typename Dtype>void dump_data(FILE*fp,const char * comment,const caffe::Blob<Dtype>& data)
{
  fprintf(fp,"%s={\n",comment);
  fprintf(fp,"count=%d\n",data.count());
  fprintf(fp,"shape=%s\n",data.shape_string().c_str());
  if(data.data_){  
        dump_array(fp,"data",data.cpu_data(),data.count());
        fprintf(fp,"\n");   
  }
  if(data.diff_){  
       dump_array(fp,"diff",data.cpu_diff(),data.count());   
  }
  fprintf(fp,"\n}");
}


template <typename Dtype>void dump_data(FILE*fp,const char * comment,const std::vector <Dtype>&data)
{
   
   fprintf(fp,"%s={\n",comment);
   for(int i=0;i<data.size();i++)
   {
       if(i!=0) fprintf(fp,",");   
       if((i%5)==4) fprintf(fp,"\n");
        const Dtype & d=data[i];          
       dump_data(fp,d);
   }
   fprintf(fp,"\n}");
}


template <typename Dtype>void dump_data(FILE*fp,const char * comment, std::vector <Dtype>&data)
{
   
   fprintf(fp,"%s={\n",comment);
   for(int i=0;i<data.size();i++)
   {
       if(i!=0) fprintf(fp,",");   
       if((i%5)==4) fprintf(fp,"\n");
        const Dtype & d=data[i];          
       dump_data(fp,d);
   }
   fprintf(fp,"\n}");
}
void dump_data(FILE*fp,const char * comment,const std::vector<int> *data)
{
    const std::vector<int>&d=*data;
    dump_data(fp,comment,d);        
}
void dump_data(FILE*fp,const char * comment,const std::map <int,std::string>&data)
{
   fprintf(fp,"%s={\n",comment);
   int i=0;
   std::map <int,std::string>::const_iterator iter=data.begin();
   for(;iter!=data.end();iter++)
   {
       if(i!=0) fprintf(fp,",");   
       if((i%5)==4) fprintf(fp,"\n");          
       fprintf(fp,"{%d,\"%s\"}",iter->first,iter->second.c_str());
       i++;
   }
   fprintf(fp,"\n}");
}



template<typename Dtype>  void dump_data(FILE*fp,const char * comment,const caffe::DataTransformer<Dtype> & data)
{
        fprintf(fp,"%s={\n",comment);
        dump_data(fp,"param_",data.param_);
        dump_data(fp,"data_mean_",data.data_mean_);
        dump_data(fp,"mean_values_",data.mean_values_);
        fprintf(fp,"}\n");
}
template<typename Dtype> void dump_data(FILE*fp,const char * comment,const boost::shared_ptr<caffe::DataTransformer<Dtype> >& data)
{
     if(data)
     {
        const caffe::DataTransformer<Dtype> & d=*data;
        dump_data(fp,comment,d);
     } else
     {
        fprintf(fp,"%s={}\n",comment);
     }   
}

template void dump_data<float>(FILE*fp,const char * comment,const caffe::DataTransformer<float> & data);
template void dump_data<double>(FILE*fp,const char * comment,const caffe::DataTransformer<double> & data);
template void dump_data<float>(FILE*fp,const char * comment,const boost::shared_ptr<caffe::DataTransformer<float> >& data);
template void dump_data<double>(FILE*fp,const char * comment,const boost::shared_ptr<caffe::DataTransformer<double> >& data);
template void dump_data<std::pair<int, int>>(FILE*fp,const char * comment,const std::vector<std::pair<int, int> >&data);
template void dump_data<int>(FILE*fp,const char * comment,const std::vector<int >&data);
template void dump_data<float>(FILE*fp,const char * comment,const std::vector<float>&data);
template void dump_data<double>(FILE*fp,const char * comment,const std::vector<double>&data);
template void dump_data<std::string>(FILE*fp,const char * comment,const std::vector<std::string>&data);
template void dump_data<float>(FILE*fp,const char * comment,const caffe::Blob<float>& data);
template void dump_data<int>(FILE*fp,const char * comment,const caffe::Blob<int>& data);
template void dump_data<double>(FILE*fp,const char * comment,const caffe::Blob<double>& data);

template void dump_data<int>(FILE*fp,const char * comment,std::vector<int >&data);
template void dump_data<float>(FILE*fp,const char * comment,std::vector<float>&data);
template void dump_data<double>(FILE*fp,const char * comment,std::vector<double>&data);

#define DUMP_FIELD(x) dump_data(fp,#x,data.x())
void dump_data(FILE*fp, const char * comment, const caffe::SaltPepperParameter&data)
{}
void dump_data(FILE*fp, const char *comment, const caffe::EmitConstraint& data)
{
        fprintf(fp,"%s={\n",comment);
   DUMP_FIELD(emit_type);
   DUMP_FIELD(emit_overlap);
        fprintf(fp,"}\n");
}
void dump_data(FILE*fp, const char *comment, const caffe::NoiseParameter&data)
{
        fprintf(fp,"%s={\n",comment);
    DUMP_FIELD(decolorize);
    DUMP_FIELD(gauss_blur);
    DUMP_FIELD(hist_eq);
    DUMP_FIELD(clahe);
     DUMP_FIELD(jpeg);
     DUMP_FIELD(erode);
     DUMP_FIELD(posterize);
     DUMP_FIELD(inverse);
     DUMP_FIELD(saltpepper_param);
     DUMP_FIELD(saltpepper);
     DUMP_FIELD(convert_to_hsv);
     DUMP_FIELD(convert_to_lab);
        fprintf(fp,"}\n");
}
void dump_data(FILE*fp, const char *comment, const caffe::DistortionParameter& data)
{
        fprintf(fp,"%s={\n",comment);
   DUMP_FIELD(brightness_prob);
   DUMP_FIELD(brightness_delta);
   DUMP_FIELD(contrast_prob);
   DUMP_FIELD(contrast_upper);
   DUMP_FIELD(saturation_prob);
   DUMP_FIELD(saturation_upper);
   DUMP_FIELD(hue_delta);
   DUMP_FIELD(random_order_prob);
   DUMP_FIELD(brightness_prob);
   DUMP_FIELD(brightness_delta);
   DUMP_FIELD(saturation_prob);
   DUMP_FIELD(saturation_upper);
   DUMP_FIELD(contrast_prob);
   DUMP_FIELD(contrast_upper);
   DUMP_FIELD(random_order_prob);
        fprintf(fp,"}\n");
}
void dump_data(FILE*fp, const char *comment, const caffe::ExpansionParameter& data)
{
        fprintf(fp,"%s={\n",comment);
        DUMP_FIELD(max_expand_ratio);
        DUMP_FIELD(prob);
        fprintf(fp,"}\n");
}

void dump_data(FILE*fp,const char * comment,caffe::TransformationParameter data)
{
        fprintf(fp,"%s={\n",comment);
    
    P_FIELD(crop_h);
    P_FIELD(crop_w);
    P_FIELD(crop_size);
    if(data.has_distort_param())
       DUMP_FIELD(distort_param);
    if(data.has_emit_constraint())
       DUMP_FIELD(emit_constraint);
    DUMP_FIELD(force_color);
    DUMP_FIELD(force_gray);
    if(data.has_mean_file())
       DUMP_FIELD(mean_file);
    DUMP_FIELD(mean_value_size);
    DUMP_FIELD(mirror);
    if(data.has_noise_param())
        DUMP_FIELD(noise_param);
    DUMP_FIELD(scale);
    if(data.has_resize_param())
      DUMP_FIELD(resize_param);
    if(data.has_expand_param())
      DUMP_FIELD(expand_param);
//resize_param().height
//resize_param().width
//expand_param().max_expand_ratio
        fprintf(fp,"}\n");
}
