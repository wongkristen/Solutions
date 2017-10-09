//
// Created by Kristen Wong on 10/9/17.
//

#include <vector>
using namespace std;

// !!!!!! NOT DONE !!!!!!
// !!!!!! NOT DONE !!!!!!
// !!!!!! NOT DONE !!!!!!
// !!!!!! NOT DONE !!!!!!

class Twitter {

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