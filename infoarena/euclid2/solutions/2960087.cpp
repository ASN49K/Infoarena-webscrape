#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    //Declarăm și citim cele două numere
    int a, b, t;
    fin >> t;
    for(int z = 0; z < t; ++z) {
    fin >> a >> b;
    while(b != 0) {
        int r = a % b; //Restul împărțirii lui a la b
        a = b;
        b = r;
    }
    fout << a << endl;
    }
    return 0;
}
/*void functie(int a, int b) {
    if(a > b) {
            a -= b;
    }
    else if(a < b) {
        b -= a;
    }
    else if(a == b) {
        cout << a << endl;
    }
}*/
