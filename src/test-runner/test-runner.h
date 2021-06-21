#pragma once

#include <cstdlib>
#include <iostream>
#include <exception>
#include <cassert>
#include <string>
#include <sstream>

#define ASSERT(actual, expected) {                              \
    std::ostringstream os;                                      \
    os << "Assertion failed: " << actual << " != " << expected; \
    os << "; file = " << __FILE__ << ": line = " << __LINE__;   \
    Assert(actual, expected, os.str());                         \
}

#define TEST_RUN(tr, function) {        \
    tr.TestRun(function, #function);    \
}

template<typename T>
void Assert(const T &actual, const T &expected, const std::string &message) {
    if (actual != expected) {
        throw std::runtime_error(message);
    }
}

class TestRunner {
public:
    ~TestRunner();

    template<typename T>
    void TestRun(T &function, std::string name) {
        try {
            function();
            std::cerr << name << " is OK" << std::endl;
        } catch (const std::runtime_error &ex) {
            failed_tests++;
            std::cerr << ex.what() << std::endl;
        }
    }


private:
    int failed_tests = 0;
};
