#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstring>


using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }


    return 0;
}
