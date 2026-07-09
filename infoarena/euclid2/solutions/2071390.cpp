#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, a, b;

int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void Solve(){
    f >> t;
    for(int i = 1; i <= t; i++)
    {
        f >> a >> b;
        g << cmmdc(a,b) << '\n';
    }
}

int main()
{
    Solve();
    f.close();
    g.close();
}
