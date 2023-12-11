#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class repair_work
{
public:
	repair_work();
	repair_work(string name, string addres, string name_customer, string date_begin, int duration, int price);
	~repair_work();
	void printInfo();
	void setData();

private:
	string name;//������������ �������
	string addres;//����� �������
	string name_customer;//��� ���������
	string date_begin;//���� ������ �����
	int duration;//�����������������
	int price;//��������� �����
};
int main()
{
	setlocale(LC_ALL, "rus");
	repair_work rw;
	vector<repair_work> arr;
	int var_switch = 0;
	bool exit = false;
	while (!exit)
	{
		rw.printInfo();
		cout << "�������� �����: " << endl;
		cin >> var_switch;
		switch (var_switch)
		{
		case 1:
			rw.setData();
			arr.push_back(rw);
			cout << "������ ������" << endl;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
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
			break;
		case 10:
			cout << "---------------------------------------" << endl;
			cout << "��������� ���������" << endl;
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
	cout << "��������� ������ :" << endl;
	cout << "1 - ���� ������ " << endl;
	cout << "2 - ���������� ������ � ����" << endl;
	cout << "3 - ������ ������ �� �����" << endl;
	cout << "4 - �������� ������" << endl;
	cout << "5 - ����� ������ �� �����" << endl;
	cout << "6 - ����� ������������ ��������" << endl;
	cout << "7 - ����� ������������� ��������" << endl;
	cout << "8 - ��������� �� ����" << endl;
	cout << "9 - ����� ����� ��������" << endl;
	cout << "10 - ����� �� ���������" << endl;
}

void repair_work::setData()
{
	string first_name, second_name, third_name;
	cout << "������� ������������ �������" << endl;
	cin >> name;
	cout << "����� �������" << endl;
	cin >> addres;
	cout << "������� ������� ���������" << endl;
	cin >> first_name;
	cout << "������� ��� ���������" << endl;
	cin >> second_name;
	cout << "������� �������� ���������" << endl;
	name_customer = first_name + " " + second_name + " " + third_name;
	cout << "������� ���� ������ �����" << endl;
	cin >> date_begin;
	cout << "������� ����������������� ����� � ����" << endl;
	cin >> duration;
	cout << "������� ��������� �����" << endl;
	cin >> price;
}
