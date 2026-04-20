#ifndef LENS_WAIT_H
#define LENS_WAIT_H

/**
 * @file wait.h
 * @brief Wait utilities for the LENS hybrid emulation/simulation framework.
 *
 * Provides mechanisms to pause execution until a duration elapses, a
 * condition becomes true, or the user provides input.  All three forms
 * are composable so simulation steps can synchronise cleanly with either
 * wall-clock time or human interaction.
 */

#include <chrono>
#include <functional>
#include <string>
#include <thread>

namespace lens {

/**
 * Block the calling thread until the user presses Enter.
 *
 * An optional @p prompt is printed to standard output before waiting.
 * If @p prompt is empty no output is produced.
 *
 * @param prompt  Text shown to the user before blocking (default: empty).
 */
void wait_for_input(const std::string& prompt = "");

/**
 * Block the calling thread for the specified @p duration.
 *
 * The function uses a high-resolution sleep so the actual delay is as
 * close to @p duration as the operating system allows.
 *
 * @tparam Rep    Arithmetic type representing the number of ticks.
 * @tparam Period std::ratio representing the tick period.
 * @param  duration  How long to wait.
 *
 * @example
 *   using namespace std::chrono_literals;
 *   lens::wait(500ms);   // wait half a second
 *   lens::wait(2s);      // wait two seconds
 */
template <typename Rep, typename Period>
void wait(const std::chrono::duration<Rep, Period>& duration);

/**
 * Block the calling thread until @p condition returns @c true or the
 * optional @p timeout elapses.
 *
 * The predicate is polled at @p poll_interval intervals (default 10 ms).
 * If @p timeout is zero (the default) the function waits indefinitely.
 *
 * @param condition     Callable returning @c bool; @c true ends the wait.
 * @param timeout       Maximum time to wait; zero means no limit.
 * @param poll_interval How often to re-evaluate @p condition.
 * @return @c true if @p condition became true, @c false if @p timeout elapsed.
 */
bool wait_until(
    const std::function<bool()>&              condition,
    std::chrono::milliseconds                 timeout       = std::chrono::milliseconds::zero(),
    std::chrono::milliseconds                 poll_interval = std::chrono::milliseconds(10));

/* ---- inline / template implementations --------------------------------- */

template <typename Rep, typename Period>
void wait(const std::chrono::duration<Rep, Period>& duration)
{
    std::this_thread::sleep_for(duration);
}

} // namespace lens

#endif /* LENS_WAIT_H */
