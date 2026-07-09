#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a,b,n;

int euclid(int a,int b)
{
    if(!b)  return a;
    return euclid(b,a%b);
}

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {fin>>a>>b;
    fout<<euclid(a,b)<<'\n';}
    return 0;
}
