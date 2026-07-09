#include<iostream>
#include<fstream>
#include<vector>

void read(std::ifstream &in, std::vector<int> &v, int n)
{
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        in >> v[i];
    }
}

std::vector<int> cmlsc(std::vector<int> a, std::vector<int> b)
{
    std::vector< std::vector< std::vector<int> > > matrix;
    matrix.resize(a.size() + 1);

    for(int i=0; i<a.size() + 1; i++)
    {
        matrix[i].resize(b.size() + 1);
        matrix[i][0] = std::vector<int> ();
    }

    for(int i=0; i<b.size() + 1; i++)
    {
        matrix[0][i] = std::vector<int> ();
    }

    for(int i=1; i<a.size() + 1; i++)
    {
        for(int j=1; j<b.size() + 1; j++)
        {
            if(a[i-1] == b[j-1])
            {
                matrix[i][j] = matrix[i-1][j-1];
                matrix[i][j].push_back(a[i-1]);
            }
            else
            {
                if(matrix[i-1][j].size() > matrix[i][j-1].size())
                {
                    matrix[i][j] = matrix[i-1][j];
                }
                else
                {
                    matrix[i][j] = matrix[i][j-1];
                }
            }
        }
    }
    return matrix[a.size()][b.size()];
}

int main()
{
    int n1, n2;
    std::vector<int> a, b;
    std::ifstream in ("cmlsc.in");
    std::ofstream out ("cmlsc.out");
    in >> n1 >> n2;
    read(in, a, n1);
    read(in, b, n2);
    std::vector<int> r = cmlsc(a,b);
    out << r.size() << "\n";
    for(int i=0; i<r.size(); i++)
    {
        out << r[i] << " ";
    }
    in.close();
    out.close();
    return 0;
}
