/* ---     ��� ��带 ����� ���� ���� ���� ����Ʈ    --- */
/* ---         �ۼ���: �蹮��, �й�: 20130162          --- */
/* ---         375 lines, �ۼ���: 2017. 5. 30.         --- */

#include "TaskManager.h"

void main(int args, char **argv)
{
	DblList dl;
	TaskManager tm;

	if (args != 2)
	{
		cout << "���ϸ��� �Է��Ͽ� �ֽʽÿ�." << endl;
		return;
	}
	if (dl.loadFile(argv[1]) == false) return;
	tm.taskMenu(dl);

	dl.saveFile(argv[1]);
}