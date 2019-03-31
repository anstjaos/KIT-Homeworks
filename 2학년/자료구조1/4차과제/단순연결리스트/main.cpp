/* --- 헤더 노드를 사용하지 않는 연결리스트 --- */
/* ---    작성자: 김문서, 학번: 20130162    --- */
/* ---    288 lines, 작성일: 2017. 5. 24.   --- */

#include "TaskManager.h"

void main(int args, char **argv)
{
	Chain c;
	TaskManager tm;

	if (args != 2)
	{
		cout << "파일명을 입력해주세요." << endl;
		return;
	}

	if (c.loadFile(argv[1]) == false) return;	// File load
	tm.getMenu(c);					// 메뉴 출력과 작업 수행
	c.saveFile(argv[1]);			// File save
}