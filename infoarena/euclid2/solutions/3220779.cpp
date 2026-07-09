#include <iostream>
#include <fstream>
    
using namespace std;

int cmmdc(int a, int b){
    if(b == 0) return a;
    return cmmdc(b, a%b);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    int t, a, b;
    fin >> t;
    for(int i = 1; i <= t; i++)
        fin >> a >> b, fout << cmmdc(a, b) << '\n';

    return 0;
}