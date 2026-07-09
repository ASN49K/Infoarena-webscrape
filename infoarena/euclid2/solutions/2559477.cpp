#include <fstream>
//#include <iostream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n, a,b,z[100001],i,y;

int main()
{
    i=1;
    in>>n;
    while(n)
    {
    in>>a>>b;
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
     z[i]=a;
     i++;
    }
    y=i;
    for(i=1;i<=y;i++)
    out<<z[i]<<'\n';
    return 0;
}
