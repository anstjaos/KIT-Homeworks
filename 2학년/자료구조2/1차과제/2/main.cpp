/* ---	 ������ tree�� �����ϴ� ���α׷�	--- */
/* ---    �ۼ���: �蹮��, �й�: 20130162    --- */
/* ---    831 lines, �ۼ���: 2017. 9. 12.    --- */

#include "Tree.h"

void main()
{
	Tree<Token> t;
	string formula;
	while (1)
	{
		Expression ex;
		
		cout << "������ �Է��ϼ��� (����� quit) : ";
		getline(cin, formula);
		if (formula == "quit" || formula == "QUIT")
		{
			cout << "**** �����մϴ� ****" << endl;
			return ;
		}
		else if (formula == "")							// ������ �Է����� �� ����ó��
		{
			cout << "������ �Է����ּ���." << endl;
			continue;
		}

		try {							// ���� ó���� ���� try catch
			ex = ex.getPostfix(formula);		// ���� ǥ��� ���
			t.createTree(ex);
			t.showAll();				// ����� ���
		}
		catch(Exception e)
		{
			e.putError();
		}
	}
	
}