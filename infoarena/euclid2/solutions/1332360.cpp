#include <iostream>
#include <fstream>
using namespace std;
int N,a,b;

int j,k,d=1;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    cin>>N;
    for(int x=0;x<N;x++){
        cin>>a>>b;
int d=1;
        while(d)
        {
d=a%b;
a=b;
b=d;
        }
        cout<<a<<"\n";


        }
    return 0;
}
