#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        int a,b;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
