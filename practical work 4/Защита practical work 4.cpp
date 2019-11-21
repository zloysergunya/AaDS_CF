#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>


using namespace std;

struct chains {
	int str;
	chains* link = nullptr;
};

int main_hash_logic(int n) {
	int sum = 0;
	do {
		int a = n % 10;
		int b = (n / 10) % 10;
		sum += (a + b);
		n /= 10;
	} while ((n / 10) != 0);
	return sum;
	//мы сначала складываем все коды знаков , а вотом остаток от деления на 256 возвращаем
}

void read_file(fstream& file, vector<int>& main_arr)//считываение значений из файла
{
	int buf;//переменная буфер для ввода

	while (file >> buf)
	{
		main_arr.push_back(buf);
	}
}

void insert(int key, chains**& hash_arr)
{
	int sum = main_hash_logic(key);//вычисляем ключ

	chains* k = new chains;//создаем буферную переменную для хранения ячецки
	k->str = key;//присваиваем ец значение из буферного вектора

	if (hash_arr[sum] == nullptr)//проверяем на первй элемент в строке ква
	{
		hash_arr[sum] = k;
		hash_arr[sum]->link = nullptr;
	}
	else
	{
		k->link = hash_arr[sum];
		hash_arr[sum] = k;
	}
}

void hash_fun(vector<int> main_arr, chains**& hash_arr)//функция создания хэш таблицы
{
	for (int i = 0; i < main_arr.size(); i++)//идем по всем строкам вектора
	{
		insert(main_arr[i], hash_arr);
	}
}

void serch(chains** hash_arr)//функция поиска нужных элементов
{
	int buf;//буфер для ввода
	cout << "\nВедите число для поиска: ";
	cin >> buf;

	int key = main_hash_logic(buf);//вычисляем ключ для быстроко перемещения
								   //в нужный узел массива списков
	int count_copise = 0;//счетчик количества повторяющихся слов
	for (chains* i = hash_arr[key]; i != nullptr; i = i->link)//проходим полностью по списку
	{
		if (buf == i->str)//если находим нужное слово
		{
			cout << i->str << " ";//то выводим его
			count_copise++;//и увеличиваем на 1 количество одинаковых слов
		}
	}

	if (count_copise == 0)//если не нашел н одного слова
		cout << "\nНет данного числа\n";//то выводим сообщение об отсутствии этого слова
	else//иначе выводим информацию
		cout << "\nКоличество копий данного числа в таблице: " << count_copise
		<< "\nНомер списка в массиве: " << key << "\n";
}

void deleter(chains**& hash_arr)//удаление строки в таблице
{
	bool delete_complit = false;
	int buf;//буфер под ввод
	cout << "\nВедите число для удаления: ";
	cin >> buf;

	int key = main_hash_logic(buf);//находим ключ для быстрого перемещения по массиву списков

	for (chains* i = hash_arr[key], *back = hash_arr[key]; i != nullptr;)//проходим по всему списку
	{
		if (buf == i->str)//если совпало слово с нужным
		{
			delete_complit = true;
			if (hash_arr[key] == i)//если эта ячейка списка стоит в самом начале
				hash_arr[key] = i->link;
			else if (i->link != nullptr)//если стоит в середине
				back->link = i->link;
			else//если стоит в конце
				back->link = nullptr;

			chains* del_buf = i;//создаем указатель на место удаления
			i = i->link;//переводим наш счетчик на следующий элемент
			delete del_buf;//удаляем нашу ячейку из памяти
		}
		else//если слово не нашлось , то идем дальше по списку
		{
			back = i;
			i = i->link;
		}
	}
	if (!delete_complit)
		cout << "\nНе найден!\n";
}

void print_all(chains** hash_arr)//выводим все элементы хэш таблицы
{
	for (int i = 0; i < 256; i++)
	{
		for (chains* j = hash_arr[i]; j != nullptr; j = j->link)
		{
			cout << " " << j->str;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "");

	fstream file_str("in.txt");

	chains** hash_arr = new chains * [1000];//массив списков
	for (int i = 0; i < 256; i++)
		hash_arr[i] = nullptr;

	vector<int> buf_arr;//временный массив

	read_file(file_str, buf_arr);//вызываем функцию чтения из файла

	hash_fun(buf_arr, hash_arr);//вызываем функию формирования хэш-таблицы

	int user = 0;//переменная под действия пользователя

	while (user != 5)//диалог с пользователем
	{
		cout << "\nВведите цифру соответствующую действию"
			<< "\n1 Поиск элемента в таблице"
			<< "\n2 Удалить элемент таблицы"
			<< "\n3 Вывести все элемента таблицы"
			<< "\n4 Вставить новый элемент"
			<< "\n5 Выйти из программы\n";

		cin >> user;

		switch (user)
		{
		case 1:
			serch(hash_arr);
			break;
		case 2:
			deleter(hash_arr);
			break;
		case 3:
			print_all(hash_arr);
			break;
		case 4:
			int key;
			cout << "\nВведите значение нового элемента: ";
			cin >> key;
			insert(key, hash_arr);
			break;
		}
	}
}
