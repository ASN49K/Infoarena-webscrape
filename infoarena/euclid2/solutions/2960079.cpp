#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void functie(int a, int b) {
    while(a != b) {
    if(a > b) {
            a -= b;
    }
    else if(a < b) {
        b -= a;
    }
    }
    fout << a << endl;
    return;
}
int main()
{
    int n, a, b;
    fin >> n;
    for(int z = 0; z < n; ++z) {
        fin >> a >> b;
        functie(a, b);
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
