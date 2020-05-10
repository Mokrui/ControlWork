#include"Header.h"



int main() {
	init();
	do {
		int choose = 0;
		cout << "1. Add Quiz\n";
		cout << "1. Take a Quiz\n";
		cout << "Choose: ";
		cin >> choose;
		switch (choose) {
		case 1:
			addQ();
			break;
		case 2:
			takeQ();
			break;
		}
	} while (true);
}