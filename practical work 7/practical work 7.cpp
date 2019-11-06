#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#pragma warning(disable : 4996)

using namespace std;
void simpleMergingSort(const char* name) {
	int a1, a2, k, i, j, kol, tmp;
	FILE *f, *f1, *f2;
	kol = 0;
	if ((f = fopen(name, "r")) == NULL)
		printf("Исходный файл не может быть прочитан...");
	else {
		while (!feof(f)) {
			fscanf(f, "%d", &a1);
			kol++;
		}
		fclose(f);
	}
	k = 1;
	while (k < kol) {
		f = fopen(name, "r");
		f1 = fopen("smsort_1", "w");
		f2 = fopen("smsort_2", "w");
		if (!feof(f)) fscanf(f, "%d", &a1);
		while (!feof(f)) {
			for (i = 0; i < k && !feof(f); i++) {
				fprintf(f1, "%d ", a1);
				fscanf(f, "%d", &a1);
			}
			for (j = 0; j < k && !feof(f); j++) {
				fprintf(f2, "%d ", a1);
				fscanf(f, "%d", &a1);
			}
		}
		fclose(f2);
		fclose(f1);
		fclose(f);

		f = fopen(name, "w");
		f1 = fopen("smsort_1", "r");
		f2 = fopen("smsort_2", "r");
		if (!feof(f1)) fscanf(f1, "%d", &a1);
		if (!feof(f2)) fscanf(f2, "%d", &a2);
		while (!feof(f1) && !feof(f2)) {
			i = 0;
			j = 0;
			while (i < k && j < k && !feof(f1) && !feof(f2)) {
				if (a1 < a2) {
					fprintf(f, "%d ", a1);
					fscanf(f1, "%d", &a1);
					i++;
				}
				else {
					fprintf(f, "%d ", a2);
					fscanf(f2, "%d", &a2);
					j++;
				}
			}
			while (i < k && !feof(f1)) {
				fprintf(f, "%d ", a1);
				fscanf(f1, "%d", &a1);
				i++;
			}
			while (j < k && !feof(f2)) {
				fprintf(f, "%d ", a2);
				fscanf(f2, "%d", &a2);
				j++;
			}
		}
		while (!feof(f1)) {
			fprintf(f, "%d ", a1);
			fscanf(f1, "%d", &a1);
		}
		while (!feof(f2)) {
			fprintf(f, "%d ", a2);
			fscanf(f2, "%d", &a2);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
		k *= 2;
	}
	remove("smsort_1");
	remove("smsort_2");
}

void simpleMergingSort2(const char* name) {
	int a1, a2, k, i, j, kol, tmp;
	fstream f, f1, f2;
	FILE* f, * f1, * f2;
	kol = 0;
	if (!f.is_open()) {
		printf("Исходный файл не может быть прочитан...");
	}
	else {
		while (!f.eof()) {
			f >> a1;
			kol++;
		}
		f.close();
	}
	k = 1;
	while (k < kol) {
		f.open(name);
		f1.open("smsort_1.txt");
		f2.open("smsort_2.txt");
		if (!f.eof()) f >> a1;

		while (!f.eof()) {
			for (i = 0; i < k && !f.eof(); i++) {
				f1 << a1;
				f >> a1;
			}
			for (j = 0; j < k && !f.eof(); j++) {
				f2 << a1;
				f >> a1;
			}
		}
		f2.close();
		f1.close();
		f.close();

		f.open(name);
		f1.open("smsort_1.txt");
		f2.open("smsort_2.txt");
		if (!f1.eof()) f1 >> a1;
		if (!f2.eof()) f2 >> a2;
		while (!f1.eof() && !f2.eof()) {
			i = 0;
			j = 0;
			while (i < k && j < k && !f1.eof() && !f2.eof()) {
				if (a1 < a2) {
					f << a1;
					f1 >> a1;
					i++;
				}
				else {
					f << a2;
					f2 >> a2;
					j++;
				}
			}
			while (i < k && !f1.eof()) {
				f << a1;
				f1 >> a1;
				i++;
			}
			while (j < k && !f2.eof()) {
				f << a2;
				f2 >> a2;
				j++;
			}
		}
		while (!f1.eof()) {
			f << a1;
			f1 >> a1;
		}
		while (!f2.eof()) {
			f << a2;
			f >> a2;
		}
		f2.close();
		f1.close();
		f.close();
		k *= 2;
	}
}


int main() {
	setlocale(LC_ALL, "");

	simpleMergingSort2("input.txt");

	cout << "Сортировка прошла успешно! Проверьте исходных файл!" << endl;

	return 0;
}
