# BST

add_library(gtbst_lib STATIC gt_bst.cpp)
add_executable(bst_tests bst_tests.cpp)
add_executable(bst_tests_asan bst_tests.cpp)

target_link_libraries(bst_tests gtest_main gtest pthread bst_lib gtbst_lib)
target_link_libraries(bst_tests_asan gtest_main gtest pthread bst_lib gtbst_lib)

target_compile_options(bst_tests_asan PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
target_link_options(bst_tests_asan PRIVATE -fsanitize=address)

add_test(NAME preorder_test COMMAND bst_tests)
set_tests_properties(preorder_test PROPERTIES LABELS "normal")

add_test(NAME preorder_test_asan COMMAND bst_tests_asan)
set_tests_properties(preorder_test_asan PROPERTIES LABELS "asan")
