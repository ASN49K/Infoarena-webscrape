#include <iostream.h>
#include <fstream.h>
using namespace std;
long a,b;
int gcd(int a, int b) 
{if (b==1) return a;
 return gcd(b, a % b); 
} 
void citire()
{ifstream f("euclid2.in");
 f>>a>>b;
 f.close();
}

void afisare()
{ofstream g("euclid2.out");
 g<<gcd(a,b);
 g.close();
}



int main()
{citire();
 afisare();
 return 0;
}
