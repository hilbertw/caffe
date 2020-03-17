#pragma once
namespace debug {
void print_shape(FILE*fp,const std::vector<int>& shape);
void print_blob(FILE*fp,const caffe::Blob<int> * b);
template <typename Dtype>
void print_blob(FILE*fp,const caffe::Blob<Dtype> * b);

template <typename DType>
void print_blobs(FILE*fp,const  std::string & title,const std::vector<caffe::Blob<DType>*> & blobs);
void print_s(FILE *fp,const std::string & s);
void print_s(FILE *fp,const char * s);


}


#define BEGIN_DEBUG FILE*fp=fopen("debug.txt","a"); if(fp){
#define END_DEBUG fclose(fp);}

	
