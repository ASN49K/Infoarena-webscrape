#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a[100000000],c,b,i,r,n;
int main()
{   fin>>n;
    for(i=1;i<=n;i++)
        {fin>>c>>b;
                while (b)
                {
                    r=c%b;
                    c=b;
                    b=r;
                }
           a[i]=c;
        }
        for(i=1;i<=n;i++)
        fout<<a[i]<<'\n';



}
