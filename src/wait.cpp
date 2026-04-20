/**
 * @file wait.cpp
 * @brief Implementation of wait utilities for the LENS framework.
 */

#include "lens/wait.h"

#include <chrono>
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <thread>

namespace lens {

void wait_for_input(const std::string& prompt)
{
    if (!prompt.empty()) {
        std::cout << prompt << std::flush;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool wait_until(
    const std::function<bool()>&  condition,
    std::chrono::milliseconds     timeout,
    std::chrono::milliseconds     poll_interval)
{
    using clock = std::chrono::steady_clock;

    const bool has_timeout = timeout > std::chrono::milliseconds::zero();
    clock::time_point deadline;
    if (has_timeout) {
        deadline = clock::now() + timeout;
    }

    while (!condition()) {
        if (has_timeout && clock::now() >= deadline) {
            return false;
        }
        std::this_thread::sleep_for(poll_interval);
    }

    return true;
}

} // namespace lens
