#include <iostream>
#include <vector>
#include <string>
#include <limits> // Required for numeric_limits

// --- Function Prototypes ---
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

        // Input validation to ensure the user enters a number
        while (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear(); // Clear the error flag
            // Discard the invalid input
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
        std::cout << "\n"; // Add a newline for better spacing
    } while (choice != 4);

    return 0;
}

/**
 * @brief Displays the main menu options to the user.
 */
void displayMenu() {
    std::cout << "===== TO-DO LIST =====\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Exit\n";
    std::cout << "======================\n";
}

/**
 * @brief Prompts the user for a task and adds it to the list.
 * @param tasks A reference to the vector of task strings.
 */
void addTask(std::vector<std::string>& tasks) {
    std::string taskDescription;
    std::cout << "Enter a new task: ";
    
    // Clear the input buffer before using getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    std::getline(std::cin, taskDescription);
    tasks.push_back(taskDescription);
    
    std::cout << "Task added successfully! 👍\n";
}

/**
 * @brief Displays all the tasks currently in the list.
 * @param tasks A constant reference to the vector of task strings.
 */
void viewTasks(const std::vector<std::string>& tasks) {
    std::cout << "\n--- Your Tasks ---\n";
    if (tasks.empty()) {
        std::cout << "Your to-do list is empty. 🎉\n";
    } else {
        // Loop through the vector and print each task with its number (1-based)
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
    std::cout << "------------------\n";
}

/**
 * @brief Deletes a task from the list based on user input.
 * @param tasks A reference to the vector of task strings.
 */
void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }

    viewTasks(tasks); // Show tasks to help user choose
    int taskNumber;
    std::cout << "Enter the task number to delete: ";
    std::cin >> taskNumber;
    
    // Input validation for the task number
    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> taskNumber;
    }


    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        // Erase the task. Adjust for 0-based vector indexing.
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task " << taskNumber << " deleted successfully! 🗑️\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}