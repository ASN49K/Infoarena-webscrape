#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int t,a,b,r;
    f >> t;
    for(int i = 1; i <= t; i++){
        f >> a >> b;
        if(a > b){
            while(b > 0){
                r = a % b;
                a = b;
                b = r;
            }
            g << a << "\n";
        } else {
            while(a > 0){
                r = b % a;
                b = a;
                a = r;
            }
            g << b << "\n";
        }
    }
    return 0;
}
