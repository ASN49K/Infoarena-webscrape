#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("data.in");
ofstream fout("data.out");
int main() {
    int T;
    int a, b;
    fin >> T;
    while (T){
        fin >> a >> b;
        while (a != b){
            if (a > b){
                a = a - b;
            }
            else if (b > a){
                b = b - a;
            }
            fout << a;
        }
        T--;
    }
}

