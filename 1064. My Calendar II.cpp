class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ev_table[start]++;
        ev_table[end]--;
        
        map<int, int>::iterator iter = ev_table.begin();
        int sum = 0;
        for(; iter != ev_table.end(); iter++){
            sum += iter->second;
            if(sum > 2){
                ev_table[start]--;
                ev_table[end]++;
                return false;
            }
        }
        
        return true;
    }
    
private:
    map<int, int> ev_table;  
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */