/* ---			자료구조 Radix sort   		--- */
/* ---  작성자 대표: 김문서, 학번: 20130162 --- */
/* ---    390 lines, 작성일: 2017. 11. 9.   --- */

#include "Radix.h"

enum Menu {MODULO16 = 1, LOGICAL, MODULO10, EXIT};
void main()
{
	int select;
	while (1)
	{
		while (1)
		{
			cout << "\n===============================================" << endl;
			cout << "\t\tSelect Radix Sort" << endl;
			cout << "\t1) 16 Modulo Radix Sort" << endl;
			cout << "\t2) Logical Radix Sort" << endl;
			cout << "\t3) 10 Modulo Radix Sort" << endl;
			cout << "\t4) EXIT" << endl;
			cout << "===============================================" << endl;
			cout << "Select ? ";
			cin >> select;

			if (MODULO16 > select || select > EXIT) continue;
			else break;
		}

		if (select == EXIT) return;

		Radix r;
		Node* chain = r.loadFile();
		if (chain == NULL) continue;

		switch (select)
		{
		case MODULO16:
			r.modulo16RadixSort(chain);
			break;
		case LOGICAL:
			r.logicalRadixSort(chain);
			break;
		case MODULO10:
			r.modulo10RadixSort(chain);
			break;
		}
	}
}