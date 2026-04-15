#include<iostream>
using namespace std;

struct Nodedathuc{
     float heso;
     int somu;
    Nodedathuc* link;
};

struct ListDT {
    Nodedathuc*first, *last;
};

void initDathuc(ListDT* l) {
    l->first=l->last = NULL;
}

Nodedathuc* callNode(float hs, int sm) {
    Nodedathuc *p;
    p = new Nodedathuc;
    if(p==NULL) return NULL;
    p->heso = hs;
    p->somu = sm;
    p->link = NULL;
    return p;
}

void themNode(ListDT* lDT, Nodedathuc* p){
    if(lDT->first = NULL) {
        lDT->first = lDT->last = p;
    }
    else {
        lDT->last -> link = p;
        lDT-> last = p;
    }
}

void ganNode(ListDT*lDT, float hs, int sm){
    Nodedathuc* pDT = callNode(hs, sm);
    if(pDT == NULL) return;
    themNode(lDT, pDT);
}

void taoDaThuc(ListDT* lDT){
    float hs; 
    int sm;
    int i = 0; //số phần tử
        cout << "nhap da thuc ket thuc khi hs = 0: " << endl;
    do
    {
        i++;
        cout << "nhap so phan tu thu " << i << endl;
		 cout << "\nnhap he so = ";
        cin >> hs;
        if (hs == 0) break;
        cout << "\nnhap so mu = ";
        cin >> sm;
        ganNode(lDT, hs, sm);
	} while (hs != 0);
    cout << "ket thuc " << endl;

}

void inDaThuc(ListDT lDT) {
    Nodedathuc* p;
    p = lDT.first;
    cout << "\nf(x) = ";
    while (p != NULL) {
        cout << p->heso << " * x^" << p->somu;
        if (p->link != NULL && p->heso!= 0) cout << " + ";
        p = p->link;
    }
}
int main()
{
    ListDT DT1;
    initDathuc(&DT1);
    taoDaThuc(&DT1);
    inDaThuc(&DT1);
}


