add_library(bst_lib STATIC bst_repr.cpp bst_func.cpp)

target_include_directories(bst_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")
