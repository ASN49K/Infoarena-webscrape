#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("cmlsc.in") ;
ofstream fo("cmlsc.out");

int a[1026];
int b[1026];
int n,m;
int s[1026],nr;
int c[1026][1026];

int maxi(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

void cit(int sir[1026],int num)
{
    for(int i=1;i<=num;i++)
        fi>>sir[i];
}

int main()
{
    fi>>n>>m;

    cit(a,n);
    cit(b,m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=maxi(c[i-1][j],c[i][j-1]);

    for(int i=n,j=m; i; )
        if(a[i]==b[j])
    {
        s[++nr]=a[i];
        i--;
        j--;
    }
        else
            if(c[i][j-1]>c[i-1][j])
                j--;
            else
                i--;

    fo<<nr<<'\n';

    for(int i=nr;i>=1;i--)
        fo<<s[i]<<" ";

    return 0;
}
