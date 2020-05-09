#include<iostream>
using namespace std;

class FixedMultiStack {
    int stackCapacity;
    int *values; // スタック
    int sizes[3] = {0,0,0};
public:
    FixedMultiStack(int stackCapacity) {
        this->stackCapacity = stackCapacity;
        values = new int[stackCapacity * 3];
        for (int i=0; i<stackCapacity*3; i++) values[i]=0;
    }
    void push(int stackNum, int value) {
        cout << "[push] " << value << " -> Stack" << stackNum << "\n";
        if (isFull(stackNum)) cout << "[!] Stack" << stackNum << " is Full\n";
        else {
            sizes[stackNum]++;
            values[indexOftop(stackNum)] = value;
        }
    }
    int pop(int stackNum) {
        cout << "[pop] Stack" << stackNum << " -> ";
        if (isEmpty(stackNum)) {
            cout << "[!]  Stack" << stackNum << " is Empty\n";
            return 0;
        }
        else {
            int value = values[indexOftop(stackNum)];
            values[indexOftop(stackNum)] = 0;
            sizes[stackNum]--;
            return value;
        }
    }
    void display() {
        cout << "  Array: ";
        for (int i=0; i<3; i++) {
            for (int j=0; j<stackCapacity; j++) {
                cout << values[i*stackCapacity+j] << " ";
            }
        }
        cout << "\n";
    }
    bool isEmpty(int stackNum) {
        return sizes[stackNum]==0;
    }
    bool isFull(int stackNum) {
        return sizes[stackNum]==stackCapacity;
    }
    int indexOftop(int stackNum) {
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size - 1;
    }
};

int main() {
    FixedMultiStack stack = FixedMultiStack(2);
    stack.display();
    stack.push(0,10);
    stack.display();
    stack.push(0,20);
    stack.display();
    stack.push(0,30);
    stack.display();
    stack.push(1,40);
    stack.display();
    stack.push(2,50);
    stack.display();
    cout << stack.pop(2) << "\n";
    stack.display();
    return 0;
}