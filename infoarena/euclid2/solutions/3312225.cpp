/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc( long long a, long long b){
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    long long n, a, b;
    cin>>n;
    for( int i=1;i<=n;i++){
        cin>>a>>b;
        cout<<cmmdc(a,b)<<endl;
    }

    return 0;
}