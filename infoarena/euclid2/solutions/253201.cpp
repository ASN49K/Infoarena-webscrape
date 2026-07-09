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
        f>>a>>b;
        long long x,y;
        if(a<b) {x=b;y=a;}
        else {x=a;y=b;}

        long long r=x%y;
        while(r)
        {
            x=y;
            y=r;
            r=x%y;
        }
        f2<<y<<endl;

    }

    f.close();
    f2.close();
    return 0;
}
