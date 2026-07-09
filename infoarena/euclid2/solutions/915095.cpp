#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a[100000000],c,b,i,r,n;
int cmmdc1(int c,int b)
    {
         while (b)
                {
                    r=c%b;
                    c=b;
                    b=r;
                }
                return c;
    }
int main()
{   fin>>n;
    for(i=1;i<=n;i++)
        {fin>>c>>b;

           a[i]=cmmdc1(c,b);
        }
        for(i=1;i<=n;i++)
        fout<<a[i]<<'\n';



}
