#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1025],B[1025];
int D[1025][1025];

void refacere_traseu(int ifinish,int jfinish, int lg){
    if(lg){
        if(A[ifinish]==B[jfinish]){
            refacere_traseu(ifinish-1,jfinish-1,lg-1);
            fout<<A[ifinish]<<" ";
        }
        else
            (D[ifinish-1][jfinish]>D[ifinish][jfinish-1]) ? refacere_traseu(ifinish-1,jfinish,lg) : refacere_traseu(ifinish,jfinish-1,lg);
    }
}

int main(){
    ios::sync_with_stdio(false);
    fin.tie(nullptr);

    int n,m;
    fin>>n>>m;

    for(int i=1;i<=n;i++)
        fin>>A[i];
    for(int i=1;i<=m;i++)
        fin>>B[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(A[i]==B[j])
                D[i][j]=D[i-1][j-1]+1; // am gasit nr comun nou, deci +1 +ce era in urma
                else
                    D[i][j]=max(D[i-1][j],D[i][j-1]);
        }
        // D[i][j] = lungime amaxima a unui subsir care foloseste primele i elemente din A si primele j elemente din B
        // rezolnstrui traseul rezursiv plecand de la sfarsit

        fout<<D[n][m]<<'\n';
    refacere_traseu(n,m,D[n][m]);
    return 0;
}
