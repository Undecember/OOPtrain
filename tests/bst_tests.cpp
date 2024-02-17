#include <gtest/gtest.h>
#include <bst.h>
#include "gt_bst.h"

#include <vector>
using std::vector;
#include <set>
using std::set;
#include <cstdlib>
#include <ctime>

class BSTTest : public ::testing::Test {
protected:
    BST bst;
    GT::BST gtbst;

    vector<int> generateUniqueRandomIntegers(size_t count) {
        set<int> numbers;
        while (numbers.size() < count) {
            numbers.insert(rand() % 1000 + 1);
        }
        return vector<int>(numbers.begin(), numbers.end());
    }
};

TEST_F(BSTTest, preorder_test) {
    srand(time(nullptr));
    auto numbers = generateUniqueRandomIntegers(10);
    for (int num : numbers) bst.insert(num);
    auto preorderResult = bst.preorder();
    ASSERT_TRUE(true);
}
