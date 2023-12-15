//подключение библиотек
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;//пространство имен
class repair_work
{
public:
	repair_work();//конструктор по умолчанию 
	repair_work(string name, string addres, string name_customer, string date_begin, int duration, int price);//конструктор с параметрами
	~repair_work();//деструктор
	void printInfo();//вывод информации о консольном меню
	void setData();//ввод данных
	void writeFile(vector<repair_work> &arr, string path);//сохранение данных в файл
	void readFile(vector<repair_work>& arr, string path);//чтение данных из файла
	void printData();//вывод ролей объекта
	void searchData(vector<repair_work>& arr, string data, int var);//поиск данных по полям
	void printField();//вывод доступных полей
	void findMin(vector<repair_work>& arr, int var);//поиск минимального элемента 
	void findMax(vector<repair_work>& arr, int var);//поиск максимального элемента
	void printFieldMM();//вывод доступных элементов для нахождения максимального и минимального элемента
	void sortField(vector<repair_work>& arr, int var);//сортировка по полю
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
	repair_work rw;//объявление объекта класса
	vector<repair_work> arr;//объявление вектора объектов
	//объявление переменных
	int var_switch, count, var;
	count = var_switch = var = 0;
	string path = "data.txt";
	string field;
	bool exit = false;
	rw.readFile(arr, path);//чтение фаайла
	rw.printInfo();//вывод информации о консольном меню
	while (!exit)
	{
		cout << "Выберите режим: " << endl;
		cin >> var_switch;//навигация по консольному меню
		switch (var_switch)//навигация по консольному меню
		{
		case 1://режим 1
			rw.setData();//ввод данных
			arr.push_back(rw);//добавление объекта в вектор
			cout << "Объект создан" << endl;
			break;
		case 2://режим 2
			rw.writeFile(arr, path);//запись данных в файл
			cout << "Данные записаны в файл" << endl;
			break;
		case 3://режим 3
			rw.readFile(arr, path);//чтение данных из файла
			cout << "Данные считаны" << endl;
			break;
		case 4://режим 4
			if (arr.empty())//проверка вектора на наличие объектов
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				count = 0;
				for (auto& el : arr)//цикл фор ич
				{
					cout << "Объект "<<count << endl;//перечисление объектов вектора
					count++;
				}
				cout << "Выберите удаляемый объект" << endl;
				cin >> var;
				arr.erase(arr.begin() + var);//удаление элемента
				cout << "Объект удален" << endl;
			}
			break;
		case 5://режим 5
			if (arr.empty())//проверка вектора на наличие объектов
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				rw.printField();//вывод доступных полей
				cout << "Выберите поле для поиска" << endl;
				cin >> var;//выбор поля
				cout << "Введите данные для поиска" << endl;
				cin >> field;//ввод данных
				rw.searchData(arr, field, var);//поиск данных по полю
			}
			break;
		case 6://режим 6
			if (arr.empty())//проверка вектора на наличие объектов
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				cout << "Выберите поле для нахождения минимального значения" << endl;
				rw.printFieldMM();//вывод полей для нахождения максимума и минимума
				cin >> var;
				rw.findMin(arr, var);//поиск минимального
			}
			break;
		case 7://режим 7
			if (arr.empty())//проверка вектора на наличие объектов
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				cout << "Выберите поле для нахождения максимального значения" << endl;
				rw.printFieldMM();//вывод полей для нахождения максимума и минимума
				cin >> var;
				rw.findMax(arr, var);//поиск максимального
			}
			break;
		case 8://режим 8
			if (arr.empty())//проверка вектора на наличие объектов
			{
				cout << "В веторе нет элементов" << endl;
			}
			else
			{
				rw.printField();//вывод доступных полей
				cout << "Выберите нужное поле" << endl;
				cin >> var;
				rw.sortField(arr, var);//сортировка поля
				cout << "Вектор успешно отсортирован" << endl;
			}
			break;
		case 9://режим 9
			if (arr.empty())//проверка вектора на наличие объектов
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				for (auto& el : arr)//цикл фор ич
				{
					el.printData();//вывод полей объекта
				}
			}
			break;
		case 10://режим 10
			cout << "---------------------------------------" << endl;
			cout << "Программа завершена" << endl;
			cout << "---------------------------------------" << endl;
			exit = true;//выход из программы
			break;
		default:
			cout << "Некоректный ввод" << endl;
			break;
		}
	}
	return 0;
}

repair_work::repair_work()//конструктор по умолчанию
{
	//присвоение переменным значения
	this->name = "";
	this->addres = "";
	this->name_customer = "";
	this->date_begin = "";
	this->duration = 0;
	this->price = 0;
}

repair_work::repair_work(string name, string addres, string name_customer, string date_begin, int duration, int price)//конструктор с параметрами
{
	//присвоение переменным значения
	this->name = name;
	this->addres = addres;
	this->name_customer = name_customer;
	this->date_begin = date_begin;
	this->duration = duration;
	this->price = price;
}

repair_work::~repair_work()//деструктор
{
	this->name = "";
	this->addres = "";
	this->name_customer = "";
	this->date_begin = "";
	this->duration = 0;
	this->price = 0;
}

void repair_work::printInfo()//вывод информации о консольном меню
{
	cout << "===================================================" << endl;
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
	cout << "===================================================" << endl;
}

