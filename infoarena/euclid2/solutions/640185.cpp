using namespace std;
#include<fstream>
int main()
{
    int a,b,n,i,x,y,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {   f>>a;
        f>>b;
        x=a;
        y=b;
        while(x!=y)
        {if(x>y)
        x=x-y;
        else
        y=y-x;
        }
        g<<y<<endl;
    }
    return 0;
}
