#include <fstream>

int T;
long int a, b, c;

using namespace std;

int main()
{
    fstream f("euclid2.in", ios::in);
    fstream g("euclid2.out", ios::out);
    f>>T;
    for(int i=1; i<=T; i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            c=b;
            b=a%b;
            a=c;
        }
        g<<a<<endl;

    }
    f.close();
    g.close();

}
