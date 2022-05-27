#include "Exam.h"


Exam::Exam()
{
	course = 0;
	codeOfGroupe = 0;
	studentSurname = "";
	recordBookNumber = 0;
	subject = "";
	mark = 0;
}


Exam::Exam(const Exam& exam)
{
	course = exam.course;
	codeOfGroupe = exam.codeOfGroupe;
	studentSurname = exam.studentSurname;
	recordBookNumber = exam.recordBookNumber;
	subject = exam.subject;
	mark = exam.mark;
}


bool Exam::operator==(Exam& otherExam)
{
	if (course == otherExam.course &&
		codeOfGroupe == otherExam.codeOfGroupe &&
		studentSurname == otherExam.studentSurname &&
		recordBookNumber == otherExam.recordBookNumber &&
		subject == otherExam.subject &&
		mark == otherExam.mark)
		return true;
	return false;
}


Exam& Exam::operator=(Exam const& exam)
{
	course = exam.course;
	codeOfGroupe = exam.codeOfGroupe;
	studentSurname = exam.studentSurname;
	recordBookNumber = exam.recordBookNumber;
	subject = exam.subject;
	mark = exam.mark;
	return *this;
}


void Exam::fill()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	cout << "Курс:\n~~>";
	course = inputInRange(0, 6);

	cout << "Код группы:\n~~>";
	codeOfGroupe = inputInt();

	cout << "Фамилия студента:\n~~>";
	cin >> studentSurname;

	cout << "Номер зачетной книжки:\n~~>";
	recordBookNumber = inputInt();

	cout << "Дисциплина:\n~~>";
	cin >> subject;

	cout << "Оценка по дисциплине:\n~~>";
	mark = inputInRange(2, 5);
}


void Exam::change()
{
	int choice = -1;
	while (choice != 0)
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Что вы хотите изменить?\n";
		cout << "[1] Курс\n";
		cout << "[2] Код группы\n";
		cout << "[3] Фамилию студента\n";
		cout << "[4] Номер зачетной книжки\n";
		cout << "[5] Дисциплину\n";
		cout << "[6] Оценку по дисциплине\n";
		cout << "[0] Возрат в главное меню\n~~>";
		choice = inputInRange(0,6);
		switch (choice)
		{
		case 1:
		{
			cout << "Новый курс:\n~~>";
			course = inputInRange(0, 6);
			break;
		}
		case 2:
		{
			cout << "Новый код группы:\n~~>";
			codeOfGroupe = inputInt();
			break;
		}
		case 3:
		{
			cout << "Новая фамилия студента:\n~~>";
			cin >> studentSurname;
			break;
		}
		case 4:
		{
			cout << "Новый номер зачетной книжки:\n~~>";
			recordBookNumber = inputInt();
			break;
		}
		case 5:
		{
			cout << "Новая дисциплина:\n~~>";
			cin >> subject;
			break;
		}
		case 6:
		{
			cout << "Новая оценка по дисциплине:\n~~>";
			mark = inputInRange(2, 5);
			break;
		}
		}
	}
}


void Exam::setCodeOfGroupe(int num)
{
	codeOfGroupe = num;
}


void Exam::setCourse(int num)
{
	course = num;
}


void Exam::setRecordBookNumber(int num)
{
	recordBookNumber = num;
}


void Exam::setStudentSurname(string str)
{
	studentSurname = str;
}


void Exam::setMark(int num)
{
	mark = num;
}


int Exam::getCodeOfGroupe()
{
	return codeOfGroupe;
}


int Exam::getCourse()
{
	return course;
}


int Exam::getRecordBookNumber()
{
	return recordBookNumber;
}


string Exam::getStudentSurname()
{
	return studentSurname;
}

string Exam::getSubject()
{
	return subject;
}

int Exam::getMark()
{
	return mark;
}


bool operator==(const Exam& first, const Exam& second)
{
	if (first.course == second.course &&
		first.codeOfGroupe == second.codeOfGroupe &&
		first.studentSurname == second.studentSurname &&
		first.recordBookNumber == second.recordBookNumber &&
		first.subject == second.subject &&
		first.mark == second.mark)
		return true;
	return false;
}


ostream& operator<<(ostream& out, const Exam& exam)
{
	out << "Курс: " << exam.course << '\n';
	out << "Код группы: " << exam.codeOfGroupe << '\n';
	out << "Фамилия студента: " << exam.studentSurname << '\n';
	out << "Номер зачетной книжки: " << exam.recordBookNumber << '\n';
	out << "Дисциплина: " << exam.subject << '\n';
	out << "Оценка по дисциплине: " << exam.mark << '\n';
	return out;
}


istream& operator>>(istream& in, Exam& exam)
{
	in >> exam.course;
	in >> exam.codeOfGroupe;
	in >> exam.studentSurname;
	in >> exam.recordBookNumber;
	in >> exam.subject;
	in >> exam.mark;
	return in;
}


int Exam::inputInRange(int left, int right)
{
	int res;
	cin >> res;
	while (!cin.good() || res < left || res > right)
	{
		cin.clear();
		cin.ignore(255, '\n');
		cout << "Значение было введено некорректно\nВведите значение в диапозоне от " << left << " до " << right << "\n~~>";
		cin >> res;
	}
	return res;
}


int Exam::inputInt()
{
	int res;
	cin >> res;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(255, '\n');
		cout << "Значение было введено некорректно\nВведите целое число\n~~>";
		cin >> res;
	}
	return res;
}
