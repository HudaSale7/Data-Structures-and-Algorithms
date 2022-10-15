#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& v);
int main() {
    vector<int> v = {6, 3, 4, 1, 2, 5};
    sort(v);
    for(auto it : v)
        cout << it << " ";
    cout << endl;
    system("pause");
    return 0;
}

void sort(vector<int>& v) {
    for(int i = 0; i < v.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < v.size(); j++) {
            if(v[j] < v[min]) 
                min = j;
        }
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}