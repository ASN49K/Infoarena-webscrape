#include <fstream>
#include <vector>
using namespace std;

int *a;
int *b;
vector<int>c;

short m1,m2,i,j;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in >> m1;
    in >> m2;
    a = new int[m1];
    b = new int[m2];

    for (i=0;i<m1;i++)
        in>> a[i];
    for (i=0;i<m2;i++)
        in >> b[i];

    for (i=0;i<m1;i++)
        for (j=0;j<m2;j++)
        {
            if (a[i] == b[j])
            {
                c.push_back(a[i]);
                break;
            }
        }
    out << c.size() << '\n';
    for (i=0;i<c.size();i++)
        out << c[i] << " ";
    return 0;
}
