#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void functie(int a, int b) {
    while(b != 0) {
    int r = a % b;
    a = b;
    b = r;
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
    cout << 25 % 75;
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
