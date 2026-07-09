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

    fout<<dynamic[lengthVec1][lengthVec2];

    return 0;
}