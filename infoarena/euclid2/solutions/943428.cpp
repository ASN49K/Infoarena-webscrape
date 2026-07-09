#include <fstream>
using namespace std;
int main()
{
    int n, a, b, i;
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    cin>>n;
    for(i=1; i<=n; i++)
        {
            cin>>a>>b;
            while(a!=b)
                {
                    if(a>b)
                        a=a-b;
                    if(b>a)
                        b=b-a;
                }
            cout<<a<<"\n";
        }

}
