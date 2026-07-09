#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main()
{
    int n, a, b;

    fin >> n;
    while(n){
        fin >> a >> b;
        while(b){
            int r;
            r = a % b;
            a = b;
            b = r;
        }
        n--;
        fout<<a<<"\n";
    }
    return 0;
}
