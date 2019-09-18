#include <iostream>
#include <clocale>
#include <ctime>
#include <vector>

using namespace std;

void fastSolution(vector<int> sequence) {
	bool first;
	vector<int> buffer;
	buffer.push_back(sequence[0]);
	buffer.push_back(sequence[1]);
	buffer.push_back(sequence[2]);
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] > buffer[0]) {
			buffer[2] = buffer[1];
			buffer[1] = buffer[0];
			buffer[0] = sequence[i];
		} 
		else if (sequence[i] > buffer[1]) {
			buffer[2] = buffer[1];
			buffer[1] = sequence[i];
		}
		else if (sequence[i] > buffer[2]) {
			buffer[2] = sequence[i];
		}
	}

	cout << endl << endl << "Три максимальный элемента последовательности: " << buffer[0] << " " << buffer[1] << " " << buffer[2] << endl;
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
		sequence.push_back(rand());
	}
	// for (int& i : sequence) cout << i << " ";

	startTime = time(NULL);
	fastSolution(sequence);
	finishTime = time(NULL);
	cout << "Время выполнения быстрой программы: " << difftime(finishTime, startTime);

	startTime = time(NULL);
	slowSolution(sequence);
	finishTime = time(NULL);
	cout << "Время выполнения медленной программы: " << difftime(finishTime, startTime);

	return 0;
}
