#pragma once
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

using namespace std;

class University {
public:
	//��� ����������
	int SubjectID;
	//������������ ����������
	string SubjectName;
	//������� �������������
	string TeachersSurname;
	//��� ������
	int GroupID;
	//���-�� ��������� � ������
	int AmountOfStudents;
	//���-�� ����� ������
	double HoursOfLectures;
	//���-�� ����� ��������
	double HoursOfPractice;
	//������� �������� ������
	bool CourseWork;
	//��� ��������� ��������
	string KindOfControl;


	int typesearch;

	//����������� �� ���������
	University()
	{
		int SubjectID = 0;
		string SubjectName = "";
		string TeachersSurname = "";
		int GroupID = 0;
		int AmountOfStudents = 0;
		double HoursOfLectures = 0;
		double HoursOfPractice = 0;
		string CourseWork = "";
		string KindOfControl = "";
	}

	//��������� ��������� "�����������"
	University ChangeUniversity(University &result)
	{
		setlocale(LC_ALL, "Russian");
		int num = InputNumber(0, 9, "��� ������ ��������\n1 - ��� ����������\n2 - ������������ ����������\n3 - ������� �������������\n4 - ��� ������\n5 - ���������� ���������\n6 - ���������� ����� ������\n7 - ���������� ����� ��������\n8 - ������� �������� ������\n9 - ��� ��������\n - ������\n");
		switch (num)
		{
		case 1:
			result.SubjectID = InputNumber(0, 999999, "������� ����� ��� ���������� (1-10): ");
			break;
		case 2:
			result.SubjectName = InputInformation("������� ����� �������� ��������: ");
			break;
		case 3:
			result.TeachersSurname = InputInformation("������� ������� ������ ��������������: ");
			break;
		case 4:
			result.GroupID = InputNumber(1, 100, "������� ����� ��� ������ (1-10): ");
			break;
		case 5:
			result.AmountOfStudents = InputNumber(0, 40, "������� ����� ���-�� ��������� : ");
			break;
		case 6:
			result.HoursOfLectures = InputNumber(0, 200, "������� ����� ���-�� ����� ������ ");
			break;
		case 7:
			result.HoursOfPractice = InputNumber(0, 150, "������� ����� ���-�� ����� ��������: ");
			break;
		case 8:
			result.CourseWork = InputNumber(0, 1, "������� ����� �������� ������� �������� ������ (1 - Yes/0 - No): ");
			break;
		case 9:
			result.KindOfControl = InputInformation("������� ����� ��� �������� (�����/�������): ");
			break;
		default:
			break;
		}
		return result;
	}

	//������������� �������� ��������� ��� ��������� "�����������"
	University& operator = (University c)
	{
		SubjectID = c.SubjectID;
		SubjectName = c.SubjectName;
		TeachersSurname = c.TeachersSurname;
		GroupID = c.GroupID;
		AmountOfStudents = c.AmountOfStudents;
		HoursOfLectures = c.HoursOfLectures;
		HoursOfPractice = c.HoursOfPractice;
		CourseWork = c.CourseWork;
		KindOfControl = c.KindOfControl;

		return (*this);
	}

	//����� ������� �������� �� ���������� ��������
	/*type_search - ��� ������
	1 - ������� �������������
	2 - ��� ������
	3 - ������� ��������
	4 - ��� ��������� ��������*/
	bool SearchElement(University second)
	{
		switch (typesearch)
		{
		case 1:
			return ((*this).TeachersSurname == second.TeachersSurname);
		case 2:
			return ((*this).GroupID == second.GroupID);
		case 3:
			return ((*this).CourseWork == second.CourseWork);
		case 4:
			return ((*this).KindOfControl == second.KindOfControl);
		default:
			return false;
		}
	}

};

//������� ����� ��������� "�����������" � �������
University InputScreenUniversity()
{
	setlocale(LC_ALL, "Russian");
	University c;
	c.SubjectID = InputNumber(0, 999999, "������� ��� ���������� (1-20): ");
	c.SubjectName = InputInformation("������� �������� ����������: ");
	c.TeachersSurname = InputInformation("������� ������� �������������: ");
	c.GroupID = InputDoubleNumber(1, 100, "������� ��� ������(1-10): ");
	c.AmountOfStudents = InputNumber(0, 40, "������� ���-�� ���������: ");
	c.HoursOfLectures = InputNumber(0, 200, "������� ���-�� ����� ������: ");
	c.HoursOfPractice = InputNumber(0, 150, "������� ���-�� ����� ��������: ");
	c.CourseWork = InputNumber(0, 1, "���� �� �������� ������(1 - ��/0 - ���): ");
	c.KindOfControl = InputInformation("������� ��� ��������(�����/�������): ");

	return c;
}

