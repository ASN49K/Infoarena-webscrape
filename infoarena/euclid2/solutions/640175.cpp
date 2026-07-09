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
        r=x%y;
        while(r!=0)
        {x=y;
        x=r;
        r=x%y;
        }
        g<<r<<endl;
    }
    return 0;
}
