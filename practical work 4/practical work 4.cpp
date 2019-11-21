#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
#include <ctime>

using namespace std;

int additive(int n) {
	int  sum = 0;
	int k = n;
	do {
		int a = n % 10;
		int b = (n / 10) % 10;
		sum += (a + b);
		n /= 10;
	} while ((n / 10) != 0);
	return sum;
}

int findRealIndexElement(int i, int elem, vector<int>& sequence) {
	for (; i < sequence.size(); ++i) {
		if (sequence[i] == elem) return i;
	}
	return -1;
}

int setNewID(int i, vector<int>& sequence) {
	if (i >= sequence.size()) return -1;
	return (sequence[i] == -1) ? i : setNewID(i + 1, sequence);
}

void deleteElement(int elem, vector<int>& sequence) {
	int i = additive(elem);
	i = findRealIndexElement(i, elem, sequence);
	sequence[i] = -1;
}

int addElement(int elem, vector<int>& sequence) {
	int i = additive(elem);
	i = setNewID(i, sequence);
	if (i == -1) return -1;
	sequence[i] = elem;
}

int main() {
	setlocale(LC_ALL, "");
	ifstream fin("input.txt");
	int n;
	fin >> n;
	vector <int> sequence(n, -1);

	for (int i = 0, k; i < n; ++i) {
		fin >> k;
		addElement(k, sequence);
	}

	for (auto &i : sequence) cout << i << " ";

	int key;
	cout << endl << "Введите элемент для поиска: ";
	cin >> key;

	time_t startTime, finishTime;

	startTime = time(NULL);
	n = additive(key);
	n = findRealIndexElement(n, key, sequence);
	if (n == -1) {
		cout << "Указанный элемент не найден!" << endl;
	}
	else {
		cout << "Индекс указанного элемента = " << n << endl;
	}
	finishTime = time(NULL);
	cout << endl << "Время поиска указанного элемента: " << difftime(finishTime, startTime) / 1000. << endl;

	cout << "Введите элемент для удаления: ";
	cin >> key;
	startTime = time(NULL);
	n = additive(key);
	n = findRealIndexElement(n, key, sequence);
	if (n == -1) {
		cout << "Не найден " << endl;
	}
	else {
		deleteElement(key, sequence);
	}
	finishTime = time(NULL);
	cout << endl << "Время удаления указанного элемента: " << difftime(finishTime, startTime) / 1000. << endl;

	cout << "Введите элемент для поиска: ";
	cin >> key;
	n = additive(key);
	n = findRealIndexElement(n, key, sequence);
	if (n == -1) {
		cout << "Указанный элемент не найден!" << endl;
	}
	else {
		cout << "Индекс указанного элемента = " << n << endl;
	}

	return 0;
}