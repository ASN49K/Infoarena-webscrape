#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
    long n,m;
    fin>>n>>m;
    vector <long> s1(n+1);
    vector <long> s2(m+1);
    vector < vector <long> > a(n+1, vector <long> (m+1));
    vector <long> sol;
    for(long i=1; i<=n;i++)
        fin>>s1[i];
    for(long i=1; i<=m; i++)
        fin>>s2[i];
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
    long i=n,j=m;
    while(i>0 && j>0)
    {
        if(s1[i]==s2[j])
        {
            sol.push_back(s1[i]);
            //cout<<s1[i]<<' ';
            i--;
            j--;


        }
        else
        {
            if(a[i-1][j]>a[i][j-1])
                i--;
            else
                j--;
        }
    }
    fout<<a[n][m]<<'\n';
    for(long i=sol.size()-1;i>=0;i--)
        fout<<sol[i]<<' ';
    fout<<'\n';
    /*for(long i=0;i<=n;i++)
    {
        for(long j=0;j<=m;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }*/
    return 0;
}
