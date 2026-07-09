#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int teste, gramezi, pietrePeGramada;

int main() {
    int i, j, s = 0;

    fin >> teste;
    for (i = 1; i <= teste; i++) {
        fin >> gramezi;
        s = 0;
        for (j = 1; j <= gramezi; j++) {
            fin >> pietrePeGramada;
            s = s ^ pietrePeGramada;
        }
        if (s > 0) 
            fout << "DA" << '\n';
        else 
            fout << "NU" << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}