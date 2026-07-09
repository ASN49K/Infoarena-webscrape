#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,X,r,n,i;
int main()
{  f>> n;
 while (n!=0) {n--;
    f>> a >> b;
    r=a%b;
    while (r!=0) {a=b;b=r;r=a%b;}
    g << b<<endl;
 }

    return 0;
}
