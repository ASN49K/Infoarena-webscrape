#include <fstream>
#include <iostream>

using namespace std;
ofstream fout("euclid2.out");
int a,b,t,i,r;
int main()
{
    freopen("euclid2.in","r",stdin);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&a,&b);
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<'\n';
    }
    return 0;
}
