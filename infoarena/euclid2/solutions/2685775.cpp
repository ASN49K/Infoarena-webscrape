#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void get(int a,int b)
{   while(a%b && b%a)
    if(a>b)a=a%b;
    else b=b%a;
    if(a<b)fout<<a<<endl;
    else fout<<b<<endl;
}
int main()
{
    int n,a,b;
    fin>>n;
    for(int i=1;i<=n;++i)
    {
        fin>>a>>b;
        get(a,b);
    }
    return 0;
}
