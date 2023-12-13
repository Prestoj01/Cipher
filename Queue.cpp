#include "Queue.h"
#include <iostream>

//QNode constructor
QNode::QNode(char value) : data(value), next(nullptr) {}

//Queue constructor
Queue::Queue() : front(nullptr), rear(nullptr) {}

//Queue destructor
Queue::~Queue() {
    clear();
}

//function to add to queue
void Queue::enqueue(char item) {
    //checks if queue is full before adding
    if (isFull()) {
        std::cerr << "Error: Queue is full." << std::endl;
        return;
    }
    
    QNode* newNode = new QNode(item);

    if (isEmpty()) {
        front = rear = newNode;
    } 
    else {
        rear->next = newNode;
        rear = newNode;
    }

    ++size;
}

//function to remove from queue
void Queue::dequeue(char &item) {
    //checks if queue is empty before removing anything
    if (isEmpty()) {
        std::cerr << "Error: Queue is empty." << std::endl;
    }
    else {
        item = front->data;
        QNode* oldFront = front;
        front = front->next;
        delete oldFront;
        --size;
    }
}

//function that checks if the queue is full at 100
bool Queue::isFull() const {
    return size == 100;
}

//checks if queue is empty
bool Queue::isEmpty() const {
    return front == nullptr;
}

//function to erase queue elements
void Queue::clear() {
    while (!isEmpty()) {
        char temp;
        dequeue(temp);
    }
}