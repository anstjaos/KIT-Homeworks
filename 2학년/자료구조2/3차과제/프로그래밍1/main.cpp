/* ---	   자료구조 정렬 알고리즘 분석   	--- */
/* ---  작성자 대표: 김문서, 학번: 20130162 --- */
/* ---    390  lines, 작성일: 2017. 11. 9.  --- */


#include "TaskManager.h"
enum Menu {INT =1,DOUBLE,STRING,STUDENT,EXIT};

void main()
{
	int dataType;
	while (1)
	{
		cout << "\n===============================================" << endl;
		cout << "\t\tSelect Data Type" << endl;
		cout << "\t1) int" << endl;
		cout << "\t2) double" << endl;
		cout << "\t3) string" << endl;
		cout << "\t4) student" << endl;
		cout << "\t5) EXIT" << endl;
		cout << "===============================================" << endl;
		cout << "Select ? ";

		cin >> dataType;

		if (0 > dataType || dataType > 5)
		{
			cout << "Wrong Input ! " << endl << endl;
			continue;
		}
		if (dataType == EXIT) return;

		string fileName;
		int size;
		
		cout << "Input FileName ? ";
		cin >> fileName;
		cout << "Input Size ? ";
		cin >> size;

		int *intArr = NULL;
		double *doubleArr = NULL;
		string *strArr = NULL;
		Student *stuArr = NULL;

		switch (dataType)							// TaskManager를 Template으로 구현하여 자료형에 맞게 선언.
		{
		case INT:
			TaskManager<int> intTm;
			intArr = intTm.loadFile(fileName, size);
			if (intArr == NULL) break;

			intTm.run(intArr, size);
			delete[] intArr;
			break;
		case DOUBLE:
			TaskManager<double> doubleTm;
			doubleArr = doubleTm.loadFile(fileName, size);
			if (doubleArr == NULL) break;

			doubleTm.run(doubleArr, size);
			delete[] doubleArr;
 			break;
		case STRING:
			TaskManager<string> strTm;
			strArr = strTm.loadFile(fileName, size);
			if (strArr == NULL) break;

			strTm.run(strArr, size);
			delete[] strArr;
			break;
		case STUDENT:
			TaskManager<Student> stuTm;
			stuArr = stuTm.loadStudentFile(fileName, size);
			if (stuArr == NULL) break;

			stuTm.run(stuArr, size);
			delete[] stuArr;
			break;
		}
	}
}