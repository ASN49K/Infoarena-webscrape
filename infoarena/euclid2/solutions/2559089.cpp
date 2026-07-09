#include<iostream>
#include<fstream>
using namespace std;
int euc(int a, int b)
{
    int r=1;
    while(r!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a, b, T;
    f>>T;
    while(T--)
    {f>>a>>b;
     g<<euc(a,b)<<endl;
     
    }
    f.close();
    g.close();
    return 0;
}
