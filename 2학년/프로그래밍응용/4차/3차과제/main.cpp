#include "WordMatching.h"

void main()
{
	WordMatching wm;

	wm.loadFile();
	while (1)
	{
		wm.showQuiz();
		if (wm.selectMenu() == 9) return;
	}
}