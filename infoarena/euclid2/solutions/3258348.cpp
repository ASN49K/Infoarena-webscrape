#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc (int a, int b){
    if (b == 0){
        return a;
    }
    return cmmdc(b, a%b);
}

int main()
{
    int T, m[100001][3];
    fin >> T;
    for (int i = 1; i <= T; i++){
        for (int k = 1; k <= 2; k++){
            fin >> m[i][k];
        }
        fout << cmmdc(m[i][1], m[i][2]) << '\n';
    }
}
