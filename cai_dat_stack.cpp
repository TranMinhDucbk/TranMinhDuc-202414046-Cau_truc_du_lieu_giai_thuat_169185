#include<iostream>
using namespace std;

#define MAX 1000
struct Stack{
    int Top; // phần tử đỉnh
    int Data[MAX];
};
Stack S;

//khởi tạo ngăn xếp
 void Init(Stack*S){
    S->Top = 0;
 }
 //kiem tra rong
  int Isempty(Stack S) {
    return(S.Top == 0);
  }
//kiem tra day
int Isfull (Stack S) {
    return(S.Top == MAX);
}
int main() {
    Stack S;
    
    // 1. Khởi tạo ngăn xếp
    Init(&S);
    // 2. Kiểm tra ngăn xếp vừa khởi tạo có rỗng không
    if (Isempty(S)) {
    cout << "Stack rong" << endl;
    } else {
    cout << "Stack khong rong" << endl;
    }
    // 3. Kiểm tra ngăn xếp có đầy không
    if (Isfull(S)) {
    cout << "Stack day" << endl;
    } else {
    cout << "Stack khong day" << endl;
    }
    
    return 0;
}
