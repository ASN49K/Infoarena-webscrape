#include<fstream.h>
int T, A, B;
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>T;
    while(T)
    {
        f>>A>>B;
        g<<gcd(A,B)<<"\n";
        T--;
    }          
  
    return 0;  
}