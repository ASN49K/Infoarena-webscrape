#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int n,x,y;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        while((x!=0)&&(y!=0))
        {
            if(x>y)
                x=x%y;
            else
                y=y%x;



        }
        if(x!=0)
g<<x;
else
            g<<y;
g<<'\n';


    }





    return 0;
}
