#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int nr1, nr2;
vector<int> sir1, sir2;
stack<int> solutie;

int main() {

    fin>>nr1>>nr2;
    sir1.push_back(0);
    sir2.push_back(0);
    int dinamic[nr2+1][nr1+1];

    for(int i = 0; i < nr1; ++i) {
        int x; fin>>x;
        sir1.push_back(x);
    }

    for(int i = 0; i < nr2; ++i) {
        int x;
        fin>>x;
        sir2.push_back(x);
    }

    for(int i = 0; i <= nr2; ++i) {
        for(int j = 0; j <= nr1; ++j) {
            dinamic[i][j] = 0;
        }
    }

    for(int i = 1; i <= nr2; ++i) {
        for(int j = 1; j <= nr1; ++j) {
            bool nou = (sir1[j] == sir2[i]);
            dinamic[i][j] = max(dinamic[i][j-1], dinamic[i-1][j] + nou);
        }
    }
//
//    for(int i = 0; i <= nr2; ++i) {
//        for(int j = 0; j <= nr1; ++j) {
//            cout<<dinamic[i][j]<<' ';
//        } cout<<'\n';
//    }

    fout<<dinamic[nr2][nr1]<<'\n';

    int contor = dinamic[nr2][nr1],
        linie = nr2, coloana = nr1;
    while(contor) {
        solutie.push(sir2[linie]);
        while(dinamic[linie][coloana] == contor) {
            --linie;
        } --contor;
        while(dinamic[linie - 1][coloana] == contor) {
            --linie;
        }
        while(dinamic[linie][coloana - 1] == contor) {
            --coloana;
        }
    }

    while(!solutie.empty()) {
        fout<<solutie.top()<<' ';
        solutie.pop();
    }

    fin.close();
    fout.close();
    return 0;
}
