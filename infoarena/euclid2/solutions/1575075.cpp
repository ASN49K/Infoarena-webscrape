#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int eu(int &a,int &b)
{
    int r;
    while (b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void read(ifstream &f,int &n,int a[1000],int b[1000])
{
    int i;
    f>>n;
    for (i=1;i<=n;i++)
        f>>a[i]>>b[i];
}

void solve(ofstream &g,int n,int a[1000],int b[1000])
{
    int i;
    for (i=1;i<=n;i++)
        g<<eu(a[i],b[i])<<endl;
}

int main()
{
    int n,a[1000],b[1000];
    read(f,n,a,b);
    solve(g,n,a,b);
    return 0;
}
