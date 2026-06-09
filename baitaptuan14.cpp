#include<iostream>
using namespace std;
// khai báo nút
struct Node {
    int data;
    Node *left;
    Node *right;
};
// tạo nút
Node *taonode(int a) {   
    Node *p = new Node;
    p->data = a;
    p->left = NULL;
    p->right = NULL;
    return p;
}
