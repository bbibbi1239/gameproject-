#include "main.h"
#include "game.h"

int main() {
	init();
	//����ȭ��. �򰥷��� �����аŴ� ����� �Ͻø� �˴ϴ�
	while (1)
	{
		titleDraw(6);
		loveGauge();
		int n = keyControl();
		if (n == SUBMIT) {
			return 0;
		}
	}
	return 0;


	
}