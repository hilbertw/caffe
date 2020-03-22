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
    int data_flag;
    int diff_flag;
};
#if 0
struct blob_int_def
{
    struct shape_def shape;
    int count;
    int *data;
    int *diff;
    int data_flag;
    int diff_flag;
};
struct blob_double_def
{
    struct shape_def shape;
    int count;
    double *data;
    double *diff;
    int data_flag;
    int diff_flag;
};
struct blob_float_def
{
    struct shape_def shape;
    int count;
    float *data;
    float *diff;
    int data_flag;
    int diff_flag;
};
#else
typedef  struct blob_dtype_def<int> blob_int_def; 
typedef  struct blob_dtype_def<float> blob_float_def; 
typedef  struct blob_dtype_def<double> blob_double_def; 
#endif
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
    int phase;
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
#if 0
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
#else

typedef struct vector_dtype_def<int> vector_int_def;
typedef struct vector_dtype_def<float> vector_float_def;
#endif
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
#define P_FIELD_R(x)  vector_int_def x
#define P_FIELD_R_F(x)  vector_float_def x

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
