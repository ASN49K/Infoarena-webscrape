#include<fstream>
using namespace std;
int main ()
{
    fstream f("euclid2.in",ios::in), g("euclid2.out",ios::out);
    unsigned long int a,b,r,T;
    f>>T;
    while (T)
    {
        f>>a>>b;
        while (b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<"\n";
        --T;
    }
    f.close();
    f.close();
    return 0;
}
