#pragma once
#include "Duck.h"
#include "Turkey.h"

class TurkeyAdapter : public Duck, private Turkey {
private:
	void gobble() { cout << "Turkey's Gobble gobble\n"; }
	void flyTurkey() { cout << "Turkey's fly!\n"; }
public:
	void quack() { TurkeyAdapter::gobble(); }
	void fly() { TurkeyAdapter::flyTurkey(); }
};