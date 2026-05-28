#ifndef TITANOS_H
#define TITANOS_H
#include <stdint.h>

#define SYS_READ 0
#define SYS_WRITE 1
#define SYS_OPEN 2
#define SYS_MMAP 3
#define SYS_NANOSLEEP 35
#define SYS_GETUPTIME 36
#define SYS_EXIT 60
#define SYS_SET_TCB 158

static inline uint64_t execute_syscall(uint64_t syscall_num, uint64_t arg0, uint64_t arg1, uint64_t arg2){
  asm volatile("int $0xfe" : "=a"(arg0) : "a"(syscall_num), "D"(arg0) , "S"(arg1), "d"(arg2): "memory", "cc");
  return arg0;
}

#endif // !TITANOS_H

