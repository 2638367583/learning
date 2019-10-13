#include <iostream>
#include <thread>

using namespace std;
int main() {
    thread *p_thread = new thread();
    auto id = p_thread->get_id();
    std:cout << id;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}