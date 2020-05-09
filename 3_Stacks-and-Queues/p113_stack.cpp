// 連結リストによるスタックの実装.

#include<iostream>
using namespace std;

class MyStack {
    struct StackNode {
        double data;
        struct StackNode *next;
    };
    StackNode *top;
public:
    MyStack() {
        top = NULL;
    }
    void push(double);
    double pop();
    double peek();
};

void MyStack::push(double data) {
    StackNode *t = new StackNode;
    t->data = data;
    t->next = top;
    top = t;
}
double MyStack::pop() {
    if (top==NULL) return 0;
    double data = top->data;
    top = top->next;
    return data;
}
double MyStack::peek() {
    if (top==NULL) return 0;
    return top->data;
}

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << "\n";
    cout << stack.pop() << "\n";
    cout << stack.peek() << "\n";
    cout << stack.pop() << "\n";
    cout << stack.pop() << "\n";
    return 0;
}