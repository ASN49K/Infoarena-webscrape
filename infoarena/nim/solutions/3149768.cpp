#include <fstream>

using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int main()
{
    int t,n,rez,nr;
    cin>>t;
    while(t>0)
    {
        t--;
        cin>>n;
        rez=0;
        while(n>0)
        {
            n--;
            cin>>nr;
            rez^=nr;
        }
        if(rez==0)
            cout<<"NU";
        else
            cout<<"DA";
        cout<<'\n';
    }
    return 0;
}
