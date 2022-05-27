#include "Journal.h"


void mainMenu();
void iteratorMenu(Journal<Exam>& journal);

bool codeCmp(Exam f, Exam s);
bool courseCmp(Exam f, Exam s);
bool bookNumberCmp(Exam f, Exam s);
bool surnameCmp(Exam f, Exam s);
bool markCmp(Exam f, Exam s);

void findMenu(Journal<Exam>& journal);
void findMenuBinary(Journal<Exam>& journal);

void findNoteMenu(Journal<Exam>& journal);
void findNoteMenuBinary(Journal<Exam>& journal);

void taskMenu(Journal<Exam>& journal);

void printFoundedResult(bool isFind);
void waitContinue();


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	mainMenu();
}


void mainMenu()
{
	Journal<Exam> journal;
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "\n <~~ �������� ���� ������� ��������������� ������ ~~>\n\n";
		cout << "[1] ���� � ����� � ������� ��������� ����������\n"; // +
		cout << "[2] ������� ������\n"; //  +
		cout << "[3] �������� ������\n"; // +
 		cout << "[4] ������� ������\n"; //  +
		cout << "[5] �������� ������\n"; // +
		cout << "[6] �����\n"; // +
		cout << "[7] �������� �����\n"; // +
		cout << "[8] ������� ������������\n"; // +
		cout << "[9] �������� ������� ������������\n"; // +
		cout << "[10] ��������� ������� �����\n";
		cout << "[0] �����\n\n~~>";

		choice = Exam::inputInRange(0, 10);
		switch (choice)
		{
		case 1:
		{
			iteratorMenu(journal);
			break;
		}
		case 2:
		{
			journal.print();
			waitContinue();
			break;
		}
		case 3:
		{
			Exam exam;
			exam.fill();
			journal.addNote(exam);
			waitContinue();
			break;
		}
		case 4:
		{
			if (journal.getSize() == 0)
				cout << "������� ���\n";
			else
			{
				journal.print();
				cout << "����� ������, ������� ����� �������:\n~~>";
				int num = Exam::inputInRange(1, journal.getSize());
				journal.deleteNote(num);
			}
			waitContinue();
			break;
		}
		case 5:
		{
			if (journal.getSize() == 0)
			{
				cout << "������� ���\n";
				waitContinue();
			}
			else
			{
				journal.print();
				cout << "����� ������, ������� ����� ��������:\n~~>";
				int num = Exam::inputInRange(1, journal.getSize());
				journal.change(num);
			}
			break;
		}
		case 6:
		{
			findMenu(journal);
			break;
		}
		case 7:
		{
			findMenuBinary(journal);
			break;
		}
		case 8:
		{
			findNoteMenu(journal);
			break;
		}
		case 9:
		{
			findNoteMenuBinary(journal);
			break;
		}
		case 10:
		{
			taskMenu(journal);
			break;
		}
		case 0:
			return;
		}
	}
}


void iteratorMenu(Journal<Exam>& journal)
{
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "\n <~~ ����������� ���� ~~>\n\n";
		cout << "[1] ������� ������ � �������\n";
		cout << "[2] ������� ������ � ����\n";
		cout << "[3] ������ ������ � �������\n";
		cout << "[4] ������� ������ � �����\n";
		cout << "[0] ������ � ������� ����\n~~>";
		choice = Exam::inputInRange(0, 4);
		switch (choice)
		{
		case 1:
		{
			journal.print(cout);
			break;
		}
		case 2:
		{
			cout << "\n������� �������� �����:\n~~>";
			string fileName;
			cin >> fileName;
			ofstream f(fileName);
			journal.print(f);
			f.close();

			break;
		}
		case 3:
		{
			cout << "\n������� �������� �� ������� ���� (ctrl+D - ���������� ����)\n";
			cout << "����, ������, �������, �. �������, ����������, ������\n~~>";
			journal.addNoteIter(cin);
			break;
		}
		case 4:
		{
			cout << "\n������� �������� �����:\n~~>";
			string fileName;
			cin >> fileName;
			ifstream f(fileName);
			if (!f.is_open())
			{
				cout << "�� ������� ������� ����\n";
				break;
			}
			journal.addNoteIter(f);
			f.close();
			break;
		}
		case 0:
			return;
		}
		waitContinue();
	}
}


