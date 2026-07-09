#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,a[1025],b[1025],c[1025][1025],j,aux[1025],k=0;
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j]){
              c[i][j]=c[i-1][j-1]+1;
              //aux[++k]=b[j];
              }
            else{
                c[i][j]=max(c[i][j-1],c[i-1][j]);
            }
            }
    }
    i=n;
    j=m;
    while(i>0&&j>0){
        if(a[i]==b[j]){
            aux[++k]=b[j];
            i--;
            j--;
        }
        else{
            if(c[i][j-1]>c[i-1][j])
                j--;
            else
                i--;
        }
    }
    fout<<c[n][m];
    fout<<endl;
    for(i=k;i>=1;i--)
        fout<<aux[i]<<" ";
    /*for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    return 0;
}
