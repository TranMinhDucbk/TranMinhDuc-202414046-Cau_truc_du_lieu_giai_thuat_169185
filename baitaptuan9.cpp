#include<iostream>
using namespace std;
struct Ngay{
     int ngay, thang , nam;
};
struct SinhVien {
    char maSV[10];
    char name[50];
    int GioiTinh;
    Ngay Ngaysinh;
    char diachi[100];
    char lop[12];
    char khoa[7];
};

struct Node{
    SinhVien data;
    Node* next;
};

struct List{
    Node* first;
    Node*last;
}; 

void List_Init (List* list){
    list->first = 0;
}
void themsvvodau(List*list, SinhVien sinhvien){
     Node*newnode =new Node;
     newnode-> data = sinhvien;
     newnode->next = list->first;
     list->first = newnode;
}

void themsv(Node*node, SinhVien sinhvien){
     Node* newnode = new Node;
     newnode->data = sinhvien;
     newnode->next = node->next;
     node->next = newnode;
}

void duyettheomssv(List* list, SinhVien sinhvien){
   if(list -> first == 0 ||list->first->data.maSV > sinhvien.maSV){
      themsvvodau(list, sinhvien);
      return ;
   }
   Node* node = list->first;
 while(node -> next!=0 && node->data.maSV < sinhvien.maSV) {
      node = node->next;
}
     themsv(node, sinhvien);
}
 void inDS(List* list) {
    Node* p = list -> first;
    while(p!=0){
        cout << "MSSV: " << p->data.maSV <<'\t'
             << "Ten: " << p->data.name <<'\t'
             << "NS: " << p->data.Ngaysinh.ngay << "/" << p->data.Ngaysinh.thang << "/" << p->data.Ngaysinh.nam <<'\t'
             << "Lop: " << p->data.lop << '\t'
             << "Khoa: " << p->data.khoa << endl;
        
        p = p->next;
    }
}
    
 int cungngaysinh(SinhVien sv1, SinhVien sv2) {
    return(sv1.Ngaysinh.ngay == sv2.Ngaysinh.ngay && sv1.Ngaysinh.thang == sv2.Ngaysinh.thang && sv1.Ngaysinh.nam == sv2.Ngaysinh.nam);

 }
 void inSVcungngaysinh(List* list){
    Node* p =list -> first;
    int t = 0;
    while(p!=0){
        Node* check = list->first;
        int daIn = 0;
        while (check != p) {
            if (cungngaysinh(check->data, p->data)) {
                daIn = 1;
                break;
            }
            check = check->next;
        }
        if (daIn) { 
            p = p->next;
            continue;
        }
        Node* q = p->next;
        int c = 0;
        while(q!=0){
            if(cungngaysinh(p->data,q->data)){
                c = 1;
                break;
            }
            q =q->next;
        }
        if(c){
            t = 1;
             cout << "MSSV: " << p->data.maSV <<'\t'
             << "Ten: " << p->data.name <<'\t'
             << "NS: " << p->data.Ngaysinh.ngay << "/" << p->data.Ngaysinh.thang << "/" << p->data.Ngaysinh.nam <<'\t'
             << "Lop: " << p->data.lop << '\t'
             << "Khoa: " << p->data.khoa << endl;
        }
        Node* q2 = p->next; 
            while(q2 != 0){
                if(cungngaysinh(p->data, q2->data)){
                    cout << "MSSV: " << q2->data.maSV <<'\t'
                         << "Ten: " << q2->data.name <<'\t'
                         << "NS: " << q2->data.Ngaysinh.ngay << "/" << q2->data.Ngaysinh.thang << "/" << q2->data.Ngaysinh.nam <<'\t'
                         << "Lop: " << q2->data.lop << '\t'
                         << "Khoa: " << q2->data.khoa << endl;
                }
                q2 = q2->next;
            }
       p = p->next;
    }
    if(!t){
        cout<<"không tìm thấy sinh viên cùng ngày sinh";
    }
 }
void xoaNode(List* list) {
    Node* p = list->first;
    Node* prev = 0; 

    while (p != 0) {
        int count = 0;
        Node* temp = list->first;
        while (temp != 0) {
            if (cungngaysinh(p->data, temp->data)) {
                count++;
            }
            temp = temp->next;
        }
        if (count > 1) {
            Node* q = p; 

            if (prev == 0) { 
               
                list->first = p->next;
                p = p->next;
            } else { 
                prev->next = p->next; 
                p = p->next;
            }
            
            delete q; 
        } else {
            prev = p;
            p = p->next;
        }
    }
}

int main() {

}int main() {
    List ds;
    List_Init(&ds);

    // Tạo dữ liệu mẫu (sv1 và sv3 cố tình để trùng ngày sinh)
    SinhVien sv1 = {"202414046", "Tran Minh Duc", 1, {1, 1, 2000}, "Ha Noi", "Dien tu 02", "K69"};
    SinhVien sv2 = {"202414043", "Tran Thi Bich", 0, {2, 2, 2000}, "Hai Phong", "Dien tu 02", "K70"};
    SinhVien sv3 = {"202416032", "Le Van Cu", 1, {1, 1, 2000}, "Da Nang", "Co Khi 03", "K68"}; 
    SinhVien sv4 = {"202414853", "Pham Thi Dich", 0, {3, 3, 2001}, "Sai Gon", "Co Khi 04", "K69"};

    // Thêm sinh viên vào danh sách
    duyettheomssv(&ds, sv1);
    duyettheomssv(&ds, sv2);
    duyettheomssv(&ds, sv3);
    duyettheomssv(&ds, sv4);

    cout << "--- DANH SACH SAU KHI CHEN ---" << endl;
    inDS(&ds);

    cout << "\n--- IN SINH VIEN CUNG NGAY SINH ---" << endl;
    inSVcungngaysinh(&ds);

    cout << "\n--- DANH SACH SAU KHI XOA NGUOI CUNG NGAY SINH ---" << endl;
    xoaNode(&ds);
    inDS(&ds);

    return 0;
}
