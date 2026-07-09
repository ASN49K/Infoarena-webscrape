#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int n, int m)
{
    while(n!=m)
    {
        if(n>m)
            n-=m;
        else
            m-=n;
    }
    return n;
}
int n,a,b,i;
int main()
{
    in>>n;
    for(i=1;i<=n;i++)
    {
       in>>a>>b;
       out<<euclid(a,b)<<endl;
    }
    return 0;
}
