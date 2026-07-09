#include <fstream>

using namespace std;
int long i, n, m, rest;
int main()
{
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
