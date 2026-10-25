#include <stdio.h>

// --- Function Prototypes ---
void displayWelcome();
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int targetID, int ids[], int size);

int main() {
    int choice;
    displayWelcome(); // Call the welcome function once

    do {
        displayMenu(); // Show the menu
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                float amount;
                printf("\nEnter amount: ");
                scanf("%f", &amount);
                printf("VAT (15%%): %.2f\n", calculateVAT(amount));
                break;
            }
            case 2: {
                float basic, housing, transport;
                printf("\nBasic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;
            }
            case 3: {
                float rev, exp, balance;
                printf("\nEnter revenue: ");
                scanf("%f", &rev);
                printf("Enter expenses: ");
                scanf("%f", &exp);
                balance = calculateBudget(rev, exp);
                
                if (balance > 0) printf("Result: SURPLUS of %.2f\n", balance);
                else if (balance < 0) printf("Result: DEFICIT of %.2f\n", -balance);
                else printf("Result: BALANCED\n");
                break;
            }
            case 4: {
                int searchID;
                int employeeIDs[] = {101, 102, 103, 104, 105};
                int numEmployees = 5;
                
                printf("\nEnter employee ID to search: ");
                scanf("%d", &searchID);
                
                int position = searchEmployee(searchID, employeeIDs, numEmployees);
                if (position != -1) {
                    printf("Employee found at position %d.\n", position);
                } else {
                    printf("Employee not found.\n");
                }
                break;
            }
            case 5:
                printf("\nGoodbye.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// --- Function Definitions ---

void displayWelcome() {
    printf("=========================================\n");
    printf(" Welcome to the Municipal Financial System\n");
    printf("=========================================\n");
}

void displayMenu() {
    printf("\n--- MAIN MENU ---\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
}

float calculateVAT(float amount) {
    return amount * 0.15; // 15% VAT
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

int searchEmployee(int targetID, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == targetID) {
            return i; // Return the index (position)
        }
    }
    return -1; // Return -1 if not found
}