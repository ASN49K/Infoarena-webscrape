#include <iostream>
#include <fstream>
using namespace std;
int main()
{
int x,n,a,b,i;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
f >> n;
while(n){
        f>>a>>b;
    while (b) {
        x = a % b;
        a = b;
        b = x;
    }
    n--;
    g<<a<<endl;
}
return 0;

}
