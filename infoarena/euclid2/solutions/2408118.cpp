#include <iostream>
#include <fstream>

using namespace std;

int n, x, y;

bool euclid(int a, int b)
{
    while(a != b)
    {
    	if(a > b)
    	   a-=b;
    	else
    	   b-=a;
    } 
    return a;
}
int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");

    in >> n;
    for(int i = 0; i < n; i++)
    {
        in >> x >> y;
        out << euclid(x, y);
    }
    return 0;
}
