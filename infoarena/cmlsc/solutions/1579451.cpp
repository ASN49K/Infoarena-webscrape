#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int i,j,M,N,a[257],b[257],k=0,v[257];
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>M>>N;
    for(i=1;i<=M+N;i++)
    {
        if(i<=M)
        {
            fin>>j;
            a[i]=j;
        }
        else
        {
            fin>>j;
            k++;
            b[k]=j;
        }
    }
    k=0;
    for(i=1;i<=M;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(a[i]==b[j])
            {
                k++;
                v[k]=a[i];
            }
        }
    }
    fout<<k<<"\n";
    for(i=1;i<=k;i++)
    {
        fout<<v[i]<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
