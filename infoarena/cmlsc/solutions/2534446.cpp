#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[100],m,b[100],n,ab[100][100],v[100],k;
int main()
{
    fin>>m;
    fin>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];

    for (int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if (a[i]==b[j])
            {
                ab[i][j]=ab[i-1][j]+1;
                v[k]=a[i];
                k++;
            }
            else
                ab[i][j]= max(ab[i-1][j],ab[i][j-1]);
    fout<<ab[m][n]<<endl;
    for(int i=0;i<k;i++)
        fout<<v[i]<<" ";
    return 0;
}
