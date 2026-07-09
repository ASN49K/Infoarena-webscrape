#include<fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a,int b){
    if(!b) return a;
    return cmmdc(b,a%b);
}
int main()

{
    int a,b;
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
