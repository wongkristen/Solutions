#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

class TwitterSolution {
public:
    struct followArrayItem{
        int follower;
        int followee;
    };

    struct likeArrayItem{
        int user;
        int tweet;
    };

    struct tweet{
        int tweetID;
        int numLikes;
    };

    struct tupleItem{
        int firstVal;
        int secondVal;
        tupleItem(int first, int second){
            firstVal = first;
            secondVal = second;
        }
    };

// MERGE SORT FOR TUPLE ITEM STRUCTURE
    void merge (tupleItem arr[], int left, int right, int mid){
        int leftSize = (mid + 1) - left;
        int rightSize = right - mid;
        int leftArr[leftSize];
        int rightArr[rightSize];

        for (int i = 0; i < (mid + 1) - left; i ++){
            arr[left + i].firstVal = leftArr[i];
        }
        for (int i = 0; i < right - mid; i ++){
            arr[mid + 1 + i].firstVal = rightArr[i];
        }

        int i = 0, j = 0, index = left;

        while(i < leftSize && j < rightSize){
            if(leftArr[i] <= rightArr[j]){
                arr[index].firstVal = leftArr[i];
                index ++;
                i ++;
            } else{
                arr[index].firstVal = rightArr[j];
                index ++;
                j ++;
            }
        }

        while (i < leftSize){
            arr[index].firstVal = leftArr[i];
            index ++;
            i ++;
        }

        while (j < rightSize){
            arr[index].firstVal = rightArr[j];
            index ++;
            j ++;
        }
    }

    tupleItem* mergeSort(tupleItem arr[], int left, int right){
        if (left < right){
            int mid = (left + right) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, right, mid);
        }
        return arr;
    }

    tupleItem* getRecommendedTweets(tupleItem followGraph_edges[], tupleItem likeGraph_edges[], int targetUser, int minLikeThreshold){
        vector<int> following;
        vector<tupleItem> goodTweets;
        vector<int> recommendTweets;
//    for (int i = 0; i < sizeof(followGraph_edges); i ++){
//        if(followGraph_edges[i].firstVal == targetUser) following.push_back(followGraph_edges[i].secondVal);
//    }

        int numFollowing = sizeof(followGraph_edges) / sizeof(followGraph_edges[0]);
        int numLikes = sizeof(likeGraph_edges) / sizeof(likeGraph_edges[0]);

        followGraph_edges = mergeSort(followGraph_edges, 0, numFollowing - 1);
        likeGraph_edges = mergeSort(likeGraph_edges, 0 , numLikes - 1);
        int i = 0;

        while (i < numFollowing || followGraph_edges[i].firstVal <= targetUser){
            if (followGraph_edges[i].firstVal < targetUser) i ++;
            else {
                following.push_back(followGraph_edges[i].firstVal);
                i ++;
            }
        }

//    if (following.size() == 0) return following;

        i = 0;
        for (int j = 0; j < following.size(); j ++){
            while (i < numLikes || likeGraph_edges[i].firstVal <= following[j]){
                if (likeGraph_edges[i].firstVal == following[j]){
                    bool inc = false;

                    for (int k = 0; k < goodTweets.size(); k ++){
                        if (likeGraph_edges[i].secondVal == goodTweets[k].firstVal){
                            goodTweets[k].secondVal ++;
                            inc = true;
                        }
                        if (goodTweets[k].secondVal >= minLikeThreshold) recommendTweets.push_back(goodTweets[k].firstVal);
                    }

                    if (!inc) goodTweets.push_back(tupleItem{likeGraph_edges[i].secondVal, 1});
                }
            }
        }



        tupleItem *temp = &goodTweets[0];

        return(mergeSort(temp, 0, sizeof(temp) / sizeof(temp[0])));


    }

//    followArrayItem followArray[] = {(1,2),
//                                     (2,3),
//                                     (3,2),
//                                     (1,3),
//                                     (1,4),
//                                     (5,1),
//                                     (1,5),
//                                     (2,4),
//                                     (1,6),
//                                     (1,7)};
//    likeArrayItem likeArray[] = {(3,10),
//                                 (4,10),
//                                 (2,10),
//                                 (2,4),
//                                 (6,10),
//                                 (4,4),
//                                 (5,10)};
};

int lengthOfLongestSubstring(string s) {
    int length = s.length();
    string ans;
    bool add = true;
    int longest = 0;

    if(length == 1){
        return 1;
    }
    for (int i = 0; i < length; i ++){
        for(int j = 0; j < ans.length(); j ++){
            if(ans[j] == s[i]){
                add = false;
                if(longest < ans.length()){
                    longest = ans.length();
                }
                ans = s[i];
                break;
            }
            add = true;
        }
        if (add){
            ans += s[i];
        }
    }

    if(longest < ans.length()){
        longest = ans.length();
    }

    return longest;
}

