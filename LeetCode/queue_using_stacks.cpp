class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int size;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (size == 0)
            s1.push(x);
        else{
            for (int i = 0; i < size; i ++){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            for (int i = 0; i < size; i ++){
                s1.push(s2.top());
                s2.pop();
            }
        }
        ++size;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = s1.top();
        s1.pop();
        --size;
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (size == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */