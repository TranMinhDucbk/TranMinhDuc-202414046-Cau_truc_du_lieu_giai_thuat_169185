#include<iostream>
using namespace std;
// khai báo nút
struct Node {
    int data;
    Node *left;
    Node *right;
};
// tạo nút
Node *taonode(int a){   
    Node *p = new Node;
    p->data = a;
    p->left = NULL;
    p->right = NULL;
    return p;
}
// thêm nút vô cây
void themnode(Node *&nodethem, int a) {
    if (nodethem == NULL)
    {nodethem = taonode(a);}
    else{
        if (a < nodethem->data){     // nhỏ hơn sang trái
            themnode(nodethem->left, a); }
        else{
            themnode(nodethem->right, a); } //còn lại sang phải
    }
}
