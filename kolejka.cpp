// Version 1.2
// Methods:
// 1. empty()
// 2. push()
// 3. dequeue()
// 4. size()
// 5. first()
// 6. pop()



#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class myqueue {
public:
    myqueue() {
        f = l = -1;
    }
    bool empty() {
        if (f == -1) {
            return true;
        }
        return false;
    }
    void push(int value_to_add) {
        if (empty()) {
            elements.push_back(value_to_add);
            f = 0;
            l = 0;
            return;
        }
        elements.push_back(value_to_add);
        ++l;
        return;
    }
    int dequeue() {
        int value_to_return;
        if (empty()) {
            return value_to_return;
        }
        if (f == l) {
            value_to_return = elements[f];
            elements.clear();
            f = l = -1;
            return value_to_return;
        }
        value_to_return = elements[f];
        ++f;
        return value_to_return;
    }
    int size() {
        if (empty()) {
            return 0;
        }
        return l - f + 1;
    }
    int first() {
        int front;
        if (empty()) {
            return front;
        }
        return elements[f];
    }
    void pop() {
        if (empty()) {
            return;
        }
        ++f;
        return;
    }


private:
    vector <int> elements;
    int f, l;
};

    int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    myqueue kolejka;
    cout << kolejka.empty() << "\n";
    kolejka.push(88888);
    kolejka.push(55555);
    cout << kolejka.empty() << "\n";
    cout << "size " << kolejka.size() << "\n";
    cout << "first element " << kolejka.first() << "\n";
    kolejka.pop();
    cout << "size " << kolejka.size() << "\n";
    cout << "first element " << kolejka.first() << "\n";
    cout << kolejka.dequeue() << "\n";
    cout << kolejka.empty() << "\n";
    return 0;  
    }