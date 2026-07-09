#include <fstream>

int T, i;
long int a, b, cmmdc;

using namespace std;

int main()
{
    fstream f("euclid2.in", ios::in);
    fstream g("euclid2.out", ios::out);
    f>>T;
    for(i=1; i<=T; i++)
    {
        f>>a>>b;
        if(a<=b) cmmdc=a+1;
        else cmmdc=b+1;
        int gasit=0;
        while(!gasit)
        {
            cmmdc--;
            if(a%cmmdc==0 && b%cmmdc==0) gasit=1;
        }
        g<<cmmdc<<endl;

    }
    f.close();
    g.close();

}
