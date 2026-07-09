#include <iostream>

using namespace std;

int main()
{
    int x,y,c;
    cin >> x >> y;
    while(y)
    {
        c=x%y;
        x=y;
        y=c;
    }

    if(x==0&&y==0)
        cout << "-1";
    else
        cout << x;
    return 0;
}
