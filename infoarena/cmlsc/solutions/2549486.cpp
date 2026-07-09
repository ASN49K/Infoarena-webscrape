#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
unsigned short int table[1025][1025];

void rebuild(unsigned short int i, unsigned short int j, unsigned short int a[], unsigned short int b[])
{
    if(i < 1 || j < 1){
        return;
    }
    if(a[i - 1] == b [j - 1]){
        rebuild(i - 1, j - 1, a, b);
        fout << a[i - 1] << " ";
    } else {
        if(table[i - 1][j] > table[i][j - 1]){
            rebuild(i - 1, j, a, b);
        } else {
            rebuild(i, j - 1, a, b);
        }
    }
}

int main()
{
    unsigned short int * a;
    unsigned short int * b;
    unsigned short int n, m;
    fin >> n >> m;
    a = new unsigned short int[n];
    b = new unsigned short int[m];
    for(unsigned short int i = 0; i < n; i++){
        fin >> a[i];
    }
    for(unsigned short int i = 0; i < m; i++){
        fin >> b[i];
    }
    for(unsigned short int i = 0; i <= n; i++){
        for(unsigned short int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                table[i][j] = 0;
            } else {
                if(a[i - 1] == b[j - 1]){
                    table[i][j] = table[i - 1][j - 1] + 1;
                } else {
                    if(table[i - 1][j] > table[i][j - 1]){
                        table[i][j] = table[i - 1][j];
                    } else {
                        table[i][j] = table[i][j - 1];
                    }
                }
            }
        }
    }
    fout << table[n][m] << '\n';
    rebuild(n, m, a, b);
    return 0;
}