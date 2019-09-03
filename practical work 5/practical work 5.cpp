#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

vector<int> gnomeSort(vector<int> sequence) {
	for (int i = 0; i + 1 < sequence.size(); ++i) {
		if (sequence[i] > sequence[i+1]) {
			int temp = sequence[i]; 
			sequence[i] = sequence[i + 1]; 
			sequence[i + 1] = temp;

			if (i != 0) {
				i -= 2;
			}
		}
	}
	return sequence;
}

vector<int> quickSort(vector<int> sequence) {
	int mid, count;
	int first = 0, last = sequence.size() - 1;
	int f = first, l = last;
	mid = sequence[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (sequence[f] < mid) f++;
		while (sequence[l] > mid) l--;
		if (f <= l) //перестановка элементов
		{
			count = sequence[f];
			sequence[f] = sequence[l];
			sequence[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quickSort(sequence);
	if (f < last) quickSort(sequence);

	return sequence;
}

int main() {
	setlocale(LC_ALL, "");
	srand(time(0));

	vector<int> sequence;
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		sequence.push_back(rand());
	}

	for (int& i : sequence) cout << i << " ";

	time_t startTime, finishTime;

	cout << endl << endl;

	startTime = time(NULL);
	sequence = gnomeSort(sequence);
	finishTime = time(NULL);
	for (int& i : sequence) cout << i << " ";
	cout << endl << "Время гномьей сортировки: " << difftime(finishTime, startTime);

	startTime = time(NULL);
	sequence = quickSort(sequence);
	finishTime = time(NULL);
	for (int& i : sequence) cout << i << " ";
	cout << endl << "Время гномьей сортировки: " << difftime(finishTime, startTime);


	return 0;
}