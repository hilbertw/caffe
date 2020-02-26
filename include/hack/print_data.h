#pragma once 
template<> void print_blob_dtype<int>(FILE*fp,const char *  comment, caffe::Blob<int>& data);
template<> void print_blob_dtype_data<int>(FILE*fp,const char *  comment,caffe::Blob<int>& data);
template<> void print_blob_dtype<float>(FILE*fp,const char *  comment, caffe::Blob<float>& data);
template<> void print_blob_dtype_data<float>(FILE*fp,const char *  comment,caffe::Blob<float>& data);
template<> void print_blob_dtype_shape_data<int>(FILE*fp,const char *  comment, caffe::Blob<int>&data);
template<> void print_blob_dtype_shape_data<float>(FILE*fp,const char *  comment, caffe::Blob<float>&data);
void print_blob_int(FILE*fp,const char *  comment,caffe::Blob<int>& data);
void print_blob_int_data(FILE*fp,const char *  comment,caffe::Blob<int>& data);
void print_blob_int_shape_data(FILE*fp,const char *  comment,istd:vector<int>& data);
void print_vector_float(FILE*fp,const char *  comment,std::vector<float>& data);
void print_vector_float_data(FILE*fp,const char *  comment, std::vector<float>&data);
void print_vector_int(FILE*fp,const char *  comment,std::vector<int>& data);
void print_vector_int_data(FILE*fp,const char *  comment, std::vector<int>&data);
void print_transformer_param_data(FILE*fp,const char *  comment, caffe::TransformationParameter&data);
void print_transformer_data(FILE*fp,const char *  comment, caffe::DataTransformer&data);
void print_transformer(FILE*fp,const char *  comment, caffe::DataTransformer&data);
