#pragma once 
#include <string>
#include <map>
#include <vector>
#include "caffe/caffe.hpp"

template<typename Dtype> void print_blob_dtype(FILE*fp,const char *  comment, caffe::Blob<Dtype>& data);
template<typename Dtype> void print_blob_dtype_data(FILE*fp,const char *  comment,caffe::Blob<Dtype>& data);
template<typename Dtype> void print_blob_dtype_shape_data(FILE*fp,const char *  comment, caffe::Blob<Dtype>&data);

//template<typrname Dtype> void print_array(FILE*fp,const char *  comment,Dtype * data,int len);
void print_array(FILE*fp,const char *  comment,int * data,int len);
void print_array(FILE*fp,const char *  comment,float * data,int len);
template<typename Dtype> void print_vector_dtype(FILE*fp,const char *  comment,std::vector<Dtype>& data);
template<typename Dtype> void print_vector_dtype_data(FILE*fp,const char *  comment, std::vector<Dtype>&data);

void print_transformer_param_data(FILE*fp,const char *  comment, caffe::TransformationParameter&data);
void print_transformer_param(FILE*fp,const char *  comment, caffe::TransformationParameter&data);
template<typename Dtype> void print_transformer_data(FILE*fp,const char *  comment, caffe::DataTransformer<Dtype>&data);
template<typename Dtype> void print_transformer(FILE*fp,const char *  comment, caffe::DataTransformer<Dtype>&data);
void print_vector_int_int_pair(FILE*fp,const char *comment,std::vector<std::pair<int,std::string>>& m);
void print_vector_int_int_pair_data(FILE*fp,const char * comment,std::vector<std::pair<int,int>>& m);
void print_map_int_string(FILE*fp,const char *comment,std::map<int,std::string>& m);
void print_map_int_string_data(FILE*fp,const char * comment,std::map<int,std::string>& m);
