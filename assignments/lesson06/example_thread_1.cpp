#include <iostream>
#include <thread>

// Функция, которая будет выполняться в потоке
void threadFunction() {
  std::cout << "Hello from the thread!" << std::endl;
}

int main() {
  // Создаем поток
  std::thread thread(threadFunction);

  // Ожидаем завершения потока
  thread.join();

  return 0;
}