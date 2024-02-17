#include "gt_bst.h"

#include <cstdlib>

using namespace GT;

BST::Node* BST::from_preorder(vector<int>& pre, vector<int>::iterator& iter) {
    if (*iter < 0) return iter++, nullptr;
    Node* res = (Node*) malloc(sizeof(Node));
    res->value = *iter++;
    if (iter == pre.end()) return free(res), nullptr;
    res->left = BST::from_preorder(pre, iter);
    if (iter == pre.end()) return free(res), nullptr;
    res->right = BST::from_preorder(pre, iter);
    return res;
}
BST* BST::from_preorder(std::vector<int>& pre) {
    if (pre.empty()) return nullptr;
    BST* res = (BST*) malloc(sizeof(BST));
    auto iter = pre.begin();
    res->root = BST::from_preorder(pre, iter);
    if (iter != pre.end()) {
        res->~BST();
        free(res);
        return nullptr;
    }
    return res;
}

bool BST::Node::validate() {
    if (left && left->value >= value) return false;
    if (right && value >= right->value) return false;
    return true;
}
bool BST::validate() {
    if (!root) return true;
    return root->validate();
}

BST::Node::~Node() {
    if (left) {
        left->~Node();
        free(left);
    }
    if (right) {
        right->~Node();
        free(right);
    }
}
BST::~BST() {
    if (root) {
        root->~Node();
        free(root);
    }
}
