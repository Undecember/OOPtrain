add_library(myvec_lib STATIC myvec.cpp)

target_include_directories(myvec_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")
