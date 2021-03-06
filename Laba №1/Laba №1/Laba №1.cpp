// Laba №1.cpp: определяет точку входа для консольного приложения.
//
#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
#include <cmath>
using namespace std;
//создание файла из рандомных значений с помощью цикла
ofstream CreateFileRand(string FileName, int N, int M) {
	ofstream fs(FileName);
	for (int i = 0; i < N; ++i) {

		int r = rand() % (2 * M + 1) - M;
		fs << r << " ";
	}
	fs.close();
	return fs;
}

//создание файла из рандомных значений с помощью generate
ofstream CreateFileGenerate(string FileName, int N, int M) {
	ofstream fs;
	fs.open(FileName);
	generate_n(std::ostream_iterator<int>(fs, " "), N, [M]() {int i = rand() % (2 * M + 1) - M; return i; });
	fs.close();
	return fs;
}

//загрузка из файла
deque<double> LoadFromFile(ifstream &fin) {
	deque<double> dec;
	if (!fin) {
		cout << "Файл не найден." << endl;
		return dec;
	}

	int a;
	if (!(fin >> a)) {
		cout << "Неверный формат данных" << endl;
		return dec;
	}
	if (fin.eof()) {
		cout << "Файл пуст." << endl;
	}
	else {
		while (!fin.eof()) {
			dec.push_back(a);

			if (!(fin >> a) && !fin.eof()) {
				cout << "Неверный формат данных" << endl;
				dec.clear();
				return dec;
			}
		}
	}
	return dec;
}

//преобразование дека (Разделить все числа на половину максимального из чисел) с циклом for
deque<double> Modify(deque<double> &dec1) {
	double max = 0;
	deque<double> dec = dec1;
	int len = dec.size();
	for (const double i : dec) {
		if (i > max) {
			max = i;
		}
	}
	max = max / 2;
	for (double &i : dec) {
		i = i / max;

	}
	return dec;
}

//преобразование дека (Разделить все числа на половину максимального из чисел) с итераторами
void Modify(deque<double>::iterator begin, deque<double>::iterator end) {
	double max = 0;
	for (deque<double>::iterator i = begin; i != end; i++) {
		if (*i > max) max = *i;
	}
	max = max / 2;
	for (deque<double>::iterator i = begin; i != end; i++) {
		*i = *i / max;
	}
}

//преобразование дека (Разделить все числа на половину максимального из чисел) с transform
void Modify_Transform(deque<double>::iterator begin, deque<double>::iterator end) {
	double max = 0;
	transform(begin, end, begin, [&max](double i) { if (i > max) max = i;	return i; });
	max = max / 2;
	transform(begin, end, begin, [max](double i) { max: i = i / max; return i;  });
}

//преобразование дека (Разделить все числа на половину максимального из чисел) с for_each
void Modify_For_Each(deque<double>::iterator begin, deque<double>::iterator end) {
	double max;
	for_each(begin, end, [&max](double i) { if (i > max) max = i; });
	max = max / 2;
	for_each(begin, end, [max](double &i) {i = i / max; });
}

//подсчет суммы элементов
double Summ(deque<double> dec) {
	double summ = 0;
	for_each(dec.begin(), dec.end(), [&summ](double i) {summ += i; });
	return summ;
}

//подсчет среднего арифметического
double MidArith(deque<double> &dec) {
	return (double)Summ(dec) / dec.size();
}

//печать в файл
void  Print(fstream &st, deque<double> &dec) {
	for_each(dec.begin(), dec.end(), [&st](double i) {st << i << " "; });
}

//перегруженный метод, печать в консоль
void  Print(ostream &st, deque<double> dec) {
	for_each(dec.begin(), dec.end(), [&st](double i) {st << i << " "; });
	st << endl;
}

//консольное меню
int Menu(int flag) {
	cout << "Menu:" << endl;
	cout << 1 << " - - - " << "Создать новый файл со случайной последовательностью чисел.(рандом)" << endl;
	cout << 2 << " - - - " << "Создать новый файл со случайной последовательностью чисел.(генерейт)" << endl;
	cout << 3 << " - - - " << "Загрузить последовательность из файла." << endl;
	if (flag > 0) {
		cout << 4 << " - - - " << "Разделить все числа на половину максимального из чисел.(с циклом for)" << endl;
		cout << 5 << " - - - " << "Разделить все числа на половину максимального из чисел.(с итератором)" << endl;
		cout << 6 << " - - - " << "Разделить все числа на половину максимального из чисел.(с transform)" << endl;
		cout << 7 << " - - - " << "Разделить все числа на половину максимального из чисел.(с for_each)" << endl;
		cout << 8 << " - - - " << "Вычислить сумму членов последовательности." << endl;
		cout << 9 << " - - - " << "Вычислить среднее арифметическое." << endl;
		cout << 10 << " - - - " << "Записать последовательность в файл." << endl;
		cout << 11 << " - - - " << "Напечатать последовательность." << endl;
	}
	cout << 0 << " - - - " << "Выход." << endl << endl;
	int res;
	while (!(cin >> res) || flag <= 0 && (res > 3) || (flag > 0) && (res > 11));
	return res;
}

//ввод ответа да/нет
bool InputQuery(string question) {
	cout << question << endl;
	cout << 1 << " - - - Да" << endl;
	cout << 0 << " - - - Нет" << endl;
	int res;
	while (!(cin >> res) || res != 0 && res != 1);
	return res == 1;
}

//ввод имени файла
string InputFileName() {
	string name;
	cout << "Введите имя файла" << endl;
	cin >> name;
	return name;
}

//ввод числа
int InputNum(string str) {
	int Num;
	do {
		cout << str << endl;
		while ((!(cin >> Num)) || cin.get() != '\n')
		{
			cout << "Неправильный ввод! Повторите снова." << endl;
			cin.clear();
			cin.sync();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << str << endl;
		}
	} while (Num <= 0);
	return Num;
}

int main() {
	setlocale(LC_ALL, "Russian");
	bool exit = false;
	deque<double> dec;
	string FileName = "";
	int N;
	int M;
	ofstream ofs;
	ifstream ifs;
	do {
		switch (Menu(dec.size())) {
		case 1:
			N = InputNum("Введите количество элементов.");
			M = InputNum("Введите максимальный модуль чисел.");
			FileName = InputFileName();
			ofs=CreateFileRand(FileName,N,M);
			break;
		case 2:
			N = InputNum("Введите количество элементов.");
			M = InputNum("Введите максимальный модуль чисел.");
			FileName = InputFileName();
			ofs = CreateFileGenerate(FileName, N, M);
			break;
		case 3:
			if (FileName == "") FileName = InputFileName();
			else if (!InputQuery("Использовать текущий файл?")) {
				FileName = InputFileName();
			}
			ifs.open(FileName);
			dec = LoadFromFile(ifs);
			ifs.close();
			break;
		case 4:
			dec = Modify(dec);
			break;
		case 5:
			Modify(dec.begin(), dec.end());
			break;
		case 6:
			Modify_Transform(dec.begin(), dec.end());
			break;
		case 7:
			Modify_For_Each(dec.begin(), dec.end());
			break;
		case 8:
			cout << "Сумма элементов равна " << Summ(dec) << endl;
			break;
		case 9:
			cout << "Среднее арифметическое равно " << MidArith(dec) << endl;
			break;
		case 10:
			FileName = InputFileName();
			ofs.open(FileName);
			Print(ofs, dec);
			ofs.close();
			break;
		case 11:
			Print(cout, dec);
			break;
		default:
			return 0;
		}
	} while (1);

}