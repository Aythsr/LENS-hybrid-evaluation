/**
 * @file wait_example.cpp
 * @brief Demonstrates the LENS wait utilities.
 *
 * Compile (from the repository root):
 *   g++ -std=c++17 -Iinclude examples/wait_example.cpp src/wait.cpp -o wait_example
 * Run:
 *   ./wait_example
 */

#include "lens.h"

#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    /* ---- 1. wait for a fixed duration ---------------------------------- */
    std::cout << "Waiting 1 second...\n";
    lens::wait(1s);
    std::cout << "Done.\n\n";

    /* ---- 2. wait_until with a condition and timeout -------------------- */
    std::atomic<bool> ready{false};

    // A background thread will flip `ready` after 300 ms.
    std::thread worker([&ready] {
        std::this_thread::sleep_for(300ms);
        ready.store(true);
    });

    std::cout << "Waiting for condition (should resolve in ~300 ms, 2 s timeout)...\n";
    bool resolved = lens::wait_until([&ready] { return ready.load(); }, 2000ms);
    worker.join();
    std::cout << (resolved ? "Condition met.\n" : "Timed out.\n") << '\n';

    /* ---- 3. wait for user input ---------------------------------------- */
    lens::wait_for_input("Press Enter to continue...");
    std::cout << "User input received. Exiting.\n";

    return 0;
}
