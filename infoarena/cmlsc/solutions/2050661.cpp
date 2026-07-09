#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int lengthVec1, lengthVec2;
int vec1[1030], vec2[1030], dynamic[1030][1030];

int main() {

    fin >> lengthVec1 >> lengthVec2;
    for (auto i = 1; i <= lengthVec1; ++i) {
        fin >> vec1[i];
    }
    for (auto i = 1; i <= lengthVec2; ++i) {
        fin >> vec2[i];
    }
    for (int step = 1; step <= lengthVec1; ++step) {
        for (int iter = 1; iter <= lengthVec2; ++iter) {
            if (vec1[step] == vec2[iter])
                dynamic[step][iter] = dynamic[step - 1][iter - 1] + 1;
            else
                dynamic[step][iter] = max(dynamic[step - 1][iter], dynamic[step][iter - 1]);
        }
    }

    fout << dynamic[lengthVec1][lengthVec2] << '\n';
    int iter = lengthVec1;
    int step = lengthVec2;
    int sol[1000];
    int lengthSol = -1;
    while (iter > 0 && step > 0 && dynamic[iter][step] > 0) {
        if (vec1[iter] == vec2[step]) {
            sol[++lengthSol] = vec1[iter];
            iter--;
            step--;
        } else {
            if (dynamic[iter - 1][step] > dynamic[iter][step - 1]) {
                iter--;
            } else {
                step--;
            }
        }
    }
    for (auto iter = lengthSol; iter >= 0; iter--) {
        fout << sol[iter] <<' ';
    }
    return 0;
}