#include <iostream>

using namespace std;

int cmmdc(int m, int n) {

    int a, b, r;

    a = m;
    b = n;

    if (a != 0 || b != 0) {

        while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;

    }

}

int main()
{
    int n, nr1, nr2;
    cin>>n;
    int raspunsuri[1000];

    for(int i = 0; i <= n; i++) {
        cin >> nr1 >> nr2;
        raspunsuri[i] = cmmdc(nr1, nr2);
    }

    for(int i = 0; i <= n; i++) {
        cout<<raspunsuri[i]<<endl;
    }

    return 0;
}
