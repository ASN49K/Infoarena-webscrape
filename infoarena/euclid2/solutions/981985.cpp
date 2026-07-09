#include <fstream>

int T;
long int a, b;

using namespace std;

int main()
{
    fstream f("euclid2.in", ios::in);
    fstream g("euclid2.out", ios::out);
    f>>T;
    for(int i=1; i<=T; i++)
    {
        f>>a>>b;
        while(a!=b)
        {
            if(a>b) a=a-b;
            else b=b-a;
        }
        g<<a<<endl;

    }
    f.close();
    g.close();

}
