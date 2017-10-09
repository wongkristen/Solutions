//
// Created by Kristen Wong on 10/9/17.
//

#include <vector>
using namespace std;

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