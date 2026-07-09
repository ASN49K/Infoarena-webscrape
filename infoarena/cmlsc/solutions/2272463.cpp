//Lee clasic
#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1032],b[1032],LCS[1032][1032];
char unde[1032][1032];
int m,n,i,j;
void citire();
void pd();
void afisare();
int main()
{
    citire();
    pd();
    afisare();
    return 0;
}

void citire()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
}

void pd()
{
  for(i=n;i>=1;i--)
    for(j=m;j>=1;j--)
    if(a[i]==b[j]){
    LCS[i][j]=1+LCS[i+1][j+1];
    unde[i][j]='1';
    }
    else
    if(LCS[i+1][j]>LCS[i][j+1])
    {
        LCS[i][j]=LCS[i+1][j];
        unde[i][j]='2';
    }
    else
    {
        LCS[i][j]=LCS[i][j+1];
        unde[i][j]='3';
    }

}
void afisare()
{
    fout<<LCS[1][1]<<'\n';
    i=1;
    j=1;
    while(i<=n&&j<=n)
    {
        if(unde[i][j]=='1'){
            fout<<a[i]<<" ";
        i++;
        j++;
        }
        else
        if(unde[i][j]=='2')
        i++;
        else
        j++;
    }
}
