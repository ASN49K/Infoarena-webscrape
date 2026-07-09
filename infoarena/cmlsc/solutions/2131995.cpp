#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,D[1300][1300],v1[1300],v2[1300],d[1301];
void citire() {
    f>>n>>m;
    for (int i=1;i<=n;i++) {
        f>>v1[i];
    }
    for (int i=1;i<=m;i++) {
        f>>v2[i];
    }
}
void rez() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (v1[i]==v2[j]) {
                D[i][j]=D[i-1][j-1]+1;
            }
            else {
                D[i][j]=max(D[i-1][j],D[i][j-1]);
            }
        }
    }
    /*
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cout<<D[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    int Answ=D[n][m];
    int posi=n;
    int posj=m;
    int Nr=0;
    while (posi>=1 && posj>=1) {
        if (v1[posi]==v2[posj]) {
            d[++Nr]=v1[posi];
            posi--;
            posj--;
        }
        else {
            if (D[posi-1][posj]>D[posi][posj-1]) {
                posi--;
            }
            else {
                posj--;
            }
        }
    }
    g<<Answ<<"\n";
    for (int i=Answ;i>=1;i--) {
        g<<d[i]<<" ";
    }
}
int main() {
    citire();
    rez();
    return 0;
}
