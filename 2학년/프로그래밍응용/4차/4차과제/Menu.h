#pragma once
#include "PersonList.h"

class Menu
{
private:
	string menuName;
	int fee;
	int remnant;
public:
	Menu() {}
	Menu(string m_name, int m_fee);
	Menu(string m_name, int m_fee, int m_remnant);

	string getMenuName() { return menuName; }
	int getFee() { return fee; }
	int getRemnant() { return remnant; }

	void plusRemnant(int quantity) { remnant += quantity; }
	void minusRemnant(int quantity) { remnant -= quantity; }
};

