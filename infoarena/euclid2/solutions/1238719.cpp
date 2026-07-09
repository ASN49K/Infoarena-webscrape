#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream readin("euclid2.in");

    ofstream writeout("euclid2.out");

    int t, a, b, manevra;

    readin >> t; // Citesc variabila t

    for(int counter = 1; counter <= t; counter++){

        readin >> a >> b;
        while (b != 0){
            manevra = b;
            b = a%b;
            a = manevra;

        }

        if (counter < t ) {
                writeout << a << "\n";
        }
        else {
                writeout << a;
        }
    }

    return 0;
}
