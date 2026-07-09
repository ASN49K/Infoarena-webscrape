#include <iostream>

using namespace std;

int main()
{
    int a, b, t, aux;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> a >> b;
        while(b != 0) {
            aux = b;
            b = a % b;
            a = aux;
        }
        cout << a << endl;
    }
    return 0;
}
