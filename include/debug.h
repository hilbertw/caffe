#pragma once

inline void print_shape(FILE*fp,const std::vector<int>& shape)
{
  fprintf(fp,"shape:num:%d,ch:%d,height:%d,width:%d\n",shape[0],shape[1],shape[2],shape[3]);
}
template <typename DType>
inline void print_blob(FILE*fp,const caffe::Blob<DType> * b)
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

template <typename DType>
inline void print_blobs(FILE*fp,const  std::string & title,const std::vector<caffe::Blob<DType>*> & blobs)
{
  fprintf(fp,"\n%s\nblobs:%d\n",title.c_str(),blobs.size());
  for( auto const & b: blobs)
  {
  	     print_blob(fp,b);
  } 	  
}
inline void print_s(FILE *fp,const std::string & s)
{
    fprintf(fp,"%s\n",s.c_str());
}
inline void print_s(FILE *fp,const char * s)
{
    fprintf(fp,"%s\n",s);
}
#define BEGIN_DEBUG FILE*fp=fopen("debug.txt","a"); if(fp){
#define END_DEBUG fclose(fp);}

	