class IslandSolution {
public:
    int length, height;
    int numIslands(vector<vector<char>> grid){
        length = grid.size();

        if(length == 0) return 0;

        height = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < length; i ++){
            for (int j = 0; j < height; j++){
                if (grid[i][j] == '1'){
                    islandCount ++;
                }
            }
        }
    }

    void markIslands(vector<vector<int>> grid, int i, int j){
        if (grid[i][j] == 0 || i < length || j < height) return;

        grid[i][j] = 0;
        markIslands(grid, i + 1, j);
        markIslands(grid, i - 1, j);
        markIslands(grid, i, j + 1);
        markIslands(grid, i, j - 1);
    }
};

class LongestUnivaluePathSolution {
    // Finds length of longest univalue path in a tree (the length of the path between 2 nodes is the number of edges between them).
//    EXAMPLE :     1
//              4       5
//          4       4       5       ANSWER = 2
public:
    int max;
    struct TreeNode {
             int val;
             TreeNode *left;
             TreeNode *right;
             TreeNode(int x) : val(x), left(NULL), right(NULL) {}
         };
    int longestUnivaluePath(TreeNode* root) {
        max = 0;
        findExtensions(root);
        return max;
    }

    int findExtensions(TreeNode* root) {
        if(root == NULL) return 0;
        int left = findExtensions(root->left);
        int right = findExtensions(root->right);

        if (root->left != NULL && root->val == root->left->val) left++;
        else left = 0;

        if (root->right != NULL && root->val == root->right->val) right++;
        else right = 0;

        if (right + left > max) max = right + left;

        return (left > right ? left : right);
    }
};

class PowerOfFourSolution {
//    Returns true if number is a power of 4
public:
    bool isPowerOfFour(int num) {
        int x = 0;
        while (pow(4, x) <= num) {
            if (pow(4, x) == num) return true;
            x++;
        }
        return false;
    }

    bool isPowerOfFourNoLoop(int num) {
        float x = pow(num, 0.25);
        cout << x << endl;
        return floor(x) == ceil(x);
    }
};

class ValidSquareSolution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

    }
}; // not done

class ThirdMaxSolution {
public:
    int thirdMax(vector<int>& nums) {
        int max = NULL, max2 = NULL, max3 = NULL;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max || max == NULL){
                int temp = max;
                int temp2 = max2;
                max = nums[i];
                max2 = temp;
                max3 = temp2;
                continue;
            } else if ((nums[i] > max2 && nums[i] != max) || (max2 == NULL && nums[i] != max)) {
                int temp = max2;
                max2 = nums[i];
                max3 = temp;
                continue;
            } else if ((nums[i] > max3 && (nums[i] != max && nums[i] != max2)) || (nums[i] == NULL && (nums[i] != max && nums[i] != max2))) {
                max3 = nums[i];
            }
        }
        cout << max << endl;
        cout << max3 << endl;
        if (max3 == NULL && max2 == NULL) return max;
        else if (max3 == NULL) return max;
        return max3;
    }
};

class appleSolution {
    void onHouse(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
        int appleCount = 0, orangeCount = 0;
        for (int i = 0; i < apples.size(); i ++) {
            if(apples[i] + a >= s && apples[i] + a <= t) appleCount++;
        }
        for (int i = 0; i < oranges.size(); i++){
            if(oranges[i] + b >= s && oranges[i] + b <= t) orangeCount++;
        }
        cout << appleCount << endl << orangeCount;
    }
};

class MaxAreaSolution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, max = 0;
        while (i < j) {
            int area = (j - i) * min(height[i], height[j]);
            max = area > max ? area : max;

            int currHeight = min(height[i], height[j]);

            while (height[j] <= currHeight && i < j) j--;
            while (height[i] <= currHeight && i < j) i++;
        }
        return max;
    }
};

class IsPalindromeSolution {
public:
    bool isPalindrome(int x) {
        int check = 0, temp = x;
        while (x != 0) {
            check = check * 10;
            check += x % 10;
            x = x / 10;
        }
        return temp == check;
    }
};

class IntToRomanSolution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};

class LongestCommonPrefixSolution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        if (strs.size() == 0) return "";
        string ans = "";
        int index = 0;
        while (index <= strs[0].length()){
            for (int i = 1; i < strs.size(); i ++){
                for(int j = 0; j <= index; j++){
                    if(strs[0][j] != strs[i][j]) return ans;
                }
            }
            ans += strs[0][index];
            index ++;
        }
        return ans;
    }
};

