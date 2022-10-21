#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& original, int n, int i);
void swap(vector<int>& original, int index1, int index2);

int main() {
    vector<int> original = {6, 3, 4, 7, 1, 2, 5, 7};
    int size = original.size() - 1;

    //build max heap
    for (int i = size / 2; i >= 0; i--)
        heapify(original, size, i);

    //sort heap
    for (int i = size; i > 0; i--)
    {
        swap(original, i, 0);
        heapify(original, i - 1, 0);
    }

    for(auto it : original)
        cout << it << " ";

    cout << endl;
    system("pause");
    return 0;
}

void heapify(vector<int>& original, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left <= n && original[left] > original[largest])
        largest = left;

    if(right <= n && original[right] > original[largest])
        largest = right;

    if(largest != i) {
        swap(original, i, largest);
        heapify(original, n, largest);
    }
}

void swap(vector<int>& original, int index1, int index2) {
    int temp = original[index1];
    original[index1] = original[index2];
    original[index2] = temp;
}