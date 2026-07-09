#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n,a,b,r,i;
    in>>n;
    for(i=1;i<=n;i++){
        in>>a>>b;
        while(b){
            r=a%b;
            a=b;b=r;
        }
        out<<a<<endl;
    }
    in.close();
    out.close();
    return 0;
}
