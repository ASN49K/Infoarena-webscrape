#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
{
    while(a!=b){
        if(a>b) a-=b;
        if(b>a) b-=a;
    }
    return a;
}

int main()
{
    int n,a,b;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b);
        g<<endl;
    }
    f.close();
    g.close();
    return 0;
}
