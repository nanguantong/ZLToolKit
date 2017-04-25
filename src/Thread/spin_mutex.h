/*
 * spinmutex.h
 *
 *  Created on: 2017年3月31日
 *      Author: xzl
 */

#ifndef SRC_THREAD_SPIN_MUTEX_H_
#define SRC_THREAD_SPIN_MUTEX_H_

#include <atomic>

using namespace std;

namespace ZL {
namespace Thread {

class spin_mutex {
  std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
  spin_mutex() = default;
  spin_mutex(const spin_mutex&) = delete;
  spin_mutex& operator= (const spin_mutex&) = delete;
  void lock() {
    while(flag.test_and_set(std::memory_order_acquire))
      ;
  }
  void unlock() {
    flag.clear(std::memory_order_release);
  }
};

} /* namespace Thread */
} /* namespace ZL */

#endif /* SRC_THREAD_SPIN_MUTEX_H_ */
