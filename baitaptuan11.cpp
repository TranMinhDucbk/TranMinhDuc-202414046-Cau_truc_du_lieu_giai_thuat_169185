#include<iostream> 
using namespace std; 

double pow(double x, long long n) {
    
    if (n == 0) return 1.0;
    if (n < 0) {
        x = 1.0 / x;
        n = -n; 
    }

    double result = 1.0;
    for (long long i = 0; i < n; i++) {
        result *= x;
    }

    return result;
}
//  CẤU TRÚC LƯU TRỮ TUẦN TỰ
#define MAXLENGTH 100         // Định nghĩa kích thước tối đa của mảng là 100
typedef int KieuDuLieu;      
typedef int Node;            

// Định nghĩa cấu trúc Cây lưu bằng mảng
typedef struct {
    KieuDuLieu Data[MAXLENGTH];   // Mảng 1 chiều chứa giá trị của các nút trong cây
    int MaxNode;                  // Số lượng nút thực tế đang có trong cây
} Cay;

// Hàm khởi tạo cây tuần tự 
void KhoiTaoCay(Cay &T) {
    T.MaxNode = 0;                        // Ban đầu cây chưa có nút nào
    for (int i = 0; i < MAXLENGTH; i++) { // Duyệt qua toàn bộ mảng
        T.Data[i] = -1;                   // Gán -1 để đánh dấu vị trí này chưa có dữ liệu
    }
}

// Kiểm tra cây có rỗng hay không
int CayRong(Cay T) {
    return T.MaxNode == 0; // Trả về 1  nếu MaxNode = 0, ngược lại trả về 0
}

// Lấy chỉ số của nút gốc
Node Root(Cay T) { 
    if (!CayRong(T)) return 0; // Nếu cây không rỗng, gốc luôn nằm ở chỉ số 0 của mảng
    else return -1;            // Trả về -1 nếu cây rỗng
}

// tạo con trái
int ConTrai(Node p, Cay T) {
    return 2 * (p + 1) -1; 
}

// tạo con phải
int ConPhai(Node p, Cay T) {
    return 2 * (p + 1);     
}

// Tạo cây nhị phân đầy đủ trên mảng với số tầng cho trước
void TaoCayDayDu_TuanTu(Cay &T, int chieucao) {
    KhoiTaoCay(T); // Reset cây
    T.MaxNode = pow(2, chieucao) - 1; // Tổng số nút của cây đầy đủ = 2^h - 1
    for (int i = 0; i < T.MaxNode; i++) { 
        T.Data[i] = i + 1; 
    }
}

// Tạo cây lệch trái hoàn toàn trên mảng
void TaoCayLechTrai_TuanTu(Cay &T, int soNut) {
    KhoiTaoCay(T);
    T.MaxNode = soNut; // Ghi nhận số nút
    int p = 0; // Bắt đầu từ vị trí gốc
    for (int i = 0; i < soNut; i++) {
        T.Data[p] = i + 1; // Gán dữ liệu cho nút hiện tại
        p = ConTrai(p, T); // chuyển dữ liệu sang con trái
    }
}
// Tạo cây lệch phải
void TaoCayLechPhai_TuanTu(Cay &T, int soNut) {
    KhoiTaoCay(T);
    T.MaxNode = soNut; 
    int p = 0; // Bắt đầu từ vị trí gốc
    for (int i = 0; i < soNut; i++) {
        T.Data[p] = i + 1; // Gán dữ liệu cho nút hiện tại
        p = ConPhai(p, T); // chuyển dữ liệu sang con phải
    }
}

// Duyệt tiền tố
void duyettiento(Node p, Cay T) {
    // Điều kiện dừng: index hợp lệ và vị trí đó có dữ liệu (khác -1)
    if (T.Data[p] != -1) {
        cout << T.Data[p] << " ";       // Xử lý nút hiện tại 
        duyettiento(ConTrai(p, T), T);  // Gọi đệ quy duyệt nhánh con trái 
        duyettiento(ConPhai(p, T), T);  // Gọi đệ quy duyệt nhánh con phải 
    }
}

// Duyệt trung tố
void duyettrungto(Node p, Cay T) {
    if ( T.Data[p] != -1) {
        duyettrungto(ConTrai(p, T), T); // Gọi đệ quy đi sâu vào nhánh con trái
        cout << T.Data[p] << " ";       // In ra nút hiện tại 
        duyettrungto(ConPhai(p, T), T); // Gọi đệ quy sang nhánh con phải
    }
}

