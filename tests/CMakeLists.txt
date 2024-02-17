# MyVec

add_executable(myvec_tests myvec_tests.cpp)
add_executable(myvec_tests_asan myvec_tests.cpp)

target_link_libraries(myvec_tests gtest_main gtest pthread myvec_lib)
target_link_libraries(myvec_tests_asan gtest_main gtest pthread myvec_lib)

target_compile_options(myvec_tests_asan PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
target_link_options(myvec_tests_asan PRIVATE -fsanitize=address)

add_test(NAME push_pop_test COMMAND myvec_tests)
set_tests_properties(push_pop_test PROPERTIES LABELS "normal")

add_test(NAME push_pop_test_asan COMMAND myvec_tests_asan)
set_tests_properties(push_pop_test_asan PROPERTIES LABELS "asan")
