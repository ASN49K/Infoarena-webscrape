#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[1026], b[1026], mat[1026][1026], sol[1026], cnt;

void citire(){
    f >> n >> m;
    for(int i = 1;i <= n;i++){
        f >> a[i];
    }
    for(int i = 1;i <= m;i++){
        f >> b[i];
    }
}

void construire_matrice(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i] == b[j]){
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            else if(mat[i-1][j] > mat[i][j-1]){
                mat[i][j] = mat[i-1][j];
            }
            else{
                mat[i][j] = mat[i][j-1];
            }
        }
    }
}

void construire_solutie(){
    int i = n;
    int j = m;
    cnt = mat[n][m];
    int poz = cnt;
    while(mat[i][j] > 0){
        while(mat[i-1][j] == mat[i][j]){
            i--;
        }
        while(mat[i][j-1] == mat[i][j]){
            j--;
        }
        sol[poz] = a[i];
        i--;
        j--;
        poz--;
    }
}

void afisare(){
    g << cnt <<"\n";
    for(int i = 1; i <= cnt;i++){
        g << sol[i] << " ";
    }
}

int main(){
    citire();
    construire_matrice();
    construire_solutie();
    afisare();
    return 0;
}
