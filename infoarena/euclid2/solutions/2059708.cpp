#include <iostream>

using namespace std;

long  gcd(long  a , long b)
{
while  (a!=b)
{
    if (a>b){
        a=a-b;
    }
    {
      if (b>a) { b=b-a; }
    }
}
return a;

}
int main()
{
    long x;
    long y;
    cin >> x >>y ;
    cout << gcd(x,y) << endl;
}
