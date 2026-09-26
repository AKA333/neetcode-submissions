class MedianFinder {
public:
    priority_queue<int>m;
    priority_queue<int, vector<int>, greater<int>>M;
    MedianFinder() {
        
    }
    
    void addNum(int n) {
        m.push(n);
        while(!m.empty() && !M.empty() && m.top()>M.top()){
            int a=m.top();
            int b= M.top();
            m.pop(); M.pop();
            m.push(b);
            M.push(a);
        }
        if(m.size()-M.size()>=2){
            int t= m.top();
            m.pop();
            M.push(t);
        }
    }
    
    double findMedian() {
        if(m.size()== M.size())
            return (m.top()+M.top())/2.0;
        return m.top();
    }
};
