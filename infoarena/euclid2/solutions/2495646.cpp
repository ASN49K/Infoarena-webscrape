#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t,a,b;
int euclid2(int a,int b)
{
    if(!b)
        return a;
    return euclid2(b,a%b);

}
int main()
{
    cin>>t;
    for(;t;--t)
    {
        cin>>a>>b;
        cout<<euclid2(a,b)<<endl;
    }
    return 0;
}
