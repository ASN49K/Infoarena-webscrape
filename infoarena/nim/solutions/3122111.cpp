#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");


int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,x=0,a;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>a;
            x^=a;
        }
        if(x==0)
            cout<<"NU\n";
        else
            cout<<"DA\n";
    }
}
