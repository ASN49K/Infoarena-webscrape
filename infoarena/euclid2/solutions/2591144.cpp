    #include <iostream>
    #include <fstream>

    using namespace std;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int Solve(int a, int b) {
        int r;
        while (b > 0) {
        r = a % b;
        a = b;
        b = r;
        }
        return a;
    }

    int main()
    {   int x, y;
        int n;
        fin >> n;
        for (int i = 1; i <= n; i++)
        {
            fin >> x >> y;
            fout << Solve(x, y) << "\n";
        }
        fin.close();
        fout.close();
        return 0;
    }
