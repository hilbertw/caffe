#pragma once
#include <boost/property_tree/ptree.hpp>
#include "caffe/caffe.hpp"
#include "caffe/util/bbox_util.hpp"

typedef float _Dtype_;

struct shape_def 
{
   int count;
   int * data;
};
template <typename Dtype>
struct vector_dtype_def 
{
   int count;
   Dtype * data;
};
template <typename Dtype>
struct blob_dtype_def
{
    struct shape_def shape;
    int count;
    Dtype *data;
    Dtype *diff;
};
struct blob_int_def
{
    struct shape_def shape;
    int count;
    int *data;
    int *diff;
};
struct blob_double_def
{
    struct shape_def shape;
    int count;
    double *data;
    double *diff;
};
struct blob_float_def
{
    struct shape_def shape;
    int count;
    float *data;
    float *diff;
};
struct transformer_param_def
{
    int mean_size;
    float * mean_value;
    const char * mean_file;
    int crop_size;
    bool mirror;
    bool force_color;
    bool force_gray;
    float scale;
};
template<typename Dtype>
struct data_transformer_def
{
//    transformer_param_def param;
    blob_dtype_def<Dtype> data_mean_;
    vector_dtype_def<Dtype> mean_values;
};
struct int_string_pair
{
    int first;
    const char * second;
};
struct map_int_string_def
{
    int count;
    struct int_string_pair  *data;
};
struct vector_float_def
{
    int count;
    float *data;
};
struct vector_int_def
{
    int count;
    int *data;
};
struct vector_int_ptr_def
{
    int count;
    int *data;
};
struct int_int_pair
{
    int first;
    int second;
};
struct vector_pair_int_int_def
{
    int count;
    struct int_int_pair *data;
};
struct vector_string_def
{
    int count;
    const char * *data;
};

#define P_FIELD(x) int x
#define P_FIELD_R(x) struct vector_int_def x
#define P_FIELD_R_F(x) struct vector_float_def x

struct resize_param_def
{
   P_FIELD(height);
   P_FIELD(width);
   P_FIELD(height_scale);
   P_FIELD(width_scale);
   P_FIELD(resize_mode);
   P_FIELD_R(interp_mode);
   P_FIELD(pad_mode);
   P_FIELD_R_F(pad_value);
};
