#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int t,a,aux,b,r;
    in>>t;
    for (int i=1;i<=t+1;i++)
    {
        in>>a>>b;
        if (a>b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        r=a%b;
        while (r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        out<<b<<endl;
    }
}