class FindMedianSortedArraysSolution {
public:
    vector<int> sort(vector<int> data){
        int length = data.size();
        int j;
        int temp;
        bool flag = true;

        while (flag){
            flag = false;
            for (int i = 0; i < length - 1; i++){
                j = i + 1;
                if(data[i] > data[j]){
                    temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                    flag = true;
                }
            }
        }
        return data;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        nums1 = sort(nums1);

        if(nums1.size() % 2 == 1){
            return nums1[(nums1.size()/2)];
        }else{
            float med = (float) (nums1[nums1.size()/2] + nums1[(nums1.size()/2) - 1]) / (float) 2;
            return med;
        }
    }
};

class ZigZagConversionSolution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {return s;}

        int length = s.length();
        int row = 0;
        bool down = true;
        string ans[numRows];

        for (int i = 0; i < length; i++){
            ans[row].push_back(s[i]);

            if (row == (numRows - 1)){
                down = false;
            }
            else if (row == 0){
                down = true;
            }

            down ? row ++ : row --;
        }
        for(int i = 1; i < numRows; i++){
            ans[0] += ans[i];
        }

        return ans[0];

    }
};

class ReverseIntegerSolution {
public:
    int reverse(int x) {
        if(x < 10 && x > -10) {return x;}

        bool neg = false;
        if (x < 0) {
            x = -x;
            neg = true;
        }

        string intString = to_string(x);
        string temp;
        for(int i = intString.length() - 1; i >= 0; i--){
            temp.push_back(intString[i]);
        }

        long num;

        num = stol(temp, nullptr, 10);
        if(neg){
            num = -num;
        }

        cout << num << endl;
        cout << INT_MAX << endl;
        if(num > INT_MAX || num < INT_MIN){
            return 0;
        }else{
            x = (int) num;
            return x;
        }
    }
};

class TwoSumSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int length = nums.size();

        for (int i = 0; i < length; i++){
            for(int j = i + 1; j < length; j++){
                if((nums[i] + nums[j] == target)){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    }
};

class IsSubSequenceSolution {
public:
    bool isSubsequence(string s, string t) {
        int sPos = 0;
        int tPos = 0;
        int sLength = s.length();
        int tLength = t.length();
        bool flag = true;

        while (flag){
            flag = false;
            for(int i = tPos; i < tLength; i++){
                if(s[sPos] == t[i]){
                    tPos = i + 1;
                    sPos ++;
                    flag = true;
                    break;
                }
            }
        }
        return sPos >= sLength;
    }
};

class IsPalindromeLinkedListSolution {
public:
    struct ListNode {
             int val;
             ListNode *next;
             ListNode(int x) : val(x), next(NULL) {}
         };

    bool isPalindrome(ListNode* head) {
        if(head == nullptr) {return true;}

        ListNode *temp = head;
        stack <int> s;
        s.push(temp -> val);

        while (temp -> next != nullptr){
            temp = temp -> next;
            s.push(temp -> val);
        }

        temp = head;
        while (temp -> next != nullptr){
            if(s.top() != temp -> val) {return false;}

            s.pop();
            temp = temp -> next;
        }

        return true;
    }
};

class FindMinRotatedSortedArrSolution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();

        for(int i = 0; i < (length - 1); i++){
            if(nums[i] > nums[i + 1]) {return nums[i + 1];}
        }
        return nums[0];
    }
};

class PascalsTriangleSolution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> outer;
        if (numRows == 0){
            return outer;
        }

        if (numRows == 1){
            return (vector<vector<int>> {{1}});
        }

        outer.push_back(vector<int> {1});

        for (int i = 1; i < numRows; i++){
            vector<int> inner;
            inner.push_back(1);
            for(int j = 1; j < i; j++){
                inner.push_back(outer[i - 1][j - 1] + outer[i - 1][j]);
            }
            inner.push_back(1);
            outer.push_back(inner);
        }
        return outer;
    }
};

class FriendCirclesSolution {
public:
    void depthFirst(vector<vector<int>> M, bool arr[], int i){
        for (int j = 0; j < M.size(); j ++ ){
            if(M[i][j] == 1 && !arr[j]){
                arr[j] = true;
                depthFirst(M, arr, j);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& M) {
        int friendCircles = 0;
        int length = M.size();
        bool arr[length] = {false};

        for (int i = 0; i < length; i ++){
            if (arr[i] == 0){
                friendCircles ++;
                depthFirst(M, arr, i);
            }
        }
        return friendCircles;
    }


};

class ThreeSumSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

    }
};

int main(){
    vector <int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);

    IntToRomanSolution itr;
    cout << "int to roman: " << itr.intToRoman(255);

    vector<string> strings;
    strings.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaa");
    strings.push_back("aaaaaaaaaaaaaaaaaaaaaa");
    strings.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    LongestCommonPrefixSolution lcp;
    cout << endl << "longest common prefix: " << lcp.longestCommonPrefix(strings);

}
