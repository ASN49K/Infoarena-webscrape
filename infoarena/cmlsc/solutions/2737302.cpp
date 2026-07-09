#include <fstream>
using namespace std;
ifstream cin("fsb.in");
ofstream cout("fsb.out");
int sp[200001],fp[200001],fn[200001];
int main()
{
    int n,nmax=0,nmin=0,nrs=0;
    cin>>n;
    fp[0]=1;
    for(int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        if(ch=='1')
            sp[i]=sp[i-1]+1;
        else sp[i]=sp[i-1]-1;
        if(sp[i]>=0)
        {
            fp[sp[i]]++;
            if(sp[i]>nmax&&fp[sp[i]]>1)
                nmax=sp[i];
        }
        else
        {
            fn[-sp[i]]++;
            if(-sp[i]>nmin&&fn[-sp[i]]>1)
                nmin=-sp[i];
        }
    }
    for(int i=0; i<=nmax; i++)
        if(fp[i]>1)
            nrs+=fp[i]*(fp[i]-1)/2;
    for(int i=0; i<=nmin; i++)
        if(fn[i]>1)
            nrs+=fn[i]*(fn[i]-1)/2;
    cout<<nrs;
    return 0;
}
