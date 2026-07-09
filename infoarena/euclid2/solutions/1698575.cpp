#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
void euclid (unsigned m, unsigned n){
for(unsigned int r = m%n; r; m = n, n = r, r = m%n);
    fout << n << '\n';
}
int main()
{
    unsigned t;
    fin >> t;
    for (unsigned i=0; i <t; i++){
        unsigned m , n;
        fin >> m >> n;
        euclid(m,n);
    }
return 0;
}
