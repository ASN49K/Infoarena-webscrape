#include <fstream>
#include <string>
#include <vector>

void swap(long long& a, long long& b)
{
	a = a - b;
	b = a + b;
	a = b - a;
}

long long cmmdc(long long a, long long b)
{
	if (a < b)
	{
		swap(a, b);
	}

	long long r = a % b;

	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

int main()
{
	std::string input_filename = "euclid2.in";
	std::string output_filename = "euclid2.out";

	std::ifstream in_file(input_filename);

	long long n_pairs;
	std::vector<std::vector<long long>> v_pairs;

	if (in_file.is_open())
	{
		in_file >> n_pairs;

		for (long long i = 0; i < n_pairs; i++)
		{
			long long a, b;
			in_file >> a >> b;
			v_pairs.push_back({ a, b });
		}
	}

	std::ofstream out_file(output_filename);

	for (long long i = 0; i < v_pairs.size(); i++)
	{
		long long result = cmmdc(v_pairs[i][0], v_pairs[i][1]);
		out_file << result << "\n";
	}

	out_file.close();
	return 0;
}