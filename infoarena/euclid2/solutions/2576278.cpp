#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
void f(int a,int b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<'\n';
}
int main ()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        fin>>x>>y;
        f(x,y);
    }
    fin.close();
    fout.close();
    return 0;
}
