#include <bits/stdc++.h>
using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int N , M ,arr[100] , i;

void read_input ()
{
    while(in >> arr[i])
    {
        out << arr[i] <<" ";
        ++ i;
    }
}

int main()
{
    read_input ();
    return 0;
}