//������� ������ ��������� "����������� �� �������
void OutputScreenUniversity(University c)
{
	setlocale(LC_ALL, "Russian");
	cout << "��� ����������: " << c.SubjectID << endl;
	cout << "�������� ����������: " << c.SubjectName << endl;
	cout << "������� �������������: " << c.TeachersSurname << endl;
	cout << "��� ������: " << c.GroupID << endl;
	cout << "���-�� ���������: " << c.AmountOfStudents << endl;
	cout << "���-�� ����� ������: " << c.HoursOfLectures << endl;
	cout << "���-�� ����� ��������: " << c.HoursOfPractice << endl;
	cout << "������� �������� ������: " << c.CourseWork << endl;
	cout << "��� ��������: " << c.KindOfControl << endl;
}

//������� ��������� "�����������" � ������
string ToString(University c, int i)
{
	string result = "������ � " + to_string(i) + "\r\n" + "��� ����������: " + to_string(c.SubjectID) + "\r\n" + "�������� ����������: " + c.SubjectName + "\r\n" + "������� �������������: " + c.TeachersSurname + "\r\n" + "��� ������: " + to_string(c.GroupID) + "\r\n" + "���-�� ���������: " + to_string(c.AmountOfStudents) + "\r\n" + "���-�� ����� ������: " + to_string(c.HoursOfLectures) + "\r\n" + "���-�� ����� ��������: " + to_string(c.HoursOfPractice) + "\r\n" + "������� �������� ������: " + to_string(c.CourseWork) + "\r\n" + "��� ��������: " + c.KindOfControl + "\r\n";
	return result;
}

//���������� ��������� "�����������" �� ������
University ReadFromString(ifstream& input)
{
	setlocale(LC_ALL, "Russian");
	University result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ����������(1-20): ";
			result.SubjectID = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "�������� ���������� ";
			result.SubjectName = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� �������������: ";
			result.TeachersSurname = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ������(1-9): ";
			result.GroupID = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���-�� ���������: ";
			result.AmountOfStudents = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���-�� ����� ������: ";
			result.HoursOfLectures = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���-�� ����� ��������: ";
			result.HoursOfPractice = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� �������� ������(1-��/0-���): ";
			result.CourseWork = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ��������� ��������(�����/�������): ";
			result.KindOfControl = s.substr(wrd.length(), s.length()).c_str();
		}
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}

//���� �������� ������ � ����������� �� ���������� ����
University InputChangeTypeSearch(int type_search)
{
	setlocale(LC_ALL, "Russian");
	University result;
	switch (type_search)
	{
	case 1:
		result.TeachersSurname = InputInformation("������� ��� �������������: ");
		return result;
	case 2:
		result.GroupID = InputNumber(1, 100, "������� ��� ������(1-10):");
		return result;
	case 3:
		result.CourseWork = InputNumber(0, 1, "������� ������� �������� ������ (1 - Yes/0 - No): ");
		return result;
	case 4:
		result.KindOfControl = InputInformation("������� ��� �������� (�����/�������): ");
		return result;
	default:
		return result;
	}
}

//��������� �������� � ����������� �� ���������� ���� ��� ����������
int Sort(University first, University second, int type_search)
{
	switch (type_search)
	{
	case 1:
		if (first.TeachersSurname > second.TeachersSurname) return 1;
		else if (first.TeachersSurname < second.TeachersSurname) return -1;
		else return 0;
	case 2:
		if (first.GroupID > second.GroupID) return 1;
		else if (first.GroupID < second.GroupID) return -1;
		else return 0;
	case 3:
		if (first.CourseWork > second.CourseWork) return 1;
		else if (first.CourseWork < second.CourseWork) return -1;
		else return 0;
	case 4:
		if (first.KindOfControl > second.KindOfControl) return 1;
		else if (first.KindOfControl < second.KindOfControl) return -1;
		else return 0;
	default:
		return -2;
	}
}
