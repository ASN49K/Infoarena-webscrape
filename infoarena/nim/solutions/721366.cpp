#include<fstream>
using namespace std;
ifstream q("nim.in");
ofstream w("nim.out");
int main()
{
    int t,n,x;
    for(q>>t; t>=1; t--)
    {
        int y=0;
        for(q>>n; n>=1; n--)
        {
            q>>x;
            y^=x;
        }
        if(y!=0)
            w<<"DA";
        else
            w<<"NU";
        w<<"\n";
    }
    return 0;
}
