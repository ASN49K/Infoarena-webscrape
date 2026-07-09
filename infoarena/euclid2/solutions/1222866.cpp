#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int i,ok,a,b,t;
    in>>t;
    for(i=1;i<=t;i++)
    {   ok=0;
        in>>a>>b;
        while(ok==0)
        {   if(a>b)
            { a=a-b;
                if(a==0)
                {   out<<b<<endl;
                    ok=1;

                }
            }
            else
            {   b=b-a;
                if(b==0)
                {
                    out<<a<<endl;
                    ok=1;
                }
            }


        }

    }
    return 0;
}
