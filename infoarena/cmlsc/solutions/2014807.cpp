#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void read(int v[], int n)
{
    for (int i=0; i<n; i++)
    {
        fin>>v[i];
    }
}
bool searchPosition(int v[], int n, int k, int &p)
{
    bool gasit=false;
    for (int i=p+1; i<n; i++)
    {
        if (v[i]==k)
        {
            gasit=true;
            p=i;
            i=n;
        }
    }
    return gasit;
}
int main()
{
    int m,n,i,j=0,ct,k;
    fin>>m>>n;
    int a[m],b[n];
    read(a,m);
    read(b,n);
    if (n<=m)
    {
        int sol[n];
        for (i=0; i<n; i++)
        {
            ct=0; j=0;
            if (searchPosition(a,m,b[i],j))
            {
                ct++;
                k=i+1;
                while (k<n)
                {
                    if (searchPosition(a,m,b[k],j))
                                ct++;
                    k++;
                }
            }
            sol[i]=ct;
        }
    ct=sol[0]; j=0;
    for (i=0; i<n; i++)
    {
        if (ct<sol[i])
        {
            ct=sol[i];
            j=i;
        }
    }
    fout<<ct<<"\n";
    ct=0;
    while (j<n)
    {
        if (searchPosition(a,m,b[j],ct))
        {
            fout<<b[j]<<" ";
        }
        j++;
    }
    }
    else
    {
        int sol[m];
        for (i=0; i<m; i++)
        {
            ct=0; j=0;
            if (searchPosition(b,n,a[i],j))
            {
                ct++;
                k=i+1;
                while (k<m)
                {
                    if (searchPosition(b,n,a[k],j))
                                ct++;
                    k++;
                }
            }
            sol[i]=ct;
        }
    ct=sol[0]; j=0;
    for (i=0; i<m; i++)
    {
        if (ct<sol[i])
        {
            ct=sol[i];
            j=i;
        }
    }
    fout<<ct<<"\n";
    ct=0;
    while (j<m)
    {
        if (searchPosition(b,n,a[j],ct))
        {
            fout<<a[j]<<" ";
        }
        j++;
    }

    }
}
