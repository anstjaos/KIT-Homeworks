#include "MallardDuck.h"
#include "TurkeyAdapter.h"

int main()
{
	Duck *md = new MallardDuck();
	Duck *ta = new TurkeyAdapter();

	cout << "The Duck says..\n";
	md->quack();
	md->fly();

	cout << "The Turkey Adapter says..\n";
	ta->quack();
	ta->fly();

	delete md;
	delete ta;
}