class MyCalendar {
    public:
    vector<pair<int, int>> booking;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (pair<int,int> temp:booking) {
            if (max(temp.first,start) < min(end,temp.second))
                return false;
        }
        
        booking.push_back({start,end});
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */