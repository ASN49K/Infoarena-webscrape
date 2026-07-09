using namespace std;
#include<fstream>
int main()
{
    int a,b,n,i,x,y;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {   f>>a;
        f>>b;
        x=a;
        y=b;
        while(a!=b)
        {if(a>b)
        a=a-b;
        else
        b=b-a;}
        g<<a<<endl;
    }
    return 0;
}
