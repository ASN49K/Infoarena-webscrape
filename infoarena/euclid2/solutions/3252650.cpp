#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t;
    fin >> t;
    for(int i = 1; i <= t; ++i){
        int n, m, aux;
        fin >> n >> m;
        while(m){
            aux = n % m;
            n = m;
            m = aux;
        }
        fout << n << "\n";
    }
    return 0;
}
