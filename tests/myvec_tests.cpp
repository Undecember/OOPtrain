#include <gtest/gtest.h>
#include "test.h"
#include <myvec.h>
using myvec::MyVector;
#include <vector>
using std::vector;

class push_pop_test : public ::testing::Test { };
class size_test : public ::testing::Test { };
class resize_test : public ::testing::Test { };
class clear_test : public ::testing::Test { };
class empty_test : public ::testing::Test { };

TEST_F(push_pop_test, half_pop) {
    srand(time(nullptr));
    for (int t = 0; t < 10; t++) {
        vector<int> stdvec;
        MyVector myvec;
        int N = rand() % 900 + 100;
        for (int i = 0; i < N; i++) {
            int rv = rand() % 1000 + 1;
            stdvec.push_back(rv);
            myvec.push_back(rv);
        }
        for (int i = 0; i < N / 2; i++) {
            stdvec.pop_back();
            myvec.pop_back();
        }
        for (int i = 0; i < stdvec.size(); i++) {
            ASSERT_EQ(stdvec[i], myvec.get(i))
                << INFO("MyVector.get returns different value to std::vector");
        }
    }
}

TEST_F(push_pop_test, pop_all) {
    srand(time(nullptr));
    for (int t = 0; t < 10; t++) {
        vector<int> stdvec;
        MyVector myvec;
        int N = rand() % 900 + 100;
        for (int i = 0; i < N; i++) {
            int rv = rand() % 1000 + 1;
            stdvec.push_back(rv);
            myvec.push_back(rv);
        }
        for (int i = 0; i < N; i++) {
            stdvec.pop_back();
            myvec.pop_back();
        }
        ASSERT_EQ(myvec.get(0), 0)
            << INFO("MyVector.get returns nonzero value for invalid index");
    }
}

TEST_F(size_test, sequential_push_pop) {
    srand(time(nullptr));
    for (int t = 0; t < 10; t++) {
        MyVector myvec;
        ASSERT_EQ(myvec.size(), 0)
            << INFO("MyVector.size returns nonzero value for new instance");
        for (int i = 0; i < 10000; i++) {
            int rv = rand() % 1000 + 1;
            myvec.push_back(rv);
            ASSERT_EQ(myvec.size(), i + 1)
                << INFO("MyVector.size returns wrong size after push");
        }
        for (int i = 9999; i >= 0; i--) {
            myvec.pop_back();
            ASSERT_EQ(myvec.size(), i)
                << INFO("MyVector.size returns wrong size after pop");
        }
        ASSERT_EQ(myvec.get(0), 0)
            << INFO("MyVector.get returns nonzero value for emptied instance");
    }
}

TEST_F(resize_test, half_shrink) {
    srand(time(nullptr));
    for (int t = 0; t < 10; t++) {
        vector<int> origin;
        MyVector myvec;
        unsigned int size = 1 << 15;
        for (int i = 0; i < (int)size; i++) {
            int rv = rand() % 10000 + 1;
            myvec.push_back(rv);
            origin.push_back(rv);
        }
        while (size > 1) {
            unsigned int newsize = size >> 1;
            myvec.resize(newsize);
            ASSERT_EQ(myvec.size(), newsize)
                << INFO("MyVector.size returns wrong size after resize smaller");
            for (int i = 0; i < (int)newsize; i++) {
                ASSERT_EQ(myvec.get(i), origin[i])
                    << INFO("MyVector.get returns wrong value after resize smaller");
            }
            for (int i = newsize; i < (int)size; i++) {
                ASSERT_EQ(myvec.get(i), 0)
                    << INFO("MyVector.get returns nonzero value "
                            "for invalidated index after resize smaller");
            }
            size = newsize;
        }
    }
}

TEST_F(resize_test, double_size) {
    srand(time(nullptr));
    for (int t = 0; t < 10; t++) {
        vector<int> origin;
        MyVector myvec;
        unsigned int size = 1 << (rand() % 13 + 2);
        size += rand() % size;
        for (int i = 0; i < (int)size; i++) {
            int rv = rand() % 10000 + 1;
            myvec.push_back(rv);
            origin.push_back(rv);
        }
        unsigned int newsize = size << 1;
        myvec.resize(newsize);
        ASSERT_EQ(myvec.size(), newsize)
            << INFO("MyVector.size returns wrong size after resize larger");
        for (int i = 0; i < (int)size; i++) {
            ASSERT_EQ(myvec.get(i), origin[i])
                << INFO("MyVector.get returns wrong value after resize larger");
        }
        for (int i = size; i < (int)newsize; i++) {
            ASSERT_EQ(myvec.get(i), 0)
                << INFO("MyVector.get returns nonzero value for new index after resize larger");
        }
        size = newsize;
    }
}

TEST_F(clear_test, simple_clear) {
    srand(time(nullptr));
    for (int t = 0; t < 50; t++) {
        MyVector myvec;
        unsigned int size = 1 << (rand() % 13 + 2);
        size += rand() % size;
        for (int i = 0; i < (int)size; i++) {
            int rv = rand() % 10000 + 1;
            myvec.push_back(rv);
        }
        myvec.clear();
        ASSERT_EQ(myvec.size(), 0)
            << INFO("MyVector.size returns nonzero value after clear");
        for (int i = 0; i < (int)size; i++) {
            ASSERT_EQ(myvec.get(i), 0)
                << INFO("MyVector.get returns nonzero value for invalidated index after clear");
        }
    }
}

TEST_F(empty_test, simple_empty) {
    srand(time(nullptr));
    MyVector myvec;
    unsigned int size = 1 << (rand() % 13 + 2);
    size += rand() % size;
    for (int i = 0; i < (int)size; i++) {
        int rv = rand() % 10000 + 1;
        myvec.push_back(rv);
    }
    for (int t = 0; t < 50; t++) {
        size = 1 << (rand() % 13 + 2);
        size += rand() % size;
        ASSERT_FALSE(myvec.empty())
            << INFO("MyVector.empty returns true when size is positive");
    }
    myvec.clear();
    ASSERT_TRUE(myvec.empty())
        << INFO("MyVector.empty returns false when size is zero");
}
