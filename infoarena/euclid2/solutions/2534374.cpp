#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}

int main()
{  int x;
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    int a,b,n,i;
    f>>n;
    for(i=1;i<=n;i++)
    {
    f>>a>>b;
    o<<cmmdc(a,b)<<endl;
    }
}
