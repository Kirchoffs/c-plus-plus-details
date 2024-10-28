#include <string>
#include <thread>
#include <cstdio>

void f(int i, std::string const& s) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf("i = %i, s = %s\n", i, s.c_str());
}

// It has a bug: the buffer may be destroyed before the thread has a chance to use it.
void not_oops(int some_param)
{
    char buffer[1024];
    sprintf(buffer, "%i", some_param);
    std::thread t(f, 6174, buffer);
    t.detach();
}

int main() {
    not_oops(42);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
