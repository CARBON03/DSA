#include<iostream>
using namespace std;

const int MAX = 100; // Define a maximum size for the queue
int queue[MAX], n, front = -1, rear = -1;

void EnQueue() {
    int value;
    if (rear == n-1) {
        cout << "\nQueue Overflow. Cannot enter any more elements in the Queue.";
    }
    else {
        if (front == -1) {
            front = 0;
        }
        cout << "Enter new element to Enqueue in Queue: ";
        cin >> value;
        rear++;
        queue[rear] = value;
    }
}

void DeQueue() {
    if (front == -1 || front > rear) {
        cout << "\nQueue Underflow. No elements present in the Queue.";
    }
    else {
        cout << "\nElement "<< queue[front] <<" Dequeued from Queue";
        front++;
        if (front > rear) { // Reset the queue if it becomes empty
            front = rear = -1;
        }
    }
}

void Display() {
    if (front == -1 || front > rear) {
        cout << "\nQueue is Empty. Please insert elements into the Queue.";
    }
    else {
        cout << "\nQueue Elements: ";
        for (int i = front; i <= rear; i++) 
            cout << queue[i] << " ";
    }
}

int main() {
    cout << "Enter the number of elements you want in the queue: ";
    cin >> n;
    
    if (n > MAX) {
        cout << "The number of elements exceeds the maximum allowed size of " << MAX << ". Please restart the program and enter a valid size.";
        return 0;
    }

    int choice;
    cout << "Enter Your Choice =>";
    cout << "\n1: Add an element into Queue.";
    cout << "\n2: Delete an element from  Queue.";
    cout << "\n3: Display Queue elements.";
    cout << "\n4: EXIT the program.";
    do {
        cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\nEnter Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                EnQueue();
                break;
            }
            case 2: {
                DeQueue();
                break;
            }
            case 3: {
                Display();
                break;
            }
            case 4: {
                cout << "\nPROGRAM EXIT.";
                break;
            }
            default: {
                cout << "\nInvalid choice. Please choose from the given list =>\n1: ENQUEUE new element into Queue.\n2: DEQUEUE an element from existing Queue.\n3: DISPLAY Queue elements.\n4: EXIT the program.";
            }
        }
    } while (choice != 4);

    return 0;
}
