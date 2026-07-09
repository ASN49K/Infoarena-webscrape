#include <iostream>

using namespace std;
int a , b,r;
int euclidimp(int a,int b);
int main()
{
    cin >> a >> b;
    cout << euclidimp(a,b);
    return 0;
}

int euclidimp(int a,int b) {

    while (r != 0) {
        r = a % b;
        a = b;
        b = r;

    }
return b;
}

