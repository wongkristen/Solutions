# Solutions :octocat:
`C++` solutions for online algorithm problems from LeetCode and HackerRank.

<br />

## LeetCode
*Questions are listed with their corresponding titles and problem numbers from LeetCode*

1. -[X] **1.** [Container With Most Water](LeetCode/ContainerWithMostWater.cpp) [11]

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

<br />

2. -[X] **2.** [Friend Circles](LeetCode/FriendCircles.cpp) [547]
 
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
 
Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
 ```
 Input: 
  [[1,1,0],
   [1,1,0],
   [0,0,1]]
  Output: 2
  Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
  The 2nd student himself is in a friend circle. So return 2.
  ```
Example 2:
  ```
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
```
Note:
1. N is in range [1,200].
2. M[i][i] = 1 for all students.
3. If M[i][j] = 1, then M[j][i] = 1.

<br />

3. -[X] **3.** [Palindrome Number](LeetCode/IntegerPalindrome.cpp) [9]

Determine whether an integer is a palindrome. Do this without extra space.

<br />

4. -[X] **4.** [Integer to Roman Numeral](LeetCode/IntegerToRomanNum.cpp) [12]

Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.

<br />

5. -[X] **5.** [Is Subsequence](LeetCode/IsSubsequence.cpp) [392]

Given a string **s** and a string **t**, check if **s** is subsequence of **t**.

You may assume that there is only lower case English letters in both **s** and **t**. **t** is potentially a very long (length ~= 500,000) string, and **s** is a short string (<=100).
 
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
 
**Example 1:**

s = "abc", t = "ahbgdc"
 
Return `true`.

**Example 2:**

s = "axc", t = "ahbgdc"

Return `false`.

<br />

6. -[ ] **6.** [Longest Substring Without Repeating Characters](LeetCode/LengthofLongestSubstring.cpp) [3]

Given a string, find the length of the longest substring without repeating characters.
 
Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

<br />

7. -[X] **7.** [Letter Combinations of a Phone Number](LeetCode/LetterCombosofPhoneNum.cpp) [17]

Given a digit string, return all possible letter combinations that the number could represent.

```
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```

<br />

8. -[X] **8.** [Longest Common Prefix](LeetCode/LongestCommonPrefixString.cpp) [14]

Write a function to find the longest common prefix string amongst an array of strings.

<br />

9. -[X] **9.** [Longest Univalue Path](LeetCode/LongestUnivaluePath.cpp) [687]

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

**Example 1:**

Input:
```
              5
             / \
            4   5
           / \   \
          1   1   5
```

Output: 
```
2
```
**Example 2:**

Input:
```
              1
             / \
            4   5
           / \   \
          4   4   5
```
Output:
```
2
```

<br />

10. -[X] **10.** [Median of Two Sorted Arrays](LeetCode/MedianSortedArrays.cpp) [4]

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

**Example 1:**
```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

**Example 2:**
```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

<br />

11. -[X] **11.** [Merge Two Sorted Lists](LeetCode/MergeTwoSortedLists.cpp) [21]

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

<br />

12. -[X] **12.** [Find Minimum in Rotated Sorted Array II](LeetCode/MinRotatedSortedArr.cpp) [154]

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

<br />

13. -[X] **13.** [Palindrome Linked List](LeetCode/PalindromeLinkedList.cpp) [234]

Given a singly linked list, determine if it is a palindrome.

<br />

14. -[X] **14.**  [Pascal's Triangle](LeetCode/PascalsTriangle.cpp) [118]

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,

Return:
```
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

<br />

15. -[X] **15.** [Power of Four](LeetCode/PowerOfFour.cpp) [342]

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

**Example:**

Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

<br />

16. -[X] **16.** [Remove Nth Node From End of List](LeetCode/RemoveNthFromEndLinkedList.cpp) [19]

Given a linked list, remove the nth node from the end of list and return its head.

For example,
```
   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
   ```
**Note:**

Given n will always be valid.
Try to do this in one pass.

<br />

17. -[X] **17.** [Reverse Integer](LeetCode/ReverseInteger.cpp) [7]

Reverse digits of an integer.

Example1: x = 123, return 321

Example2: x = -123, return -321

<br />

18. -[ ] **18.** [Third Maximum Number](LeetCode/ThirdMax.cpp) [414]

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.

Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

<br />

19. -[X] **19.** [3Sum](LeetCode/ThreeSum.cpp) [15]

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

<br />

20. -[X] **20.** [3Sum Closest](LeetCode/ThreeSumClosest.cpp) [16]

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

```
For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

<br />

20. -[X] **20.** [Valid Parentheses](LeetCode/ValidParentheses.cpp) [20]

Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

The brackets must close in the correct order, `"()"` and `"()[]{}"` are all valid but `"(]"` and `"([)]"` are not.

<br />

21. -[X] **21.** [ZigZag Conversion](LeetCode/ZigZagConversion.cpp) [6]

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```
And then read line by line: `"PAHNAPLSIIGYIR"`
Write the code that will take a string and make this conversion given a number of rows:
```C++
string convert(string text, int nRows);
```
`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`.

<br />

## Hacker Rank
1. -[X] **1.** [Apple and Orange](HackerRank/AppleAndOrangeTrees.cpp)

<br />

## Other
1. -[ ] **1.** [Islands](Other/Island.cpp)
2. -[ ] **2.** [Twitter](Other/Twitter.cpp)


