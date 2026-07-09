#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main ()
{
    int a,b,n,r;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a;
        fin>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;b=r;
        }
        fout<<a<<" ";
        fout<<'\n';
    }
    return 0;
}
