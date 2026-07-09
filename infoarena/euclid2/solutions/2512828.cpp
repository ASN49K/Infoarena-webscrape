#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int cmmdc(int a , int b){
while(a != b and a > 0 and b > 0)
    {
        if( a > b)
            a %= b;
        else
            b %= a;
    }
    return max(a,b);
}

int main()
{
    int a , b , n;
    fi >> n;
    for(int i = 0; i < n; i ++)
    {
        fi >> a >> b;
        fo << cmmdc(a,b) << '\n';
    }
    fi.close();
    fo.close();
    return 0;
}
