#pragma once
#include "Exam.h"


template <typename T>
class Journal
{
private:
	vector<T> journal;
public:
	void print()
	{
		if (journal.size() == 0)
			cout << "Записей нет\n";
		int cnt = 1;;
		for (auto it : journal)
			cout << "\nЗапись номер " << cnt++ << "\n" << it << '\n';
	}
	
	void addNote (T exam)
	{
		journal.emplace_back(exam);
	}

	void print(ostream_iterator<T> out)
	{
		for (auto it : journal) *out++ = it;
	}

	void addNoteIter(istream_iterator<T> in)
	{
		istream_iterator<T> i;
		while (in != i)
			journal.emplace_back(*in++);
	}

	void deleteNote(int cnt)
	{
		journal.erase(journal.begin() + cnt - 1;);
	}

	void change(int cnt)
	{
		(journal.begin() + cnt - 1;)->change();
	}

	template<typename Func>
	bool find(Func func)
	{
		return find_if(journal.begin(), journal.end(), func) != journal.end();
	}

	bool findBinary(bool(*cmp)(T, T), Exam exam)
	{
		sort(journal.begin(), journal.end(), cmp);
		return binary_search(journal.begin(), journal.end(), exam, cmp);
	}

	template<typename Func>
	Journal<T> noteFind(Func func)
	{
		Journal<T> result;
		auto left = journal.begin();
		auto right = journal.end();
		while (left != right)
		{
			left = find_if(left, right, func);
			if (left != right)
			{
				result.addNote(*left);
				left++;
			}
		}
		return result;
	}

	template<typename Func>
	double findSrBall(Func func)
	{
		auto left = journal.begin();
		auto right = journal.end();
		double res = 0;
		double cnt = 0;
		while (left != right)
		{
			left = find_if(left, right, func);
			if (left != right)
			{
				res += left->getMark();
				cnt++;
				left++;
			}
		}
		if (cnt == 0)
			return -1;
		return res / cnt;
	}
	
	Journal<T> noteFindBinary(bool (*cmp)(T, T), T val)
	{
		Journal<T> result;
		sort(journal.begin(), journal.end(), cmp);
		pair<vector<T>::iterator, vector<T>::iterator> bounds;
		bounds = equal_range(journal.begin(), journal.end(), val, cmp);
		while (bounds.first != bounds.second)
		{
			result.addNote(*bounds.first);
			bounds.first++;
		}
		return result;
	}

	int getSize()
	{
		return journal.size();
	}
};