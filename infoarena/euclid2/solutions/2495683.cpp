#include <fstream>
int a,b,i,T;
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        cout<<a<<'\n';
    }
    cin.close();
    cout.close();
    return 0;
}
