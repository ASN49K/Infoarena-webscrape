#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void euclid(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<'\n';
}

int main()
{
    int a,b,n;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        euclid(a,b);
    }

    return 0;
}
