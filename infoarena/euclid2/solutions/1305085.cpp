#include <iostream>
#include <fstream>


using namespace std;

int main()
{       int t,a,b,r,i;
        ifstream f("euclid2.in");
        f>>t;
        int v[2*t];
        for(i=1;i<=2*t;i++)
        f>>v[i];
        f.close();
        ofstream g("euclid2.out");
        for(i=1;i<=2*t;i++)
        {
            a=v[i];
            b=v[i+1];
            i++;
            r=a%b;
            while(r!=0)
            {
                a=b;b=r;r=a%b;
            }
            g<<b<<endl;
        }
        g.close();
        return 0;
}
