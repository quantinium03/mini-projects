#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

class Task {
   public:
    std::string name;
    Task *next;

    Task(const std::string &task_name) : name(task_name), next(nullptr) {}
};

class TaskManager {
   private:
    Task *head;

   public:
    TaskManager() : head(nullptr) {}
    ~TaskManager() { freeTask(); }

    void insertTask(const std::string &name) {
        Task *new_task = new Task(name);
        new_task->next = head;
        head = new_task;
    }

    void printTask() {
        std::cout << "Tasks: " << std::endl;
        Task *current = head;
        while (current != nullptr) {
            std::cout << current->name << std::endl;
            current = current->next;
        }
    }

    void deleteTask(const std::string &name) {
        if (head == nullptr) {
            std::cout << "Task \"" << name << "not found." << std::endl;
            return;
        }
        if (head->name == name) {
            Task *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Task *current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Task *temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        std::cout << "Task \"" << name << "\" not found." << std::endl;
    }

    void freeTask() {
        while (head != nullptr) {
            Task *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    TaskManager task_manager;

    std::cout << "What do you wanna do: " << std::endl;
    std::cout << "Add a task[1],\n 2. delete a task[2],\n 3.print "
                 "all tasks[3], \n4. Delete everything[4]\n, 5. Stop[5]"
              << std::endl;

    int operation;
    std::string heading;
    while (operation != 5) {
        std::cin >> operation;
        switch (operation) {
        case 1:
            std::cout << "What task you wanna add" << std::endl;
            std::cin >> heading;
            task_manager.insertTask(heading);
            break;
        case 2:
            std::cout << "Which task do you wanna delete" << std::endl;
            std::cin >> heading;
            task_manager.deleteTask(heading);
            break;
        case 3:
            task_manager.printTask();
            break;
        case 4:
            task_manager.freeTask();
            break;
        default:
            std::cout << "Enter a valid operation number: " << std::endl;
        }
    }
    return 0;
}
