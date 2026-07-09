#include <iostream>
#include <fstream>
#define NMax 1025
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[NMax],b[NMax],c[NMax][NMax],sir[NMax],NSir;

int main(void)
{
    int n,m;
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[j]==b[i])
                c[i][j]=1+c[i-1][j-1], NSir++;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
    fout<<NSir<<"\n";
    if(NSir)
    {
        int val;
        i=m,j=n,val=c[i][j];
        do{
            while(c[i][j]==val){
                j--;
            }
            j++;
            while(c[i][j]==val){
                i--;
            }
            i++;
            if(b[i]==a[j]){
                sir[++sir[0]]=a[j];
                val--;
            }
            j--;
        }while(val!=0);
        for(i=NSir;i>=1;i--)
            fout<<sir[i]<<" ";
    }
    return 0;
}
