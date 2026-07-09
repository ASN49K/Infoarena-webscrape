#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, x, y;

int cmmdc(int x, int y){

int c = 0;

while(y != 0){

    c = x%y;
    x = y;
    y = c;

}

return x;

}

int main()
{

f>>t;

for(int i=1; i<=t; i++){

    f>>x>>y;
    g<<cmmdc(x, y)<<'\n';


}

    return 0;
}
