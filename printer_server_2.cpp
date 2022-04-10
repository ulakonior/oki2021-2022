// Version 2.0
// object oriented programming with new methods
// 1. new_printout
// 2. status_checking
// 3. statistics



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
        average_print_time = -1;
        total_print_time = 0;
        number_of_prints_so_far = 0;
        longest_print = 0;
        longest_queue = 0;
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
        int value_to_return =0;
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
        int front = 0;
        if (empty()) {
            return front;
        }
        return elements[f];
    }
    void pop() {
        if (empty()) {
            return;
        }
        else if (f == l) {
            f = l = -1;
            elements.clear();
            return;
        }
        ++f;
        return;
    }
    void new_printout(int time) {
        // add task to printer
        push(time);
        // update data
        longest_queue = max(longest_queue, size());
        // calculate expected waiting time
        if (average_print_time == -1) {
            expected_time = -1;
        }
        else {
            expected_time = average_print_time * size();
        }
        // print communicate
        cout << "Request accepted. You are number " << size() << " in queue, ";
        cout << " expected time is " << expected_time << " seconds. \n";
    }
    void status_checking(int time) {
        // when there is no prints in the queue
        if (empty()) {
            cout << "Printer is ready.\n";
        }
        else {
            start_time = dequeue();
            print_time = time - start_time;
            ++number_of_prints_so_far;
            total_print_time += print_time;
            average_print_time = total_print_time / number_of_prints_so_far;
            longest_print = max(longest_print, print_time);
            cout << "Printer is ready. Print time: " << print_time << " seconds.\n";
        }
    }
    void statistics (){
        cout << "Stats: Longest queue: " << longest_queue << ", longest waiting time: " << longest_print << " seconds.\n";
    }


private:
    vector <int> elements;
    int f, l;
    int number_of_prints_so_far, total_print_time, average_print_time;
    int expected_time, start_time, print_time;
    int longest_print, longest_queue;
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    myqueue printer;
    int number_of_tasks;
    int time;
    char task;

    cin >> number_of_tasks;
    for (int i = 0; i < number_of_tasks; ++i) {
        cin >> task;
        if (task == 'd') {
            cin >> time;
            printer.new_printout(time);
        }
        else if (task == 'g'){
            cin >> time;
            printer.status_checking(time);
        }
        else if (task == 's') {
            printer.statistics();
        }

    }

    return 0;
}