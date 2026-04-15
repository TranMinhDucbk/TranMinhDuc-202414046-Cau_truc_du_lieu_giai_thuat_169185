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
