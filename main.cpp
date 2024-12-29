#include "todolist.h"

int main() {
    int n;
    std::cout << "Enter number of tasks: ";
    std::cin >> n;
    testTodoListOperations(n);
    return 0;
}
