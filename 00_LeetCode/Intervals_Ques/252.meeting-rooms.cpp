// Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), determine if a person could add all meetings to their schedule without any conflicts. The intervals may be provided in any order.

// Note: (0,8),(8,10) is not considered a conflict at 8

// Example 1:

// Input: intervals = [(0,30),(5,10),(15,20)]

// Output: false

#include<bits/stdc++.h>
using namespace std;

  //Definition of Interval:
  class Interval {
  public:
      int start, end;
      Interval(int start, int end) {
          this->start = start;
          this->end = end;
      }
  };
 
class Solution {
public:
    struct lemda{
        bool operator()(Interval &a , Interval&b ){
            return a.start < b.start;
        }
    };
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n= intervals.size();
        sort(intervals.begin(),intervals.end(),lemda());
        int i=0;
        while(i<n) {
            if(i+1<n && intervals[i].end > intervals[i+1].start) return false;
            else i++;
        } 
        return true;
    }
};
