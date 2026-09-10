# Operating Systems Lab Programs (CSA04)

40 C programs covering the full OS lab syllabus — process management, CPU
scheduling, IPC, synchronization, memory management, file systems, disk
scheduling, and UNIX system calls. All programs are tested and compile
cleanly with `gcc` on Linux.

## How to compile & run

Most programs need only plain `gcc`:
```bash
gcc 01_create_process_pid.c -o exp1
./exp1
```

Programs that use threads/semaphores need `-lpthread`:
```bash
gcc 11_multithreading_demo.c -o exp11 -lpthread
./exp11
```
(Files needing `-lpthread`: 11, 12, 18, 19, 20, 29, 30)

Shared memory / message queue programs (09, 10) use System V IPC — no
extra flags needed, just plain `gcc`.

## File list

| # | File | Topic |
|---|------|-------|
| 1 | 01_create_process_pid.c | Create process with fork(), get PID/PPID |
| 2 | 02_file_copy.c | Copy file using open/read/write |
| 3 | 03_fcfs_scheduling.c | FCFS CPU scheduling |
| 4 | 04_sjf_nonpreemptive.c | SJF (shortest burst first) |
| 5 | 05_priority_scheduling_nonpreemptive.c | Priority scheduling (non-preemptive) |
| 6 | 06_priority_scheduling_preemptive.c | Priority scheduling (preemptive) |
| 7 | 07_sjf_with_arrival.c | Non-preemptive SJF with arrival times |
| 8 | 08_round_robin_scheduling.c | Round Robin scheduling |
| 9 | 09_ipc_shared_memory.c | IPC using shared memory |
| 10 | 10_ipc_message_queue.c | IPC using message queue |
| 11 | 11_multithreading_demo.c | Multithreading basics |
| 12 | 12_dining_philosophers.c | Dining Philosophers problem |
| 13 | 13_memory_allocation_strategies.c | Memory allocation strategy |
| 14 | 14_single_level_directory.c | Single level directory structure |
| 15 | 15_two_level_directory.c | Two level directory structure |
| 16 | 16_random_access_employee_file.c | Random access file - employee records |
| 17 | 17_bankers_algorithm.c | Banker's algorithm (deadlock avoidance) |
| 18 | 18_producer_consumer_semaphore.c | Producer-Consumer using semaphores |
| 19 | 19_mutex_lock_sync.c | Synchronization using mutex locks |
| 20 | 20_reader_writer_semaphore.c | Reader-Writer problem using semaphores |
| 21 | 21_worst_fit_allocation.c | Worst fit memory allocation |
| 22 | 22_best_fit_allocation.c | Best fit memory allocation |
| 23 | 23_first_fit_allocation.c | First fit memory allocation |
| 24 | 24_unix_file_management_syscalls.c | UNIX file management system calls |
| 25 | 25_unix_io_syscalls.c | UNIX I/O system calls (fcntl, lseek, stat, opendir, readdir) |
| 26 | 26_file_management_operations.c | File management operations |
| 27 | 27_simulate_ls_command.c | Simulate `ls` command |
| 28 | 28_simulate_grep_command.c | Simulate `grep` command |
| 29 | 29_sleeping_barber_problem.c | Classical synchronization: Sleeping Barber |
| 30 | 30_thread_create_join_equal_exit.c | Thread create/join/equal/exit |
| 31 | 31_fifo_page_replacement.c | FIFO page replacement |
| 32 | 32_lru_page_replacement.c | LRU page replacement |
| 33 | 33_optimal_page_replacement.c | Optimal page replacement |
| 34 | 34_sequential_file_allocation.c | Sequential file allocation |
| 35 | 35_indexed_file_allocation.c | Indexed file allocation |
| 36 | 36_linked_file_allocation.c | Linked file allocation |
| 37 | 37_fcfs_disk_scheduling.c | FCFS disk scheduling |
| 38 | 38_scan_disk_scheduling.c | SCAN disk scheduling |
| 39 | 39_cscan_disk_scheduling.c | C-SCAN disk scheduling |
| 40 | 40_file_access_permissions.c | File access permissions (Linux) |

## Uploading to GitHub

```bash
git init
git add .
git commit -m "OS lab programs"
git branch -M main
git remote add origin https://github.com/<your-username>/<repo-name>.git
git push -u origin main
```
