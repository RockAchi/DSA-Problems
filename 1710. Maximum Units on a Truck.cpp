//This Problem is simlar to Greedy Knapsack/Fractional Knapsack 
//Here it has given that there is truck for which size has given like how many boxes it can take
//And also given there are different types of boxes which has different numbers of unit inside it, also number of boxes available for each box type is also differnent
//We have to load the truch such a way that, we load maximum number of Units 
//For Example, boxTypes = {{1,3}, {2,2}, {3,8}}, truckSize = 5, 
//here boxTypes[1] is the 1th type of box, where total number of box available is 3 and each box contains 8 unit in it, means total 24 Units available
//As we have to load the max number of units, so first we can sort the boxTypes based on the max number unit, then we will load the unit in sorting order
//sorted boxTypes = {{3,8}, {1,3}, {2,2}}
//then we will check if the trucksize is greater than 0 and if we can load all the box of current type or not
//if  we can load than we will calculate the maxUnits += allBoxesOfCurrentTypeOfBox*unitsPresentInEachBox
//If we can't then we will load whatever is truckSize left, but before that we should if truckSize is not Zero
//Here in this Case Maximum units: 29

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int lengthOfboxTypes = boxTypes.size();
        int maxUnits = 0;
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1]; // Sort in descending order
             });
        int i;
        for (i = 0; i < lengthOfboxTypes; i++) {
            if (truckSize > 0 && truckSize >= boxTypes[i][0]) {
                maxUnits += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                break;
            }
        }
        if (truckSize > 0 && i != lengthOfboxTypes)
            maxUnits += truckSize * boxTypes[i][1];
        return maxUnits;
    }
};

int main() {
    vector<vector<int>> boxTypes = {{1,3}, {2,2}, {3,8}};
    int truckSize = 4;
    Solution solution;
    int maxUnits = solution.maximumUnits(boxTypes, truckSize);
    cout << "Maximum units: " << maxUnits << endl;
    return 0;
}
