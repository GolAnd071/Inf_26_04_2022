// ProblemA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

size_t binSearch(int32_t a[], int32_t key, size_t len)
{
    size_t l = 0;
    size_t r = len;
    while (l < r - 1) {
        size_t m = (l + r) / 2;
        if (a[m] < key)
            l = m;
        else
            r = m;
    }
    return r;
}

size_t findLIS(std::vector<int32_t> a)
{
    size_t n = a.size();
    int32_t* d = new int32_t[n + 1];
    size_t length = 0;

    d[0] = INT32_MIN;
    for (size_t i = 1; i <= n; ++i)
        d[i] = INT32_MAX;
    for (size_t i = 0; i <= n - 1; ++i) {
        size_t j = binSearch(d, a[i], n + 1);
        if (d[j - 1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            length = std::max(length, j);
        }
    }

    return length;
}

int main()
{
    size_t n;
    std::cin >> n;
    std::vector<int32_t> arr(n);
    std::for_each(arr.begin(), arr.end(), [](int32_t& elem)->void { std::cin >> elem; });

    std::cout << findLIS(arr) << '\n';
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
