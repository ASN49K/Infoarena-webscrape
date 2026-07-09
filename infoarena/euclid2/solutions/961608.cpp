#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{
    while(a!=b)
        if(a>b) a=a-b;
        else b=b-a;
    return a;
}
int main()
{int t,i,a,b;
 f>>t;
 for(i=1;i<=t;i++)
 {
     f>>a>>b;
     g<<cmmdc(a, b)<<endl;
 }
    return 0;
}
