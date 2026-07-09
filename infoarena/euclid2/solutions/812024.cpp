#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int n,i,x,y,cmmdc=0;

    in>>n;
    for(i=0;i<n;i++)
    {
        if(cmmdc!=0) out<<cmmdc<<endl;
      in>>x;
      in>>y;
         while(x!=y)
        {
            if(x>y) x=x-y;
            else    y=y-x;
        }
        cmmdc=x;
    }
    out<<cmmdc;
in.close();
out.close();
return 0;
}
