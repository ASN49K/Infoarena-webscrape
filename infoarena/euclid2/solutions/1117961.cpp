#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in",ios::in);
    ofstream out("euclid2.out",ios::out);

    int T,a,b;

    in>>T;

    for(int i=0;i<T;++i)
    {
        in>>a>>b;

        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }

        out<<a;
        out<<"\n";
    }




in.close();
out.close();

return 0;


}
