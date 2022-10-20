#include "../heap.h"
#include <iostream>
using namespace std;

int main(){
    int D_ARY = 2;
    Heap<int> heap(D_ARY);

    heap.push(1);
    heap.push(2);
    heap.push(3);

    cout << "no pops" << endl;
    cout << heap.top() << endl;

    heap.pop();

    cout << "first pop" << endl;
    cout << heap.top() << endl;

    heap.pop();

    cout << "second pop" << endl;
    cout << heap.top() << endl;

    heap.pop();

    cout << "third pop" << endl;
    cout << heap.top() << endl;

}