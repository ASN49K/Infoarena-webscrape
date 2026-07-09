#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int ale(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,a,b,i;
    fin>>n;
    for(i=1 ; i<=n ; ++i)
        {fin>>a>>b;
         fout<<ale(a,b)<<'\n';
        }
    return 0;
}
