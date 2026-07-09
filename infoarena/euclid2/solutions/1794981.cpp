#include <iostream>

using namespace std;

int main()
{
    int nr1, nr2, rest;
    cin >> nr1 >> nr2;
    while(nr2!=0) // sau (nr2), este default diferit de 0
    {
        rest = nr1 % nr2;
        nr1= nr2;
        nr2 = rest;
    }
    cout<<nr1;
    return 0;
}
