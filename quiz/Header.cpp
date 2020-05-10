#include "Header.h"

int sizeQ = 0;
Quiz* arrQ = new Quiz[sizeQ];

void init() {
	ifstream fin;
	fin.open("file.txt", fstream::app);
	bool isOpen = fin.is_open();
	string line;


	int cStr = 0;
	if (isOpen == true) {
		while (!fin.eof()) {
			getline(fin, line);
			cStr++;
		}
	}

	sizeQ = cStr/26;
	arrQ = new Quiz[sizeQ];
	cStr = 0;
	fin.close();


	ifstream file2;
	file2.open("file.txt", fstream::app);
	if (isOpen == true) {
		int cStr = 0;
		int indexQuestion = 0;
		int indexAnsw = 0;

		if (sizeQ > 0) {
			while (!file2.eof()) {
				getline(file2, line);

				switch (cStr) {
				case 0:
					arrQ[indexQuestion].title = line;
					break;
				case 1:
					arrQ[indexQuestion].QA->quest = line;
					break;
				case 2:
					arrQ[indexQuestion].QA->answears[indexAnsw] = line;
					indexAnsw++;
					break;
				case 3:
					arrQ[indexQuestion].QA->answears[indexAnsw] = line;
					indexAnsw++;
					break;
				case 4:
					arrQ[indexQuestion].QA->answears[indexAnsw] = line;
					indexAnsw = 0;
					break;
				case 5:
					int answ = atoi(line.c_str());
					arrQ[indexQuestion].QA->rightA = answ;
					cStr = 0;
					indexQuestion++;
					break;
				}

				if (indexQuestion != 4)cStr++;
			}
		}
	}

}

void save() {
	ofstream fout;
	fout.open("file.txt");

	bool is_open_write = fout.is_open();
	if (!is_open_write) {
		system("cls");
		cout << "Eror: your file -habits.txt- can't open";
	}
	else {
		for (int i = 0; i < sizeQ; i++) {
			fout << arrQ[i].title << endl;
			fout << arrQ[i].QA->quest;
			for (int j = 0; j < 3; j++) {
				fout << arrQ[i].QA->answears[j] << endl;
			}
			fout << arrQ[i].QA->rightA;
			if (i != sizeQ - 1) fout << endl;
		}
	}
	fout.close();
}

void addQ(){
	Quiz newQuiz;
	Quest newQuest;

	cout << "Enter title: ";
	cin >> newQuiz.title;

	for (int i = 0; i < 5; i++) {
		system("cls");
		cout << "Enter question " << i+1 << " / 5 : ";
		cin >> newQuest.quest;

		for (int i = 0; i < 3; i++) {
			cout << "Enter answear " << i + 1 << " / 3 :";
			cin >> newQuest.answears[i];
		}

		bool norm = true;
		do {
			int answ;
			norm = true;
			cout << "Enter index of right ansear (1-3): ";
			cin >> answ;
			if (answ <= 3 && answ > 0) newQuest.rightA = answ - 1;
			else norm = false;
		} while (norm != true);

		newQuiz.QA[i] = newQuest;
	}

	Quiz* temp = new Quiz[sizeQ];
	for (int i = 0; i < sizeQ; i++) {
		temp[i] = arrQ[i];
	}

	sizeQ++;
	arrQ = new Quiz[sizeQ];
	
	for (int i = 0; i < sizeQ - 1; i++) {
		arrQ[i] = temp[i];
	}
	arrQ[sizeQ-1] = newQuiz;
}

void takeQ() {
	int choose = 0;
	bool norm = true;
	int score = 0;

	system("cls");
	cout << "Quizes list: ";
	for (int i = 0; i < sizeQ; i++) {
		cout << i+1<<"."<< arrQ[i].title << endl;
	}
	do {
		cout << "\tChoose quiz to take it (1-" << sizeQ << ") :";
		
		cin >> choose;
		choose -= 1;
		if (choose >= 0 && choose < sizeQ) {}
		else norm = false;

	} while (norm != true);

	
	for (int i = 0; i < 5; i++) {
		int answear = 0;
		do {
			system("cls");
			cout << arrQ[choose].title << endl;
			cout << arrQ[choose].QA[i].quest <<"\t"<< i + 1 << " / 5" << endl;

			for (int j = 0; j < 3; j++) {
				cout << j + 1 << ". " << arrQ[choose].QA[i].answears[j] << endl;
			}
			cout << "Your choose: ";
			cin >> answear;
			norm = true;
			answear -= 1;
			if (answear >= 0 && answear < 3) {}
			else norm = false;
		} while (norm != true);
		if(arrQ[choose].QA[i].rightA == answear) score++;
	}

	system("cls");
	cout << "U passed the Quiz! Your score: " << score << endl;
	system("pause");
}