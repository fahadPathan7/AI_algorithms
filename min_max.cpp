#include <bits/stdc++.h>
using namespace std;

void minMax(vector<int> levels[], int level, bool maxOperation) {
    // the tree is completed. so we will print the root value and return
    if (level == 0) {
        cout << "The root is: " << levels[0][0] << endl;
    }

    // generating the upper level
    for (int i = 0; i < levels[level].size(); i += 2) {
        int val1 = levels[level][i], val2 = levels[level][i + 1]; // taking two chaild values

        // doing operating accordingly
        if (maxOperation) levels[level - 1].push_back(max(val1, val2));
        else levels[level - 1].push_back(min(val1, val2));
    }

    // printing this level
    cout << "The values of level " << level << ": ";
    for (int i = 0; i < levels[level].size(); i++) {
        cout << levels[level][i] << " ";
    }
    cout << endl;

    maxOperation ^= 1; // changing the operation

    return minMax(levels, level - 1, maxOperation); // going to the upper levels
}
int main() {
    int n; // total number of values. must be the power of two
    cout << "Enter count of numbers: ";
    cin >> n;

    int level = (int)((ceil)(log2(n))); // number of levels in the tree. starting from 0

    vector<int> levels[level + 1]; // to store the tree values

    // taking user inputs
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        levels[level].push_back(val);
    }

    cout << endl; // printin an empty line
    minMax(levels, level, false); // calling minMax function
}


/*
Sample input and output

Enter count of numbers: 16
Enter values: 3 4 2 1 7 8 9 10 2 11 1 12 14 19 13 16

The values of level 4: 3 4 2 1 7 8 9 10 2 11 1 12 14 19 13 16
The values of level 3: 3 1 7 9 2 1 14 13
The values of level 2: 3 9 2 14
The values of level 1: 3 2
The root is: 3
*/
