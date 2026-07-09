#include <fstream>

using namespace std;

int main()
{
    int n,a,b,i,c;
    ifstream input;
    ofstream output;
    output.open("euclid2.out");
    input.open("euclid2.in");
    input>>n;
    for (i=0;i<n;i++)
    {
        input>>a>>b;
       /* if (a<b)
        {
            c = a;
            a = b;
            b = c;
        }*/
        while (b != 0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        output<<a<<endl;
    }
    input.close();
    output.close();
    return 0;
}
