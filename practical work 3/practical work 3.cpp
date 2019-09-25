#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void fill_sequence(vector<int> &sequence) {
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		sequence.push_back(rand() % 10);
	}
}

void print_sequence(vector<int>& sequence) {
	cout << "Текущий вектор: " << endl;
	for (int& i : sequence) cout << " " << i;
	cout << endl;
}

// Последовательный поиск
int searchIncremental(vector<int>& sequence, int key) {
	int min = abs(sequence[0] - key);
	int ch = NULL;
	for (int i = 0; i < sequence.size(); i++) {
		if (abs(sequence[i] - key) <= min) {
			min = abs(sequence[i] - key);
			ch = sequence[i];

		}
	}
	return ch;
}

// Двоичный поиск
int searchBinary(vector<int> &sequence, int key) {
	int midd = 0;
	int left = 0;
	int right = sequence.size() - 1;

	while (true) {
		for (int i = 0; i < right; i++) {
			int midd = (right + left) / 2;
			if (sequence[midd] > key) {
				right = midd;
			}
			else {
				left = midd;
			}

		}
		if (left != right) {
			return (abs(sequence[right] - key) < abs(sequence[left] - key) ? right : left);
		}
		return left;
	}
}

int main() {
	setlocale(LC_ALL, "");
	srand(time(0));

	vector<int> sequence;

	fill_sequence(sequence);
	print_sequence(sequence);

	int key;
	cout << "Введите искомое число: ";
	cin >> key;

	
	// Сортируем массив за O(nlogn)
	sort(sequence.begin(), sequence.end());

	time_t startTime, finishTime;
	startTime = time(NULL);
	int index = searchBinary(sequence, key);
	finishTime = time(NULL);
	cout << endl << "Элемент, наиболее близкий к заданному: " << sequence[index] << endl;
	cout << "Время двоичного поиска составило: " << difftime(finishTime, startTime) << endl << endl;

	startTime = time(NULL);
	index = searchIncremental(sequence, key);
	finishTime = time(NULL);
	cout << "Элемент, наиболее близкий к заданному: " << index << endl;
	cout << "Время последовательного поиска составило: " << difftime(finishTime, startTime) << endl << endl;

	return 0;
}