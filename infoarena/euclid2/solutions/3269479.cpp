#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int c;
    fin>>c;
    for(int i=0; i<c; i++){
        int n, m;
        fin>>n>>m;
        fout<<__gcd(m,n)<<endl;
    }
    return 0;
}
