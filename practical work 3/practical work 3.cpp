#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
#include <ctime>

using namespace std;

struct chains {
	int number;
	chains* link = nullptr;
};

int additive(int num) {
	int sum = 0;
	do {
		int a = num % 10;
		int b = (num / 10) % 10;
		sum += (a + b);
		num /= 10;
	} while ((num / 10) != 0);

	return sum;
}

void readFile(fstream & fin, vector<int> & sequence) {
	int buf;
	while (fin >> buf) {
		sequence.push_back(buf);
	}
}

void insert(int key, chains * *&hash_arr) {
	int sum = additive(key);
	chains* k = new chains;
	k->number = key;

	if (hash_arr[sum] == nullptr) {
		hash_arr[sum] = k;
		hash_arr[sum]->link = nullptr;
	}
	else {
		k->link = hash_arr[sum];
		hash_arr[sum] = k;
	}
}

void createHashTable(vector<int> main_arr, chains * *&hash_arr) {
	for (int i = 0; i < main_arr.size(); i++) {
		insert(main_arr[i], hash_arr);
	}
}

void searchElement(chains * *hash_arr) {
	int buf;
	cout << endl << "Введите число для поиска: ";
	cin >> buf;

	int key = additive(buf);
	int count_copise = 0;
	for (chains* i = hash_arr[key]; i != nullptr; i = i->link) {
		if (buf == i->number) {
			cout << i->number << " ";
			count_copise++;
		}
	}

	if (count_copise == 0) {
		cout << endl << "Заданное число не найдено" << endl;
	}
	else {
		cout << endl << "Количество копий данного числа в таблице: " << count_copise
			<< endl << "Номер списка в массиве: " << key << endl;
	}
}

void deleteElement(chains * *&sequence) {
	bool deleteComplete = false;
	int buf;
	cout << endl << "Введите число для удаления: ";
	cin >> buf;

	int key = additive(buf);
	for (chains* i = sequence[key], *back = sequence[key]; i != nullptr;) {
		if (buf == i->number) {
			deleteComplete = true;
			if (sequence[key] == i) sequence[key] = i->link;
			else if (i->link != nullptr) back->link = i->link;
			else back->link = nullptr;

			chains * deleteBuf = i;
			i = i->link;
			delete deleteBuf;
		}
		else {
			back = i;
			i = i->link;
		}
	}
	if (!deleteComplete) cout << endl << "Элемент не найден!" << endl;
}

void printHashTable(chains * *hash_arr) {
	for (int i = 0; i < 256; i++) {
		for (chains* j = hash_arr[i]; j != nullptr; j = j->link) {
			cout << " " << j->number;
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	fstream fin("input.txt");
	int n;
	cout << "Введите количество элементов для формирования хэш-таблицы не меньше 255: ";
	cin >> n;

	if (n < 255) {
		return -1;
	}

	chains** hash_arr = new chains * [n];
	for (int i = 0; i < 256; i++) {
		hash_arr[i] = NULL;
	}

	vector<int> buf;

	readFile(fin, buf);
	createHashTable(buf, hash_arr);

	int userChoise = -1;
	while (userChoise != 5) {
		cout << endl << "<===========>"
			<< endl << "Меню: "
			<< endl << "1. Поиск элемента в таблице"
			<< endl << "2. Вставить новый элемент"
			<< endl << "3. Удалить элемент таблицы"
			<< endl << "4. Вывести все элемента таблицы"
			<< endl << "5. Выйти из программы"
			<< endl;

		cout << "Выбор: ";
		cin >> userChoise;
		bool checker = cin.fail();

		if (userChoise < 1 || userChoise > 5) {
			cout << "Введите значение из [1;5]!" << endl;
		}
		else {
			switch (userChoise) {
			case 1:
				time_t startTime, finishTime;
				startTime = time(NULL);
				searchElement(hash_arr);
				finishTime = time(NULL);
				cout << "Время поиска составило: " << difftime(finishTime, startTime) /1000. << endl << endl;
				break;
			case 2:
				int key;
				cout << endl << "Введите значение нового элемента: ";
				cin >> key;
				insert(key, hash_arr);
				break;
			case 3:
				startTime = time(NULL);
				deleteElement(hash_arr);
				finishTime = time(NULL);
				cout << "Время удаления составило: " << difftime(finishTime, startTime) / 1000. << endl << endl;
				break;
			case 4:
				printHashTable(hash_arr);
				break;
			}
		}

	}

	return 0;
}
