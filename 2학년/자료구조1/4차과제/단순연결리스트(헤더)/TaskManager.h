#pragma once
#include "Chain.h"

class TaskManager
{
public:
	void taskMenu(Chain &c);			// 메뉴 출력과 작업 수행
	void insertNode(Chain &c);			// 도서 번호와 도서명을 입력받아 객체 생성 후 노드 삽입
	void deleteNode(Chain &c);			// 도서 번호를 입력받아 노드 삭제
};