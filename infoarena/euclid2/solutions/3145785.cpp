#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmmdc.in");
ofstream g("cmmdc.out");

int a, b, r, t;

int main()
{
    f >> t;
    for(int i = 1; i <= t; i++){
        f >> a >> b;
        while(b){
            r = a%b;
            a = b;
            b = r;
        }
            g << a << '\n';
    }
}
