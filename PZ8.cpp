#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Клас для представлення процесу
class Process {
private:
    int priority; // Приорітет процесу
public:
    Process(int initialPriority) : priority(initialPriority) {} // Конструктор з початковим приорітетом

    void increasePriority() {
        ++priority; // Збільшення приорітету
    }

    void decreasePriority() {
        --priority; // Зменшення приорітету
    }

    int getPriority() const {
        return priority; // Отримати поточний приорітет
    }
};

int main() {
    srand(time(nullptr)); // Ініціалізація генератора випадкових чисел

    const int initialPriority = 5; // Початковий приорітет процесу
    const int numProcesses = 10; // Кількість процесів

    std::vector<Process> processes; // Вектор для зберігання процесів

    // Ініціалізація процесів з випадковими початковими приорітетами
    for (int i = 0; i < numProcesses; ++i) {
        processes.push_back(Process(initialPriority));
    }

    // Симуляція обробки черги процесів
    for (int i = 0; i < 100; ++i) {
        int randomProcessIndex = rand() % numProcesses; // Випадковий вибір процесу
        Process& currentProcess = processes[randomProcessIndex]; // Поточний процес

        // Симуляція звертання до черги та отримання/невдачі отримання процесорного часу
        if (rand() % 2 == 0) {
            currentProcess.increasePriority(); // Збільшення приорітету процесу
            std::cout << "Process " << randomProcessIndex << " increased its priority to " << currentProcess.getPriority() << std::endl;
        }
        else {
            currentProcess.decreasePriority(); // Зменшення приорітету процесу
            std::cout << "Process " << randomProcessIndex << " decreased its priority to " << currentProcess.getPriority() << std::endl;
        }
    }

    return 0;
}
