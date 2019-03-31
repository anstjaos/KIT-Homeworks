/* --- 헤더 노드를 사용하지 않은 이중 연결 원형 리스트 --- */
/* ---         작성자: 김문서, 학번: 20130162          --- */
/* ---         423 lines, 작성일: 2017. 5. 28.         --- */

#include "TaskManager.h"

void main(int args, char** argv)
{
	DblList dl;
	TaskManager tm;
	
	if (args != 2)
	{
		cout << "파일명을 입력하여 주십시오." << endl;
		return;
	}
	if (dl.loadFile(argv[1]) == false) return;
	tm.taskMenu(dl);
	dl.saveFile(argv[1]);
}