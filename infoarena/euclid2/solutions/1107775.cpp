#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
    int n,a,b;
    for(int i = 0;i<n;i++)
    {
        cin>>a>>b;
        int r;
        while(b!=0)
        {
            r = a%b;
            a=b;
            b = r;
        }
        cout<<a<<endl;
    }
}
