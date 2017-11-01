cmake_minimum_required(VERSION 3.6)
project(AlgoTests)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        Other/Twitter.cpp
        LeetCode/LengthofLongestSubstring.cpp
        Other/Island.cpp
        LeetCode/LongestUnivaluePath.cpp
        LeetCode/PowerOfFour.cpp
        LeetCode/ThirdMax.cpp
        HackerRank/AppleAndOrangeTrees.cpp
        LeetCode/ContainerWithMostWater.cpp
        LeetCode/IntegerPalindrome.cpp
        LeetCode/IntegerToRomanNum.cpp
        LeetCode/LongestCommonPrefixString.cpp
        LeetCode/MedianSortedArrays.cpp
        LeetCode/ZigZagConversion.cpp
        LeetCode/ReverseInteger.cpp
        LeetCode/TwoSum.cpp
        LeetCode/IsSubsequence.cpp
        LeetCode/PalindromeLinkedList.cpp
        LeetCode/MinRotatedSortedArr.cpp
        LeetCode/PascalsTriangle.cpp
        LeetCode/FriendCircles.cpp
        LeetCode/ThreeSum.cpp
        ref.h
        LeetCode/LetterCombosofPhoneNum.cpp
        LeetCode/ValidParentheses.cpp
        LeetCode/RemoveNthFromEndLinkedList.cpp
        LeetCode/MergeTwoSortedLists.cpp
        LeetCode/ThreeSumClosest.cpp
        LeetCode/GenerateParentheses.cpp
        LeetCode/ValidBST.cpp
        LeetCode/PlusOne.cpp
        LeetCode/Power.cpp
        LeetCode/WordSearch.cpp
        LeetCode/FirstMissingPositive.cpp
        LeetCode/SetMatrixZeroes.cpp
        LeetCode/AddTwoNumbers.cpp
        LeetCode/JumpGame.cpp
        LeetCode/MoveZeroes.cpp
        LeetCode/LongestContIncSubsequence.cpp
        LeetCode/MultiplyStrings.cpp
        LeetCode/ClimbingStairs.cpp LeetCode/InorderTreeTraversalIterative.cpp)

add_executable(AlgoTests ${SOURCE_FILES})

