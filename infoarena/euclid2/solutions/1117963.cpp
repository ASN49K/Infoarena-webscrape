#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in",ios::in);
    ofstream out("euclid2.out",ios::out);

    int T,a,b,c;

    in>>T;

    for(int i=0;i<T;++i)
    {
        in>>a>>b;

       while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }

        out<<a;
        out<<"\n";
    }




in.close();
out.close();

return 0;


}
