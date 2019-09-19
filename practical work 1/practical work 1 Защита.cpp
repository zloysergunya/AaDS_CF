#include <iostream>
#include <clocale>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void fastSolution(vector<int> sequence, int k) {
	
	sort(sequence.rbegin(), sequence.rend());

	cout << endl << k << "-максимальных членов последовательности: ";
	for (int i = 0; i < k; i++) {
		cout << " " << sequence[i];
	}
	cout << endl;
}

void slowSolution(vector<int> sequence) {
	for (int i = 0; i < sequence.size(); i++) {
		for (int j = sequence.size() - 1; j > i; j--) {
			if (sequence[j - 1] < sequence[j]) {
				int temp = sequence[j - 1];
				sequence[j - 1] = sequence[j];
				sequence[j] = temp;
			}
		}
	}

	cout << endl << endl << "Три максимальный элемента последовательности: " << sequence[0] << " " << sequence[1] << " " << sequence[2] << endl;
}

int main() {
	setlocale(LC_ALL, "");

	cout << "В имеющейся последовательности чисел требуется найти три максимальных элемента." << endl << endl;

	time_t startTime, finishTime;

	int n, k;
	cout << "Введите количество элементов: ";
	cin >> n;
	cout << "Введите количество максимальных элементов: ";
	cin >> k;

	vector<int> sequence;
	for (int i = 0; i < n; i++) {
		sequence.push_back(rand() % 10);
	}
	for (int& i : sequence) cout << i << " ";

	startTime = time(NULL);
	fastSolution(sequence, k);
	finishTime = time(NULL);
	cout << "Время выполнения быстрой программы: " << difftime(finishTime, startTime);

	/*startTime = time(NULL);
	slowSolution(sequence);
	finishTime = time(NULL);
	cout << "Время выполнения медленной программы: " << difftime(finishTime, startTime);*/

	return 0;
}
