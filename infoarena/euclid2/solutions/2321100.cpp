#include <iostream>
#include <fstream>
using namespace std;

int f(int a,int b)
{
    while(a!=b)
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

int main()
{int i,n,a,b;
    ifstream f1("euclid2.in");
    f1>>n;
    ofstream f2 ("euclid2.out");
    for(i=1;i<=n;i++)
    {
        f1>>a>>b;
        f2<<f(a,b);
    }
    f1.close();
    f2.close();
    return 0;
}
