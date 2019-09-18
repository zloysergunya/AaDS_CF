#include <iostream>
#include <clocale>
#include <ctime>
#include <vector>

using namespace std;

void fastSolution(vector<int> sequence, int n) {
	int* buffer = new int[sequence.size()];
	for (int i = 0; i < sequence.size(); i++) {
		buffer[i] = 0;
	}

	for (int i = 0; i < sequence.size(); i++) {
		int n = sequence[i];
		buffer[n]++;
	}

	cout << "Максимальные элементы последовательности: ";
	for (int i = sequence.size(); i >= sequence.size() - n; i--) {
		int n = buffer[i];

		while (n > 0) {
			cout << " " << i;
			n--;
		}
	}

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

	int n;
	cout << "Введите количество элементов: ";
	cin >> n;

	vector<int> sequence;
	for (int i = 0; i < n; i++) {
		sequence.push_back(rand() % 10);
	}
	for (int& i : sequence) cout << i << " ";

	startTime = time(NULL);
	fastSolution(sequence, n);
	finishTime = time(NULL);
	cout << "Время выполнения быстрой программы: " << difftime(finishTime, startTime);

	/*startTime = time(NULL);
	slowSolution(sequence);
	finishTime = time(NULL);
	cout << "Время выполнения медленной программы: " << difftime(finishTime, startTime);*/

	return 0;
}
