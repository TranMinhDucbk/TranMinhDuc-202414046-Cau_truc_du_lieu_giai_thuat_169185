#include<iostream>
using namespace std;


void timcap(int mang[], int n, int tongcantim)
{
    // Duyệt qua từng cặp phần tử
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Kiểm tra điều kiện tổng
            if (mang[i] + mang[j] == tongcantim)
            {
                cout << "thay roi (" << mang[i] << ", " << mang[j] << ")" << endl;
                return;
            }
        }
    }

    cout << "khong thay" << endl;
}

int main()
{
    int mang[] = { 8, 7, 2, 5, 3, 1 };
    int tongcantim = 10;

    // Tính kích thước mảng
    int n = sizeof(mang) / sizeof(mang[0]);

    timcap(mang, n, tongcantim);

    return 0;
}