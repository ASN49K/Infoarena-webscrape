#include<fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int sol, x, n, t;
int main(){
    for( fin >> t; t != 0; t-- ){
        fin >> n;
        sol = 0;
        for( int i = 1; i <= n; i++ ){
            fin >> x;
            sol ^= x;
        }
        if( sol > 0 ){
            fout << "DA\n";
        }else{
            fout << "NU\n";
        }
    }
    return 0;
}
