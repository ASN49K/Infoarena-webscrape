#include <iostream>

using namespace std;

int main() 
{
    int nr1, nr2;
    cin >> nr1 >> nr2;
    while(nr1 != nr2)
    {
        if(nr1 > nr2)
            nr1 = nr1 - nr2;
        if(nr2 > nr1)
            nr2 = nr2 - nr1;
    }
    cout << nr1 << endl;
    return 0;
}