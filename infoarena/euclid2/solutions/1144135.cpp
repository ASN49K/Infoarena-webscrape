//EUCLID2-INFOARENA - RECURSIVITATE
#include<iostream>
#include<fstream>

//FUNCTIE RECURSIVA PENTRU CEL MAI MARE DIVIZOR COMUN
int gcd(int a, int b)
{
    if (!b)
        return a;
    return CMMDC(b, a % b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T, i, A, B;
    f>>T;
    for (i=1; i<=T; i++)
    {
        f>>A>>B;
        g<<CMMDC(A, B)<<'\n';
    }
    return 0;
}
