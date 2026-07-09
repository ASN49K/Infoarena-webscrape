#include <fstream>

int main()
{
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");

    int n;
    in>>n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        in>>a>>b;
        while(b)
        {
            const int r = a % b;
            a = b;
            b = r;
        }
        out<<a<<"\n";
    }

    in.close();
    out.close();
    return 0;
}
