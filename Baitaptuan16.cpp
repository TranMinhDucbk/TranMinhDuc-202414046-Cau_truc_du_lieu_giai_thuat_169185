#include <iostream>
#include <string>

using namespace std;

const int VO_CUC = 999999;
const int SO_THANH_PHO = 11;

// Thay mảng char bằng mảng std::string của C++ giúp quản lý chuỗi dễ dàng hơn
const string ten_thanh_pho[SO_THANH_PHO] = {
    "Ha Noi", "Son Tay", "Thai Nguyen", "Bac Ninh", "Bac Giang",
    "Uong Bi", "Hai Phong", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh"
};

struct DoThi {
    int so_luong_dinh;
    int ma_tran_ke[SO_THANH_PHO][SO_THANH_PHO];
};