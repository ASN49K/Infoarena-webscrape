#include <fstream>

using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a,x;
        cin>>a;
        x=a;
        for(int i=1;i<n;i++)
        {
            cin>>a;
            x=(x^a);
        }
        if(x>0)cout<<"DA\n";
        else
            cout<<"NU\n";
    }
    return 0;
}
