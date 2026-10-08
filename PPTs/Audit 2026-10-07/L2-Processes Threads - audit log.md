# L2-Processes Threads.pptx - audit log

共 37 页。逐页读过全部文字、备注、表格和分组形状，并渲染检查。课程名称统一为 “CSC 112”，没有发现 CSC256 / 旧学期遗留。

## 已修改

| 页 | 位置 | 修改前 | 修改后 | 原因 |
|---|---|---|---|---|
| 2 | 内容占位符 2 (id 3) para 3 | `… program started via Graphic User Interface (GUI) mouse …` | `… program started via Graphical User Interface (GUI) mouse …` | "Graphic User Interface" -> "Graphical User Interface" |
| 4 | Plassholder for innhold 2 (id 3) para 5 | `…Stack Pointer), PC (Program counter)` | `…Stack Pointer), PC (Program Counter)` | Capitalisation consistent with "PC (Program Counter)" in the diagram |
| 5 | Plassholder for innhold 2 (id 3) para 6 | `…ty, but PCB in Linux include them for convenient referen…` | `…ty, but PCB in Linux includes them for convenient referen…` | Grammar |
| 6 | Plassholder for innhold 2 (id 3) para 2 | `Ready to run and pending for running` | `Ready to run, waiting to be scheduled onto the CPU` | "Ready to run and pending for running" was awkward |
| 6 | Plassholder for innhold 2 (id 3) para 4 | `Being executed by OS` | `Being executed on the CPU` | A process is executed by the CPU, not "by OS" |
| 7 | Plassholder for innhold 2 (id 3) para 7 | `Kill the processes` | `Kill (terminate) a process` | Singular/plural and clarity |
| 9 | Plassholder for innhold 2 (id 3) para 7 | `Fun analogy: imaging you are a process after fork, but you don’t know if you are the child or parent process, as if you are running inside of a Matrix. But you can identify which process you are running, by looking up to the sky and see the ret value from fork() ` | `Fun analogy: imagine you are a process after fork, but you don’t know if you are the child or parent process, as if you are running inside of a Matrix. But you can identify which process you are running, by looking up at the sky and seeing the ret value from fork() ` | Typo |
| 9 | Plassholder for innhold 2 (id 3) para 4 | `…unning in the parent process, ` | `…unning in the parent process. ` | Stray comma at end of bullet |
| 9 | Content Placeholder para 8 | `has same` | `has the same` | Grammar |
| 9 | Content Placeholder para 10 | `Child and parents have different` | `Child and parent have different` | Number agreement |
| 9 | Content Placeholder para 11 | `PIDs, memory spaces` | `PIDs and memory spaces` | Grammar |
| 12 | Plassholder for innhold 2 (id 3) para 2 | `⇥printf("hello world (ret:%d)\n", (int) getpid()); ` | `⇥printf("hello world (pid:%d)\n", (int) getpid()); ` | Label said ret but prints getpid(); matches the output screenshots on slide 13 ("hello world (pid:...)") |
| 12 | Plassholder for innhold 2 (id 3) para 13 | `…is path (original process). wc (wait child) stores pid of the child p…` | `…is path (original process). cpid (child pid) stores pid of the child p…` | Comment referred to a non-existent variable "wc"; the variable is cpid |
| 12 | Plassholder for innhold 2 (id 3) para 14 | `⇥⇥int cpid = wait(NULL); //wc contains pid of the child p…` | `⇥⇥int cpid = wait(NULL); //cpid contains pid of the child p…` | Comment referred to a non-existent variable "wc"; the variable is cpid |
| 13 | 内容占位符 2 (id 3) para 5 | `…it(): child runs first, and parents waits for child to finish` | `…it(): child runs first, and the parent waits for the child to finish` | Grammar |
| 14 | Plassholder for innhold 2 (id 3) para 1 | `It does not return. It starts to execute the n…` | `It does not return on success (it returns -1 only on error). It starts to execute the n…` | Accuracy: exec returns (-1) when it fails; notes already say so |
| 15 | Plassholder for innhold 2 (id 3) para 7 | `} else if (pid == 0) {  // child (new proc…` | `} else if (ret == 0) {  // child (new proc…` | Undeclared variable pid; the fork() result is stored in ret (compile error) |
| 15 | Plassholder for innhold 2 (id 3) para 10 | `⇥myargs[0] = strdup(“wc”);  // program: ”wc“ (word count) ` | `⇥myargs[0] = strdup("wc");  // program: "wc" (word count) ` | Curly quote is a compile error in C |
| 15 | Plassholder for innhold 2 (id 3) para 11 | `⇥myargs[1] = strdup(“p3.c”);  // argument: file to cou…` | `⇥myargs[1] = strdup("p3.c");  // argument: file to cou…` | Curly quotes are a compile error in C |
| 15 | Plassholder for innhold 2 (id 3) para 14 | `⇥printf(“This line will never be exec…` | `⇥printf("This line will never be exec…` | Mismatched curly/straight quotes: compile error |
| 15 | Plassholder for innhold 2 (id 3) para 17 | ` ⇥printf(“hello, I am parent of %d (wc:%d) (pid:%d)\n”, ret, cpid, (int) getpid())…` | ` ⇥printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", ret, cpid, (int) getpid())…` | Curly quote is a compile error in C |
| 15 | 内容占位符 2 (id 11) para 0 | `In the child process (rc == 0), the execvp() function replaces the current process image with the program named “wc“, a program that counts Lines, Words, and Bytes in a file, with output …` | `In the child process (ret == 0), the execvp() function replaces the current process image with the program named “wc”, a program that counts lines, words, and bytes in a file, with output …` | Variable is named ret in the code |
| 15 | 内容占位符 2 (id 11) para 1 | `…ram are passed as an array (args[]), where the first ele…` | `…ram are passed as an array (myargs[]), where the first ele…` | Array is called myargs in the code |
| 15 | 内容占位符 2 (id 11) para 2 | `…rogram, so the line “printf(“This line will never be executed.");“ will never be executed. ` | `…rogram, so the line “printf("This line will never be executed.");” will never be executed. ` | Quote style inside the quoted code |
| 16 | 标题 1 (id 2) para 0 | `IO redirection and pipe ` | `I/O redirection and pipe ` | Consistent "I/O" (used elsewhere in the deck) |
| 16 | 内容占位符 2 (id 3) para 0 | `…a new program and make the IO redirection and pipe possi…` | `…a new program and make the I/O redirection and pipe possi…` | Consistent "I/O" |
| 16 | 内容占位符 2 (id 3) para 1 | `IO redirection: output of the…` | `I/O redirection: output of the…` | Consistent "I/O" |
| 16 | Rectangle 5 (id 7) top | `3.91 in` | `4.10 in` | Gray command box sat on top of the "Pipe: ..." text line; moved down 0.19in |
| 19 | 内容占位符 2 (id 3) para 6 | `% ps (to show all processes as a flat list)` | `% ps ax (to show all processes as a flat list; plain “ps” shows only the current terminal’s processes)` | Plain "ps" lists only the current terminal's processes; screenshot shows all processes (PID 1 launchd) |
| 22 | bullet | `exec() to replace the command` | `exec() to replace the program` | exec() replaces the process image with a new program (slide 8 says "new program") |
| 36 | bullet | `exec() to replace the command` | `exec() to replace the program` | exec() replaces the process image with a new program (slide 8 says "new program") |
| 23 | Rectangle 3 (id 128003) para 5 | `Registers, IP` | `Registers, PC` | "IP" vs "PC": the deck uses PC everywhere else (slides 3, 4, 25, 28) |
| 24 | 文本框 6 (id 9) para 0 | `Thread for disk IO` | `Thread for disk I/O` | Consistent "I/O" |
| 28 | Rectangle 13 (id 110605) para 1 | `(dynamic allocated mem)` | `(temporary data)` | Stack was labelled "dynamic allocated mem" (that is the heap); slide 4 labels the stack "(temporary data)" |
| 31 | Content Placeholder 2 (id 3) | `(empty placeholder)` | `(removed)` | Empty content placeholder ("Click to add text" in editing view) |
| 33 | Rectangle 3 (id 136195) para 4 | `the Linux thread package multiplexes user-level thre…` | `a user-level thread package (e.g., early Java “green threads”) multiplexes user-level thre…` | Linux (NPTL) uses 1:1 kernel threads and does not multiplex user-level threads on kernel threads; the statement describes e.g. early Java green threads |
| 11 | NOTES para 0 | `…l reap any terminated child arbitrarily. process (preventing it from becoming a zombie process` | `…l reap any terminated child (chosen arbitrarily), preventing it from becoming a zombie process.` | Garbled sentence with unbalanced parenthesis |
| 15 | NOTES para 1 | `` | `(deleted)` | Stale paragraph copied from the exercise deck (refers to SOME_COMMAND / printf("Child\n"), which are not on this slide) |
| 15 | NOTES para 0 | `In Child process: exec() replaces the current process image with a new program called SOME_COMMAND. The child process will execute the command and terminate. Th` | `(deleted)` | Stale paragraph copied from the exercise deck (refers to SOME_COMMAND / printf("Child\n"), which are not on this slide) |
| 30 | NOTES para 10 | `pthread_signal(condition_variable)` | `pthread_cond_signal(condition_variable)` | No such function; the API (and slide table) is pthread_cond_signal |
| 30 | NOTES para 14 | `pthread_wait(t)` | `pthread_join(t)` | No such function; the API (and slide table) is pthread_join |
| 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 | 标题框位置 | 第 2-22 页标题 top=0.30in、width=12.4in（第 9 页宽 9.97in、第 15 页宽 8.47in 且偏左） | 全部改为 left 1.44in, top 0.17in, 10.44×0.58in（与第 23-37 页一致） | 前半部分（Process）与后半部分（Threads，来自另一份模板）标题高度不同，第 9、15 页还偏离居中；已统一 |

