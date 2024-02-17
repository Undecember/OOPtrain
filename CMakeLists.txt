cmake_minimum_required(VERSION 3.14)

project(
    BSTrain
    VERSION 0.1
    DESCRIPTION "A project to learn about BST, AVL, and RB trees")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
