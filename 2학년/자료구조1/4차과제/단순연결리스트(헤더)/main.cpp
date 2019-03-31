/* ---    헤더 노드를 사용하는 연결리스트   --- */
/* ---    작성자: 김문서, 학번: 20130162    --- */
/* ---    284 lines, 작성일: 2017. 5. 25.   --- */

#include "TaskManager.h"

void main(int args, char** argv)
{
	TaskManager tm;
	Chain c;

	if (args != 2)			// 파일명을 입력하지 않았을 시의 예외처리
	{
		cout << "파일명을 입력하여 주십시오." << endl;
		return;
	}
	
	if (c.loadFile(argv[1]) == false)	return;	// 파일이 존재하지 않으면 프로그램 종료
	tm.taskMenu(c);

	c.saveFile(argv[1]);
}