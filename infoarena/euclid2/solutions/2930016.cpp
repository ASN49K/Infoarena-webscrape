
#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n,a,b;
int euclid(int a, int b){
    if(b == 0)
        return a;
    else
        return euclid(b, a % b);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<'\n';
    }

    return 0;
}
