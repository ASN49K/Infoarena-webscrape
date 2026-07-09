
//EUCLID

#include <fstream>

#define N 100000
using namespace std;
fstream in ("euclid2.in",ios::in);
fstream out ("euclid2.out",ios::out);
struct perechi
{
    int x,y;
};

int main()
{
    perechi v[N];
    int T,r;
    in>>T;
    for (int i=0;i<T;i++)
    {
        in>>v[i].x>>v[i].y;
        while (v[i].y!=0)
        {
            r=v[i].x%v[i].y,v[i].x=v[i].y,v[i].y=r;
        }
        out<<v[i].x<<'\n';
    }

    return 0;
}
