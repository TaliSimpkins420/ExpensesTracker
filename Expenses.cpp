#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Expense {
    string date;
    string category;
    double amount;
};

// Function to add an expense
void addExpense(vector<Expense>& expenses) {
    Expense e;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> e.date;
    cout << "Enter category (e.g. Food, Transport): ";
    cin >> e.category;
    cout << "Enter amount: ";
    cin >> e.amount;
    expenses.push_back(e);
    cout << "Expense added successfully!\n";
}

// Function to display all expenses
void viewExpenses(const vector<Expense>& expenses) {
    cout << "\n--- All Expenses ---\n";
    for (const auto& e : expenses) {
        cout << e.date << " | " << e.category << " | $" << e.amount << endl;
    }
}

// Function to save expenses to a file
void saveExpenses(const vector<Expense>& expenses, const string& filename) {
    ofstream file(filename);
    for (const auto& e : expenses) {
        file << e.date << " " << e.category << " " << e.amount << endl;
    }
    file.close();
}

// Function to load expenses from a file
void loadExpenses(vector<Expense>& expenses, const string& filename) {
    ifstream file(filename);
    Expense e;
    while (file >> e.date >> e.category >> e.amount) {
        expenses.push_back(e);
    }
    file.close();
}

int main() {
    vector<Expense> expenses;
    string filename = "expenses.txt";

    // Load any existing expenses
    loadExpenses(expenses, filename);

    int choice;
    do {
        cout << "\nExpense Tracker Menu:\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                viewExpenses(expenses);
                break;
            case 3:
                saveExpenses(expenses, filename);
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
