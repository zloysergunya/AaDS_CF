#include <iostream>
#include <clocale>
#include <ctime>

#include <list>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	srand(time(0));

	// Постановка задачи
	cout << "Требуется умножить все элементы последовательности на элемент, находящийся в её середине." << endl << endl;
	
	int n;
	cout << "Введите число элементов массива: ";
	cin >> n;
	
	list<int> sequence;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand();
		sequence.push_back(arr[i]);
	}

	int middleIndexElement = arr[n / 2];

	time_t startTime, finishTime;

	startTime = time(NULL);
	// Прогон массива
	for (int i = 0; i < n; i++) {
		arr[i] *= middleIndexElement;
	}
	finishTime = time(NULL);

	/*cout << "Получившийся массив: " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}*/
	cout << endl << "Время выполнения прогона массива: " << difftime(finishTime, startTime);

	startTime = time(NULL);
	// Прогон двухсвязного списка
	for (int &i : sequence) {
		i *= middleIndexElement;
	}
	finishTime = time(NULL);
	
	cout << endl << "Время выполнения прогона двухсвязного списка: " << difftime(finishTime, startTime);
	cout << endl << "Получившийся двухсвязный список: " << endl;
	for (int i : sequence) cout << i << " ";

	return 0;
}