#include <iostream>

using namespace std;

void gcd(int a, int b){
    while (b!=0){
        int rest = a%b;
        a = b;
        b = rest;
    }
    cout <<a;
}



int main()
{
    gcd(210,189);
    return 0;
}
