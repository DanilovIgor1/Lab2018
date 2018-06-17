#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "University.h"
#include "HelpUtils.h"

using namespace std;


template <typename University>
struct iterator {
	University *ptr;
	iterator(University* ptr_ = 0) : ptr(ptr_) {}
	University& operator*() { return *ptr; }
	University* operator->() { return ptr; }
	University* operator++() { return ++ptr; }
	University* operator--() { return --ptr; }
	bool operator==(const iterator& other) const { return ptr == other.ptr; }
	bool operator!=(const iterator& other) const { return !(*this == other); }
};

template <class Type>
class Task {
private:
	//���������� �� ��������� ��������
	//int (*Compare)(Type, Type, int) - ��������� �� �������, ������� ���������� ������� ��-�� � ������� �� Type_search
	void Shell_Sort(int n, int typ, int(*Compare)(Type, Type, int))
	{
		int i, j;
		University tmp;
		for (int step = n / 2; step > 0; step /= 2)
		{
			for (i = step; i < n; i++)
			{
				tmp = vect[i];
				for (j = i; j >= step; j -= step)
				{
					if ((Compare(tmp, vect[j - step], typ) == -1))
						vect[j] = vect[j - step];
					else
						break;
				}
				vect[j] = tmp;
			}
		}
	}

	//�������� �����
	int Binary_Search_Element(int left, int right, int Type_search, Type d, int(*Compare)(Type, Type, int))
	{
		int middle = 0;
		while (1)
		{
			middle = (left + right) / 2;
			if (Compare(d, vect[middle], Type_search) == -1) //���� ������� ������ �������� � ������
				right = middle - 1;	//������� ������ ������� ������
			else if (Compare(d, vect[middle], Type_search) == 1) //���� ������� ������ �������� � ������
				left = middle + 1;	//������� ������ ������� ������
			else                    //����� (�������� �����)
				return middle;		//������� ���������� ������ ������
			if (left > right) //���� ������� ����������
				return -1;
		}
	}

public:
	vector<Type> vect;
	Task() {}
	~Task() {}

	//�������� ��������
	void Remove(int num)
	{
		if (num != 0)
			vect.erase(vect.begin() + num - 1);
	}

	//���������� ��������
	void Add(Type elem)
	{
		vect.push_back(elem);
	}

	//������ �������
	int size()
	{
		return vect.size();
	}

	//�������� �� �������
	bool IsEmpty()
	{
		return (vect.size() == 0);
	}

	//����� � ����
	//void(*f)(Type) - ��������� �� �������, ������� ���������� ���� ��������� � ����
	void OutputFile(vector<Type> items, string(*f)(Type, int))
	{
		string filename = InputFileName();
		ofstream fout(filename);
		if (fout)
		{
			vector <University>::const_iterator pos;
			int count = 1;
			for (pos = items.begin(); pos != items.end(); pos++)
			{
				fout << f(*pos, count) << ' ';
				count++;
			}
			cout << endl << "���� ��������!" << endl;
			fout.close();
		}
		else
		{
			cout << "���� �� ��������!" << endl;
		}
	}

	//����� �� �����
	//void(*f)(Type) - ��������� �� �������, ������� ��������� ���� ��������� � ����
	void OutputScreen(vector<Type> items, void(*f)(Type))
	{
		vector<University>::const_iterator pos;
		int count = 1;
		for (pos = items.begin(); pos != items.end(); pos++)
		{
			cout << "������ � " << count << endl;
			f(*pos);
			count++;
		}
		cout << "����� ������!" << endl;
	}

	//���� �� �����
	//Type(*f)(ifstream&) - ��������� �� �������, ������� ��������� ���� ��������� �� ����� 
	bool ReadFromFile(Type(*f)(ifstream&))
	{
		string filename = InputFileName();
		ifstream input;
		input.open(filename);
		if (!input)
		{
			cout << "�� ������� ������� ����!" << endl;
			return false;
		}
		else
		{
			while (!input.eof())
			{
				vect.push_back(f(input));
			}
			vect.erase(vect.begin() + vect.size() - 1);
			input.close();
			return true;
		}
	}

	//���� � ������
	//Type(*f)() - ��������� �� �������, ������� ������ ���� ��������� � �������
	void ReadFromScreen(Type(*f)())
	{
		int n;
		Type elem;
		do
		{
			vect.push_back(f());
			n = InputNumber(0, 1, "�� ������ �������� �������? (1 - ��, 0 - ���) \n��� �����: ");
		} while (n != 0);
	}

	//�������� �����
	// bool(*Equal)(Type, Type, int) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � ������� �� Type_search
	vector<Type> LinearySearch(Type searchelem)
	{
		vector<Type> vctr;
		for (auto iter = vect.begin(); iter != vect.end(); iter++)
		{
			if (searchelem.SearchElement(*iter))
				vctr.push_back(*iter);
		}
		return vctr;
	}

	//�������� �����
	// int(*Compare)(Type, Type, int) - ��������� �� �������, ������� ���������� ������� ��-� � ������� �� Type_search 
	// bool(*Equal)(Type, Type, int) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � ������� �� Type_search
	vector<Type> BinarySearch(int Typesearch, Type findelem, int(*Compare)(Type, Type, int))
	{
		vector<Type> vctr;
		Shell_Sort(vect.size(), Typesearch, Compare);
		int left = 0;
		int right = vect.size();
		int index;
		if ((index = Binary_Search_Element(left, right - 1, Typesearch, findelem, Compare)) != -1)
		{
			vctr.push_back(vect[index]);
			int first_index = index;
			while ((++index < right) && findelem.SearchElement(vect[index]))
				vctr.push_back(vect[index]);
			while ((--first_index >= 0) && findelem.SearchElement(vect[first_index]))
				vctr.push_back(vect[first_index]);
		}
		return vctr;
	}

};