#include<iostream>
using namespace std;
//định nghĩa tạo file
struct File{
    char name[50];
    int time;
    double size;
};
//cấu trúc móc nối
struct Node{
     File data;
     Node* next;
};

struct List {
   Node* firstNode;
};

void List_Init (List* list){
    list->firstNode = 0;
}

//chèn file vào trước phía đầu
void themfilevaodau(List*list, File filemoi){
     Node*newnode =new Node;
     newnode-> data = filemoi;
     newnode->next = list->firstNode;
     list->firstNode = newnode;
}
// 2 chèn file vào 

void themFile(Node* node, File filemoi) {
     Node* newnode = new Node;
     newnode->data = filemoi;
     newnode->next = node->next;
     node->next = newnode;
}
// xếp theo thời gian cần duyệt list 
void duyetthoigian(List* list, File filemoi) {
 if (list->firstNode == 0 || list->firstNode->data.time > filemoi.time) {
     themfilevaodau(list, filemoi);
     return;
 }
 Node* node = list->firstNode;
 while(node!=0 && node->data.time < filemoi.time) {
      node = node->next;
}
     themFile(node, filemoi);
}

//3 Tính toán các file cần duyệt xong tính tổng size giống phần tính đồ dài trong slide
double tinhtoancacfile(List*list){
 Node* node = list->firstNode;
 double tongdungluong = 0;
 while(node!=0){
    tongdungluong += node->data.size;
    node = node->next; 

}
return tongdungluong;
}

//4  loại bỏ file -> duyệt list rồi dùng xoá bỏ 1 node -> tìm file size nhỏ nhất và xoá nó
void xoafilenho(List*list) {
  Node* p = list->firstNode;
  Node* q = p;
 while(p!=0){
      if(p->data.size < q-> data.size){
         q = p;
 }
      p = p -> next;
 }
 if (q == list->firstNode) {
 list->firstNode = q ->next;
 }
else{
     Node* f = list->firstNode;
      while(f->next!=q){
         f = f->next;
 }
 f->next = q->next;
 }delete q;
}

//xoá đến khi vừa 32gb
void xoaduvua32gb(List*list) {
     while(tinhtoancacfile(list)>32) {
          xoafilenho(list);
     }
}
int main {
    // 1. Khởi tạo danh sách
    List fileList;
    List_Init(&fileList);

    // 2. Tạo file 
    File f1 = {"Document.pdf", 10, 15.0}; 
    File f2 = {"Video_A.mp4", 5, 20.0};   
    File f3 = {"Image_B.png", 20, 10.0};  

    // 3 thêm file vào danh sách
    duyetthoigian(&fileList, f2); 
    duyetthoigian(&fileList, f1); 
    duyetthoigian(&fileList, f3); 

    // 4 tính toán các file  
    cout << "Tong dung luong ban dau: " << tinhtoancacfile(&fileList) << " GB" << endl;

    // 5 xóa file nhỏ nhất cho đến khi dung lượng <= 32GB
    cout <<"cho vào usb 32gb" << xoavuadu32gb(&fileList);
}
