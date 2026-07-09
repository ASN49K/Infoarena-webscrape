#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t,n,x,sum;
    fin >> t;
    while(t--){
        fin >> n;
        sum = 0;
        for(int i = 1; i <= n; i++){
            fin >> x;
            sum ^= x;
        }
        if(sum){
            fout << "DA\n";
        } else {
            fout << "NU\n";
        }
    }
    return 0;
}