void findMenu(Journal<Exam>& journal)
{
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "\n <~~ ���� ������ ~~>\n\n�� ������ ��������� ����� �������� ����� ������?\n";
		cout << "[1] ������\n";
		cout << "[2] �����\n";
		cout << "[3] ������ �������� ������\n";
		cout << "[4] �������\n";
		cout << "[5] �������\n";
		cout << "[0] ����� � ������� ����\n\n~~>";
		choice = Exam::inputInRange(0, 5);
		switch (choice)
		{
		case 1:
		{
			cout << "������� ��� ������:\n~~>";
			int code = Exam::inputInt();
			printFoundedResult(journal.find([code](Exam e) {return e.getCodeOfGroupe() == code; }));
			break;
		}
		case 2:
		{
			cout << "������� ����� �����:\n~~>";
			int course = Exam::inputInt();
			printFoundedResult(journal.find([course](Exam e) {return e.getCourse() == course; }));
			break;
		}
		case 3:
		{
			cout << "������� ����� �������� ������:\n~~>";
			int number = Exam::inputInt();
			printFoundedResult(journal.find([number](Exam e) {return e.getRecordBookNumber() == number; }));
			break;
		}
		case 4:
		{
			cout << "������� ������� ��������:\n~~>";
			string surname;
			cin >> surname;
			printFoundedResult(journal.find([surname](Exam e) {return e.getStudentSurname() == surname; }));
			break;
		}
		case 5:
		{
			cout << "������� ������ ��������:\n~~>";
			int mark = Exam::inputInt();
			printFoundedResult(journal.find([mark](Exam e) {return e.getMark() == mark; }));
			break;
		}
		case 0:
			return;
		}
		waitContinue();
	}
}


void findMenuBinary(Journal<Exam>& journal)
{
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "\n <~~ ���� ��������� ������ ~~>\n\n�� ������ ��������� ����� �������� ����� ������?\n";
		cout << "[1] ������\n";
		cout << "[2] �����\n";
		cout << "[3] ������ �������� ������\n";
		cout << "[4] �������\n";
		cout << "[5] �������\n";
		cout << "[0] ����� � ������� ����\n\n~~>";
		choice = Exam::inputInRange(0, 5);
		switch (choice)
		{
		case 1:
		{
			cout << "������� ��� ������:\n~~>";
			int code = Exam::inputInt();
			Exam pred;
			pred.setCodeOfGroupe(code);
			printFoundedResult(journal.findBinary(codeCmp, pred));
			break;
		}
		case 2:
		{
			cout << "������� ����� �����:\n~~>";
			int course = Exam::inputInt();
			Exam pred;
			pred.setCourse(course);
			printFoundedResult(journal.findBinary(courseCmp, pred));
			break;
		}
		case 3:
		{
			cout << "������� ����� �������� ������:\n~~>";
			int number = Exam::inputInt();
			Exam pred;
			pred.setRecordBookNumber(number);
			printFoundedResult(journal.findBinary(bookNumberCmp, pred));
			break;
		}
		case 4:
		{
			cout << "������� ������� ��������:\n~~>";
			string surname;
			cin >> surname;
			Exam pred;
			pred.setStudentSurname(surname);
			printFoundedResult(journal.findBinary(surnameCmp, pred));
			break;
		}
		case 5:
		{
			cout << "������� ������ ��������:\n~~>";
			int mark = Exam::inputInt();
			Exam pred;
			pred.setMark(mark);
			printFoundedResult(journal.findBinary(markCmp, pred));
			break;
		}
		case 0:
			return;
		}
		waitContinue();
	}
}


void noteSubMenu(Journal<Exam>& journal)
{
	int choice = -1;
	while (choice != 0)
	{
		cout << "\n <~~ ������� ~~>\n\n";
		cout << "[1] ������� ������� � �������\n";
		cout << "[2] ������� ������� � ����\n";
		cout << "[0] ������ � ������� ����\n~~>";
		choice = Exam::inputInRange(0, 2);
		switch (choice)
		{
		case 1:
		{
			journal.print();
			break;
		}
		case 2:
		{
			cout << "\n������� �������� �����:\n~~>";
			string fileName;
			cin >> fileName;
			ofstream f(fileName);
			journal.print(f);
			f.close();
			break;
		}
		case 0:
			return;
		}
	}
}


void findNoteMenu(Journal<Exam>& journal)
{
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "\n <~~ ���� ������ ������� ~~>\n\n�� ������ ��������� ����� �������� ����� ������?\n";
		cout << "[1] ������\n";
		cout << "[2] �����\n";
		cout << "[3] ������ �������� ������\n";
		cout << "[4] �������\n";
		cout << "[5] �������\n";
		cout << "[0] ����� � ������� ����\n\n~~>";
		choice = Exam::inputInRange(0, 5);
		switch (choice)
		{
		case 1:
		{
			cout << "������� ��� ������:\n~~>";
			int code = Exam::inputInt();
			Journal<Exam> result = journal.noteFind([code](Exam e) {return e.getCodeOfGroupe() == code; });
			noteSubMenu(result);
			break;
		}
		case 2:
		{
			cout << "������� ����� �����:\n~~>";
			int course = Exam::inputInt();
			Journal<Exam> result = journal.noteFind([course](Exam e) {return e.getCourse() == course; });
			noteSubMenu(result);
			break;
		}
		case 3:
		{
			cout << "������� ����� �������� ������:\n~~>";
			int number = Exam::inputInt();
			Journal<Exam> result = journal.noteFind([number](Exam e) {return e.getRecordBookNumber() == number; });
			noteSubMenu(result);
			break;
		}
		case 4:
		{
			cout << "������� ������� ��������:\n~~>";
			string surname;
			cin >> surname;
			Journal<Exam> result = journal.noteFind([surname](Exam e) {return e.getStudentSurname() == surname; });
			noteSubMenu(result);
			break;
		}
		case 5:
		{
			cout << "������� ������ ��������:\n~~>";
			int mark = Exam::inputInt();
			Journal<Exam> result = journal.noteFind([mark](Exam e) {return e.getMark() == mark; });
			noteSubMenu(result);
			break;
		}
		case 0:
			return;
		}
	}
}


