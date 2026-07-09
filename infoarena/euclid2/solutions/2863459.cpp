#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t;
int a,b;
int euclid(int a, int b)
{
    if(b==0) return a;
    else return euclid(b,a%b);
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<endl;
    }
    cin.close();
    cout.close();
    return 0;
 
}
