#include <iostream>

using namespace std;

void functie(int a, int b) {
    if(a >= b) {
            for(int i = b; i > 0; --i) {
                if(b % i == 0 && a % i == 0) {
                    cout << i << endl;
                    return;
                }
            }
        }
        else if(a < b) {
            for(int i = a; i > 0; --i) {
                if(b % i == 0 && a % i == 0) {
                    cout << i << endl;
                    return;
                }
            }
        }
}

int main()
{
    int n, a, b;
    cin >> n;
    for(int z = 0; z < n; ++z) {
        cin >> a >> b;
        functie(a, b);
    }
    return 0;
}
