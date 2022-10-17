#include <iostream>
#include <vector>
using namespace std;

void divide(vector<int>& original);
void merge(vector<int>& left, vector<int>& right, vector<int>& original);
int main() {
    vector<int> original = {6, 3, 4, 4, 1, 2, 5};
    divide(original);
    for(auto it : original)
        cout << it << " ";
    cout << endl;
    system("pause");
    return 0;
}

void divide(vector<int>& original) {
    if(original.size() == 1)
        return;

    int leftSize = original.size() / 2;
    int rightSize = original.size() - leftSize;
    vector<int> left(leftSize);
    vector<int> right(rightSize);

    for (int i = 0; i < leftSize; i++)
        left[i] = original[i];

    for (int i = 0; i < rightSize; i++)
        right[i] = original[leftSize++];

    divide(left);
    divide(right);
    merge(left, right, original);
} 

void merge(vector<int>& left, vector<int>& right, vector<int>& original) {
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            original[k++] = left[i++];

        else
            original[k++] = right[j++];
    }

    while(i < left.size())
        original[k++] = left[i++];

    while(j < right.size())
        original[k++] = right[j++];
}