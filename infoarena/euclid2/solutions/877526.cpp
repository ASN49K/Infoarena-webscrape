#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long int a,b,n,r;
int main()
{  f>> n;
 while (n!=0) {n--;
    f>> a >> b;
    r=a%b;
    while (r) {a=b;b=r;r=a%b;}
    g << b<<endl;
 }

f.close();
g.close();
    return 0;
}
