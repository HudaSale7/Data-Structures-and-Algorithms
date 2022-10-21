#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& original, int start, int end);
void sort(vector<int>& original, int start, int end);
void swap(vector<int>& original, int index1, int index2);

int main() {
    vector<int> original = {6, 3, 4, 7, 1, 2, 5};
    sort(original, 0, original.size() - 1);
    for(auto it : original)
        cout << it << " ";
    cout << endl;
    system("pause");
    return 0;
}

void sort(vector<int>& original, int start, int end) {
    if (start < end)
    {
        int pivotIndex = partition(original, start, end);
        sort(original, start, pivotIndex - 1);
        sort(original, pivotIndex + 1, end);
    }
}

int partition(vector<int>& original, int start, int end) {
    int pivotIndex = 0;
    for (int i = 0; i < end; i++)
    {
        if(original[i] < original[end]) {
            swap(original, pivotIndex, i);
            pivotIndex++;
        }
    }
    swap(original, pivotIndex, end);
    return pivotIndex;
}

void swap(vector<int>& original, int index1, int index2) {
    int temp = original[index1];
    original[index1] = original[index2];
    original[index2] = temp;
}
