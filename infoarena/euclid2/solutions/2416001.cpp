#include <iostream>
#include <fstream>
using namespace std;
int cmmdc (int a, int b){
        if (b == 0)
            return a;
        else cmmdc(b, a%b);
        }
int main()
{
    int n, a, b;
    ifstream fin("euclid2.in");
    ofstream fout ("euclid2.out");

    fin >> n;
    for (int i = 0; i < n; i++){
    fin >> a >> b;
    fout << cmmdc(a, b) << endl;}

    return 0;
}
