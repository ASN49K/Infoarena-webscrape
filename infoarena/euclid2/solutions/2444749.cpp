#include <fstream>
using namespace std;

int euclid(int a, int b){
    if(b == 0) return a;
    return euclid(b, a%b);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int a, b, t;

    fin>>t;
    for(; t>0; t--){
        fin>>a>>b;
        fout<<euclid(a, b)<<"\n";
    }

}
