#include <fstream>
using namespace std;
int main()
{
    unsigned long a,b,t,i,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        if((a==0)&&(b!=0))
            g<<b<<'\n';
            else
            {
                if((a!=0)&&(b==0))
                    g<<a<<'\n';
                    else
                    {
                        if((a==0)&&(b==0))
                            g<<0<<'\n';
                            else
                            {
                                r=1;
                                while(r!=0)
                                {
                                    r=a%b;
                                    a=b;
                                    b=r;
                                }
                                g<<a<<'\n';
                            }
                    }
            }
    }
    f.close();
    g.close();
    return 0;
}
