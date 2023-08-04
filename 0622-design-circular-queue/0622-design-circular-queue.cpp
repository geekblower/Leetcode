class MyCircularQueue {
public:
    int F, R, size;
    int *Q;

    MyCircularQueue(int k) {
        Q = new int[k];
        F = R = -1;
        size = k;    
    }
    
    bool enQueue(int value) {
        if(isFull()) {return false;}
        
        // Enqueue at beginning
        if(R == -1 && F == -1) {
            F = R = 0;
            Q[R] = value;
            return true;
        }
        
        // Rear is at last index
        else if(F != 0 && R == size-1) {
            R = 0;
        }
        
        // Other conditions
        else {
            R++;
        }

        Q[R] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {return false;}

                
        // Single element remaining
        if(F == R) {
            F = R = -1;
        }
        
        // Front is at last index
        else if(F == size-1) {
            F = 0;
        }
        
        // Other conditions
        else {
            F++;
        }

        return true;
    }
    
    int Front() {return (isEmpty()) ? -1 : Q[F];}
    int Rear() {return (isEmpty()) ? -1 : Q[R];}
    bool isEmpty() {return (F == -1) ? true : false;}
    bool isFull() {return ((F == 0 && R == size-1) || (R == (F-1)%size)) ? true : false;}
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */