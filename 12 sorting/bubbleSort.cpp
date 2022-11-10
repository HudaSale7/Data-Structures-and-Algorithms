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
    for (int i = 0; i < v.size() - 1; i++) {
        int flag = 0;
        for (int j = 0; j < v.size() - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                flag = 1;
            }
        }
        if(!flag) break;
    }
}