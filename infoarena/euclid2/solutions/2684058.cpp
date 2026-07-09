#include <fstream>

using namespace std;
ifstream cin("fructe.in");
ofstream cout("fructe.out");
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        int a,b;
        cin>>a>>b;
        while(a!=b)
        {
            if(a>b) a-=b;
            else b-=a;
        }
        cout<<a<<endl;



    }

    return 0;
}
