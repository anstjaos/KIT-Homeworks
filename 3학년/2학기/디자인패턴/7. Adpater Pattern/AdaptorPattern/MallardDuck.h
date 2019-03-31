#pragma once
#include "Duck.h"
#include <iostream>
using namespace std;

class MallardDuck : public Duck {
public:
	void quack() { cout << "Quack\n"; }
	void fly() { cout << "I'm flying\n"; }
};