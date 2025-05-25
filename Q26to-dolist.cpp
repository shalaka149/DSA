#include <iostream>
#include <string>
using namespace std;

// Task class to represent individual tasks
class Task {
public:
    string title;         // Title of the task
    int priority;         // Priority of the task (lower number means higher priority)
    bool isCompleted;     // Status of the task (completed or pending)
    Task* next;           // Pointer to the next task in the list

    // Constructor to initialize task details
    Task(string t, int p) {
        title = t;             // Set task title
        priority = p;          // Set task priority
        isCompleted = false;   // Initialize the task as not completed
        next = nullptr;        // Set next pointer to null (no next task initially)
    }
};

// ToDoList class to manage the list of tasks
class ToDoList {
private:
    Task* head;           // Head of the task list (all tasks, both pending and completed)

public:
    // Constructor to initialize the list to nullptr
    ToDoList() {
        head = nullptr;  // No tasks initially in the list
    }

    // Function to add a task to the list (insert by priority)
    void addTask(string title, int priority) {
        Task* newTask = new Task(title, priority);  // Create a new task
        if (head == nullptr || head->priority > priority) {
            newTask->next = head;  // Insert task at the beginning if it's the highest priority
            head = newTask;  // Update head to the new task
        } else {
            Task* temp = head;
            while (temp->next != nullptr && temp->next->priority <= priority) {
                temp = temp->next;  // Traverse the list to find the correct position
            }
            newTask->next = temp->next;  // Insert the new task at the found position
            temp->next = newTask;  // Update the next pointer of the previous task
        }
    }

    // Function to display tasks based on completion status (true for completed, false for pending)
    void displayTasks(bool completed) {
        Task* temp = head;  // Start from the head of the list
        if (temp == nullptr) {
            cout << "No tasks available." << endl;  // If the list is empty, print a message
            return;
        }

        // Traverse the list and display tasks that match the completion status
        while (temp != nullptr) {
            if (temp->isCompleted == completed) {
                cout << "Title: " << temp->title
                     << " | Priority: " << temp->priority
                     << " | Status: " << (temp->isCompleted ? "Completed" : "Pending") << endl;
            }
            temp = temp->next;  // Move to the next task
        }
    }

    // Function to delete a task from the list
    void deleteTask(string title) {
        Task* temp = head;  // Start from the list
        Task* prev = nullptr;  // To track the previous task

        // Traverse the list to find the task with the given title
        while (temp != nullptr && temp->title != title) {
            prev = temp;  // Update the previous task
            temp = temp->next;  // Move to the next task
        }

        if (temp == nullptr) {
            cout << "Task not found!" << endl;  // If task is not found, print a message
            return;
        }

        // Remove the task from the list
        if (prev == nullptr) {
            head = temp->next;  // If it's the first task, update head
        } else {
            prev->next = temp->next;  // Otherwise, skip the current task
        }

        delete temp;  // Delete the task
        cout << "Task '" << title << "' has been deleted." << endl;
    }

    // Function to mark a task as completed
    void markTaskCompleted(string title) {
        Task* temp = head;  // Start from the task list
        while (temp != nullptr && temp->title != title) {
            temp = temp->next;  // Traverse the list to find the task with the given title
        }

        if (temp == nullptr) {
            cout << "Task not found!" << endl;  // If task is not found, print a message
            return;
        }

        // Mark the task as completed
        temp->isCompleted = true;
        cout << "Task '" << title << "' marked as completed." << endl;
    }

    // Destructor to free allocated memory for tasks
    ~ToDoList() {
        // Delete all tasks from the list
        while (head != nullptr) {
            Task* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Accessor method for head (optional, if you need it)
    Task* getHead() { return head; }
};

int main() {
    ToDoList todoList;  // Create a ToDoList object
    int choice;
    string title;
    int priority;

    do {
        cout << "\nTo-Do List Application" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Display Pending Tasks" << endl;
        cout << "5. Display Completed Tasks" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // To ignore any leftover newline character in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter task title: ";
                getline(cin, title);
                cout << "Enter task priority (lower number means higher priority): ";
                cin >> priority;
                todoList.addTask(title, priority);
                break;
            case 2:
                cout << "Enter task title to delete: ";
                getline(cin, title);
                todoList.deleteTask(title);
                break;
            case 3:
                cout << "Enter task title to mark as completed: ";
                getline(cin, title);
                todoList.markTaskCompleted(title);
                break;
            case 4:
                todoList.displayTasks(false);  // Display pending tasks (not completed)
                break;
            case 5:
                todoList.displayTasks(true);   // Display completed tasks
                break;
            case 6:
                cout << "Exiting the application..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
