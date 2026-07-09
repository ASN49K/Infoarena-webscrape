#include <fstream>
 
#define Nmax 1030
#define maxim(x, y) ((x > y) ? x : y)

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");
 
int n, m;
int L[Nmax][Nmax], a[Nmax], b[Nmax];

int max_length() {
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = maxim(L[i-1][j],L[i][j-1]);
        }
    }
    return L[n][m];
}
 
void afisare ( int x , int y ){
    if (x == 0 || y == 0)
        return;
 
    if (a[x] == b[y]) {
        afisare(x - 1, y - 1);
        fout << a[x] << ' ';
        return;
    }
    
    if (L[x-1][y] > L[x][y-1])
        afisare(x - 1, y);
    else
        afisare(x, y - 1);
 
 
}
 
int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];

    
    fout << max_length() << '\n';
    afisare(n,m);

    return 0;
}