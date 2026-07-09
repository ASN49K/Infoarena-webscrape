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

    cout<<a<<endl;

    }

}

int main()
{
    int n, nr1, nr2;
    cin>>n;

    for(int i = 0; i <= n; i++) {
        cin >> nr1 >> nr2;
        cmmdc(nr1, nr2);
    }

    return 0;
}
