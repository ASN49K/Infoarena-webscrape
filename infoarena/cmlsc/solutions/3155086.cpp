#include<fstream>
#include<iostream>

using namespace std;

int main() {
    cout <<"SGSGSGSBGHRTNSRHRYHRYH\n";
    ifstream read("date.in");
    ofstream write("date.out");

    int sizeA, sizeB;
    int a[1025], b[1025], c[1026][1026];
    read >> sizeA >> sizeB;
    cout << sizeA << " " << sizeB;

    c[0][0] = 0;
    for (int i = 1; i <= sizeA; i++) {
        c[i][0] = 0;
        read >> a[i];
    }

    for (int i = 1; i <= sizeB; i++) {
        c[0][i] = 0;
        read >> b[i];
    }

    for (int i = 1; i <= sizeA; i++) {
        for (int j = 1; j <= sizeB; j++) {
            c[i][j] = (a[i] == b[j]) 
                ? c[i - 1][j - 1] + 1 
                : max(c[i - 1][j], c[i][j - 1]);
        }
    }

    for (int i = 0; i <= sizeA; i++) {
        for (int j = 0; j <= sizeB; j++) {
            cout << c[i][j] << " ";
        }
        cout <<"\n";
    }

    write << c[sizeA][sizeB] << "\n";

    int *solution = (int*)malloc(c[sizeA][sizeB] * sizeof(int));
    int len = 0;
    for (int i = sizeA, j = sizeB; i > 0;) {
        if (a[i] == b[j]) {
            solution[len++] = a[i];
            i--;
            j--;
        } else if (c[i - 1][j] < c[i][j - 1]) {
            j--;
        } else i--;
    }

    for (int i = len - 1; i >= 0; i--) {
        write << solution[i] << " ";
    }

    return 0;
}