#include <iostream>
using namespace std;

void subsort(int array[], int n){
    int s, e;
    for (int i=0; i<n; i++) { // left-to-right
        if (array[i]>array[i+1]) {
            s=i;
            break;
        }
    }
    for (int i=n-1; i>0; i--) { // right-to-left
        if (array[i]<array[i-1]) {
            e=i;
            break;
        }
    }
    int min = array[s], max = array[e];
    for (int i=s; i<=e; i++) {
        if (array[i]>max) max = array[i];
        if (array[i]<min) min = array[i];
    }
    for (int i=0; i<s; i++) { // left-to-right
        if (array[i]>min) {
            s=i;
            break;
        }
    }
    for (int i=n-1; i>e; i--) { // right-to-left
        if (array[i]<max) {
            e=i;
            break;
        }
    }
    cout << s << " " << e << endl;
}

int main() {
    int array[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    int n = sizeof(array) / sizeof(array[0]);
    subsort(array, n);
    return 0;
}