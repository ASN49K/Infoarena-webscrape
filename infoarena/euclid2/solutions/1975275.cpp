#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
 int a, b, T;
int cmmdc(int a, int b){
    int r = 0;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    fin >> T;
    for(int i = 0; i < T; i++){
        fin >> a >> b;
        fout << cmmdc(a,b) << '\n';
    }
    return 0;
}
