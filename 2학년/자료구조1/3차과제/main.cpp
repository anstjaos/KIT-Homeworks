/* --- �Էµ� ���� ���� �������� ����ϰ� ����ϴ� ���α׷� --- */
/* ---            �ۼ���: �蹮��, �й�: 20130162            --- */
/* ---            612 lines, �ۼ���: 2017. 5. 04.           --- */

#include "Calculrator.h"

void main()
{
	string formula;
	
	while (1)
	{
		Expression ex;
		Calculrator cl;
		cout << "������ �Է��ϼ��� (����� quit) : ";
		getline(cin, formula);
		if (formula == "") continue;

		if (formula == "quit" || formula == "QUIT")
		{
			cout << "**** �����մϴ� ****" << endl;
			return;
		}
		try {							// ���� ó���� ���� try catch
			ex = ex.getPostfix(formula);		// ���� ǥ��� ���
			cl.calculration(ex);		// ����� ���
		}
		catch (Exception e)
		{
			e.putError();
		}
	}
}