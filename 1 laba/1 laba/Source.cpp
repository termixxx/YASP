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
		cout << "Выберите действие, которое необходимо выполнить в меню\n";
		cout << "1 Заполнить файл случайными числами\n";
		cout << "2 Заполнить файл случайными числами — generate\n";
		cout << "3 Заполнить контейнер из файла\n";
		cout << "0 Завершение работы программы\n";

		short choose = inputInt(0, 3);
		switch (choose)
		{
		case 0:
		{
			cout << "\nПрограмма завершила свою работу...\n\n";
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
			cout << "Контейнер заполнен!\n";
			worksMenu(deq);
		}
		}
	} while (true);
}

void worksMenu(deque<double>& deq)
{
	do {
		cout << "\nВыберите действие, которое необходимо выполнить c контейнером\n";
		cout << "1 Таск — modify\n";
		cout << "2 Таск — modify (iterator)\n";
		cout << "3 Таск — transform\n";
		cout << "4 Таск — forEach\n";
		cout << "5 Cреднее арифметическое\n";
		cout << "6 Сумма всех чисел\n";
		cout << "7 Печать исходного контейнера\n";
		cout << "0 Выход в главное меню\n";
		short choose = inputInt(0, 7);
		switch (choose)
		{
		case 0:
		{
			cout << "\nВыход в главное меню\n\n";
			return;
		}
		case 1:
		{
			cout << "Введите номер числа K:\n";
			int K = inputInt(0, deq.size() - 1);
			deque<double> deqModify = modify(deq, deq[K]);
			printDeque(deqModify, "modify");
			break;
		}
		case 2:
		{
			deque<double> deqModify(deq);
			cout << "Введите границы обработки контейнера:\n";

			int left = inputInt(0, deq.size() - 1);
			auto start = deqModify.begin();
			advance(start, left);

			int right = inputInt(left, deq.size() - 1);
			auto end = deqModify.begin();
			advance(end, right);

			cout << "Введите номер числа K:\n";
			int K = inputInt(0, deq.size() - 1);
			modify(start, end, deq[K]);
			printDeque(deqModify, "modify with iterators");
			break;
		}
		case 3:
		{
			cout << "Введите номер числа K:\n";
			int K = inputInt(0, deq.size() - 1);
			deque<double> deqModify = modifyTransform(deq, deq[K]);
			printDeque(deqModify, "transform");
			break;
		}
		case 4:
		{
			cout << "Введите номер числа K:\n";
			int K = inputInt(0, deq.size() - 1);
			deque<double> deqModify = modifyForEach(deq, deq[K]);
			printDeque(deqModify, "forEach");
			break;
		}
		case 5:
		{
			cout << "Cреднее арифметическое исходного контейнера: " << average(deq.begin(), deq.end()) << '\n';
			break;
		}
		case 6:
		{
			cout << "Cумма всех элементов исходного контейнера: " << sum(deq.begin(), deq.end()) << '\n';
			break;
		}
		case 7:
			cout << "Исходный контейнер:\n" << deq;
			break;
		}
	} while (true);
}

void fillFileCycle()
{
	string fileName = getFileName();

	cout << "Введите кол-во элементов: ";
	int N = inputInt(1, 100);

	cout << "Введите диапозон генерации: ";
	int M = inputInt(0, 100);

	ifstream fIn = fillFileWithRandomNumbersCycle(fileName, N, M);
	fIn.close();
	cout << "Файл заполнен!\n";
}

void fillFileGenerate()
{
	string fileName = getFileName();

	cout << "Введите кол-во элементов: ";
	int N = inputInt(1, 100);

	cout << "Введите диапозон генерации: ";
	int M = inputInt(0, 100);

	ifstream fIn = fillFileWithRandomNumbersGenerate(fileName, N, M);
	fIn.close();
	cout << "Файл заполнен!\n";
}

void printDeque(deque<double>& deq, string str)
{
	cout << "Выберите, куда нужно распечатать контейнер:\n";
	cout << "1 Консоль\n";
	cout << "2 Файл\n";
	short ch = inputInt(1, 2);
	switch (ch)
	{
	case 1:
		cout << "Изменённый контейнер" << '\n' << deq;
		break;
	case 2:
	{
		string name = getFileName();
		ofstream out;
		out.open(name, ios::out | ios::app);
		out << "\nКонтейнер изменён с помощью: " << str << '\n';
		out << deq;
		cout << "Успешно записано в файл!\n";
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
		std::cout << "Значение было введено некорректно\nВведите значение в диапозоне от " << left << " до " << right << ";\n";
		std::cin >> res;
	}
	return res;
}

string getFileName()
{
	cout << "Введите имя файла:\n";
	string name;
	cin >> name;
	return name;
}