#include "hack/print_data.h"


template <typename Dtype> void print_blobs(const std::string & name,const std::vector<caffe::shared_ptr<caffe::Blob<Dtype>>> & blobs)
{
   if(blobs.size())
   {
       std::string fn= name+std::string("_w.cpp");
       FILE *fp=fopen(fn.c_str(),"w");
       if(fp)
       {
           fprintf(fp,"#include \"hack/types.h\"\n");
           //fprintf(fp,"int %s_blob_count=%d;\n",name.c_str(),blobs.size());
           int i=0;
           for(auto &blob: blobs)
           {
               std::string comment=name+std::string("_blob")+std::to_string(i);
               print_blob_dtype_data<Dtype>(fp,comment.c_str(),*blob);
               print_blob_dtype_shape_data<Dtype>(fp,comment.c_str(),*blob);
               i=i+1;
           }
           fprintf(fp,"struct blob_dtype_def<_Dtype_> %s_blobs[]={\n",name.c_str());
           i=0;
           for(auto &blob: blobs)
           {
               if(i!=0) fprintf(fp,",\n");
               std::string comment=name+std::string("_blob")+std::to_string(i);
               print_blob_dtype<Dtype>(fp,comment.c_str(),*blob);
               i=i+1;
           }
           fprintf(fp,"\n};\n");
           fclose(fp);

       }
    }
}
template  void print_blobs<int>(const std::string & name,const std::vector<caffe::shared_ptr<caffe::Blob<int>>> & blobs);
template  void print_blobs<float>(const std::string & name,const std::vector<caffe::shared_ptr<caffe::Blob<float>>> & blobs);
template  void print_blobs<double>(const std::string & name,const std::vector<caffe::shared_ptr<caffe::Blob<double>>> & blobs);

