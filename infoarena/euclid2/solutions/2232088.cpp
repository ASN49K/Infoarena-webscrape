#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,nrp[5000],div;
bool ok[40001];
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int ind=1;
    nrp[ind]=2;
    for(int i=3;i<=40001;i+=2)
    {
        if(ok[i]==0)
        {
            ind++;
            nrp[ind]=i;
            for(int j=i+i;j<=40001;j+=i)
                ok[j]=1;
        }
    }
    in>>t;

    for(int i=1;i<=t;i++)
    {
        in>>a>>b;div=1;
        for(int j=1;j<=ind&&a>1&&b>1;j++)
        {
            if(a%nrp[j]==0&&b%nrp[j]==0)
            {
                while(a%nrp[j]==0&&b%nrp[j]==0)
                {
                    a/=nrp[j];b/=nrp[j];
                    div*=nrp[j];
                }
            }
        }
        out<<div<<'\n';
    }
    return 0;
}
