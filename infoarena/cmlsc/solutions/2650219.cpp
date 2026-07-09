#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int sor1[1050], sor2[1050];
int matrix[1050][1050];



int main() {

    ifstream input("cmlsc.in");
    ofstream output("cmlsc.out");
    int i, j, m, n;
    input >> m;
    input >> n;

    for(i=0; i<m; i++) {
        input >> sor1[i];
    }

    for(i=0; i<n; i++) {
        input >> sor2[i];
    }

    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            if(sor1[i-1] != sor2[j-1]) {
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
            } else {
                matrix[i][j] = 1 + matrix[i-1][j-1];
            }
        }
    }
/*
    for(i=0; i<=m; i++) {
        for(j=0; j<=n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "leghosszabb reszsorozat hossza: " << matrix[m][n] << endl;
*/
    int reszsor[100];
    int index = 0;
    i = m;
    j = n;
    while(i!=0 && j!=0) {
        if(matrix[i][j-1] == matrix[i][j]) {
            j--;
        } else if(matrix[i-1][j] == matrix[i][j]) {
            i--;
        } else {
            reszsor[index] = sor1[i-1];
            index++;
            i--;
            j--;
        }
    }
    output << index << endl;
   // cout << "Egyik leghosszabb kozos reszsor: ";
    for(i=index-1; i>=0; i--) {
        output << reszsor[i] << " ";
    }
    output << endl;
}
