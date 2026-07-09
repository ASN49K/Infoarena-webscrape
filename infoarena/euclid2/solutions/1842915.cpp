#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x,int y)
{
        if(x>y)
        {
            return euclid(x%y,y);
        }
        return euclid(y%x,x);
}

int main()
{
    int n,x,y;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>x>>y;
        out<<euclid(x,y)<<'\n';
    }
}
