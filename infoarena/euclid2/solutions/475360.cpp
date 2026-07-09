#include <stdio.h>
#include <iostream.h>
#include <fstream.h>
#include <conio.h>



using namespace std;

long GCD(long,long);
long t,a,b,gcd;


int main()
{
    ifstream f("euclid2.in");
    f >> t;
    FILE* g = fopen("euclid2.out", "w");
    for (int i=1;i<=t;i++)
    {
        f >> a >> b;
        gcd = GCD(a,b);
        fprintf(g, "%ld\n", gcd);
    }
    fclose(g);
    f.close();
    return 0;
}


long GCD(long a, long b)
{
    long m = 0;
    if (b==0)
        return a;
    m = a % b;
    a = b;
    b = m;
    return GCD(a,b);
}


