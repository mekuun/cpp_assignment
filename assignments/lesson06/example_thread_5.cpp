#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mutex; // Мьютекс для защиты общего ресурса
std::vector<int> sharedArr(10, 0); // Общий вектор, который потоки будут изменять

void incrementPart(int start, int end) {
    for (int i = start; i < end; ++i) {
        // Блокируем мьютекс для безопасного доступа к sharedArr
        mutex.lock();
        sharedArr[i] += 1; // Увеличиваем элемент
        mutex.unlock();
    }
}

int main() {
    const int numThreads = 2; // Количество потоков
    std::thread threads[numThreads];
    int chunkSize = sharedArr.size() / numThreads;

    // Создание потоков
    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? sharedArr.size() : (i + 1) * chunkSize;
        threads[i] = std::thread(incrementPart, start, end);
    }

    // Ожидание завершения всех потоков
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    // Вывод значений вектора
    for (const auto& value : sharedArr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}