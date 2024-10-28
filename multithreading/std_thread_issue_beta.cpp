#include <iostream>
#include <thread>

using widget_id = int;

struct widget_data {
    int value = 0;
};

void update_data_for_widget(widget_id w, widget_data& data) {
    std::cout << "Updating data for widget with id: " << w << std::endl;
    data.value = w + 42;
}

void display_status() {
    std::cout << "Displaying status..." << std::endl;
}

void process_widget_data(const widget_data& data) {
    std::cout << "Processing widget data with value: " << data.value << std::endl;
}

// It has a bug: std::thread does not know update_data_for_widget expects a reference to widget_data.
// It will pass a copy of data to the thread, and this copy is temporary so it is a rvalue.
// lvalue references cannot bind to rvalues.
void oops_again(widget_id w) {
    widget_data data;

    std::thread t(update_data_for_widget, w, data);
    // The correct way:
    // std::thread t(update_data_for_widget, w, std::ref(data));
    
    display_status();
    t.join();
    
    process_widget_data(data);
}

int main() {
    widget_id w = 5; 
    oops_again(w);
    return 0;
}
