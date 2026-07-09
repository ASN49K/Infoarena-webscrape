#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b){
    if (b)
        return cmmdc(b , a % b);
    else
        return a;
}
int main()
{
   int T, a, b;
   fin >> T;
   while (T){
    fin >> a >> b;
    fout << cmmdc(a, b) << '\n';
    T--;
   }
    return 0;
}
