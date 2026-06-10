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
Node* taoNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->chieucao = 1;
    return p;
}
Node* XoayPhai(Node* p) {   //xoay sang phải
    Node* x = p->left;
    Node* T = x->right;
x->right = p;
    p->left = T;
    p->chieucao = max(chieucao(p->left), chieucao(p->right)) + 1;
    x->chieucao = max(chieucao(x->left), chieucao(x->right)) + 1;
    return x;
}
Node* XoayTrai(Node* q) {  //xoay sang trái
    Node* p = q->right;
    Node* T = p->left;
p->left = x;
    q->right = T;
q->chieucao = max(chieucao(q->left), chieucao(q->right)) + 1;
    p->chieucao = max(chieucao(p->left), chieucao(p->right)) + 1;

    return y;
}
