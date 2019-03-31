#include "Menu.h"

Menu :: Menu(string m_name, int m_fee)
{
	menuName = m_name;
	fee = m_fee;
	remnant = 10;
}

Menu:: Menu(string m_name, int m_fee, int m_remnant)
{
	menuName = m_name;
	fee = m_fee;
	remnant = m_remnant;
}