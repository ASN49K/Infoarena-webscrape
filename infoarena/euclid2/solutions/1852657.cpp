#include <iostream>
#include <fstream>
#define nmax 100001
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
//bool c[nmax];

int main()
{
    int a,b,r,n,i;
    fin>>n;
    for(i=1; i<=n; i++)
        {
            fin>>a>>b;
            while(b)
            {
                r=a%b;
                a=b;
                b=r;
            }
            fout<<a<<" ";
        }


    return 0;
}
