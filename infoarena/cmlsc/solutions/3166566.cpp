#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[257],b[257],c[257],l=1;
int n,m,cont_adv,cont;
int main() {
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    for(int i=1;i<=m;i++){
        fin>>b[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                cont_adv++;
                c[l]=a[i];
                l++;
            }
        }
    }
    fout<<cont_adv<<endl;
    for(int i=1;i<l;i++){
        fout<<c[i]<<" ";
    }
    return 0;
}
