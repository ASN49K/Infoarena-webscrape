#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int something = 0;
        for(int i=1;i<=n;i++)
        {
            int nr;
            cin>>nr;
            something^=nr;
        }
        if(something != 0)
            cout<<"DA"<<'\n';
        else
            cout<<"NU"<<'\n';
    }
    return 0;
}
