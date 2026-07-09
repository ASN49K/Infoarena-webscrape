#include <iostream>
#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m,a[10025],b[10025],c[10025];
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
    int d=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){
                d++;
                c[d]=a[i];
            }
        }
    }
    fout<<d<<'\n';
    for(int i=1;i<=d;i++)
        fout<<c[i]<<" ";
    return 0;
}
