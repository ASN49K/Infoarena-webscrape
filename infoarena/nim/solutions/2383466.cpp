#include <fstream>
using namespace std;

#define FILE_NAME "nim"
ifstream in (FILE_NAME".in");
ofstream out(FILE_NAME".out");

int main()
{
    int T;
    in >> T;

    while(T--)
    {
        int N;
        in >> N;

        int sumXor = 0;
        while(N--)
        {
            int stones;
            in >> stones;
            sumXor ^= stones;
        }

        out << ((sumXor == 0) ? "NU" : "DA") << '\n';
    }

    return 0;
}
