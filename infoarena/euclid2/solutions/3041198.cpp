#include <iostream>
#include <fstream>
using namespace std;

ifstream F("euclid2.in");
ofstream G("euclid2.out");

int cmmdc(int a, int b)
{
    if (b==0) return a;
    return cmmdc(b,a%b);
}

int main()
{
    int n; F>>n;
    for (int i=1;i<=n;i++)
    {
        int a,b;
        F >>a >>b;
        G << cmmdc(a,b)<<endl;
    }

}
