/* --- ��� ��带 ������� �ʴ� ���Ḯ��Ʈ --- */
/* ---    �ۼ���: �蹮��, �й�: 20130162    --- */
/* ---    288 lines, �ۼ���: 2017. 5. 24.   --- */

#include "TaskManager.h"

void main(int args, char **argv)
{
	Chain c;
	TaskManager tm;

	if (args != 2)
	{
		cout << "���ϸ��� �Է����ּ���." << endl;
		return;
	}

	if (c.loadFile(argv[1]) == false) return;	// File load
	tm.getMenu(c);					// �޴� ��°� �۾� ����
	c.saveFile(argv[1]);			// File save
}