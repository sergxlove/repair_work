#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
class repair_work
{
public:
	repair_work();
	repair_work(string name, string addres, string name_customer, string date_begin, int duration, int price);
	~repair_work();
	void printInfo();
	void setData();
	void writeFile(vector<repair_work> &arr, string path);
	void readFile(vector<repair_work>& arr, string path);
	void printField();
private:
	string name;//наименование объекта
	string addres;//адрес объекта
	string name_customer;//фио заказчика
	string date_begin;//дата начала работ
	int duration;//продолжительность
	int price;//стоимость работ
};
int main()
{
	setlocale(LC_ALL, "rus");
	repair_work rw;
	vector<repair_work> arr;
	int var_switch = 0;
	int count = 0;
	int var = 0;
	string path = "data.txt";
	string field;
	bool exit = false;
	while (!exit)
	{
		rw.printInfo();
		cout << "Выберите режим: " << endl;
		cin >> var_switch;
		switch (var_switch)
		{
		case 1:
			rw.setData();
			arr.push_back(rw);
			cout << "Объект создан" << endl;
			break;
		case 2:
			if (arr.empty())
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				rw.writeFile(arr, path);
				cout << "Данные записаны в файл" << endl;
			}
			break;
		case 3:
			rw.readFile(arr, path);
			cout << "Данные считаны" << endl;
			break;
		case 4:
			for (auto& el : arr)
			{
				cout << "Объект"<<count << endl;
				count++;
			}
			cout << "Выберите удаляемый объект" << endl;
			cin >> var;
			arr.erase(arr.begin() + var);
			cout << "Объект удален" << endl;
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				for (auto& el : arr)
				{
					el.printField();
				}
			}
			break;
		case 10:
			cout << "---------------------------------------" << endl;
			cout << "Программа завершена" << endl;
			cout << "---------------------------------------" << endl;
			exit = true;
			break;
		default:
			break;
		}
	}
	return 0;
}

repair_work::repair_work()
{
	this->name = "";
	this->addres = "";
	this->name_customer = "";
	this->date_begin = "";
	this->duration = 0;
	this->price = 0;
}

repair_work::repair_work(string name, string addres, string name_customer, string date_begin, int duration, int price)
{
	this->name = name;
	this->addres = addres;
	this->name_customer = name_customer;
	this->date_begin = date_begin;
	this->duration = duration;
	this->price = price;
}

repair_work::~repair_work()
{
	this->name = "";
	this->addres = "";
	this->name_customer = "";
	this->date_begin = "";
	this->duration = 0;
	this->price = 0;
}

void repair_work::printInfo()
{
	cout << "Доступные режимы :" << endl;
	cout << "1 - Ввод данных " << endl;
	cout << "2 - Сохранение данных в файл" << endl;
	cout << "3 - Чтение данных из файла" << endl;
	cout << "4 - Удаление данных" << endl;
	cout << "5 - Поиск данных по полям" << endl;
	cout << "6 - Поиск минимального элемента" << endl;
	cout << "7 - Поиск максимального элемента" << endl;
	cout << "8 - Сортровка по полю" << endl;
	cout << "9 - Вывод полей объектов" << endl;
	cout << "10 - Выход из программы" << endl;
}

void repair_work::setData()
{
	string first_name, second_name, third_name;
	cout << "Введите наименование объекта" << endl;
	cin >> name;
	cout << "Адрес объекта" << endl;
	cin >> addres;
	cout << "Введите фамилию заказчика" << endl;
	cin >> first_name;
	cout << "Введите имя заказчика" << endl;
	cin >> second_name;
	cout << "Введите отчество заказчика" << endl;
	name_customer = first_name + " " + second_name + " " + third_name;
	cout << "Введите дату начала работ" << endl;
	cin >> date_begin;
	cout << "Введите продолжительность работ в днях" << endl;
	cin >> duration;
	cout << "Введите стоимость работ" << endl;
	cin >> price;
}

void repair_work::writeFile(vector<repair_work>& arr, string path)
{
	fstream file;
	file.open(path, fstream::out);
	if (file.is_open())
	{
		file.clear();
		file << arr.size() << "\n";
		for (auto& el : arr)
		{
			file << name << "\n";
			file << addres << "\n";
			file << name_customer << "\n";
			file << date_begin << "\n";
			file << duration << "\n";
			file << price << "\n";
		}
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void repair_work::readFile(vector<repair_work>& arr, string path)
{
	fstream file;
	repair_work obj;
	string field;
	int size = 0;
	file.open(path, fstream::in);
	if (file.is_open())
	{
		arr.clear();
		getline(file, field);
		size = stoi(field);
		for (int i = 0;i < size;i++)
		{
			getline(file, obj.name);
			getline(file, obj.addres);
			getline(file, obj.name_customer);
			getline(file, obj.date_begin);
			getline(file, field);
			obj.duration = stoi(field);
			getline(file, field);
			obj.price = stoi(field);
		}
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void repair_work::printField()
{
	cout << "-------------------------" << endl;
	cout << "Объект класса repair_work" << endl;
	cout << "Наименование объекта : " << name << endl;
	cout << "Адрес объекта : " << addres << endl;
	cout << "ФИО заказчика : " << name_customer << endl;
	cout << "Дата начала работ : " << date_begin << endl;
	cout << "Продолжительность работ : " << duration << endl;
	cout << "Стоимость работ : " << price << endl;
}
