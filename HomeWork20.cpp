#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

template <typename T>
void print_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

}
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	if (left > right)
		std::swap(left, right);
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (right + 1 - left) + left;
	}
}
template <typename T>
int search_index(T arr[], const int length, T key, int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == key)
			return i;
	return -1;
}
template <typename T>
int search_last_index(T arr[], const int length, T key) {
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == key)
			return i;
	return -1;
}
template <typename T>
int search_last_index(T arr[], const int length, T key, int begin) {
	for (int i = begin; i >= 0; i--)
		if (arr[i] == key)
			return i;
	return -1;
}

int arr_min(int arr[], const int length) {
	int min = arr[0];
		for (int i = 1; i < length; i++) {
			if (min > arr[i])
				min = arr[i];
		}
	return min;
}
int arr_max(int arr[], const int length) {
	int max = arr[0];
	for (int i = 1; i < length; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int mean_value(int arr[], const int length) {
	int value = arr[0];
	for (int i = 1; i < length;i++)
		value += arr[i];
	return value/ length;
}

void range(int arr[], const int length, int a, int b) {
	if (a > b)
		std::swap(a, b);
	for (int i = 0; i < length; i++)
		if (arr[i] >= a && arr[i] <= b)
			std::cout << arr[i] << ' ';
	std::cout << '\n';
}


int count(int arr[], const int length, int x) {
	int count = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == x)
			count++;
	return count;
}

void sort_arr(int arr[], const int length) {
	for (int i = length - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}




int main() {
	setlocale(LC_ALL, "ru");


	const int size = 20;
	int arr[size]{};
	fill_arr(arr, size, 50, -50);
		
	std::cout << "Массив: \n{ ";
	print_arr(arr, size);
	
	std::cout << "Введите число для поиска -> ";
	int n;
	std::cin >> n;

	int index1 = search_index(arr, size, n);
	if (index1 != -1)
		std::cout << "\nПозиция первого вхождения числа в массив: " << index1 << std::endl;
	else
		std::cout << "Числа нет в массиве!\n";

	int index2 = search_last_index(arr, size, n);
	if (index2 != -1)
		std::cout << "\nПозиция последнего вхождения числа в массив: " << index2 << std::endl;
	else
		std::cout << "Числа нет в массиве!\n";
		
	std::cout << "\nМинимальное число в массиве : " <<  arr_min(arr,size) << std::endl;
	std::cout << "\nМаксимальное число в массиве : " << arr_max(arr, size) << std::endl;
	std::cout << "\nСреднее арифметическое масива : " << mean_value(arr, size) << std::endl;
	std::cout << "\nЭлементы массива входящие в диапазон от -25 до 25 : ";
	range(arr, size, 25, -25);
	std::cout << "\nКоличество вхождений переданного элемента в массив: " << count(arr, size, 28) << std::endl;
	sort_arr(arr,size);
	std::cout << "\nОтсортированный массив: ";
	print_arr(arr, size);





	return 0;
}



