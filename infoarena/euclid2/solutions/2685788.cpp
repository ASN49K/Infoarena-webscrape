#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void get(int a,int b)
{   if(a>b)swap(a,b);
    while(a!=0)
    {   int r=b%a;
        b=(b-r)/(b/a);
        a=r;
    }
    fout<<b<<endl;
}
int main()
{
    int n,a,b;
    fin>>n;
    while(fin>>a>>b)get(a,b);
    return 0;
}
