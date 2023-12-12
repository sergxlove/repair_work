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
	void printData();
	void searchData(vector<repair_work>& arr, string data, int var);
	void printField();
	void findMin(vector<repair_work>& arr, int var);
	void findMax(vector<repair_work>& arr, int var);
	void printFieldMM();
	void sortField(vector<repair_work>& arr, int var);
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
			if (arr.empty())
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				for (auto& el : arr)
				{
					cout << "Объект"<<count << endl;
					count++;
				}
				cout << "Выберите удаляемый объект" << endl;
				cin >> var;
				arr.erase(arr.begin() + var);
				cout << "Объект удален" << endl;
			}
			break;
		case 5:
			if (arr.empty())
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				rw.printField();
				cout << "Выберите поле для поиска" << endl;
				cin >> var;
				cout << "Введите данные для поиска" << endl;
				cin >> field;
				rw.searchData(arr, field, var);
			}
			break;
		case 6:
			if (arr.empty())
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				cout << "Выберите поле для нахождения минимального значения" << endl;
				cin >> var;
				rw.findMin(arr, var);
			}
			break;
		case 7:
			if (arr.empty())
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				cout << "Выберите поле для нахождения максимального значения" << endl;
				cin >> var;
				rw.findMax(arr, var);
			}
			break;
		case 8:
			if (arr.empty())
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				rw.printField();
				cout << "Выберите нужное поле" << endl;
				cin >> var;
				rw.sortField(arr, var);
			}
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
					el.printData();
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

void repair_work::printData()
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

void repair_work::searchData(vector<repair_work>& arr, string data, int var)
{
	for (auto& el : arr)
	{
		switch (var)
		{
		case 1:
			if (data == el.name)
			{
				el.printData();
			}
			break;
		case 2:
			if (data == el.addres)
			{
				el.printData();
			}
			break;
		case 3:
			if (data == el.name_customer)
			{
				el.printData();
			}
			break;
		case 4:
			if (data == el.date_begin)
			{
				el.printData();
			}
			break;
		case 5:
			if (stoi(data) == el.duration)
			{
				el.printData();
			}
			break;
		case 6:
			if (stoi(data) == el.price)
			{
				el.printData();
			}
			break;
		default:
			cout << "Некоректный ввод" << endl;
			break;
		}
	}
}

void repair_work::printField()
{
	cout << "Доступные поля : " << endl;
	cout << "1 - Наименование объекта" << endl;
	cout << "2 - Адрес объекта" << endl;
	cout << "3 - ФИО заказчика" << endl;
	cout << "4 - Дата начала работ" << endl;
	cout << "5 - Продолжительность" << endl;
	cout << "6 - Стоимость работ" << endl;
}

void repair_work::findMax(vector<repair_work>& arr, int var)
{
	int max = 0;
	switch (var)
	{
	case 1:
		for (auto& el : arr)
		{
			if (el.duration > max)
			{
				max = el.duration;
			}
		}
		break;
	case 2:
		for (auto& el : arr)
		{
			if (el.price > max)
			{
				max = el.price;
			}
		}
		break;
	default:
		cout << "Некоректный ввод" << endl;
		break;
	}
	cout << "Максимальный элемент = " << max << endl;
}

void repair_work::findMin(vector<repair_work>& arr, int var)
{
	int min = 10000000000;
	switch (var)
	{
	case 1:
		for (auto& el : arr)
		{
			if (el.duration < min)
			{
				min = el.duration;
			}
		}
		break;
	case 2:
		for (auto& el : arr)
		{
			min = el.price;
		}
		break;
	default:
		cout << "Некоректный ввод" << endl;
		break;
	}
	cout << "Минимальный элемент" << endl;
}

void repair_work::printFieldMM()
{
	cout << "Доступные поля:" << endl;
	cout << "1 - Продолжительность" << endl;
	cout << "2 - Стоимость работ" << endl;
}

void repair_work::sortField(vector<repair_work>& arr, int var)
{
	switch (var)
	{
	case 1:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.name < r2.name;});
		break;
	case 2:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.addres < r2.addres;});
		break;
	case 3:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.name_customer < r2.name_customer;});
		break;
	case 4:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.date_begin < r2.date_begin;});
		break;
	case 5:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.duration < r2.duration;});
		break;
	case 6:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.price < r2.price;});
		break;
	default:
		break;
	}
}
