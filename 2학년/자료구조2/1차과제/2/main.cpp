/* ---	 계산식을 tree로 구현하는 프로그램	--- */
/* ---    작성자: 김문서, 학번: 20130162    --- */
/* ---    831 lines, 작성일: 2017. 9. 12.    --- */

#include "Tree.h"

void main()
{
	Tree<Token> t;
	string formula;
	while (1)
	{
		Expression ex;
		
		cout << "계산식을 입력하세요 (종료는 quit) : ";
		getline(cin, formula);
		if (formula == "quit" || formula == "QUIT")
		{
			cout << "**** 종료합니다 ****" << endl;
			return ;
		}
		else if (formula == "")							// 공백을 입력했을 시 예외처리
		{
			cout << "계산식을 입력해주세요." << endl;
			continue;
		}

		try {							// 예외 처리를 위한 try catch
			ex = ex.getPostfix(formula);		// 후위 표기식 출력
			t.createTree(ex);
			t.showAll();				// 결과값 출력
		}
		catch(Exception e)
		{
			e.putError();
		}
	}
	
}