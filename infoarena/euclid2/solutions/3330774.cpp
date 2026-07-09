#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n;
    in >> n;
    
    while(n) {
        --n;

        int a, b, c;
        cin >> a >> b;

        if (a > b) {
            int aux = a;
            a = b;
            b = aux;
        }

        while (b) {
            c = b % a;
            a = b;
            b = c;
        }
        cout << a << '\n';
    }
    in.close();
    out.close();
    return 0;
}