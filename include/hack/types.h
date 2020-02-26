#pragma once
template <DType>
struct shape_def 
{
   int count;
   int * data;
};
struct blob_dtype_def
{
    struct shape_def shape;
    int count;
    DType *data;
    DType *diff;
};
struct blob_int_def
{
    struct shape_def shape;
    int count;
    int *data;
    int *diff;
};
struct blob_float_def
{
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
template<typename DType>
struct data_transformer_def
{
    transformer_param_def param;
    blob_dtype_def<DType> data_mean_;
    vector_dtype<DType> mean_values;
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
    vonst char * *data;
};
