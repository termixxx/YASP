#include "Functions.h"


ifstream fillFileWithRandomNumbersCycle(string fileName, const int N, const int M)
{
	ofstream out(fileName, ios::out);
	if (!out.is_open())
		cerr << "!ERROR! File wasn`t opened\n";
	else
	{
		out << N << '\n';
		for (int i = 0; i < N; i++)
			out << rand() % (2 * M + 1) - M << ' ';
	}
	ifstream file(fileName);
	return file;
}


ifstream fillFileWithRandomNumbersGenerate(string fileName, const int N, const int M)
{
	ofstream out(fileName, ios::out);
	if (!out.is_open())
		cerr << "!ERROR! File wasn`t opened\n";
	else
	{
		deque<double> deq(N);
		generate(deq.begin(), deq.end(), [M]() -> int {return rand() % (2 * M + 1) - M; });
		out << N << '\n';
		out << deq;
	}
	ifstream file(fileName);
	return file;
}


deque<double> fillContainerFromFile(ifstream& file)
{
	deque<double> deq;
	int size, num;
	file >> size;
	for (int i = 0; i < size; i++)
	{
		file >> num;
		deq.emplace_back(num);
	}
	file.close();
	return deq;
}

double findFirstNegativeNumber(deque<double>::iterator begin, deque<double>::iterator end)
{
	for (; begin!=end; begin++)
		if (*begin < 0)
			return *begin;
}

deque<double> modify(deque<double>& deq, double K)
{
	deque<double> res(deq);
	double negativeNum = findFirstNegativeNumber(res.begin(), res.end());
	for (auto it = res.begin(); it != res.end(); it++)
		*it /= (negativeNum + K) / 2;
	return res;
}


void modify(deque<double>::iterator begin, deque<double>::iterator end, double K)
{
	double negativeNum = findFirstNegativeNumber(begin, end);
	for (; begin != end; begin++)
		*begin /= (negativeNum + K) / 2;
}


deque<double> modifyTransform(deque<double>& deq, double K)
{
	deque<double> res(deq);
	double negativeNum = findFirstNegativeNumber(res.begin(), res.end());
	
	transform(deq.begin(), deq.end(), res.begin(),
		[negativeNum, K](double elem)->double {
			elem /= (negativeNum + K) / 2;
			return elem;
		});
	return res;
}


deque<double> modifyForEach(deque<double>& deq, double K)
{
	deque<double> res(deq);
	double negativeNum = findFirstNegativeNumber(res.begin(), res.end());
	for_each(res.begin(), res.end(),
		[negativeNum, K](double& elem) {
			elem /=  (negativeNum + K) / 2;
		});
	return res;
}


double sum(deque<double>::iterator begin, deque<double>::iterator end)
{
	double res = 0;
	for (; begin != end; begin++)
		res += *begin;
	return res;
}

double average(deque<double>::iterator begin, deque<double>::iterator end)
{
	return  sum(begin, end) / distance(begin, end);
}

ostream& operator<<(ostream& stream, deque<double>& deq)
{
	for (double elem : deq)
		stream << elem << ' ';
	stream << '\n';
	return stream;
}