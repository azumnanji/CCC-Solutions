class MyStack {
    queue<int> q1;
    queue<int> q2;
    int size;
public:
    /** Initialize your data structure here. */
    MyStack() {
        size = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (size == 0)
            q1.push(x);
        else{
            q2.push(x);
            for (int i = 0; i < size; i ++){
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> temp = q1;
            q1 = q2;
            q2 = temp;
        }
        ++size;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = q1.front();
        q1.pop();
        --size;
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (size == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */