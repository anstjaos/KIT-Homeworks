#include "TicketManager.h"

void TicketManager::getMenu()
{
	int menu;
	while (1)
	{
		cout << endl;
		cout << "=============================================" << endl;
		cout << "1. ������� 2. �ǸŸ�� 3. ����" << endl;
		cout << "=============================================" << endl;
		cout << "�޴��� �Է��ϼ���-> ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case 1:
			manageMode();
			break;
		case 2:
			salesMode();
			break;
		case 3:
			cout << "�����մϴ�." << endl;
			return;
		default:
			cout << "�߸��� �޴��� �����ϼ̽��ϴ� !" << endl;
			break;
		}
	}
}

void TicketManager :: salesMode()
{
	string personName;
	string menuName;
	string temp;
	int orderQuantity;
	int sum = 0;

	time_t curr_time;
	struct tm *curr_tm;
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	string date = "";
	date += to_string(curr_tm->tm_year + 1900) + to_string(curr_tm->tm_mon + 1) + to_string(curr_tm->tm_mday);

	cout << "�Ǹ� ������ �Է��ϼ���(���̸�, �޴��̸�, ����)-> ";
	getline(cin, personName, ',');
	getline(cin, menuName,',');
	getline(cin, temp);
	orderQuantity = stoi(temp);

	if (pl.findPerson(personName) == NOT_FOUND)
	{
		cout << "�Է��Ͻ� �̸��� �������� �ʽ��ϴ�! " << endl;
		return;
	}
	int index = ml.findMenu(menuName);
	if (index == NOT_FOUND)
	{
		cout << "�Է��Ͻ� �޴��� �������� �ʽ��ϴ�! " << endl;
		return;
	}
	if (ml.getMenu(index).getRemnant() < orderQuantity)
	{
		cout << "�Ǹ� ������ �ı��� ���ڸ��ϴ�! " << endl;
		return;
	}

	sum = ml.getMenu(index).getFee() * orderQuantity;
	Sales s(personName, menuName, orderQuantity, date, sum);
	sl.insertSales(s);
	ml.minusTicket(index,orderQuantity);
}

void TicketManager :: manageMode()
{
	int menu;
	cout << endl;
	cout << "=============================================" << endl;
	cout << "1. ������� 2. �޴����� 3. �ǸŰ���" << endl;
	cout << "=============================================" << endl;
	cout << "�޴��� �Է��ϼ���-> ";
	cin >> menu;
	cin.ignore();

	switch (menu)
	{
	case 1:
		managePerson();
		break;
	case 2:
		manageMenu();
		break;
	case 3:
		manageSales();
		break;
	default:
		cout << "�߸��� �޴��� �����ϼ̽��ϴ� !" << endl;
		break;
	}
}

void TicketManager :: managePerson()
{
	int menu;
	string personName;
	cout << endl;
	cout << "=============================================" << endl;
	cout << "1. ������ 2. ������� 3. ����˻�" << endl;
	cout << "=============================================" << endl;
	cout << "�޴��� �Է��ϼ���-> ";
	cin >> menu;
	cin.ignore();

	switch (menu)
	{
	case 1:
		insertPerson();
		break;
	case 2:
		deletePerson();
		break;
	case 3:
		cout << "�˻��� ����� �̸��� �Է��ϼ���-> ";
		getline(cin, personName);
		pl.showPerson(personName);
		break;
	default:
		cout << "�߸��� �޴��� �����ϼ̽��ϴ� !" << endl;
		break;
	}
}

void TicketManager :: manageMenu()
{
	int menu;
	cout << endl;
	cout << "=============================================" << endl;
	cout << "1. �޴���� 2. �޴����� 3. �ı��߰�" << endl;
	cout << "=============================================" << endl;
	cout << "�޴��� �Է��ϼ���-> ";
	cin >> menu;
	cin.ignore();

	switch (menu)
	{
	case 1:
		insertMenu();
		break;
	case 2:
		deleteMenu();
		break;
	case 3:
		ml.plusTicket();
		break;
	default:
		cout << "�߸��� �޴��� �����ϼ̽��ϴ� !" << endl;
		break;
	}
} 

void TicketManager :: manageSales()
{
	int menu;
	cout << endl;
	cout << "=============================================" << endl;
	cout << "1. ���ĺ� �Ǹ� ���" << endl;
	cout << "2. ����� �Ǹ� ���" << endl;
	cout << "3. ����� ���� ���" << endl;
	cout << "4. ��¥�� �Ǹ� ���" << endl;
	cout << "=============================================" << endl;
	cout << "�޴��� �Է��ϼ���-> ";
	cin >> menu;
	cin.ignore();

	switch (menu)
	{
	case 1:
		sl.statisticsMenu(ml);
		break;
	case 2:
		sl.statisticsPerson();
		break;
	case 3:
		sl.statisticsPersonBuy();
		break;
	case 4:
		sl.statisticsDate();
		break;
	default:
		cout << "�߸��� �޴��� �����ϼ̽��ϴ� !" << endl;
		break;
	}
}

void TicketManager :: insertPerson()
{
	string name;
	string department;
	string phoneNumber;
	cout << "����� ����� ������ �Է��ϼ���(�̸�, �Ҽ�, ��ȭ��ȣ)-> ";
	getline(cin, name, ',');
	getline(cin, department, ',');
	getline(cin, phoneNumber);

	if (pl.findPerson(name) != NOT_FOUND)
	{
		cout << "�̹� �����ϴ� ����Դϴ�!" << endl;
		return;
	}
	
	Person p(name, department, phoneNumber);
	pl.insertPerson(p);
}

void TicketManager :: deletePerson()
{
	string name;

	cout << "������ ����� �̸��� �Է��ϼ���-> ";
	getline(cin, name);
	int index = pl.findPerson(name);

	if (index == NOT_FOUND)
	{
		cout << "��ϵ��� ���� ����Դϴ�!" << endl;
		return;
	}

	pl.deletePerson(index);
}

void TicketManager :: insertMenu()
{
	string menuName;
	int fee;

	cout << "����� �޴��� ������ �Է��ϼ���(�̸�, ����)-> ";
	getline(cin, menuName, ',');
	cin >> fee;

	if (ml.findMenu(menuName) != NOT_FOUND)
	{
		cout << "�̹� �����ϴ� �޴��Դϴ�!" << endl;
		return;
	}

	Menu m(menuName, fee);
	ml.insertMenu(m);
}

void TicketManager :: deleteMenu()
{
	string menuName;
	cout << "������ �޴��� �̸��� �Է��ϼ���-> ";
	getline(cin, menuName);
	int index = ml.findMenu(menuName);

	if (index == NOT_FOUND)
	{
		cout << "��ϵ��� ���� �޴��Դϴ�!" << endl;
		return;
	}

	ml.deleteMenu(index);
}

void TicketManager :: loadFile()
{
	pl.loadFile("Person.csv");
	ml.loadFile("Menu.csv");
	sl.loadFile("Sales.csv");
}

void TicketManager:: saveFile()
{
	pl.saveFile("Person.csv");
	ml.saveFile("Menu.csv");
	sl.saveFile("Sales.csv");
}