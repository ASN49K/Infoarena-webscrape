#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int GCD (int a, int b){
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

int main()
{
    int T;
    fin >> T;

    for(int i{1}; i <= T; ++i){
        int a, b;
        fin >> a >> b;
        fout << GCD(a, b) << "\n";
    }

    return 0;
}
