#include <iostream>
#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;

int *sol;
unsigned int m, n;
int *a, *b;

int *sirMaxim;
int lungimeMaxima;

void printSol() {
    fout << lungimeMaxima << "\n";
    for (int i = 0; i < m; i++) {
        if (sirMaxim[i] != -1)
            fout << sirMaxim[i] << ' ';
    }
}

int isInArray(int x, int *v, int len, int from) {
    from++;

    if (from < len) {
        for (int i = from; i < len; i++) {
            if (v[i] == x)
                return i;
        }
    }

    return -1;
}

void copiazaSol() {
    for (int i = 0; i < m; i++) {
        sirMaxim[i] = sol[i];
    }
}

void verificaSol() {
    int currIndex = -1;
    int solLength = 0;

    for (int i = 0; i < m; i++) {
        if (sol[i] != -1) {
            int newIndex = isInArray(sol[i], b, n, currIndex);
            if (newIndex == -1)
                return;

            if (currIndex < newIndex) {
                currIndex = newIndex;
                solLength++;
            } else {
                return;
            }
        }
    }

    if (solLength > lungimeMaxima) {
        lungimeMaxima = solLength;
        copiazaSol();
    }
}

void back(int pos) {
    if (pos == m) {
        verificaSol();
        return;
    }

    sol[pos] = a[pos];
    back(pos + 1);

    sol[pos] = -1;
    back(pos + 1);
}

int main()
{
    fin.open("cmlsc.in");
    fout.open("cmlsc.out");
    fin >> m >> n;
    a = new int[m];
    b = new int[n];
    sol = new int[m];
    sirMaxim = new int[m];

    for (int i = 0; i < m; i++) {
        fin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        fin >> b[i];
    }

    back(0);

    printSol();


    fin.close();
    fout.close();
    return 0;
}
