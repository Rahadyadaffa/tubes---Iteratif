#include "todolist.h"
#include <chrono>

void TodoList::addTask(const std::string& description) {
    tasks.push_back({description, false});
}

void TodoList::completeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
    }
}

void TodoList::printTasks() const {
    for (size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];
        std::cout << (task.completed ? "[X] " : "[ ] ") << task.description << std::endl;
    }
}


bool TodoList::allTasksCompleted() const {
    for (const auto& task : tasks) {
        if (!task.completed) return false;
    }
    return true;
}

void testTodoListOperations(int numTasks) {
    TodoList myList;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numTasks; i++) {
        myList.addTask("Task " + std::to_string(i + 1));
    }

    for (int i = 0; i < numTasks; i += 2) {  // Complete every second task
        myList.completeTask(i);
    }

    myList.printTasks();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Number of tasks(iteratif): " << numTasks << std::endl;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;
}

