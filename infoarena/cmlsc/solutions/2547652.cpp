#include <iostream>
#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m,a[260],b[260],c[260];
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
    int d=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){
                c[d]=a[i];
                d++;
            }
        }
    }
    d--;
    fout<<d<<'\n';
    for(int i=1;i<=d;i++)
        fout<<c[i]<<" ";
    return 0;
}
