#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,a[2000],b[2000],k=0,a1[300],b1[300],snew[1005],smin[1005];
int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;i++) {fin >> a[i]; if(a1[a[i]]==0) a1[a[i]]=i; }
    for(int i=1;i<=m;i++) {fin >> b[i]; if(b1[b[i]]==0) b1[b[i]]=i; }
    for(int i=0;i<=258;i++){
        if(a1[i]!=0 && b1[i]!=0){
            k++;
            snew[k]=i;
        }
    }
    fout << k << "\n";
    for(int i=1;i<=k;i++)
        fout << snew[i] << " ";
    fin.close();
    fout.close();
    return 0;
}
