#include <iostream>
#include <vector>
#include "ref.h"


using namespace std;






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
