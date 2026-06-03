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
Node* timkiemnode(Node *goc, int a) { // tìm node
    if(goc == NULL || goc->data == a)
        return goc;
    if(a < goc->data) {    // nếu nhỏ hơn gốc thì sang trái
        return timkiemnode(goc->left, a);}
    else{
    return timkiemnode(goc->right, a);}  // không thì sang phải
}
int main() {
 int a[] = {2001, 2002, 2006, 2007, 2008, 2004, 2005, 2001, 1999, 2004};
int n = 10;
    Node* goc = NULL;
    for(int i = 0; i < n; i++){
        themnode(goc, a[i]); }
    int cantim = 2004;
    Node* p = timkiemnode(goc, cantim);
    if(p != NULL) {
        cout<<"co node can tim "<< cantim << endl;
    }
    else{
        cout<<"khong co node can tim "<< cantim <<endl;
}
