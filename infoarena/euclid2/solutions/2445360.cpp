
#include <fstream>



using namespace std;



int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int n, a, b;

    int d = 0;

    in>>n;

    for(int j = 0; j< n; j++)
    {
        in>> a>>b;
        for(int i=min(a,b); i>0; i--)
    {
        if (a%i == 0 and b%i ==0)
        {
            d = i;
            break;
        }
    }

        out<< d << endl;
    }

    return 0;
}
