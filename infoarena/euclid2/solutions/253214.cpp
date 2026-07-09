#include <fstream>

using namespace std;

int main()
{
    fstream f("euclid2.in",ios::in);
    fstream f2("euclid2.out",ios::out);
    int t;
    f>>t;

    long long a,b;

    for(int i=1;i<=t;i++)
    {
        long long x,y;
        f>>x>>y;

        if(x<y) {long long aux=x; x=y; y=aux;}

        long long r=x%y;

        while(r)
        {
            x=y;
            y=r;
            r=x%y;
        }
        f2<<y<<"\n";

    }


    f2.close();
    return 0;
}
