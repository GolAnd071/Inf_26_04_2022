// Sorts.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

#include "Sorts.h"

int main()
{
	std::vector<int> v = {5, 5, 1, 3, 1, 4, 3, 5, 1, 2, 3, 2, 1, 5, 4, 3, 2, 1};
	bubbleSort(v.begin(), v.end());
	for (auto i : v)
		std::cout << i << ' ';
	std::cout << '\n';
	mergeSort(v.begin(), v.end(), [](const int l, const int r) { return l < r; });
	for (auto i : v)
		std::cout << i << ' ';
	std::cout << '\n';
	heapSort(v.begin(), v.end(), [](const int l, const int r) { return l > r; });
	for (auto i : v)
		std::cout << i << ' ';
	std::cout << '\n';
	quickSort(v.begin(), v.end(), [](const int l, const int r) { return l < r; });
	for (auto i : v)
		std::cout << i << ' ';
	std::cout << '\n';
	countingSort(v.begin(), v.end(), [](const int l, const int r) { return l > r; });
	for (auto i : v)
		std::cout << i << ' ';
	std::cout << '\n';
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
