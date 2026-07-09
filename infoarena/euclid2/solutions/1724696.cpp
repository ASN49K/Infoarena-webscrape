#include <iostream>

using namespace std;
int cmmdc(int a , int b )
{
    while(a!=b)
        if(a>b) a=a-b;
       else b=b-a;
 return a ;
}
int main()
{
    int i ;
    int a ;
    int b ;
    int n ;
    cin >> n ;
    for ( i = 1 ; i <= n ; i ++ )
       {
        cin >> a >> b ;
        cout << cmmdc ( a , b ) ;
       }
    return 0;
}
