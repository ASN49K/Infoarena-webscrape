#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc(int a, int b)
{
        while (a!=b)
        {
        if(a>b)
        a=a-b;
        else
        b=b-a;
        }
        return a;
}
int main()
{

    int a,b,n,i,x,y;
    fin >> n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        a=x;
        b=y;
        fout<<cmmdc(a,b);
        fout<<endl;
    }
    return 0;
}
