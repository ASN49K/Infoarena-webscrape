#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int na,nb;
int a[1025],b[1025];
int m[1025][1025];
int sol[1025];
int main()
{
    f>>na>>nb;
    for(int i=1;i<=na;i++)f>>a[i];
    for(int j=1;j<=nb;j++)f>>b[j];
    for(int i=0;i<=na+1;i++){
        for(int j=0;j<=nb+1;j++){
            if(i==0 ||j==0)m[i][j]=0;
            else {
                if(i!=1&&j!=1&&a[i-1]==b[j-1])m[i][j]=1+m[i-1][j-1];
                else
                    m[i][j]=max(m[i-1][j],m[i][j-1]);
            }
        }
    }
    int i=na+1,j=nb+1,nr=0;
    while (i) {
    if (a[i-1] == b[j-1]) {sol[++nr] = a[i-1]; i--; j--;}
    else if (m[i - 1][j] < m[i][j - 1])
      j--;
    else
      i--;
    }
    g<<m[na+1][nb+1]<<"\n";
    for(int i=m[na+1][nb+1];i>=1;i--)g<<sol[i]<<" ";
    return 0;
}
