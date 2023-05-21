#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;
typedef int Info;

struct Elem {
    Elem* link;
    Info info;
};

Elem* top = NULL;

void push(Elem*& top, int value) 
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = top;
    top = tmp;
}

void printStack(Elem* top) 
{
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }

    Elem* current = top;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

int getStackLength(Elem* top) 
{
    int length = 0;
    Elem* current = top;
    while (current != nullptr) {
        length++;
        current = current->link;
    }
    return length;
}

Elem* concatenateStacks(Elem* stack1, Elem* stack2)
{
    Elem* newStack = nullptr;
    Elem* current = stack1;

    // Copy elements from stack1 to newStack
    while (current != nullptr) {
        push(newStack, current->info);
        current = current->link;
    }

    current = stack2;

    // Copy elements from stack2 to newStack
    while (current != nullptr) {
        push(newStack, current->info);
        current = current->link;
    }

    return newStack;
}

void input(Elem*& top)
{
    int choice;
    cout << "Get number input:" << endl;
    cout << "1. Enter numbers from the keyboard" << endl;
    cout << "2. Read numbers from file" << endl;
    cout << "Your choice: ";
    cin >> choice;
    cout << endl;
    
    if (choice == 1)
    {
        string inputString;
        cout << "Enter numbers separated by spaces: ";
        cin.ignore(); // Ignore the newline character from the previous input
        getline(cin, inputString);

        istringstream iss(inputString);
        int number;
        while (iss >> number) {
            push(top, number);
        }
    }
    else if (choice == 2)
    {
        string filename;
        cout << "Enter file name: ";
        cin >> filename;
    
        ofstream file(filename);
        if (!file.is_open())
        {
            cout << "Failed to create the file!" << endl;
            return;
        }
    
        int count;
        cout << "Enter number of numbers: ";
        cin >> count;
    
        for (int i = 0; i < count; i++)
        {
            Info value;
            cout << "Enter number: ";
            cin >> value;
            file << value << " ";
            push(top, value);
        }
    
        file.close();
    }
    else
    {
        cout << "Wrong choice!" << endl;
    }
}

int main() {
    Elem* stack1 = nullptr;
    Elem* stack2 = nullptr;

    input(stack1);
    cout << endl;
    
    input(stack2);
    cout << endl;

    cout << "Stack 1: ";
    printStack(stack1);
    cout << "Length of Stack 1: " << getStackLength(stack1) << endl;
    cout << endl;

    cout << "Stack 2: ";
    printStack(stack2);
    cout << "Length of Stack 2: " << getStackLength(stack2) << endl;
    cout << endl;

    Elem* concatenatedStack = concatenateStacks(stack1, stack2);
    cout << endl;

    cout << "Concatenated Stack: ";
    printStack(concatenatedStack);
    cout << "Length of Concatenated Stack: " << getStackLength(concatenatedStack) << endl;

    return 0;
}