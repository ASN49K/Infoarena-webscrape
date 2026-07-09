
//EUCLID

#include <fstream>


using namespace std;
fstream in ("euclid2.in",ios::in);
fstream out ("euclid2.out",ios::out);
struct perechi
{
    int x,y;
};

int main()
{
    perechi v;
    int T,r;
    in>>T;
    for (int i=0;i<T;i++)
    {
        in>>v.x>>v.y;
        while (v.y!=0)
        {
            r=v.x%v.y,v.x=v.y,v.y=r;
        }
        out<<v.x<<'\n';
    }

    return 0;
}
