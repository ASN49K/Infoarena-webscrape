#include <iostream>
#include <fstream>
using namespace std;
int n,k,a[1001];
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a, int b){
    if(a==b)
        return a;
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a>b)
        return cmmdc(a%b,b);
    else
        return cmmdc(a,b%a);

}


int main()
{
    int n,x,y;
    in>>n;
    while(n!=0){
        in>>x>>y;
        out<<cmmdc(x,y)<<"\n";
        n--;
    }


    return 0;
}
