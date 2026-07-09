#include <iostream>
using namespace std;
int main () {
unsigned a,b,r;
cout <<"Afiseaza cmmmdc a 2 numere naturale"<<endl;
cin >>a>>b;
while (b != 0) {
    r = a % b;
    a = b;
    b = r;
}
cout <<a;
}
