/* --- 입력된 값을 후위 연산으로 출력하고 계산하는 프로그램 --- */
/* ---            작성자: 김문서, 학번: 20130162            --- */
/* ---            612 lines, 작성일: 2017. 5. 04.           --- */

#include "Calculrator.h"

void main()
{
	string formula;
	
	while (1)
	{
		Expression ex;
		Calculrator cl;
		cout << "계산식을 입력하세요 (종료는 quit) : ";
		getline(cin, formula);
		if (formula == "") continue;

		if (formula == "quit" || formula == "QUIT")
		{
			cout << "**** 종료합니다 ****" << endl;
			return;
		}
		try {							// 예외 처리를 위한 try catch
			ex = ex.getPostfix(formula);		// 후위 표기식 출력
			cl.calculration(ex);		// 결과값 출력
		}
		catch (Exception e)
		{
			e.putError();
		}
	}
}