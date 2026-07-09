#include<fstream>
#include<iostream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
long long int a,b,n;
int euclid(int a,int b)
{
    if(!b) return a;
    return euclid(b,a%b);
}
int main()
{
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
    }
}
