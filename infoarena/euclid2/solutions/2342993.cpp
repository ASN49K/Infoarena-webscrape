#include <iostream>
#include <fstream>

using namespace std;

int T, a, b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a%b)
}

int main()
{
    fin >> T;
    
    for(int i = 0; i < T; i++){
        fin >> a >> b;
        fout << GCD(a,b) << "\n";
    }
    return 0;
}
