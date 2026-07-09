#include <fstream>

using namespace std;

int euclid(int a, int b){
    if(!b) return a;
    return euclid(b, a%b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T, a, b;
    fin>>T;
    for(;T;T--){
        fin>>a>>b;
        fout<<euclid(a, b)<<endl;
    }
}
