#include <fstream>

using namespace std;

long long gcd(long long a,long long b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t;

    fin>>t;
    for(;t>0;t--) {
        int a,b;
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
    }

    fin.close();
    fout.close();

    return 0;
}
