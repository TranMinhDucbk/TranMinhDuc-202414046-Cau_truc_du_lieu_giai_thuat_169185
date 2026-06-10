#include<iostream>
using namespace std;
// khai báo nút
struct Node {
    int data;
    Node *left;
    Node *right;
    int chieucao;
};
 int chieucao(Node* c){
   if ( p = NULL){ return 0;}
     return c->chieucao ;
  }
int max(int a, int b) {
    if (a > b){
        return a;}
    else{
    return b;
 }
}
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->chieucao = 1;
    return p;
}
