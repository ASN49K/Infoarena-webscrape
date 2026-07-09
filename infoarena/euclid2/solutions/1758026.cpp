#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;

int n;
int a,b;

int main()
{
    ifstream be("euclid2.in");
    ofstream ki("euclid2.out");

    be>>n;
    for(int i = 0;i<n;i++)
    {
        be>>a>>b;
        while(a!=b)
        {
            if(a%b == 0)
            {
                a = min(a,b);
                break;
            }
            else if(b%a == 0)
            {
                a = min(a,b);
                break;
            }
            else if(a<b)
            {
                b-=(b/a)*a;
            }
            else
            {
                a-=(a/b)*b;
            }

        }
        ki<<a<<endl;
    }

    return 0;
}
