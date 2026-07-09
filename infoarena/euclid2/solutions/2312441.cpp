#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int T,a,b;
    fin >> T;
    for(int i = 0; i < T; i++){
        fin >> a >> b;
        int rest = 0;
        while(b != 0){
            rest = a % b;
            a = b;
            b = rest;
        }
        fout << a << endl;
    }
}
