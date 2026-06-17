#include <iostream>
#include <queue>
using namespace std;

string tinh[11] = {"HN","TN","BN","BG","UB","HP","HD","HY","PL", "HB","ST"};

void themcanh(int u, int v) { // kết nối các tỉnh
    a[u][v] = 1;
    a[v][u] = 1; }

