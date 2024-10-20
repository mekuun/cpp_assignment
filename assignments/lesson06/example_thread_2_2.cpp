/*
Запустите приведенный выше пример несколько раз,
вы сможете убедиться, что при наличии общего ресурса (std::cout)
результат работы программы может вести себя непредсказуемо.
*/

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

// std::mutex mtx;

void func(int a) {
  // mtx.lock();
  for (int i = 0; i < 3; i++) {
    std::cout << a + i;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << " ";
  }
  std::cout << "\n";
  // mtx.unlock();
}

int main() {
  std::thread th1(func, 1);
  std::thread th2(func, 4);

  th1.join();
  th2.join();

  return 0;
}