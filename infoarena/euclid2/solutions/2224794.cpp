#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n;
    fin >> n;
    int a, b;
    for(int i = 1; i <= n; ++i){
        fin >> a >> b;
        int r;
        while(b > 0){
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
    return 0;
}
