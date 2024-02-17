#ifndef __GT_BST_H__
#define __GT_BST_H__

#define BEGIN_NS_GT namespace GT {
#define END_NS_GT }

#include <vector>
using std::vector;

BEGIN_NS_GT

class BST {
public:
    class Node {
    public:
        int value;
        Node *left, *right;
        ~Node();
        bool validate();
    };
    Node* root;

    void preorder(Node* node, vector<int>& result);
    static Node* from_preorder(vector<int>& pre, vector<int>::iterator& iter);
public:
    BST() : root(nullptr) {}
    ~BST();

    vector<int> preorder();
    static BST* from_preorder(vector<int>& pre);
    bool validate();
};

END_NS_GT

#endif
