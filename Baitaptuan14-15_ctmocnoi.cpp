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
cout << stt++ << " " << tinh[u] << endl;
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
int main() {
      for(int i = 0; i < 11; i++)
        ds[i] = NULL;

    // HN
    themCanh(0,1);
    themCanh(0,2);
    themCanh(0,6);
    themCanh(0,8);
    themCanh(0,9);
    themCanh(0,10);

    // BN
    themCanh(2,3);
    themCanh(2,4);

    // BG
    themCanh(3,4);

    // UB
    themCanh(4,5);

    // HP
    themCanh(5,6);

    // HD
    themCanh(6,7);

    // HY
    themCanh(7,8);
     cout << "BFS từ Hà Nội:";
duyettheochieurong(0);
return 0;
}
