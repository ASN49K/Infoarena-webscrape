#include <iostream>
#include <fstream>
using namespace std;
int i,a,b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b)
{
    while(a!=b)
    {
        if(a>b)a=a-b;
        else  b=b-a;
    }
    return a;
}
int main()
{
    int t;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
