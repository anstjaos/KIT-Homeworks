/* ---		   6�� ���� ���α׷��� 	     	--- */
/* ---    �ۼ���: �蹮��, �й�: 20130162    --- */
/* ---    1023 lines, �ۼ���: 2017. 10. 5.  --- */

// ���Ḯ��Ʈ�� ����� �̿����� ����. �ֳ��ϸ� �ּ� ��� ����Ʈ�� ���α׷������� 
// Kruskal �˰����� �̿��Ͽ� �����߱� ������ edge���� ��ü �迭�� ���
// ����� ���� ������ ������ �ؼ� edge�� �����ϰ� ����Ŭ�� �߻����� �ʰ�
// å�� Weighted Union�� CollapsingFind �Լ��� ����Ͽ� ����Ŭ�� �߻��ϴ��� Ȯ���ϰ�
// �߻����� ���� ��� edge�� �����ϴ� ������ �����Ͽ����ϴ�.

#include "TaskManager.h"

void main()
{
	TaskManager tm;			// �޴��� �����ϴ� Ŭ���� ����
	char menu;
	while (1)
	{
		cout << "���α׷��� �����ϼ��� ([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit) : ";
		cin >> menu;
		switch (menu)
		{
		case 'S':				// DFS�� BFS
			tm.search();
			break;
		case 'M':				// �ּҺ�� ����Ʈ��
			tm.minimumCostSpanningTree();
			break;
		case 'T':				// ���� ����
			tm.topologicalSort();
			break;
		case 'Q':
			return;
		default:
			cout << "�߸��� ���α׷��� �����ϼ̽��ϴ�." << endl;
			break;
		}
	}
}