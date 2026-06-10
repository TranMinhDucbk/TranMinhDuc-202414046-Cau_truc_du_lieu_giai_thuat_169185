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
   if ( c == NULL){ return 0;}
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
p->left = q;
    q->right = T;
q->chieucao = max(chieucao(q->left), chieucao(q->right)) + 1;
    p->chieucao = max(chieucao(p->left), chieucao(p->right)) + 1;
return p;
}

int hesocanbang(Node* p){
     if (p == NULL)
        return 0;
return chieucao(p->left) - chieucao(p->right);
}
Node* themvaocaycanbang(Node* goc, int x) {
 if (goc == NULL){
        return taoNode(x);}
if (x < goc->data){
        goc->left = themvaocaycanbang(goc->left, x);}
 else if (x > goc->data){
        goc->right = themvaocaycanbang(goc->right, x);}
else{
        return goc;}
goc->chieucao = max(chieucao(goc->left), chieucao(goc->right)) + 1;
int canbang = hesocanbang(goc);
    if (canbang > 1 && x < goc->left->data)  // xoay đơn trái trái
        return XoayPhai(goc);
    if (canbang < -1 && x > goc->right->data)  // xoay đơn phải phải
        return XoayTrai(goc);
    if (canbang > 1 && x > goc->left->data) {   // xoay kép phải trái
        goc->left = XoayTrai(goc->left);
        return XoayPhai(goc);
    }
    if (canbang < -1 && x < goc->right->data) {  // xoay kép trái phải
        goc->right = XoayPhai(goc->right);
        return XoayTrai(goc);
    }
return goc;
}

void Duyet_giua(Node* goc) {
    if (goc != NULL) {
        Duyet_giua(goc->left);
        cout << goc->data << " ";
        Duyet_giua(goc->right);
    }
}
int main() {

    int a[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
int n = sizeof(a) / sizeof(a[0]);
Node* goc = NULL;
    for (int i = 0; i < n; i++) {
        goc = themvaocaycanbang(goc, a[i]);}
    Duyet_giua(goc);
 return 0;
}
