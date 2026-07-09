#include <fstream>

using namespace std;

ifstream cin("cmmdc.in");
ofstream cout("cmmdc.out");

int main() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int a, b, r;
        cin>>a>>b;
        while (b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<endl;
    }
    return 0;
}
