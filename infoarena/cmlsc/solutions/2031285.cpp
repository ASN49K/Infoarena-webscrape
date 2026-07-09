#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

struct punct {
int linie,coloana ;
};

int nr1, nr2;
vector<int> sir1, sir2;
stack<int> solutie;

int main() {

    fin>>nr1>>nr2;
    sir1.push_back(0);
    sir2.push_back(0);
    int dinamic[nr2+1][nr1+1],
        directie[nr2+1][nr1+1];
    punct origine[nr2+1][nr1+1];
    // 0 stanga/sus
    // 1 stanga
    // -1 sus
    // 2 stanga sus

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
            directie[i][j] = 0;
            origine[i][j].linie = 0;
            origine[i][j].coloana = 0;
        }
    }

    for(int i = 1; i <= nr2; ++i) {
        for(int j = 1; j <= nr1; ++j) {
            if(dinamic[i-1][j] > dinamic[i][j-1]) { // sus
                dinamic[i][j] = dinamic[i-1][j];
                directie[i][j] = -1;
                if(directie[i-1][j] == 2) {
                    origine[i][j].linie = i-1;
                    origine[i][j].coloana = j;
                } else {
                    origine[i][j] = origine[i-1][j];
                }
            }
            if(dinamic[i][j-1] >= dinamic[i-1][j]) { // stanga
                dinamic[i][j] = dinamic[i][j-1];
                directie[i][j] = 1;
                if(directie[i][j-1] == 2) {
                    origine[i][j].linie = i;
                    origine[i][j].coloana = j-1;
                } else {
                    origine[i][j] = origine[i][j-1];
                }
            }
            if(sir2[i] == sir1[j]) {
                if(dinamic[i-1][j-1] + 1 > dinamic[i][j]) {
                    dinamic[i][j] = dinamic[i-1][j-1] + 1;
                    directie[i][j] = 2;
                    if(directie[i-1][j-1] == 2) {
                        origine[i][j].linie = i-1;
                        origine[i][j].coloana = j-1;
                    } else {
                        origine[i][j] = origine[i-1][j-1];
                    }
                }
            }
        }
    }
//
//    for(int i = 0; i <= nr2; ++i) {
//        for(int j = 0; j <= nr1; ++j) {
//            cout<<dinamic[i][j]<<' ';
//        } cout<<'\n';
//    } cout<<'\n';
//
//    for(int i = 0; i <= nr2; ++i) {
//        for(int j = 0; j <= nr1; ++j) {
//            cout<<directie[i][j]<<' ';
//        } cout<<'\n';
//    }

    fout<<dinamic[nr2][nr1]<<'\n';

    int linie = nr2, coloana = nr1;
    while(linie >= 1 && coloana >= 1) {
        if(directie[linie][coloana] == 2) {
            solutie.push(sir2[linie]);
        }
        linie = origine[linie][coloana].linie;
        coloana = origine[linie][coloana].coloana;
    }

    while(!solutie.empty()) {
        fout<<solutie.top()<<' ';
        solutie.pop();
    }

    fin.close();
    fout.close();
    return 0;
}
