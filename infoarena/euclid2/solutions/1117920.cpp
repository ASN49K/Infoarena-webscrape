#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in",ios::in);
    ofstream out("euclid2.out",ios::out);

    int T,a[10000],b[10000];

    in>>T;

    for(int i=0;i<T;++i)
    {
        in>>a[i];
        in>>b[i];
    }

    for(int i=0;i<T;++i)
    {
        while(a[i]!=b[i])
        {
            if(a[i]>b[i])
                a[i]=a[i]-b[i];
            else
                b[i]=b[i]-a[i];
        }

        out<<a[i];
        out<<"\n";
    }


return 0;






}
