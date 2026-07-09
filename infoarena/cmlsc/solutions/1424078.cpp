#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	int M,N,A[1024],B[1024],max=0,C[1024],h=0;
	ifstream(in);
	ofstream(out);
	in.open("cmlsc.in");
	in >> M >> N;
	for(int i=0;i<M;i++)
	{
		in >> A[i];
	}
	for(int i=0;i<N;i++)
	{
		in >> B[i];
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(A[i] == B[j])
			{
				max++;
				C[h]=A[i];
				h++;
			}
		}
	}
	in.close();
	out.open("cmlsc.out");
	out << max << endl;
	for(int i=0;i<max;i++)
    {
        out << C[i] << " ";
    }
    out.close();
	return 0;
	}
