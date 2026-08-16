#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
    priority_queue<int,vector<int>,greater<int>>right_min_heap;
    priority_queue<int> left_max_heap;
public:
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        // addding element to heap
        if(left_max_heap.empty() || left_max_heap.top()>=num){
            left_max_heap.push(num);
        }else{
            right_min_heap.push(num);
        }
        // maintaning head ATQ i.e..
        // leftheap contains 1 more or equal no. of numbers as right heap
        
        if(left_max_heap.size() > right_min_heap.size()+1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }else if(left_max_heap.size() < right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        
    }
    
    double findMedian() {
        // if even , if odd.
        if(left_max_heap.size() == right_min_heap.size()){
            return (double)(left_max_heap.top() + right_min_heap.top())/2;
        }else{
            return (double)left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

