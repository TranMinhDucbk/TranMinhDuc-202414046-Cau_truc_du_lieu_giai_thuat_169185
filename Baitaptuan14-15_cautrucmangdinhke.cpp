#include <iostream>
#include <queue>
using namespace std;

string tinh[11] = {"HN","TN","BN","BG","UB","HP","HD","HY","PL", "HB","ST"};
int a[11][11] = {0};
void themcanh(int u, int v) { // kết nối các tỉnh
    a[u][v] = 1;
    a[v][u] = 1; }

void duyettheochieurong(int bandau) { // duyệt theo chiều rộng
    bool daduyet[11] = {false};
queue<int> q;
daduyet[bandau] = true;
    q.push(bandau);
    int stt = 1;
    while (!q.empty())  {
        int u = q.front();
        q.pop();
cout << stt++ << " " << tinh[u] << endl;
for (int v = 0; v < 11; v++){
            if (a[u][v] == 1 && daduyet[v] == false){
                daduyet[v] = true;
                q.push(v)
            }
        }
    }
}
int main()
 {
    themcanh(0,1);   // HN - TN
    themcanh(0,2);   // HN - BN
    themcanh(0,6);   // HN- HD
    themcanh(0,8);   // HN- PL
    themcanh(0,9);   // HN - HB
     themcanh(0,10);  // HN - ST
     
    themcanh(2,3);   // BN- BG
    themcanh(2,4);   // BN- UB
   
    themcanh(3,4);   // BG - UB
   
    themcanh(4,5);   // UB-HP
   
    themcanh(5,6);   // HP - HD
   
    themcanh(6,7);   // HD- HY
   
    themcanh(7,8);   // HY- PL
    cout << "BFS bắt đầu từ HN";
    duyettheochieurong(0);
return 0;
}
