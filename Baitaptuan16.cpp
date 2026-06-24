#include <iostream>
#include <string>

using namespace std;

const int VO_CUC = 999999;
const int SO_THANH_PHO = 11;

char ten_thanh_pho[SO_THANH_PHO] = {
    "Ha Noi", "Son Tay", "Thai Nguyen", "Bac Ninh", "Bac Giang",
    "Uong Bi", "Hai Phong", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh
};

struct DoThi {
    int so_luong_dinh;
    int ma_tran_ke[SO_THANH_PHO][SO_THANH_PHO];
};

void khoi_tao_do_thi(DoThi *do_thi) {  // tạo đồ thị
    do_thi->so_luong_dinh = SO_THANH_PHO;
    for (int i = 0; i < do_thi->so_luong_dinh; i++) {
        for (int j = 0; j < do_thi->so_luong_dinh; j++) {
            if (i == j) {
                do_thi->ma_tran_ke[i][j] = 0;
            } else {
                do_thi->ma_tran_ke[i][j] = VO_CUC
            }
        }
    }
void them_canh_noi(DoThi *do_thi, int u, int v) {
    do_thi->ma_tran_ke[u][v] = 1;
    do_thi->ma_tran_ke[v][u] = 1;
}
void tim_duong_ngan_nhat(DoThi *do_thi, int diem_xuat_phat, int diem_dich) {
    int khoang_cach[SO_THANH_PHO];
    bool da_duyet[SO_THANH_PHO];
    int vet_duong_di[SO_THANH_PHO];
 for (int i = 0; i < do_thi->so_luong_dinh; i++) 
        khoang_cach[i] = VO_CUC;
        da_duyet[i] = false;
        vet_duong_di[i] = -1
    }
   khoang_cach[diem_xuat_phat] = 0;
