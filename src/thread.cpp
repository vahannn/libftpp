#include "thread.hpp"
#include "thread_safe_iostream.hpp"

Thread::Thread(const std::string& name, std::function<void()> functToExecute)
    : _name(name),  _functToExecute(functToExecute) { };

void Thread::start() {
    _thread = std::thread(&Thread::_start, _name, _functToExecute);
};

void Thread::_start(const std::string& name, const std::function<void()> &functToExecute) {
    threadSafeCout.setPrefix(name);
    functToExecute();
};

void Thread::stop() {
    _thread.join();
};