//duyệt hậu tố
void duyethauto(Node p, Cay T) {
    if (T.Data[p] != -1) {
        duyethauto(ConTrai(p, T), T); // gọi đệ quy nhánh trái
        duyethauto(ConPhai(p, T), T); // gọi đệ quy nhánh phải
        cout<< T.Data[p] << " ";
    }
}

// cấu trúc móc nối
struct Nodemocnoi {
    int data;                
    Nodemocnoi* trai;        
    Nodemocnoi* phai;       

    Nodemocnoi(int val) {
        data = val;          // Gán giá trị được truyền vào
        trai = NULL;         // Mặc định con trái chưa có gì (NULL)
        phai = NULL;         // Mặc định con phải chưa có gì (NULL)
    }
};

// Hàm tạo cây lệch trái bằng móc nối
Nodemocnoi* TaoCayLechTrai_MocNoi(int soNut) {
    if (soNut == 0) return NULL; // Nếu yêu cầu 0 nút thì trả về rỗng
    
    Nodemocnoi* root = new Nodemocnoi(1); // Cấp phát vùng nhớ cho nút gốc
    Nodemocnoi* p = root;              // Dùng con trỏ p để đi dọc xuống dưới, giữ nguyên root
    
    for (int i = 2; i <= soNut; i++) {
        p->trai = new Nodemocnoi(i);   // Tạo nút mới và móc vào nhánh trái của curr
        p = p->trai;                // Cập nhật curr dời xuống chính nút vừa tạo
    }
    return root; // Trả về địa chỉ của gốc
}
//hàm tạo cây lệch phải bằng móc nối
Nodemocnoi* TaoCayLechPhai_MocNoi(int soNut) {
    if (soNut == 0) return NULL; // Nếu yêu cầu 0 nút thì trả về rỗng
    
    Nodemocnoi* root = new Nodemocnoi(1); // Cấp phát vùng nhớ cho nút gốc
    Nodemocnoi* p = root;              // Dùng con trỏ p để đi dọc xuống dưới, giữ nguyên root
    
    for (int i = 2; i <= soNut; i++) {
        p->phai = new Nodemocnoi(i);   // Tạo nút mới và móc vào nhánh phải
        p = p->phai;                // Cập nhật p dời xuống chính nút vừa tạo
    }
    return root; // Trả về địa chỉ của gốc
}
//cây biểu thức
// Tương tự cấu trúc móc nối ở trên, nhưng đổi kiểu dữ liệu thành char
struct NodeBieuThuc {
    char data;               // Lưu ký tự (toán tử: +, -, *, / hoặc toán hạng: A, B, C...)
    NodeBieuThuc* trai;
    NodeBieuThuc* phai;

    NodeBieuThuc(char val) { 
        data = val;
        trai = NULL;
        phai = NULL;
    }
};

int main() {

       // Test Cây đầy đủ
TaoCayDayDu_TuanTu(T_DayDu, 3);
    cout << "Duyet tien to:  "; duyettiento(Root(T_DayDu), T_DayDu); cout << endl;
    cout << "Duyet trung to: "; duyettrungto(Root(T_DayDu), T_DayDu); cout << endl;
    cout << "Duyet hau to:   "; duyethauto(Root(T_DayDu), T_DayDu); cout << endl;

    // Test Cây lệch trái
        TaoCayLechTrai_TuanTu(T_LechTrai, 3);
    cout << "Duyet trung to: "; duyettrungto(Root(T_LechTrai), T_LechTrai); cout << endl;

    // Test Cây lệch phải
    TaoCayLechPhai_TuanTu(T_LechPhai, 3);
    cout << "Duyet trung to: "; duyettrungto(Root(T_LechPhai), T_LechPhai); cout << endl;


    // 2. TEST CẤU TRÚC LƯU TRỮ MÓC NỐI
     // Test Cây lệch trái
    Nodemocnoi* rootTrai = TaoCayLechTrai_MocNoi(3);
    cout << "[+] Cay lech trai (3 nut): ";
    Nodemocnoi* temp = rootTrai;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->trai;
    }
    cout << "NULL" << endl;

    // Test Cây lệch phải
    Nodemocnoi* rootPhai = TaoCayLechPhai_MocNoi(3);
    temp = rootPhai;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->phai;
    }


    // 3. TEST CÂY BIỂU THỨC
    // Khởi tạo cây biểu thức cho: A + B
    NodeBieuThuc* rootBT = new NodeBieuThuc('+');
    rootBT->trai = new NodeBieuThuc('A');
    rootBT->phai = new NodeBieuThuc('B');

    cout << "Bieu thuc duoc tao: " 
         << rootBT->trai->data << " "  << rootBT->data << " " << rootBT->phai->data << endl;
}
