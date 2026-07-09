#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b;
int main(){
    for(fin >> t; t; t--){
        fin >> a >> b;
        for(int i = min(a, b); i; i--)
            if(a % i == 0 && b % i == 0){
                fout << i << '\n';
                break;
            }
    }
    return 0;
}
