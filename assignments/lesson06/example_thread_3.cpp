#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;  // Мьютекс для защиты общего ресурса
int sharedResource = 0;  // Общий ресурс

void increment() {
  mutex.lock();  // Защита доступа к общему ресурсу
  ++sharedResource;  // Увеличение общего ресурса
  mutex.unlock();    // Освобождение мьютекса
}

int main() {
  std::thread threads[10];  // Массив потоков

  // Создаем 10 потоков
  for (int i = 0; i < 10; ++i) {
    threads[i] = std::thread(increment);  // Инициализация каждого потока
  }

  // Ожидание завершения всех потоков
  for (int i = 0; i < 10; ++i) {
    threads[i].join();  // Присоединение каждого потока
  }

  std::cout << "Общий ресурс: " << sharedResource
            << std::endl;  // Вывод значения общего ресурса
  return 0;
}
