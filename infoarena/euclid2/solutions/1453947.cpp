#include <fstream>
using namespace std;
 
int dc(int a, int b)
{
    int r=b;
     
    while(r)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
 
int main ()
{   ios_base::sync_with_stdio(0);
    ifstream cin ("euclid2.in");
    ofstream cout("euclid2.out");
     
    int a,b,t;
     
    cin >> t;
     
    for (int i=0; i<t; i++)
    {
        cin >> a >> b;
        if (b==0) b=a;
        cout << dc(a,b) << "\n";
    }
     
     
     
return 0;
}