void findNoteMenuBinary(Journal<Exam>& journal)
{
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "\n <~~ ���� ��������� ������ ������� ~~>\n\n�� ������ ��������� ����� �������� ����� ������?\n";
		cout << "[1] ������\n";
		cout << "[2] �����\n";
		cout << "[3] ������ �������� ������\n";
		cout << "[4] �������\n";
		cout << "[5] �������\n";
		cout << "[0] ����� � ������� ����\n\n~~>";
		choice = Exam::inputInRange(0, 5);
		switch (choice)
		{
		case 1:
		{
			cout << "������� ��� ������:\n~~>";
			int code = Exam::inputInt();
			Exam pred;
			pred.setCodeOfGroupe(code);
			Journal<Exam> result = journal.noteFindBinary(codeCmp, pred);
			noteSubMenu(result);
			break;
		}
		case 2:
		{
			cout << "������� ����� �����:\n~~>";
			int course = Exam::inputInt();
			Exam pred;
			pred.setCourse(course);
			Journal<Exam> result = journal.noteFindBinary(courseCmp, pred);
			noteSubMenu(result);
			break;
		}
		case 3:
		{
			cout << "������� ����� �������� ������:\n~~>";
			int number = Exam::inputInt();
			Exam pred;
			pred.setRecordBookNumber(number);
			Journal<Exam> result = journal.noteFindBinary(bookNumberCmp, pred);
			noteSubMenu(result);
			break;
		}
		case 4:
		{
			cout << "������� ������� ��������:\n~~>";
			string surname;
			cin >> surname;
			Exam pred;
			pred.setStudentSurname(surname);
			Journal<Exam> result = journal.noteFindBinary(surnameCmp, pred);
			noteSubMenu(result);
			break;
		}
		case 5:
		{
			cout << "������� ������ ��������:\n~~>";
			int mark = Exam::inputInt();
			Exam pred;
			pred.setMark(mark);
			Journal<Exam> result = journal.noteFindBinary(markCmp, pred);
			noteSubMenu(result);
			break;
		}
		case 0:
			return;
		}
	}
}


void taskMenu(Journal<Exam>& journal)
{

	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "\n <~~ ���� ���������� �������� ����� ~~>\n\n�� ������ ��������� ����� ��������� ���������� �������� �����?\n";
		cout << "[1] ����������\n";
		cout << "[2] ������\n";
		cout << "[3] �����\n";
		cout << "[0] ������ � ������� ����\n~~>";
		choice = Exam::inputInRange(0, 3);
		switch (choice)
		{
		case 1:
		{
			cout << "������� �������� ����������:\n~~>";
			string subject;
			cin >> subject;
			cout << journal.findSrBall([subject](Exam e) {return e.getSubject() == subject; });
			break;
		}
		case 2:
		{
			cout << "������� ��� ������:\n~~>";
			int code = Exam::inputInt();
			cout << journal.findSrBall([code](Exam e) {return e.getCodeOfGroupe() == code; });
			break;
		}
		case 3:
		{
			cout << "������� ����� �����:\n~~>";
			int course = Exam::inputInt();
			cout << journal.findSrBall([course](Exam e) {return e.getCourse() == course; });
			break;
		}
		case 0:
			return;
		}
		waitContinue();
	}
}


bool codeCmp(Exam f, Exam s)
{
	return f.getCodeOfGroupe() < s.getCodeOfGroupe();
}

bool courseCmp(Exam f, Exam s)
{
	return f.getCourse() < s.getCourse();
}

bool bookNumberCmp(Exam f, Exam s)
{
	return f.getRecordBookNumber() < s.getRecordBookNumber();
}

bool surnameCmp(Exam f, Exam s)
{
	return f.getStudentSurname() < s.getStudentSurname();
}

bool markCmp(Exam f, Exam s)
{
	return f.getMark() < s.getMark();
}


void printFoundedResult(bool isFind)
{
	if (isFind)
		cout << "������ �������\n";
	else
		cout << "������ ���\n";
}

void waitContinue()
{
	cout << "\n <~~ ����� ���������� ������� ENTER ~~>";
	cin.ignore();
	cin.get();
}