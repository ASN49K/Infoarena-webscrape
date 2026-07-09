#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n,x,y,i;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        int r=x%y;
        while(r>0){
            x=y;
            y=r;
            r=x%y;
        }
        cout<<y<< '\n';
    }
    return 0;
}