## 已发现但未修改 / 需要你确认

1. **第 19 页**：我把 “% ps” 改成 “% ps ax …”，依据是截图里列出了 PID 1（launchd）和 STAT 列，普通 `ps` 不会这样；请对照截图确认命令（macOS 上通常是 `ps ax` 或 `ps -ef`）。另外该截图是 macOS，而上一页写的是 “Typical Linux process tree”。
2. **第 6 页**备注讲了 ZOMBIE / 结束状态（“This final state …”），但幻灯片和图只有 READY / RUNNING / BLOCKED 三个状态，没有终止（Terminated/Zombie）状态；第 11 页才第一次提到 zombie。建议补一个状态或删备注。
3. **第 12、13、15 页**：`printf` 里的 “wc:%d” 实际打印的是子进程 pid（变量 `cpid`），而且 13、15 页的输出截图里也写着 “wc:”；这个 “wc” 容易和第 15 页的 `wc` 命令混淆。截图无法修改，所以只改了注释。
4. **第 14 页**：`exec(cmd, argv)` 是伪记法，不是真实函数（备注里已说明）。可以在页上标注 “pseudo”。
5. **第 15 页**：右侧文字框内容较多，在 LibreOffice 渲染中超出页面底部（normAutofit 没有记录缩放比例）；请在 PowerPoint 里确认是否被截断。页面左下 “Output:” 标签也偏窄。备注现在只剩 execl 的练习答案（来自习题），与本页关系不大。
6. **第 16 页备注**（“On early PDP-7 computer, it only needs 27 lines of assembly code / 1965 / standard output”）是关于 fork 在早期 Unix/PDP-7 上实现很简单的内容，放在 “IO redirection and pipe” 页不匹配，也未注明出处；我没有改动。
7. **第 22 页** 最后一条 “Process scheduling” 在本讲义里没有对应内容（调度在 L5）。**第 22 与第 36 页**总结重复。
8. **第 24 页**：正文最后一条与下方图片在 LibreOffice 渲染中有轻微重叠，请在 PowerPoint 里确认。
9. **第 27 页** “The address space: code, most data (heap)” 不太精确：全局/静态数据也共享，栈是每线程独有。建议改为 “code, global/static data, heap”。
10. **第 34 页**：“thread context switch involves system calls” 不准确（线程的创建/同步等操作需要系统调用；上下文切换发生在内核里）。表述来自 Berkeley CS162 的旧讲义，我不确定你想保留的原意，所以只标出。
11. **第 35 页**：把 `libpthreads.a` 作为 “user-level library” 的例子容易误导——Linux 上的 pthread（NPTL）是 1:1 的内核线程；用户态线程的例子是 green threads、GNU Pth、fibers/coroutines 等。
12. **第 36 页备注**里有 “What is Thread Synchronization?” 的视频链接及零散要点（fast / great for common-case operations …），与本页无关，疑为遗留。
13. **第 37 页**：参考文献中 “Concurrency Vs Parallelism! ByteByteGo” 视频在正文里没有出现；而第 9-15 页的 fork/wait/exec 示例代码取自 OSTEP（Arpaci-Dusseau）却没有致谢。第 1 页只致谢了 UC Berkeley CS 162（线程部分）。建议补充。
14. **第 2 页** “Process is an abstraction of CPU” 不够准确（进程是对“运行中的程序”的抽象，同时虚拟化了 CPU 与内存）；未改。
15. 空的页脚占位符（第 2、3、4、17 页）无害，未动；第 31 页的空内容占位符已删除。

## 观察 / 建议

- 前半（Process，第 2-22 页）和后半（Thread，第 23-37 页）来自两种模板，字体、标题位置、字号不一致；标题位置已统一，字体/配色未动。
- 第 2-5 页连续四页标题都是 “Process”，第 18-19 页都是 “Process Tree”；建议加副标题区分。
- 缺少：zombie/orphan 进程的单独说明（第 11 页只在 wait() 里提了一句）、进程状态里的终止态、线程部分没有 pthread 竞争条件示例（可引到 L3）。
- 第 31 页示例没有 `#include <pthread.h>`，也没有编译命令（`gcc -pthread`），可在备注里补。
