#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int T,x,y,r;
int main()
{
        in>>T;
        while(T)
        {
            in>>x>>y;
            r=x%y;
            while(r)
            {
                x=y;
                y=r;
                r=x%y;
            }
            out<<y<<'\n';
            --T;
        }
}

