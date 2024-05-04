#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 50

typedef struct {
    char task[MAX_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task() {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Too many tasks.\n");
        return;
    }

    printf("Enter the task: ");
    scanf(" %[^\n]", tasks[num_tasks].task);
    tasks[num_tasks].completed = 0;
    num_tasks++;
    printf("Task added successfully.\n");
}

void edit_task() {
    int index;
    printf("Enter the index of the task to edit (1-%d): ", num_tasks);
    scanf("%d", &index);
    if (index < 1 || index > num_tasks) {
        printf("Invalid index.\n");
        return;
    }
    printf("Enter the new task: ");
    scanf(" %[^\n]", tasks[index - 1].task);
    printf("Task edited successfully.\n");
}

void delete_task() {
    int index;
    printf("Enter the index of the task to delete (1-%d): ", num_tasks);
    scanf("%d", &index);
    if (index < 1 || index > num_tasks) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index - 1; i < num_tasks - 1; i++) {
        strcpy(tasks[i].task, tasks[i + 1].task);
        tasks[i].completed = tasks[i + 1].completed;
    }
    num_tasks--;
    printf("Task deleted successfully.\n");
}

void display_tasks() {
    if (num_tasks == 0) {
        printf("No tasks in the list.\n");
        return;
    }
    printf("Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s\n", i + 1, tasks[i].task);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Edit Task\n");
        printf("3. Delete Task\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                edit_task();
                break;
            case 3:
                delete_task();
                break;
            case 4:
                display_tasks();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}