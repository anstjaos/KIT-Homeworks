/* ---    ��� ��带 ����ϴ� ���Ḯ��Ʈ   --- */
/* ---    �ۼ���: �蹮��, �й�: 20130162    --- */
/* ---    284 lines, �ۼ���: 2017. 5. 25.   --- */

#include "TaskManager.h"

void main(int args, char** argv)
{
	TaskManager tm;
	Chain c;

	if (args != 2)			// ���ϸ��� �Է����� �ʾ��� ���� ����ó��
	{
		cout << "���ϸ��� �Է��Ͽ� �ֽʽÿ�." << endl;
		return;
	}
	
	if (c.loadFile(argv[1]) == false)	return;	// ������ �������� ������ ���α׷� ����
	tm.taskMenu(c);

	c.saveFile(argv[1]);
}