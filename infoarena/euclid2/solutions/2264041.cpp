#include <iostream>

using namespace std;

int main()
{
    int a,b;
    int n;
    int i;
    cin>>n;
    for(i=1;i<=n;i++){
    cin >> a;
    cin >> b;
while(a != b)
{
    if(a > b)
        a = a - b;
    if(b > a)
        b = b - a;
}

cout << a<<"\n";
    }

    return 0;
}
