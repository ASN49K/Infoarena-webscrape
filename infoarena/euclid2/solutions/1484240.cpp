#include <fstream>

using namespace std;
int i, n, m, rest;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
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
