#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a,int b){
    if(a==b)return a;
else if(a>b)return cmmdc(a-b,b);
else return cmmdc(a,b-a);
}
int main()
{
    int a,b,n,i;
    cin>>n;
    for(i=1;i<=n;i++){
     cin>>a>>b;
     cout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
