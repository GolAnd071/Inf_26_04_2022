// ProblemC.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

struct Platform {
    int height;
    int min_energy;
    Platform()
        : height(0), min_energy(-1) {
    }
};

int d(const Platform& a, const Platform& b) {
    return abs(a.height - b.height);
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    Platform prevPlatform, curPlantform;
    cin >> prevPlatform.height >> curPlantform.height;
    prevPlatform.min_energy = 0;
    curPlantform.min_energy = d(prevPlatform, curPlantform);
    for (int i = 2; i < n; ++i) {
        Platform nextPlanftorm;
        cin >> nextPlanftorm.height;
        auto simple_step = d(nextPlanftorm, curPlantform) + curPlantform.min_energy;
        auto super_step = d(nextPlanftorm, prevPlatform) * 3 + prevPlatform.min_energy;
        nextPlanftorm.min_energy = min(simple_step, super_step);
        prevPlatform = curPlantform;
        curPlantform = nextPlanftorm;
    }
    cout << curPlantform.min_energy;
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
