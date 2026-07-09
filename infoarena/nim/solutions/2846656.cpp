#include <fstream>
std::ifstream cin("nim.in");
std::ofstream cout("nim.out");
int t,s,n,x;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        s=0;
        while(n--)
        {
            cin>>x;
            s^=x;
        }
        if(s)
            cout<<"DA\n";
        else
            cout<<"NU\n";
    }
    return 0;
}
