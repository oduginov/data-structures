#include "test-runner/test-runner.h"
#include "graphs/tests/node-test.h"

int Sum(int x, int y) {
    return x + y;
}

int Diff(int x, int y) {
    return x - y;
}

void TestSum() {
    ASSERT(Sum(1, 1), 2);
}

void TestDiff() {
    ASSERT(Diff(1, 1), 0);
}

int main() {
    {
        TestRunner testRunner;
        TEST_RUN(testRunner, TestSum);
        TEST_RUN(testRunner, TestDiff);
        TEST_RUN(testRunner, TestNode);
    }

    return 0;
}
