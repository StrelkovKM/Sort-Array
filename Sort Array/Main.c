#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"


int main()
{
	int enter_code1 = 0, enter_code2 = 0;
	Introduction();

	do {
		InputTask(&enter_code1);
		switch (enter_code1)
		{

		case 1:
		{
			InputSelection(&enter_code2);
			switch (enter_code2)
			{
			case 1:
				ConsoleWaySort();
				break;
			case 2:
				RandomWaySort();
				break;
			case 3:
				TxtWaySort();
				break;
			default: break;
			}
			break;
		}
		case 2:
		{
			InputSelection(&enter_code2);
			switch (enter_code2)
			{
			case 1:
				ConsoleWayNorm();
				break;
			case 2:
				RandomWayNorm();
				break;
			case 3:
				TxtWayNorm();
				break;
			default: break;
			}
			break;
		}
		default:
		{
			system("cls");
			PrintDelayStr("Goodbye!");
			return 0;
		}

		}
	} while (CheckCode(enter_code1, 2) != 0);
}