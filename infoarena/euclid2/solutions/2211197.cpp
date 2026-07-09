#include <fstream>
//CMMDC
using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");

int CMMDC (int &a, int &b) // aici vom afla CMMDC al fiecarei perechi de numere
{
    int div;
    f>>a>>b;
        for(int k=1;k<=b;k++)
            if(!(a%k)&&!(b%k))
                div=k;
    return div;
}

int main()
{
    int n; // N perechi de numere
    int a,b;
    f>>n;
    int i=1;
    while(i<=n)
    {
        g<<CMMDC(a,b)<<endl;
        i++;
    }
    return 0;
}
