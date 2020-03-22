#include <stdio.h>
#include"caffe/caffe.hpp" 
#include "hack/debug.h"
namespace debug {

void print_shape(FILE*fp,const std::vector<int>& shape)
{
  fprintf(fp,"shape:num:%d,ch:%d,height:%d,width:%d\n",shape[0],shape[1],shape[2],shape[3]);
}
template <typename DType>
void print_blob(FILE*fp,const caffe::Blob<DType> * b)
{
  fprintf(fp,"\n======\nshape:%s\ndata\n",b->shape_string().c_str());
  int n=b->count();
  int m=n>10?10:n;
  for(int i=0;i<m;i++)fprintf(fp,"%lf ",b->cpu_data()[i]);  	
  fprintf(fp,"\n");
  if(n>10)
  {
    for(int i=n-10;i<n;i++)fprintf(fp,"%lf ",b->cpu_data()[i]);  	

  }    
  fprintf(fp,"\ndiff\n");      
  for(int i=0;i<m;i++)fprintf(fp,"%lf ",b->cpu_diff()[i]);  	  
   fprintf(fp,"\n");  
  if(n>10)
  {
    for(int i=n-10;i<n;i++)fprintf(fp,"%lf ",b->cpu_diff()[i]);  	    	
  }
  fprintf(fp,"\n===\n");
}
void print_blob(FILE*fp,const caffe::Blob<int> * b)
{
  fprintf(fp,"\n======\nshape:%s\ndata\n",b->shape_string().c_str());
  int n=b->count();
  int m=n>10?10:n;
  for(int i=0;i<m;i++)fprintf(fp,"%d ",b->cpu_data()[i]);  	
  fprintf(fp,"\n");
  if(n>10)
  {
    for(int i=n-10;i<n;i++)fprintf(fp,"%d ",b->cpu_data()[i]);  	

  }    
  fprintf(fp,"\ndiff\n");      
  for(int i=0;i<m;i++)fprintf(fp,"%d ",b->cpu_diff()[i]);  	  
   fprintf(fp,"\n");  
  if(n>10)
  {
    for(int i=n-10;i<n;i++)fprintf(fp,"%d ",b->cpu_diff()[i]);  	    	
  }
  fprintf(fp,"\n===\n");
}
template <typename DType>
void print_blobs(FILE*fp,const  std::string & title,const std::vector<caffe::Blob<DType>*> & blobs)
{
  fprintf(fp,"\n%s\nblobs:%d\n",title.c_str(),blobs.size());
  for( auto const & b: blobs)
  {
  	     print_blob(fp,b);
  } 	  
}
void print_s(FILE *fp,const std::string & s)
{
    fprintf(fp,"%s\n",s.c_str());
}
void print_s(FILE *fp,const char * s)
{
    fprintf(fp,"%s\n",s);
}

template void print_blobs(FILE*fp,const  std::string & title,const std::vector<caffe::Blob<int>*> & blobs) ;
template void print_blobs(FILE*fp,const  std::string & title,const std::vector<caffe::Blob<float>*> & blobs) ;
template void print_blobs(FILE*fp,const  std::string & title,const std::vector<caffe::Blob<double>*> & blobs) ;
template void print_blob(FILE*fp,const caffe::Blob<float> * b);
template void print_blob(FILE*fp,const caffe::Blob<double> * b);

}	
