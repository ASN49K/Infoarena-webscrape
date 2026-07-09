#include<iostream>
#include<fstream>
using namespace std;
fstream fin("euclid2.in",ios::in),fout("euclid2.out",ios::out);
int algoritm(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,x,y;
    fin>>n;
    while(n!=0)
    {
        fin>>x>>y;
        fout<<algoritm(x,y)<<'\n';
        n--;
    }
    fin.close();
    fout.close();
    return 0;
}
