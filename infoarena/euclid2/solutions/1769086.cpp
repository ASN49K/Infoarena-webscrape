#include <iostream>

using namespace std;
int cmmdc (int a,int b)
{ int c ;
    if (a%b == 0 )
        c= b ;
    else
        c = cmmdc(b , a%b ) ;
    return c ;
}
int main()
{
    int n , m ;
    cin >> n >> m ;
    cout << cmmdc (m,n) ;
    return 0;
}
