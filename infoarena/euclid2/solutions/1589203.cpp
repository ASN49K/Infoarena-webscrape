#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,i,n;
    ifstream fin("euclid.in");
    ofstream fout("euclid.out");

    fin>>n;
    for(i=1;i<=n;i++) {
        fin>>a>>b;

        fout<<__gcd(a,b)<<"\n";
    }
    return 0;
}
