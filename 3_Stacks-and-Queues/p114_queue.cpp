// 連結リストによるキューの実装

#include<iostream>
using namespace std;

class MyQueue {
    struct QueueNode {
        double data;
        struct QueueNode *next;
    };
    QueueNode *first;
    QueueNode *last;
public:
    MyQueue() {
        first = NULL;
        last = NULL;
    }
    void add(double);
    double remove();
    double peek();
};

void MyQueue::add(double data) {
    QueueNode *t = new QueueNode;
    t->data = data;
    if (last!=NULL) last->next = t;
    last = t;
    if (first == NULL) first = last;
}

double MyQueue::remove() {
    if (first==NULL) return 0;
    double data = first->data;
    first = first->next;
    if (first == NULL) last = NULL;
    return data;
}

double MyQueue::peek() {
    if (first==NULL) return 0;
    return first->data;
}

int main() {
    MyQueue queue;
    queue.add(1);
    queue.add(2);
    queue.add(3);
    cout << queue.remove() << "\n";
    cout << queue.remove() << "\n";
    cout << queue.peek() << "\n";
    cout << queue.remove() << "\n";
    //cout << queue.remove() << "\n";
    return 0;
}