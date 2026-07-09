#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int a,b,d,T;

int main()
{
    cin>>T;
    for (int I=1; I<=T; ++I){
        cin>>a>>b;
        d=a%b;
        while (d!=0){
            a=b;
            b=d;
            d=a%b;
        }
        cout<<b<<"\n";
    }

    return 0;
}
