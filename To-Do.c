#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char description[100];
    struct Task* next;
};

struct Task* head = NULL;

void addTask(char desc[]) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    if (newTask == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(newTask->description, desc);
    newTask->next = head;
    head = newTask;

    printf("Task added successfully.\n");
}

void displayTasks() {
    if (head == NULL) {
        printf("No tasks in the to-do list.\n");
        return;
    }

    struct Task* current = head;
    printf("To-Do List:\n");
    while (current != NULL) {
        printf("- %s\n", current->description);
        current = current->next;
    }
}

void deleteTask(char desc[]) {
    struct Task* current = head;
    struct Task* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->description, desc) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Task deleted successfully.\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Task not found.\n");
}

int main() {
    int choice;
    char taskDescription[100];

    do {
        printf("\n1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]", taskDescription);
                addTask(taskDescription);
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                printf("Enter task description to delete: ");
                scanf(" %[^\n]", taskDescription);
                deleteTask(taskDescription);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}