#include <fstream>
#include <vector>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int div(int a, int b){
    if (b == 0)
        return a;
    else
        return div(b, a % b);
}

long n, a, b;

int main(){
    fin >> n;
    for(int i = 1; i <= n; i ++){
        fin >>a >> b;
        fout << div(a,b) << endl;
    }
    return 0;
}
