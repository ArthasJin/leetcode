#include <iostream>
#include <stack>

using namespace std;

template <typename T> class CQueue {
public:
    CQueue(void) {}
    ~CQueue(void) {}
    void enqueue(const T& element) {
        stack1.push(element);
    }
    T dequeue() {
        if(stack2.size() <= 0) {
            while(stack1.size() > 0) {
                T& data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        if(stack2.size() == 0) {
            throw new exception();
        }
        T head = stack2.top();
        stack2.pop();
        return head;
    }
private:
    stack<T> stack1;
    stack<T> stack2;
};

