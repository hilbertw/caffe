#pragma once

#include "hack/print_data.h"
#include "hack/dump_data.h"
//#include "hack/layer_conf.h"
template <typename Dtype> void print_blobs(const std::string & name,const caffe::vector<caffe::shared_ptr<caffe::Blob<Dtype>>> & blobs);
