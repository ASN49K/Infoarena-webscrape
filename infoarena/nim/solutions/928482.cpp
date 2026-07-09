#include <iostream>
#include <fstream>

using namespace std;

int T, N, S, x;

int main(){

    ifstream f("nim.in");
    ofstream g("nim.out");

    for( f >> T; T; T--, S = 0){

        for( f >> N; N; N--){

            f >> x;
            S = S ^ x;
        }

        if ( S )
            g<< "DA\n";
        else
            g << "NU\n";
    }

    return 0;
}
