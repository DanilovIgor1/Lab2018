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
	//Код дисциплины
	int SubjectID;
	//Наименование дисциплины
	string SubjectName;
	//Фамилия преподавателя
	string TeachersSurname;
	//Код группы
	int GroupID;
	//Кол-во студентов в группе
	int AmountOfStudents;
	//Кол-во часов лекций
	double HoursOfLectures;
	//Кол-во часов практики
	double HoursOfPractice;
	//Наличие курсовой работы
	bool CourseWork;
	//Вид итогового контроля
	string KindOfControl;


	int typesearch;

	//конструктор по умолчанию
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

	//Изменение структуры "Университет"
	University ChangeUniversity(University &result)
	{
		setlocale(LC_ALL, "Russian");
		int num = InputNumber(0, 9, "Что хотите изменить\n1 - Код дисциплины\n2 - Наименование дисциплины\n3 - Фамилия преподавателя\n4 - Код группы\n5 - Количество студентов\n6 - Количество часов лекций\n7 - Количество часов практики\n8 - Наличие курсовой работы\n9 - Вид контроля\n - Отмена\n");
		switch (num)
		{
		case 1:
			result.SubjectID = InputNumber(0, 999999, "Введите новый код Дисциплины (1-10): ");
			break;
		case 2:
			result.SubjectName = InputInformation("Введите новое название предмета: ");
			break;
		case 3:
			result.TeachersSurname = InputInformation("Введите фамилию нового преподавателяа: ");
			break;
		case 4:
			result.GroupID = InputNumber(1, 100, "Введите новый код группы (1-10): ");
			break;
		case 5:
			result.AmountOfStudents = InputNumber(0, 40, "Введите новое кол-во студентов : ");
			break;
		case 6:
			result.HoursOfLectures = InputNumber(0, 200, "Введите новое кол-во часов лекций ");
			break;
		case 7:
			result.HoursOfPractice = InputNumber(0, 150, "Введите новое кол-во часов практики: ");
			break;
		case 8:
			result.CourseWork = InputNumber(0, 1, "Введите новое значение наличия курсовой работы (1 - Yes/0 - No): ");
			break;
		case 9:
			result.KindOfControl = InputInformation("Введите новый вид контроля (зачет/экзамен): ");
			break;
		default:
			break;
		}
		return result;
	}

	//Перегруженный оператор равенства для структуры "Университет"
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

	//Поиск равного элемента по выбранному критерию
	/*type_search - тип поиска
	1 - Фамилия преподавателя
	2 - Код группы
	3 - Наличие курсовой
	4 - вид итогового контроля*/
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

//Функция ввода структуры "Университет" с консоли
University InputScreenUniversity()
{
	setlocale(LC_ALL, "Russian");
	University c;
	c.SubjectID = InputNumber(0, 999999, "Введите код дисциплины (1-20): ");
	c.SubjectName = InputInformation("Введите название дисциплины: ");
	c.TeachersSurname = InputInformation("Введите фамилию преподавателя: ");
	c.GroupID = InputDoubleNumber(1, 100, "Введите код группы(1-10): ");
	c.AmountOfStudents = InputNumber(0, 40, "Введите кол-во студентов: ");
	c.HoursOfLectures = InputNumber(0, 200, "Введите кол-во часов лекций: ");
	c.HoursOfPractice = InputNumber(0, 150, "Введите кол-во часов практики: ");
	c.CourseWork = InputNumber(0, 1, "Есть ли курсовая работа(1 - Да/0 - Нет): ");
	c.KindOfControl = InputInformation("Введите вид контроля(зачет/экзамен): ");

	return c;
}

//Функция вывода структуры "Университет на консоль
void OutputScreenUniversity(University c)
{
	setlocale(LC_ALL, "Russian");
	cout << "Код дисциплины: " << c.SubjectID << endl;
	cout << "Название дисциплины: " << c.SubjectName << endl;
	cout << "Фамилия преподавателя: " << c.TeachersSurname << endl;
	cout << "Код группы: " << c.GroupID << endl;
	cout << "Кол-во студентов: " << c.AmountOfStudents << endl;
	cout << "Кол-во часов лекций: " << c.HoursOfLectures << endl;
	cout << "Кол-во часов практики: " << c.HoursOfPractice << endl;
	cout << "Наличие курсовой работы: " << c.CourseWork << endl;
	cout << "Вид контроля: " << c.KindOfControl << endl;
}

//Перевод структуры "Университет" в строку
string ToString(University c, int i)
{
	string result = "Запись № " + to_string(i) + "\r\n" + "Код дисциплины: " + to_string(c.SubjectID) + "\r\n" + "Название дисциплины: " + c.SubjectName + "\r\n" + "Фамилия преподавателя: " + c.TeachersSurname + "\r\n" + "Код группы: " + to_string(c.GroupID) + "\r\n" + "Кол-во студентов: " + to_string(c.AmountOfStudents) + "\r\n" + "Кол-во часов лекций: " + to_string(c.HoursOfLectures) + "\r\n" + "Кол-во часов практики: " + to_string(c.HoursOfPractice) + "\r\n" + "Наличие курсовой работы: " + to_string(c.CourseWork) + "\r\n" + "Вид контроля: " + c.KindOfControl + "\r\n";
	return result;
}

//Считывание структуры "Университет" из строки
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
			string wrd = "Код дисциплины(1-20): ";
			result.SubjectID = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Название дисциплины ";
			result.SubjectName = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Фамилия преподавателя: ";
			result.TeachersSurname = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Код группы(1-9): ";
			result.GroupID = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Кол-во студентов: ";
			result.AmountOfStudents = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Кол-во часов лекций: ";
			result.HoursOfLectures = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Кол-во часов практики: ";
			result.HoursOfPractice = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Наличие курсовой работы(1-Да/0-Нет): ";
			result.CourseWork = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Вид итогового контроля(зачет/экзамен): ";
			result.KindOfControl = s.substr(wrd.length(), s.length()).c_str();
		}
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}

//Ввод критерия поиска в зависимости от выбранного типа
University InputChangeTypeSearch(int type_search)
{
	setlocale(LC_ALL, "Russian");
	University result;
	switch (type_search)
	{
	case 1:
		result.TeachersSurname = InputInformation("Введите имя преподавателя: ");
		return result;
	case 2:
		result.GroupID = InputNumber(1, 100, "Введите код группы(1-10):");
		return result;
	case 3:
		result.CourseWork = InputNumber(0, 1, "Введите наличие курсовой работы (1 - Yes/0 - No): ");
		return result;
	case 4:
		result.KindOfControl = InputInformation("Введите вид контроля (зачет/экзамен): ");
		return result;
	default:
		return result;
	}
}

//Сравнение структур в зависимости от выбранного поля для сортировки
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
