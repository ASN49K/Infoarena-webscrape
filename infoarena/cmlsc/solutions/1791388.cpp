#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],M,N,l[1030][1030],r[1025],k;

int main()
{
    fin >>N>>M;
    for(int i=1;i<=N;i++) fin >>a[i];
    for(int i=1;i<=M;i++) fin>>b[i];

    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            if ((i==0)||(j==0)) l[i][j]=0;
            else if(a[i]==b[j]) l[i][j]=1+l[i-1][j-1];
            else l[i][j]=max(l[i-1][j],l[i][j-1]);

        }
    }
        fout <<l[N][M]<<endl;
int     i=N;
  int   j=M;

    while (l[i-1][j]!=0 && l[i][j-1]!=0){

         if (l[i][j]==l[i][j-1])j--;
        else
       if (l[i][j]==l[i-1][j]) i--;
        else
        if (l[i][j]==1+l[i-1][j-1]){
            r[++k]=a[i];
            i--;
            j--;

        }
    }
    r[++k]=a[i];
    for (int i=k;i>=1;i--) fout <<r[i]<<" ";
    return 0;
}
