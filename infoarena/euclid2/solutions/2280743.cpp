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
        x = x - y;
    else
        y = y - x;
}
cout << a;
}
