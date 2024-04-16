// you can use includes, for example:
#include <exception>
#include <new>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

class Fish {
private:
    int size;
    int direction;
public:
    Fish(int size, int direction) : size(size), direction(direction) {}
    int getSize() const { return size; }
    int getDirection() const { return direction; }
};

class Stack {
 private:
    int capacity;
    Fish** data;
    int top = 0;
 public:
    Stack(int capacity) : capacity(capacity), data(nullptr) {
        data = new Fish* [capacity];
        if (data == nullptr) {
            throw std::bad_alloc();
        }
    }
    //add a 
    ~Stack() {
        if (data != nullptr) {
            for (int i = 0; i < top; i++) {
                delete data[i];
            }

            delete [](data);
            data = nullptr;
        }
    }

    void push(Fish* fish) {
        if (top >= capacity) {
            throw std::overflow_error("Stack overflow");
        }

        data[top++] = fish;

        
    }

    void pop() {
    if (top == 0) {
        throw std::underflow_error("Stack underflow");
    }
    
    delete data[--top];  // Wywołanie destruktora dla obiektu Fish        
    }

    bool isEmpty() const {
        return top == 0;
    }

    // Dodatkowa metoda do sprawdzenia, czy stos jest pełny
    bool isFull() const {
        return top == capacity;
    }

    int getSize() const {
        return top;
    }

    const Fish& peek() const {
        if (this->isEmpty()) {
            throw std::underflow_error("Stack empty");
        }

        return *data[top-1];
    }
};

int solution(vector<int> &A, vector<int> &B) {
    int N = A.size();
    Stack stack(N);

    for (int i = 0; i < N; i++) {
        Fish* fish = new Fish(A[i], B[i]);
        //jak stack pusty to pushuj tam rybke

        if (fish->getDirection() == 0) {

            while(!stack.isEmpty() && stack.peek().getDirection() == 1) {
                const Fish& prevFish = stack.peek();
                if (prevFish.getSize() > fish->getSize()) {
                    delete fish;
                    fish = nullptr;
                    break;
                }
                else
                    stack.pop();
            }

        } /*else  {

            while(stack.peek().getDirection() == 0) {
                const Fish& prevFish = stack.peek();
                if (prevFish.getSize() > fish->getSize()) {
                    pushFlag = 0;
                    delete fish;
                    break;
                }
                else
                    stack.pop();
            }
        } */

        if(fish != nullptr)
            stack.push(fish);
    }

    return stack.getSize();

    return 0;
}