#include <iostream>

using namespace std;

int main()
{
    unsigned n;
    cin>>n;
    if(((n % 10) % 2 == 1)  ||  ((n / 10000)% 2==1)  ||  (((n/1000)%10)%2==1)  ||  (((n/100)%10)%2==1)  ||  (((n/10)%10)%2==1))
        cout<<"da";
    else
        cout<<"nu";
     cout<<"\n";
    cout<<n/10000<<" "<<n%10<<"\n";
    if((n/10000)==(n%10))
        cout<<"da";
    else
        cout<<"nu";
    cout<<"\n";
    if((n%10)%3==0)
        cout<<"da";
    else
        cout<<"nu";
    cout<<"\n";
    cout<<n%100<<"\n";
    cout<<n/1000<<"\n";
    cout<<n/100;
    return 0;

}
