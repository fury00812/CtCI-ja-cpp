#include<iostream>
using namespace std;

class AnimalQueue {
    struct QueueNode {
        string data;
        struct QueueNode *next;
    };
    QueueNode *first;
    QueueNode *last;
public:
    AnimalQueue() {
        first = NULL;
        last = NULL;
    }
    void enqueue(string);
    string dequeueAny();
    string dequeueDog();
    string dequeueCat();
};

void AnimalQueue::enqueue(string data) {
    QueueNode *t = new QueueNode;
    t->data = data;
    if (last!=NULL) last->next = t;
    last = t;
    if (first == NULL) first = last;
}

string AnimalQueue::dequeueAny() {
    if (first==NULL) return 0;
    string data = first->data;
    first = first->next;
    if (first == NULL) last = NULL;
    return data;
}

string AnimalQueue::dequeueDog() {
    if (first==NULL) return 0;
    if (first->data[0]=='D') {
        string data = first->data;
        first = first->next;
        return data;
    }
    QueueNode *t = new QueueNode;
    t = first;
    while(t->next->data[0] != 'D') {
        t = t->next;
    }
    string data = t->next->data;
    t->next = t->next->next;
    first->next = t;
    if (first == NULL) last = NULL;
    return data;
}

string AnimalQueue::dequeueCat() {
    if (first==NULL) return 0;
    if (first->data[0]=='C') {
        string data = first->data;
        first = first->next;
        return data;
    }
    QueueNode *t = new QueueNode;
    t = first;
    while(t->next->data[0] != 'C') {
        t = t->next;
    }
    string data = t->next->data;
    t->next = t->next->next;
    first->next = t;
    if (first == NULL) last = NULL;
    return data;
}

int main() {
    AnimalQueue queue;
    queue.enqueue("Dog 1");
    queue.enqueue("Cat 0");
    queue.enqueue("Cat 1");
    queue.enqueue("Dog 2");
    queue.enqueue("Dog 3");
    queue.enqueue("Dog 4");
    queue.enqueue("Cat 2");
    cout << queue.dequeueAny() << endl;
    cout << queue.dequeueDog() << endl;
    cout << queue.dequeueAny() << endl;
    cout << queue.dequeueCat() << endl;
    cout << queue.dequeueAny() << endl;
    cout << queue.dequeueCat() << endl;
}