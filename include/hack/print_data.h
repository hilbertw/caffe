#pragma once 
#include <string>
#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "caffe/data_transformer.hpp"

template<typename Dtype> void print_blob_dtype(FILE*fp,const char *  comment, const caffe::Blob<Dtype>& data);
template<typename Dtype> void print_blob_dtype_data(FILE*fp,const char *  comment,const caffe::Blob<Dtype>& data);
template<typename Dtype> void print_blob_dtype_shape_data(FILE*fp,const char *  comment, const caffe::Blob<Dtype>&data);

//template<typrname Dtype> void print_array(FILE*fp,const char *  comment,Dtype * data,int len);
void print_array(FILE*fp,const char *  comment,int * data,int len);
void print_array(FILE*fp,const char *  comment,float * data,int len);
template<typename Dtype> void print_vector_dtype(FILE*fp,const char *  comment,const std::vector<Dtype>& data);
template<typename Dtype> void print_vector_dtype_data(FILE*fp,const char *  comment, const std::vector<Dtype>&data);

void print_transformer_param_data(FILE*fp,const char *  comment, const caffe::TransformationParameter&data);
void print_transformer_param(FILE*fp,const char *  comment, const caffe::TransformationParameter&data);
template<typename Dtype> void print_transformer_data(FILE*fp,const char *  comment, const caffe::DataTransformer<Dtype>&data);
template<typename Dtype> void print_transformer(FILE*fp,const char *  comment, const caffe::DataTransformer<Dtype>&data);
template<typename Dtype> void print_transformer(FILE*fp,const char *  comment, const boost::shared_ptr<caffe::DataTransformer<Dtype> >&data);
template<typename Dtype> void print_transformer_data(FILE*fp,const char *  comment, const boost::shared_ptr<caffe::DataTransformer<Dtype> >&data);
void print_vector_pair_int_int(FILE*fp,const char *comment,const std::vector<std::pair<int,int>>& m);
void print_vector_pair_int_int_data(FILE*fp,const char * comment,const std::vector<std::pair<int,int>>& m);
void print_map_int_string(FILE*fp,const char *comment,const std::map<int,std::string>& m);
void print_map_int_string_data(FILE*fp,const char * comment,const std::map<int,std::string>& m);
void print_vector_int_ptr(FILE*fp,const char *comment,const std::vector<int>* m);
void print_vector_int_ptr_data(FILE*fp,const char * comment,const std::vector<int>* m);

void print(FILE*fp,const char * comment,int);
void print(FILE*fp,const char * comment,float);
void print(FILE*fp,const char * comment,double);
void print(FILE*fp,const char * comment,bool);
void print(FILE*fp,const char * comment,const caffe::ResizeParameter &);
void print(FILE*fp,const char * comment,const boost::property_tree::ptree &);
void print(FILE*fp,const char * comment,const std::string &);
//void print(FILE*fp,const char * comment,const std::vector<int> * const);
//void print(FILE*fp,const char * comment,const std::vector<int> &);
//template <typename Dtype>void print(FILE*fp,const char * comment,const caffe::Blob<Dtype>&);
template <typename Dtype>void print(FILE*fp,const char * comment,const boost::shared_ptr<caffe::DataTransformer<Dtype> >&);
//void print(FILE*fp,const char * comment,const std::vector <std::string>&);
//void print(FILE*fp,const char * comment,const std::vector <float>&);
//void print(FILE*fp,const char * comment,const std::map <int,std::string>&);
//void print(FILE*fp,const char * comment,const std::vector<std::pair<int, int> >&);
void print_vector_string_data(FILE*fp,const char * comment,const std::vector<std::string> &data);
void print_vector_string(FILE*fp,const char * comment,const std::vector<std::string> &data);
