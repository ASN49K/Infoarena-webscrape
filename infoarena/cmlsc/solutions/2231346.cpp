#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short int a[1025], b[1025], c[1025];
short int n, m;
short int L[1025][1025];
short int mare;

int recurenta(short int i, short int j) {

    if(i > 0 && j > 0) {
        if(a[i] == b[j]){
            recurenta(i - 1, j - 1);
            mare++;
            c[mare] = a[i];
        }
        else {
            if(L[i - 1][j] > L[i][j - 1])
                recurenta(i - 1, j);
            else
                recurenta(i, j - 1);
        }
    }
    else {
        return mare;
    }
}

void formL(){

    for(short int i = 1; i <= n; i++) {
        for(short int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                L[i][j] = 1 + L[i - 1][j - 1];
            }
            else {
                L[i][j] = max(L[i][j - 1], L[i - 1][j]);
            }
        }
    }
}

int main()
{
    fin >> n >> m;
    for(short int i = 1; i <= n; i++)
        fin >> a[i];

    for(short int i = 1; i <= m; i++)
        fin >> b[i];

    formL();
    recurenta(n , m);

    fout << mare << '\n';
    for(short int i = 1; i <= mare; i++) {

        fout << c[i] << ' ';
    }
    return 0;
}
