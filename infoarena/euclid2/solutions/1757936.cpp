#include <iostream>
#include <fstream>


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
            if(a<b)
            {
                b-=a;
            }
            else
            {
                a-=b;
            }
        }
        ki<<a<<endl;
    }

    return 0;
}
