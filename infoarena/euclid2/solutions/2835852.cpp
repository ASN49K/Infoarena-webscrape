#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int m,int n){
 while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}
int main()
{
    int t;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
}