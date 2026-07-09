
#include <fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int n,q,x,s;
int main()
{
    cin>>q;
    for(int j=0;j<q;j++)
    {
        cin>>n;
        s=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            s=s^x;
        }
        if(s>0)
          cout<<"DA";
        else
         cout<<"NU";
        cout<<'\n';
    }

    return 0;
}
