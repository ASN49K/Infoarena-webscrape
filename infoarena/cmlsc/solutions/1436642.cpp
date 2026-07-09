#include <fstream>
using namespace std;
ifstream fin("scmax.in");
ofstream fout("scmax.out");
int n, i, j, v[1000005], l[1000005], maxim, lmax, p, k;
int main()
{
    fin>>n;
    for(i=1; i<=n; i++)
        fin>>v[i];

    l[n]=1;
    for(i=n-1; i>=1; i--)
    {
        maxim=0;
        for(j=i+1; j<=n; j++)
        {
            if(v[i]<v[j] && l[j]>maxim)
            {
                maxim=l[j];
            }
        }
        l[i]=maxim+1;
    }

    for(i=1; i<=n; i++)
        if(lmax < l[i])
        {
            lmax=l[i];
        }

    fout<<lmax<<"\n";

    maxim=l[i];
    k=1;
    for(i=1; i<=n; i++)
        if(maxim<l[i])
        {
            maxim=l[i];
            k=i;
        }

    fout<<v[k]<<" ";
    for(i=k+1; i<=n; i++)
        if(l[i]==maxim-1 && v[i]>v[k])
        {
            fout<<v[i]<<" ";
            maxim=maxim-1;
        }

}
