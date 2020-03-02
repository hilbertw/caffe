add_library(hack STATIC dump_data.cpp print_data.cpp)
list(APPEND Caffe_LINKER_LIBS hack)
 
#set(Caffe_LINKER_LIBS  ${Caffe_LINKER_LIBS} hack ) # note, crucial to prepend!
caffe_default_properties(hack)



