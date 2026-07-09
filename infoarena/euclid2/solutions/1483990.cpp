#include <fstream>

using namespace std;

int main()
{
    int long i, n, m, rest;
    ifstream fin("euclid2.in");
    fstream fout("euclid2.out");
    fin>>i;
    while(i--){
        fin>>n>>m;
        while(m){
            rest=n%m;
            n=m;
            m=rest;
        }
        fout<<n<<endl;
    }
    return 0;
}
