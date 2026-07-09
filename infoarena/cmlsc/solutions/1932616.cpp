#include <fstream>

const int NMAX = 1024;
int A[NMAX], B[NMAX], D[NMAX][NMAX], sol[NMAX], bst;

inline int max(int a, int b) { return (a > b ? a : b); }

void read(int& m, int& n){
    std::ifstream fin("cmlsc.in");
    fin >> m >> n;
    int i;
    for ( i = 1; i <= m; i++)
        fin >> A[i];
    for ( i = 1; i <= n; i++)
        fin >> B[i];
    fin.close();
}

void solve(int m, int n){
    int i,j;
    bst = 0;
    for ( i = 1; i <= m; i++){
        for ( j = 1; j <= n; j++){
            if (A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);
        }
    }
    
    for ( i = m, j = n; i; ){
        if (A[i] == B[j]){
            sol[++bst] = A[i];
            i--;
            j--;
        }
        else if (D[i-1][j] < D[i][j-1])
            j--;
        else
            i--;
    }
}

void print(){
    std::ofstream fout("cmlsc.out");
    fout << bst << '\n';
    for (int i = bst; i; i--){
        fout << sol[i] << ' ';
    }
    fout << '\n';
    fout.close();
}

int main(){
    int m,n;
    read(m,n);
    solve(m,n);
    print();
    return 0;
}