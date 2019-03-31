#include "TicketManager.h"

void TicketManager::getMenu()
{
	int menu;
	while (1)
	{
		cout << endl;
		cout << "=============================================" << endl;
		cout << "1. 관리모드 2. 판매모드 3. 종료" << endl;
		cout << "=============================================" << endl;
		cout << "메뉴를 입력하세요-> ";
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
			cout << "종료합니다." << endl;
			return;
		default:
			cout << "잘못된 메뉴를 선택하셨습니다 !" << endl;
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

	cout << "판매 정보를 입력하세요(고객이름, 메뉴이름, 수량)-> ";
	getline(cin, personName, ',');
	getline(cin, menuName,',');
	getline(cin, temp);
	orderQuantity = stoi(temp);

	if (pl.findPerson(personName) == NOT_FOUND)
	{
		cout << "입력하신 이름이 존재하지 않습니다! " << endl;
		return;
	}
	int index = ml.findMenu(menuName);
	if (index == NOT_FOUND)
	{
		cout << "입력하신 메뉴가 존재하지 않습니다! " << endl;
		return;
	}
	if (ml.getMenu(index).getRemnant() < orderQuantity)
	{
		cout << "판매 가능한 식권이 모자릅니다! " << endl;
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
	cout << "1. 사람관리 2. 메뉴관리 3. 판매관리" << endl;
	cout << "=============================================" << endl;
	cout << "메뉴를 입력하세요-> ";
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
		cout << "잘못된 메뉴를 선택하셨습니다 !" << endl;
		break;
	}
}

void TicketManager :: managePerson()
{
	int menu;
	string personName;
	cout << endl;
	cout << "=============================================" << endl;
	cout << "1. 사람등록 2. 사람삭제 3. 사람검색" << endl;
	cout << "=============================================" << endl;
	cout << "메뉴를 입력하세요-> ";
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
		cout << "검색할 사람의 이름을 입력하세요-> ";
		getline(cin, personName);
		pl.showPerson(personName);
		break;
	default:
		cout << "잘못된 메뉴를 선택하셨습니다 !" << endl;
		break;
	}
}

void TicketManager :: manageMenu()
{
	int menu;
	cout << endl;
	cout << "=============================================" << endl;
	cout << "1. 메뉴등록 2. 메뉴삭제 3. 식권추가" << endl;
	cout << "=============================================" << endl;
	cout << "메뉴를 입력하세요-> ";
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
		cout << "잘못된 메뉴를 선택하셨습니다 !" << endl;
		break;
	}
} 

void TicketManager :: manageSales()
{
	int menu;
	cout << endl;
	cout << "=============================================" << endl;
	cout << "1. 음식별 판매 통계" << endl;
	cout << "2. 사람별 판매 통계" << endl;
	cout << "3. 사람별 구매 통계" << endl;
	cout << "4. 날짜별 판매 통계" << endl;
	cout << "=============================================" << endl;
	cout << "메뉴를 입력하세요-> ";
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
		cout << "잘못된 메뉴를 선택하셨습니다 !" << endl;
		break;
	}
}

void TicketManager :: insertPerson()
{
	string name;
	string department;
	string phoneNumber;
	cout << "등록할 사람의 정보를 입력하세요(이름, 소속, 전화번호)-> ";
	getline(cin, name, ',');
	getline(cin, department, ',');
	getline(cin, phoneNumber);

	if (pl.findPerson(name) != NOT_FOUND)
	{
		cout << "이미 존재하는 사람입니다!" << endl;
		return;
	}
	
	Person p(name, department, phoneNumber);
	pl.insertPerson(p);
}

void TicketManager :: deletePerson()
{
	string name;

	cout << "삭제할 사람의 이름을 입력하세요-> ";
	getline(cin, name);
	int index = pl.findPerson(name);

	if (index == NOT_FOUND)
	{
		cout << "등록되지 않은 사람입니다!" << endl;
		return;
	}

	pl.deletePerson(index);
}

void TicketManager :: insertMenu()
{
	string menuName;
	int fee;

	cout << "등록할 메뉴의 정보를 입력하세요(이름, 가격)-> ";
	getline(cin, menuName, ',');
	cin >> fee;

	if (ml.findMenu(menuName) != NOT_FOUND)
	{
		cout << "이미 존재하는 메뉴입니다!" << endl;
		return;
	}

	Menu m(menuName, fee);
	ml.insertMenu(m);
}

void TicketManager :: deleteMenu()
{
	string menuName;
	cout << "삭제할 메뉴의 이름을 입력하세요-> ";
	getline(cin, menuName);
	int index = ml.findMenu(menuName);

	if (index == NOT_FOUND)
	{
		cout << "등록되지 않은 메뉴입니다!" << endl;
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