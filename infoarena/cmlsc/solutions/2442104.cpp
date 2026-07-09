#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, i, j, x, y, a[1025], b[1025], sol[1025], d[1025][1025], k;

/// Dinamica: in d[i][j] tinem lungimea celui mai lung subsir utilizand primele i elemente de primul sir
/// si j elemente din al doilea sir
/// Pentru a reconstrui solutia parcurgem matricea d de la cap la coada iar atunci cand gasim o valoare
/// cu 1 mai mare decat d[i-1][j], d[i][j-1] si d[i-1][j] inseamna ca elementul i al primului sir face parte din solutie

int main(){
    fin>>n>>m;
    for(i=1; i<=n; i++){
        fin>>a[i];
    }
    for(i=1; i<=m; i++){
        fin>>b[i];
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(a[i]==b[j]){
                d[i][j]=d[i-1][j-1]+1;
            }else{
                d[i][j]=max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    fout<<d[n][m]<<"\n";
    i=n;
    j=m;
    while(i && j){
        if(a[i]==b[j]){
            k++;
            sol[k]=a[i];
            i--;
            j--;
        }else{
            if(d[i-1][j-1]==d[i][j]){
                i--;
                j--;
            }else{
                if(d[i-1][j]==d[i][j]){
                    i--;
                }else{
                    if(d[i][j-1]==d[i][j]){
                        j--;
                    }
                }
            }
        }
    }
    for(i=k; i>0; i--){
        fout<<sol[i]<<" ";
    }
}
