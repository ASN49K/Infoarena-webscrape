#include <fstream>
#include <algorithm>

using namespace std;

int euclid(int a,int b){
    while ((a!=0) && (a!=1)){
        b=b%a;
        swap(a,b);
    }
    if (a==0) return b;
    else return a;
}

int main()
{
int t,a,b;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
cin>>t;
for (int i=1;i<=t;i++){
    cin>>a>>b;
    if (a>b) swap(a,b);
    cout<<euclid(a,b);
}
return 0;
}
