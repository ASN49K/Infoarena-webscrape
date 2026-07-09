#include <iostream>
#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m,a[1025],b[1025],c[1025];
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    int d=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
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