void repair_work::setData()//ввод данных
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
	cin >> third_name;
	name_customer = first_name + " " + second_name + " " + third_name;//объединение фаамилии, имени и отчества
	cout << "Введите дату начала работ" << endl;
	cin >> date_begin;
	cout << "Введите продолжительность работ в днях" << endl;
	cin >> duration;
	cout << "Введите стоимость работ" << endl;
	cin >> price;
}

void repair_work::writeFile(vector<repair_work>& arr, string path)//запись данных в файл
{
	fstream file;
	file.open(path, fstream::out);//открытие файла
	if (file.is_open())//проверка открытия в файл
	{
		file.clear();//очистка файла
		file << arr.size() << "\n";//запись размера в вектор
		for (auto& el : arr)//цикл фор ич
		{
			//запись полей в файл
			file << el.name << "\n";
			file << el.addres << "\n";
			file << el.name_customer << "\n";
			file << el.date_begin << "\n";
			file << el.duration << "\n";
			file << el.price << "\n";
		}
		file.close();//закрытие файла
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void repair_work::readFile(vector<repair_work>& arr, string path)//чтение данных из файла
{
	fstream file;
	repair_work obj;
	string field;
	int size = 0;
	file.open(path, fstream::in);//открытие файла
	if (file.is_open())//проверка открытия файла
	{
		arr.clear();//очистка ввектора
		getline(file, field);//считывание количчества объектов
		size = stoi(field);
		for (int i = 0;i < size;i++)
		{
			//считывание данных из файла в поля объекта
			getline(file, obj.name);
			getline(file, obj.addres);
			getline(file, obj.name_customer);
			getline(file, obj.date_begin);
			getline(file, field);
			obj.duration = stoi(field);
			getline(file, field);
			obj.price = stoi(field);
			arr.push_back(obj);//добавление объекта в вектор
		}
		file.close();//закрытие файла
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void repair_work::printData()//вывод полей объекта
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

void repair_work::searchData(vector<repair_work>& arr, string data, int var)//поиск данных по полям
{
	bool check = true;
	for (auto& el : arr)//цикл фор ич
	{
		switch (var)//поля
		{
		case 1:
			if (data == el.name)//сравнение данных с полем
			{
				el.printData();//вывод полей объекта
				check = false;
			}
			break;
		case 2:
			if (data == el.addres)//сравнение данных с полем
			{
				el.printData();//вывод полей объекта
				check = false;
			}
			break;
		case 3:
			if (data == el.name_customer)//сравнение данных с полем
			{
				el.printData();//вывод полей объекта
				check = false;
			}
			break;
		case 4:
			if (data == el.date_begin)//сравнение данных с полем
			{
				el.printData();//вывод полей объекта
				check = false;
			}
			break;
		case 5:
			if (stoi(data) == el.duration)//сравнение данных с полем
			{
				el.printData();//вывод полей объекта
				check = false;
			}
			break;
		case 6:
			if (stoi(data) == el.price)//сравнение данных с полем
			{
				el.printData();//вывод полей объекта
				check = false;
			}
			break;
		default:
			cout << "Некоректный ввод" << endl;
			break;
		}
		if (check)//при отсутствии введенных данных
		{
			cout << "Введенные данные не найдены" << endl;
		}
	}
}

void repair_work::printField()//вывод доступных полей
{
	cout << "Доступные поля : " << endl;
	cout << "1 - Наименование объекта" << endl;
	cout << "2 - Адрес объекта" << endl;
	cout << "3 - ФИО заказчика" << endl;
	cout << "4 - Дата начала работ" << endl;
	cout << "5 - Продолжительность" << endl;
	cout << "6 - Стоимость работ" << endl;
}

void repair_work::findMax(vector<repair_work>& arr, int var)//поиск максимального элемента
{
	int max = 0;
	switch (var)
	{
	case 1:
		for (auto& el : arr)//цикл фор ич
		{
			//определение максимального
			if (el.duration > max)
			{
				max = el.duration;
			}
		}
		break;
	case 2:
		for (auto& el : arr)//цикл фор ич
		{
			//определение максимального 
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

void repair_work::findMin(vector<repair_work>& arr, int var)//определение минимального
{
	int min = 10000000000;
	switch (var)
	{
	case 1:
		for (auto& el : arr)//цикл фор ич
		{
			//определение минимального
			if (el.duration < min)
			{
				min = el.duration;
			}
		}
		break;
	case 2:
		for (auto& el : arr)//цикл фор ич
		{
			//определение минимального
			if (el.price < min)
			{
				min = el.price;
			}
		}
		break;
	default:
		cout << "Некоректный ввод" << endl;
		break;
	}
	cout << "Минимальный элемент = "<<min << endl;
}

void repair_work::printFieldMM()//вывод полей доступных для определения максимального и минимального
{
	cout << "Доступные поля:" << endl;
	cout << "1 - Продолжительность" << endl;
	cout << "2 - Стоимость работ" << endl;
}

void repair_work::sortField(vector<repair_work>& arr, int var)//сортировка по полю
{
	switch (var)//поле
	{
	case 1:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.name < r2.name;});//сортировка
		break;
	case 2:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.addres < r2.addres;});//сортировка
		break;
	case 3:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.name_customer < r2.name_customer;});//сортировка
		break;
	case 4:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.date_begin < r2.date_begin;});//сортировка
		break;
	case 5:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.duration < r2.duration;});//сортировка
		break;
	case 6:
		sort(arr.begin(), arr.end(), [](const repair_work& r1, const repair_work& r2) {return r1.price < r2.price;});//сортировка
		break;
	default:
		cout << "Некоректный ввод" << endl;
		break;
	}
}
