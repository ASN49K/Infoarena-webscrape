#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,c,n,i;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    { fin>>a>>b;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    fout<<b;}
    fin.close();
    fout.close();
    return 0;
}
