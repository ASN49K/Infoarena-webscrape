#include <iostream>

using namespace std;
int a,b;
int main()
{

 cin >>a>>b;
while ((a !=0) & (b!=0)) {
    if (a>b) a=a % b; else b=b%a;

}

if (a!=0) cout <<a; else cout<<b;
    return 0;
}
