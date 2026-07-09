#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025],b[1025],c[1024][1024],k;
void Read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    fin.close();
}

void afisare(int i,int j,int k)
{if(k>0)
{
    if(i>=1)
        if(j>=1)
               {if(a[i]==b[j])
                    {
                       afisare(i,j-1,k-1);
                         fout<<a[i]<<" ";
                    }
               else afisare(i,j-1,k);

               }
    else afisare(i-1,m,k);
}

}
void Solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i]==b[j]) c[i][j]=1+c[i-1][j-1];
         else c[i][j]=max(c[i-1][j], c[i][j-1]);

      fout<<c[n][m]<<"\n";
afisare(n,m,c[n][m]);


}
int main()
{
     Read();
     Solve();

    return 0;
}
