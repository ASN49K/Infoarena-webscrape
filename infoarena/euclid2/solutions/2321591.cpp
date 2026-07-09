#include <iostream>
using namespace std;

int cmmdc(int x, int y)
{
    while(x != y)
    {
        if(x > y)
            x -= y;
        else
            y -= x;
    }
    return x;
}

int main(){
int n,a,b;

cin >> n;

for(int i = 0; i < n;i++)
{
    cin >> a >> b;
   cout << cmmdc(a, b) << "\n";
}

}
