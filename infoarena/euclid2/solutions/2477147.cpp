#include <iostream>

using namespace std;

long long cmmdc(long long a , long long b){
long long temp;
    while( b != 0 ){
        temp = a % b;
        a = b;
        b = temp;}
 return a;


}

int main()
{
    int numarperechi;
    cin>>numarperechi;
    for(int i=0; i<numarperechi; i++){
        long long a,b;
        cin>>a>>b;
        cout<<cmmdc(a,b)<<endl;
        }


    return 0;
}
