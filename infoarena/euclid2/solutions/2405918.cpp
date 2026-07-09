#include <iostream>

using namespace std;

int main()
{
    int N,i;
    cin>>N;
    int a,b,r;
    int x = 1;
    for(i = 1;i <= N;i++){
        cin>>a>>b;
        while (x <= a){
            if(a % x == 0 && b % x == 0){
                r = x;
            }
            x++;
        }
        cout<<r<<"\n";
        x = 1;
    }
}
