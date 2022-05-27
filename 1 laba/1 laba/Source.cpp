#include "Functions.h"

void worksMenu(deque<double>&);
void printDeque(deque<double>& deq, string str = "");
string getFileName();
int inputInt(int left, int right);
void fillFileCycle();
void fillFileGenerate();

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	deque<double> deq;
	do {
		cout << "�������� ��������, ������� ���������� ��������� � ����\n";
		cout << "1 ��������� ���� ���������� �������\n";
		cout << "2 ��������� ���� ���������� ������� � generate\n";
		cout << "3 ��������� ��������� �� �����\n";
		cout << "0 ���������� ������ ���������\n";

		short choose = inputInt(0, 3);
		switch (choose)
		{
		case 0:
		{
			cout << "\n��������� ��������� ���� ������...\n\n";
			return 0;
		}
		case 1:
		{
			fillFileCycle();
			break;
		}
		case 2:
		{
			fillFileGenerate();
			break;
		}
		case 3:
		{
			string name = getFileName();
			ifstream fin(name);
			deq = fillContainerFromFile(fin);
			cout << "��������� ��������!\n";
			worksMenu(deq);
		}
		}
	} while (true);
}

void worksMenu(deque<double>& deq)
{
	do {
		cout << "\n�������� ��������, ������� ���������� ��������� c �����������\n";
		cout << "1 ���� � modify\n";
		cout << "2 ���� � modify (iterator)\n";
		cout << "3 ���� � transform\n";
		cout << "4 ���� � forEach\n";
		cout << "5 C������ ��������������\n";
		cout << "6 ����� ���� �����\n";
		cout << "7 ������ ��������� ����������\n";
		cout << "0 ����� � ������� ����\n";
		short choose = inputInt(0, 7);
		switch (choose)
		{
		case 0:
		{
			cout << "\n����� � ������� ����\n\n";
			return;
		}
		case 1:
		{
			cout << "������� ����� ����� K:\n";
			int K = inputInt(0, deq.size() - 1);
			deque<double> deqModify = modify(deq, deq[K]);
			printDeque(deqModify, "modify");
			break;
		}
		case 2:
		{
			deque<double> deqModify(deq);
			cout << "������� ������� ��������� ����������:\n";

			int left = inputInt(0, deq.size() - 1);
			auto start = deqModify.begin();
			advance(start, left);

			int right = inputInt(left, deq.size() - 1);
			auto end = deqModify.begin();
			advance(end, right);

			cout << "������� ����� ����� K:\n";
			int K = inputInt(0, deq.size() - 1);
			modify(start, end, deq[K]);
			printDeque(deqModify, "modify with iterators");
			break;
		}
		case 3:
		{
			cout << "������� ����� ����� K:\n";
			int K = inputInt(0, deq.size() - 1);
			deque<double> deqModify = modifyTransform(deq, deq[K]);
			printDeque(deqModify, "transform");
			break;
		}
		case 4:
		{
			cout << "������� ����� ����� K:\n";
			int K = inputInt(0, deq.size() - 1);
			deque<double> deqModify = modifyForEach(deq, deq[K]);
			printDeque(deqModify, "forEach");
			break;
		}
		case 5:
		{
			cout << "C������ �������������� ��������� ����������: " << average(deq.begin(), deq.end()) << '\n';
			break;
		}
		case 6:
		{
			cout << "C���� ���� ��������� ��������� ����������: " << sum(deq.begin(), deq.end()) << '\n';
			break;
		}
		case 7:
			cout << "�������� ���������:\n" << deq;
			break;
		}
	} while (true);
}

void fillFileCycle()
{
	string fileName = getFileName();

	cout << "������� ���-�� ���������: ";
	int N = inputInt(1, 100);

	cout << "������� �������� ���������: ";
	int M = inputInt(0, 100);

	ifstream fIn = fillFileWithRandomNumbersCycle(fileName, N, M);
	fIn.close();
	cout << "���� ��������!\n";
}

void fillFileGenerate()
{
	string fileName = getFileName();

	cout << "������� ���-�� ���������: ";
	int N = inputInt(1, 100);

	cout << "������� �������� ���������: ";
	int M = inputInt(0, 100);

	ifstream fIn = fillFileWithRandomNumbersGenerate(fileName, N, M);
	fIn.close();
	cout << "���� ��������!\n";
}

void printDeque(deque<double>& deq, string str)
{
	cout << "��������, ���� ����� ����������� ���������:\n";
	cout << "1 �������\n";
	cout << "2 ����\n";
	short ch = inputInt(1, 2);
	switch (ch)
	{
	case 1:
		cout << "��������� ���������" << '\n' << deq;
		break;
	case 2:
	{
		string name = getFileName();
		ofstream out;
		out.open(name, ios::out | ios::app);
		out << "\n��������� ������ � �������: " << str << '\n';
		out << deq;
		cout << "������� �������� � ����!\n";
		out.close();
	}
	}
}

int inputInt(int left, int right)
{
	int res;
	std::cin >> res;
	while (!std::cin.good() || res<left || res>right)
	{
		std::cin.clear();
		std::cin.ignore(255, '\n');
		std::cout << "�������� ���� ������� �����������\n������� �������� � ��������� �� " << left << " �� " << right << ";\n";
		std::cin >> res;
	}
	return res;
}

string getFileName()
{
	cout << "������� ��� �����:\n";
	string name;
	cin >> name;
	return name;
}