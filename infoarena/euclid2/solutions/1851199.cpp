#include <iostream>
#include <fstream>
int a,b,c,x,t;
using namespace std;\
int GCD(int a, int b){
    if(!b)
        return a;
    else
        return GCD(b, a%b);

}
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
int main()
{
    f >> t;
    f >> a;
    f >> b;
    for(int i = 1; i<=t; i++)
    {
       cout << GCD(a,b);
       g << a;
    }
    return 0;
}
