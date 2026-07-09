#include<fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    long long int a,b,r;
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<endl;
    }

}
