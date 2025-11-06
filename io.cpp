#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int optimalMergePattern(vector<int> &files) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int size : files) {
        minHeap.push(size);
    }

    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        int mergedSize = first + second;
        totalCost += mergedSize;
        minHeap.push(mergedSize);
    }

    return totalCost;
}

int main() {
    vector<int> files = {5, 10, 15, 20};
    cout << "Minimum total merge cost: " << optimalMergePattern(files) << endl;
    return 0;
}
