//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin("date.in");
ofstream cout("date.out");

int t, n;
int main()
{
	cin>>t;
	while(t--)
	{
        cin>>n;
        int flag=0;
        for(int i=1; i<=n; ++i)
        {
            int x;
            cin>>x;
            flag^=x;
        }
        if(flag)
            cout<<"DA\n";
        else
            cout<<"NU\n";
	}
	return 0;
}
