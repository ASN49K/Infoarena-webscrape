#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int x, int y)
{
    while(x != y)
    {
        if(x > y)
            x -= y;
        else
            y -= x;
    }
    return x;
}

int main(){
int n
long long a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f >> n;
for(int i = 0; i < n;i++)
{
    f >> a >> b;
    if(a == 0 && b != 0)
        g >> b;
    else
   g << cmmdc(a, b) << "\n";
}

}
