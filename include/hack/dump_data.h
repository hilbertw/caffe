#pragma once
#include <string>
#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "caffe/data_transformer.hpp"
#include "caffe/proto/caffe.pb.h"


void dump_data(FILE*fp,const char * comment,int);
void dump_data(FILE*fp,const char * comment,float);
void dump_data(FILE*fp,const char * comment,double);
void dump_data(FILE*fp,const char * comment,bool);
void dump_data(FILE*fp,const char * comment,const caffe::ResizeParameter &);
void dump_data(FILE*fp,const char * comment,const boost::property_tree::ptree &);
void dump_data(FILE*fp,const char * comment,const std::string &);
void dump_data(FILE*fp,const char * comment,const std::vector<int> * const);
void dump_data(FILE*fp,const char * comment,const std::map<int,std::string> &);

void dump_data(FILE*fp,const char * comment,caffe::TransformationParameter data);

template <typename Dtype>void dump_data(FILE*fp,const char * comment,const std::vector<Dtype> &);
template <typename Dtype>void dump_data(FILE*fp,const char * comment,const caffe::Blob<Dtype>&);
template <typename Dtype>void dump_data(FILE*fp,const char * comment,const boost::shared_ptr<caffe::DataTransformer<Dtype> >&);
template <typename Dtype>void dump_data(FILE*fp,const char * comment,const caffe::DataTransformer<Dtype> &);
