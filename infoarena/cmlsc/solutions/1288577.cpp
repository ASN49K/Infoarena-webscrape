#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int main()
{
    int m,n,a[1025]={},b[1025]={},i,j,c[257]={},gasit[1025]={},lmax=0;
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>a[i];
    for(j=1;j<=n;j++)
        in>>b[j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])c[a[i]]++;
    for(i=1;i<m;i++)
        {
            if(c[a[i]]){
                lmax=1;
                gasit[lmax]=a[i];
                for(j=i+1;j<=m;j++)
                    if(c[a[j]]){
                            lmax++;
                            gasit[lmax]=a[j];
                                }
                        }
        }
    cout<<lmax<<endl;
    for(i=1;i<=lmax;i++)
    {
        cout<<gasit[i]<<' ';
    }

    return 0;
}
