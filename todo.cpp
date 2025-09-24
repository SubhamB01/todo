#include <iostream>
#include <vector>
#include <string>
#include <limits> 


void displayMenu();
void addTask(std::vector<std::string>& tasks);
void viewTasks(const std::vector<std::string>& tasks);
void deleteTask(std::vector<std::string>& tasks);

int main() {
    std::vector<std::string> tasks;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        
        while (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                std::cout << "Goodbye! 👋\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        std::cout << "\n"; 
    } while (choice != 4);

    return 0;
}


void displayMenu() {
    std::cout << "===== TO-DO LIST =====\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Exit\n";
    std::cout << "======================\n";
}


void addTask(std::vector<std::string>& tasks) {
    std::string taskDescription;
    std::cout << "Enter a new task: ";
    
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::getline(std::cin, taskDescription);
    tasks.push_back(taskDescription);
    
    std::cout << "Task added successfully! 👍\n";
}


void viewTasks(const std::vector<std::string>& tasks) {
    std::cout << "\n--- Your Tasks ---\n";
    if (tasks.empty()) {
        std::cout << "Your to-do list is empty. 🎉\n";
    } else {
        
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
    std::cout << "------------------\n";
}


void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }

    viewTasks(tasks); 
    int taskNumber;
    std::cout << "Enter the task number to delete: ";
    std::cin >> taskNumber;
    
   
    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> taskNumber;
    }


    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task " << taskNumber << " deleted successfully! 🗑️\n";
    } else {
        std::cout << "Invalid task number.\n";
    }

}
