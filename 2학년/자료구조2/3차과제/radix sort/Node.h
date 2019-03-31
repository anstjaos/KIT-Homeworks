#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Radix;

class Node {
	friend class Radix;
private:
	unsigned int data;
	Node* link;
public:
	Node();
	Node(int i_data, Node* i_link);
	~Node() {}
};