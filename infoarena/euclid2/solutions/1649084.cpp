#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, x, y;

int GCD(int a, int b){
    while(a){
        int r = b % a;
        b = a;
        a = r;
    }
    return b;
}

int main()
{
    fin >> n;
    for(int i = 0; i < n; ++i){
        fin >> x >> y;
        fout << GCD(x, y) << '\n';
    }
    return 0;
}
