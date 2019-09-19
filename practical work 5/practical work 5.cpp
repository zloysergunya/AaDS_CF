#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

vector<int> gnomeSort(vector<int> sequence) {
	for (int i = 0; i + 1 < sequence.size(); ++i) {
		if (sequence[i] > sequence[i + 1]) {
			int temp = sequence[i];
			sequence[i] = sequence[i + 1];
			sequence[i + 1] = temp;

			if (i != 0) i -= 2;
		}
	}
	return sequence;
}

void quickSort(vector<int> &sequence, int low, int high) {
	int i = low;
	int j = high;
	int x = sequence[(low + high) / 2];
		
	do {
		while (sequence[i] < x) ++i;
		while (sequence[j] > x) --j;

		if (i <= j) {
			int temp = sequence[i];
			sequence[i] = sequence[j];
			sequence[j] = temp;
			i++; j--;
		}
	} while (i < j);

	if (low < j) quickSort(sequence, low, j);	
	if (i < high) quickSort(sequence, i, high);
}

// Сортировка кучей
void heapSort(vector<int>& sequence) {

}

int main() {
	setlocale(LC_ALL, "");
	srand(time(0));

	vector<int> sequence;
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;

	for (int i = 0; i < n; i++) sequence.push_back(rand());

	for (int& i : sequence) cout << i << " ";

	time_t startTime, finishTime;

	cout << endl << endl;

	/*startTime = time(NULL);
	vector<int> newSequence = gnomeSort(sequence);
	finishTime = time(NULL);
	cout << "Результат гномьей сортировки: " << endl;
	for (int& i : newSequence) cout << i << " ";
	cout << endl << "Время гномьей сортировки: " << difftime(finishTime, startTime)/1000. << endl;

	startTime = time(NULL);
	quickSort(sequence, 0, sequence.size() - 1);
	finishTime = time(NULL);
	cout << "Результат быстрой сортировки: " << endl;
	for (int& i : sequence) cout << i << " ";
	cout << endl << "Время быстрой сортировки: " << difftime(finishTime, startTime)/1000. << endl;*/

	startTime = time(NULL);
	heapSort(sequence);
	finishTime = time(NULL);
	cout << "Результат быстрой сортировки: " << endl;
	for (int& i : sequence) cout << i << " ";
	cout << endl << "Время быстрой сортировки: " << difftime(finishTime, startTime) / 1000. << endl;

	return 0;
}
