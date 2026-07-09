#include <fstream>
using namespace std;
long long c, n , m;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    fin >> c;
    for(; c>=1; c--)
    {
        fin >> n >> m;
        while(n != m)
            if(n > m)
                n -= m;
            else
                m -= n;
        fout << n << '\n';
    }
    return 0;
}
