#pragma once
// Загоровский Анатолий 9 группа 2 курс
// B2 Разделить каждое число на полусумму первого отрицательного и K-го числа.

#include<iostream>
#include<deque>
#include<algorithm>
#include<iterator>
#include<time.h>
#include<fstream>

using namespace std;

ifstream fillFileWithRandomNumbersCycle(string fileName, const int N, const int M); // 1
ifstream fillFileWithRandomNumbersGenerate(string fileName, const int N, const int M); // 1
deque<double> fillContainerFromFile(ifstream& file); // 2 

double findFirstNegativeNumber(deque<double>::iterator begin, deque<double>::iterator end);
deque<double> modify(deque<double>& deq, double K); // 3
void modify(deque<double>::iterator, deque<double>::iterator, double K); // 4
deque<double> modifyTransform(deque<double>& deq, double K); // 5
deque<double> modifyForEach(deque<double>& deq, double K); // 6
double sum(deque<double>::iterator begin, deque<double>::iterator end); // 7
double average(deque<double>::iterator begin, deque<double>::iterator end); // 7
ostream& operator<<(ostream&, deque<double>&); // 8