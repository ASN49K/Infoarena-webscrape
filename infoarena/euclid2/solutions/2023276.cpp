#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void cmmdc(int a, int b)
{
    int r;
    if(a == 0 && b == 0) {
        fout << "-1";
        return;
    }
    if(a == 0) {
        fout << b;
        return;
    }

    if(b == 0){
        fout << a;
        return;
    }

    r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    fout << b << '\n';
}
int main()
{
    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        fin >> a >> b;
        cmmdc(a, b);
    }

    return 0;
}
