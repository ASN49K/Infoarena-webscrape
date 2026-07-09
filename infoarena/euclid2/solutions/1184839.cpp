#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int main()
{
    int n,a,b,i,r;
    for(i=1;i<=n;i++)
        {
            fin>>a>>b;
            while(!b)
                {
                    r=b;
                    b=a%b;
                    a=b;
                }
            fout<<b<<'\n';
        }
    return 0;
}
