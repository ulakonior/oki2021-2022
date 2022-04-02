#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class myqueue {
public:
    myqueue() {
        first = last = -1;
    }
    bool empty() {
        if (first == -1) {
            return true;
        }
        return false;
    }
    void push(int value_to_add) {
        if (empty()) {
            elements.push_back(value_to_add);
            first = 0;
            last = 0;
            return;
        }
        elements.push_back(value_to_add);
        ++last;
        return;
    }
    int dequeue() {
        int value_to_return;
        if (empty()) {
            return value_to_return;
        }
        if (first == last) {
            value_to_return = elements[first];
            elements.clear();
            first = last = -1;
            return value_to_return;
        }
        value_to_return = elements[first];
        ++first;
        return value_to_return;
}

private:
    vector <int> elements;
    int first, last;
};

    int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    myqueue kolejka;
    cout << kolejka.empty() << "\n";
    kolejka.push(88888);
    kolejka.push(55555);
    cout << kolejka.empty() << "\n";
    cout << kolejka.dequeue() << "\n";
    cout << kolejka.dequeue() << "\n";
    cout << kolejka.empty() << "\n";
    return 0;  
    }