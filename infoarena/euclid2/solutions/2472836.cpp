#include <fstream>
#include <string>
#include <vector>

void swap(unsigned int& a, unsigned int& b)
{
	a = a - b;
	b = a + b;
	a = b - a;
}

int cmmdc(unsigned int a, unsigned int b)
{
	if (a < b)
	{
		swap(a, b);
	}

	unsigned int r = a % b;

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

	unsigned int n_pairs;
	std::vector<std::vector<unsigned int>> v_pairs;

	if (in_file.is_open())
	{
		in_file >> n_pairs;

		for (unsigned int i = 0; i < n_pairs; i++)
		{
			unsigned int a, b;
			in_file >> a >> b;
			v_pairs.push_back({ a, b });
		}
	}

	std::ofstream out_file(output_filename);

	for (unsigned int i = 0; i < v_pairs.size(); i++)
	{
		unsigned int result = cmmdc(v_pairs[i][0], v_pairs[i][1]);
		out_file << result << "\n";
	}

	out_file.close();
	return 0;
}