#include <iostream>
using namespace std;
void incay(int mang[], int n)
{
 for(int i=1;i<=n;i++)
    {
cout<< mang[i] << " ";
    }
}
void taodong(int mang[], int i, int n)
{
    int x = mang[i];
    int j = i*2;
    while(j<=n)
    {
        if(j<n && mang[j]<mang[j+1])
        {
        j=j+1;
        }
if(x>=mang[j])
        {
            break;
        }mang[j/2]=mang[j];
    j=j*2;
    }
    mang[j/2]=x;
}
void xepdong(int mang[], int n)
{
    cout << " ban dau:" << endl;
    incay(mang,n);
 for(int i=n/2;i>=1;i--)
    {
        taodong(mang,i,n);

        cout<<"sau lan tao dong "<< i <<":"<< endl;
        incay(mang,n);
    }
    cout<<" xep dong: "<<endl;
for(int i=n;i>=2;i--)
    {
        int t=mang[1];
        mang[1]=mang[i];
        mang[i]=t;

        cout<< "sau khi sap xep:" << endl;
        incay(mang,n); //sau khi in mảng ra thì tiếp tục tạo đống
        taodong(mang,1,i-1);
cout<< "sau khi vun dong lai:" << endl;
        incay(mang,n);
    }cout<<"cuoi cung:"<<endl;
    incay(mang,n);
}
int main()
{
    int mangcansxvundong1[11]={0,4,1,3,2,16,9,10,14,8,7};
    int n1=10;
    xepdong(mangcansxvundong1,n1);
    int mangcansxvundong2[13]={0,11,54,32,106,38,78,203,16,84,17,39,15};
    int n2=12;
    xepdong(mangcansxvundong2,n2);
    int mangcansxvundong3[9]={96, 83, 45, 75, 51, 11, 27, 32, 66};
    int n3=8;
    xepdong(mangcansxvundong3,n3);

    return 0;
}
