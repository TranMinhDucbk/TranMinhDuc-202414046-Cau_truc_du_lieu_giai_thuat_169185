#include <iostream>
#include <queue>
using namespace std;

string tinh[11] = {"HN","TN","BN","BG","UB","HP","HD","HY","PL", "HB","ST"};

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
cout << stt++ << ". " << ten[u] << endl;
for (int v = 0; v < 11; v++){
            if (a[u][v] == 1 && daduyet[v] == false){
                daduyet[v] = true;
                q.push(v)
            }
        }
    }
}
