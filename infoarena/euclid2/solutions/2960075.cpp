#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void functie(int a, int b) {
    if(a >= b) {
            for(int i = b; i > 0; --i) {
                if(b % i == 0 && a % i == 0) {
                    fout << i << endl;
                    return;
                }
            }
        }
        else if(a < b) {
            for(int i = a; i > 0; --i) {
                if(b % i == 0 && a % i == 0) {
                    fout << i << endl;
                    return;
                }
            }
        }
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
