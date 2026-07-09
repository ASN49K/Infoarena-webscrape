#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t, n, a, xorsum;

int main(){

    f>>t;

    for(int j=t; j>=1; j--){

        f>>n;

        xorsum = 0;
        for(int i = 1; i <= n; ++i){

            f>>a;
            xorsum = xorsum ^ a;

        }

        if(xorsum)
            g<<"DA"<<"\n";
        else
            g<<"NU"<<"\n";

    }

}
