#include "test-runner.h"

TestRunner::~TestRunner() noexcept {
    if (failed_tests > 0) {
        exit(1);
    }
}



