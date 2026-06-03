#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *taonode(int a)
{
    Node *p = new Node;
    p->data = a;
    p->left = NULL;
    p->right = NULL;
    return p;
}