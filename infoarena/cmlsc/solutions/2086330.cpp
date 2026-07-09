#include <fstream>
using namespace std;
ifstream in ("sumfact.in");
ofstream out ("sumfact.out");

int n,v[20],s[20],k;

int main()
{
    int i,maxi=0;
    in>>n;
    v[1]=1;
    for(i=2;i<=12;i++)
        v[i]=v[i-1]*i;
    for(i=12;i>=1;i--)
        if(n/v[i]>0)
            {
                s[i]=n/v[i];
                n=n%v[i];
                if(maxi<i)
                    maxi=i;
            }
    out<<maxi<<"\n";
    for(i=1;i<=maxi;i++)
        out<<s[i]<<"\n";
    return 0;
}
