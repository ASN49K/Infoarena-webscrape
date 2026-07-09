#include<iostream>
#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
const long long c=1999999973;
void euclid(int a,int b)
{
    while(b!=0)
    {
        int aux=a%b;
        a=b;
        b=aux;
    }
    out<<a<<" "<<'\n';

}
int main()
{
    int n,a,b;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        euclid(a,b);
    }
}
