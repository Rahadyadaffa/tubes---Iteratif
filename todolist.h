#ifndef TODOLIST_H_INCLUDED
#define TODOLIST_H_INCLUDED


#include <iostream>
#include <vector>
#include <string>

// Structure for a single todo task
struct Task {
    std::string description;
    bool completed;
};

// Class to manage todo list operations
class TodoList {
private:
    std::vector<Task> tasks;
public:
    void addTask(const std::string& description);
    void completeTask(int index);
    void printTasks() const;
    bool allTasksCompleted() const;
};

void testTodoListOperations(int numTasks);

#endif
