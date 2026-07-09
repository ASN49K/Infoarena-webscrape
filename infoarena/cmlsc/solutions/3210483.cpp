#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int d[1001][1001]={0};
int main()
{
    int n,m,a[10001]={0},b[10001]={0},l=0,c=0,v[1001]={0};
    fi>>n>>m;
    for(int i=1;i<=n;i++)fi>>a[i];
    for(int j=1;j<=m;j++)fi>>b[j];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=j;k>0;k--){
                if(a[i]==b[k]&&c!=a[i])l++,c=a[i],v[l]=c;
            }
        }
    }
    fo<<l<<endl;
    for(int i=1;i<=l;i++){
        fo<<v[i]<<" ";
    }
}
