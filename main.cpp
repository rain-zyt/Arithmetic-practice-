#include "count system.h"
int main()
{
	ofstream fout("text.txt",ios::app); 
	system("color 3F");
	int choice;
	menu0();
	while (1)
	{
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			add();
			break;
		case 2:
			sub();
				break;
		case 3:
			mix();
			break;
		case 4:
			return 1;
			break;
		}
	}
	return 0;
}