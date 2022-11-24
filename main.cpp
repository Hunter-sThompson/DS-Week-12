#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;


string readfile(char *fname) {

    ifstream t(fname);
    string str((istreambuf_iterator<char>(t)),
                istreambuf_iterator<char>());
    
    return str;
}

vector<int> findRes(vector<int> nums, int target) {
    // Declaring unordered_map (uses hash table) for that nice O(n) time complexity   
    vector<int> res;
    unordered_map<int, int> map;
    
    for (size_t i = 0; i < nums.size(); i++){

        // Checks if the taget-nums[i] exists in map, basically this difference between target and a number in the
        // vector
        if (map.count(target - nums[i])){
            // Pushing back map[target-nums[i]] (index) to result
            res.push_back(map[target - nums[i]]);
            // pushes back the index
            res.push_back(i);
            break;

        } else {
            // otherwise, the number in the vector, and it's index are added to the map, in a key-value pair
            map[nums[i]] = i;
        }
    }
    return res;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        cout << "Usage: ./main.exe file.txt" << endl;
        exit(-1);
    }

    string contents = readfile(argv[1]);

    // Stores each num in a vector<int>
    string numStr;
    stringstream ss(contents);

    // Get first line and set it to target
    getline(ss, numStr, '\n');
    
    int target = stoi(numStr);
    vector<int> nums;
    
    // Another getline to clear the \n 
    getline(ss, numStr, '\n');
    // Uses stringstream to extract contents line by line from file, into vector with '\n' as divider
    while (getline(ss, numStr, '\n')) {
        nums.push_back(stoi(numStr));
    }

    vector<int> result = findRes(nums, target);
    for (auto v: result) {
        cout << "Result is: " << v << endl;
    }
    cout << "res[1]: " << nums[result[1]] << endl;
    cout << "res[0]: " << nums[result[0]] << endl;
    
    cout << "Done" << endl;

    return 0;
}
