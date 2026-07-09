#include <fstream>
#include <iostream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int a[100001],b[101],c[201],n,i,j,m,x,maxi;
int cmmdc(int a, int b)
{
    if(a < b)
        swap(a,b);
    int r = a%b;
    while(r!=0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}
int main()
{
    fi>>n;
    for(int i = 0; i < n; i++)
        fi>>a[i]>>b[i];
    for(int i = 0; i < n; i++)
        {
            fo<<cmmdc(a[i],b[i])<<endl;
        }
return 0;
}
