#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a, int b)
{
    while(b>0){
int r=a%b;
a=b;
b=r;
}
return a;
}

int main()
{
    int T,a,b;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
