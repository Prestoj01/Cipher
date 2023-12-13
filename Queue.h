#ifndef QUEUE_H
#define QUEUE_H

struct QNode {
    char data;
    QNode* next;

    QNode(char value);
};

class Queue {
private:
    int size;

public:
    Queue();
    ~Queue();
    void enqueue(char item);
    void dequeue(char &item);
    bool isFull() const;
    bool isEmpty() const;
    void clear();

    QNode* front;
    QNode* rear;
};

#endif
