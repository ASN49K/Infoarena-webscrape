#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream fin("euclid2.in");
ofstream fin("euclid2.out");
int a , b;
fin >> a >> b;
while(a != b){
    if(a > b)
        a = a - b;
    else
        b = b - a;
}
cout << a;
}
