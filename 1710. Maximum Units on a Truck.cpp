#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int lengthOfboxTypes = boxTypes.size();
        int maxBox = 0;
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1]; // Sort in descending order
             });
        int i;
        for (i = 0; i < lengthOfboxTypes; i++) {
            if (truckSize > 0 && truckSize >= boxTypes[i][0]) {
                maxBox += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                break;
            }
        }
        if (truckSize > 0 && i != lengthOfboxTypes)
            maxBox += truckSize * boxTypes[i][1];
        return maxBox;
    }
};

int main() {
    vector<vector<int>> boxTypes = {{1,3}, {2,2}, {3,1}};
    int truckSize = 4;
    Solution solution;
    int maxBox = solution.maximumUnits(boxTypes, truckSize);
    cout << "Maximum units: " << maxBox << endl;
    return 0;
}
