#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("scmax.in");
ofstream g("scmax.out");
int a[100005], SCmax[100005], Q[100005];
int N, Lmax, i, l, r, m, cnt=0;
int main()
{
    f>>N;
    for (i=1; i<=N; i++)
        f>>a[i];
    for (i=1; i<=N; i++)
    {
        if(a[i]>SCmax[cnt])
        {
            SCmax[++cnt]=a[i];
            Q[i]=cnt;
        }
        else{
            l=1, r=cnt, Lmax=cnt;
             while(l<=r)
            {
                m=(l+r)/2;
                if (SCmax[m]<a[i])
                    l=m+1;
                else
                {Lmax=m;
                 r=m-1;}
            }
            SCmax[Lmax]=a[i];
            Q[i]=Lmax;
            }
    }
    g<<cnt<<'\n';
    for (i=N, Lmax=0; i && cnt; i--)
        if (Q[i]==cnt)
            {SCmax[++Lmax]=a[i];
            cnt--;}
    for (i=Lmax; i; i--)
        g<<SCmax[i]<<" ";
    f.close();
    g.close();
    return 0;
}
