#include<iostream>
#include<fstream>
using namespace std;

class CMMDC
{
    int a,b;

public:

    CMMDC()
    {
    }

    int Rezolva()
    {
        int aux;
        ifstream f("bla.in");
        ofstream g("bla.out");
        f >> aux;
        for(int i = 0 ; i < aux; i++)
        {
            f >> a >> b;
            g << Cmmdc(a,b) << "\n";
        }
        return 0;
    }

    int Cmmdc(int a,int b)
    {
        if(!b)
            return a;
        return Cmmdc(b,a%b);
    }
};

int main()
{
    CMMDC numar;
    numar.Rezolva();
    return 0;
}
