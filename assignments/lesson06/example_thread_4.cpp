#include <iostream>
#include <vector>
#include <thread>

void processPart(const std::vector<int>& arr, int start, int end) {
    for (int i = start; i < end; ++i) {
        // Обработка элемента arr[i]
        std::cout << "Processing: " << arr[i] << std::endl;
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int numThreads = 2; // Количество потоков
    std::thread threads[numThreads];

    int chunkSize = arr.size() / numThreads;

    // Создание потоков с указанием границ
    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? arr.size() : (i + 1) * chunkSize; // Обработка последнего сегмента
        threads[i] = std::thread(processPart, std::ref(arr), start, end);
    }

    // Ожидание завершения всех потоков
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}