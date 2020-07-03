#include<vector>
#include <set>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval():start(0), end(0){}
    Interval(int s, int e) : start(s), end(e){
    }
};
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    

    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval interval(val, val);
        auto it = interval_set.lower_bound(interval);
        int start= val;
        int end = val;
        if (it != interval_set.end() && (--it)->end + 1 < val) it++;
        while ( it != interval_set.end() && val + 1 >= it->start && val - 1 <= it->end) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = interval_set.erase(it);
        }
        interval_set.insert(it, Interval(start, end));
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for(auto &val: interval_set)  {
            vector<int> v = {val.start, val.end};
            result.push_back(v);
        }
        return result;
    }

    private:
    struct  cmp {
        bool operator()(const Interval &lhs, const Interval &rhs){
        return lhs.start < rhs.start;}
    };
    std::set<Interval,  cmp> interval_set;
};

int main(int argc, char *argv[]) {
    return 0;
}