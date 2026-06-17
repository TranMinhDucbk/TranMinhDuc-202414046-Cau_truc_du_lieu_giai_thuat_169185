#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *ds[11];
string tinh[11] = {"HN","TN","BN","BG","UB","HP","HD","HY","PL", "HB","ST"};

Node* taoNode(int node) 
    Node *p = new Node;
    p->data = node;
    p->next = NULL;
return p; }
void themvaocuoi(Node *&dau, int x){
    Node *p = taoNode(x);

    if(dau == NULL){
        dau = p;
        return 0;}
Node *q = dau;
while(q->next != NULL){
        q = q->next;
    }
q->next = p;
}
void duyettheochieurong(int bandau){
    bool daduyet[11] = {false};
  queue<int> q;
  daduyet[bandau] = true;
    q.push(bandau);
    int stt = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
cout << stt++ << " " << ten[u] << endl;
Node *p = ds[u];
    while(p != NULL){
            int v = p->data
 if(daduyet[v] == false) {
                daduyet[v] = true;
                q.push(v);
            }
      p = p->next;
        }
    }

