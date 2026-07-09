#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,r,x,y,a,b;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        a=x;
        b=y;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a;
        fout<<'\n';
    }

    return 0;
}
