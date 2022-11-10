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
    for (int j = 1; j < v.size(); j++)
    {
        int i = j;
        int temp = v[j];
        while (i > 0 && temp < v[i - 1])
        {
            v[i] = v[i - 1];
            i--;
        }
        v[i] = temp;
    }
}