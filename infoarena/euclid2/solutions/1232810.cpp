#include <fstream>
#include <iostream>
#include <algorithm>
 using namespace std;
 
  ifstream f ("euclid2.in");
  ofstream o ("euclid2.out");
 
int main()
{
    int n,i,a,b,r;
    f>>n;
    for(i=1;i<=n;i++){
        f>>a>>b;
        do{
            r=a%b;
            a=b;
            b=r;
        } while(r!=0);
    o<<a<<"\n";
    }
 
    return 0;
}
    
    
 
