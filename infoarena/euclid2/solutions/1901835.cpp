#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int euclid(int a, int b){

    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    fin >> n;

    for(int i = 1; i <= n; ++i){
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }

    return 0;
}
