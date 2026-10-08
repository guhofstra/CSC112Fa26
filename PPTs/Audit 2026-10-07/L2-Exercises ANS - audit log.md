# L2-Exercises ANS.pptx - audit log

审计时间：2026-10-07；原始文件已备份在 `PPTs/bak/audit-20261007/`。共 14 页。**已修改 63 处（见下表，同一处的多步编辑已合并）；需要确认 / 未修改 8 项。**

## 已修改

### 答案复核（我把每道题重新做了一遍）

| 页 | 题目 | 我的推导 | 结论 |
|---|---|---|---|
| 2-3 | `for(i<2){fork(); child: printf; return; parent: wait}` | i=0：子进程打印 Hello 0 后 return，父进程 wait 后进入 i=1；子进程打印 Hello 1；父进程循环结束打印 Parent exiting。因为每轮都 wait，输出唯一。 | 答案 Hello 0 / Hello 1 / Parent exiting **正确** |
| 4-5 | 同上，子进程 printf 后 exec(SOME_COMMAND)（该命令不打印） | exec 成功则不返回，"Hello again" 和 return 0 不会执行；父进程行为同上。 | **正确**（前提：exec 成功；`exec()` 并非真实 API，见下方“未修改”） |
| 6-7 | 两个子进程先后 fork，父进程之后 wait 两次 | 两个子进程各打印一次 Hello i，顺序不定；父进程在 2 次 wait 之后才打印 Parent exiting；只有父进程能走到循环外（子进程在循环内 return）。共 2 种输出 | **正确**（但原代码有编译错误，已修，见下表） |
| 8 | `fork(); printf(getpid())` | 父子各打印一行，共 2 行，顺序可交换 | **正确** |
| 9 | `a=5; if(fork()==0) a+=5 else a-=5` | 子进程 a=10，父进程 a=0；虚拟地址相同（fork 复制地址空间），物理地址不同。所以 u+10=x 且 v=y，即选项 (C) | 幻灯片输出 **正确**；备注原来没有给答案，现已补上 (C) |
| 10 | `for(i<3) fork(); printf("Hello")` | 进程数 1→2→4→8，每个进程各打印一次 → 8 行（2^3） | **正确** |
| 11 | `for(i<3){fork(); printf}` | 第 i 轮 fork 之后有 2^(i+1) 个进程打印：2+4+8 = 14 行 | **正确**（但原代码 printf("Hello i\n") 打印的是字面量 "Hello i"，已修） |
| 13 | 两个 fork + if(pid1>0 && pid2==0){ if(pid3=fork()>0) pid4=fork(); } | P0 fork→P1；P0,P1 各 fork→P2(P0 的子),P3(P1 的子)。条件仅在 P2 为真（pid1>0 由 P0 复制而来，pid2==0）。P2 fork→P4，P2 得到 true 再 fork→P5，P4 得到 false。共 P0–P5 = 6 个 | **正确** |
| 14 | `if(pid1=fork()>0 \|\| pid2=fork()>0) pid3=fork()` | P0：fork→P1，pid1=1，短路，跳过第二个 fork；进入 if，fork→P2。P1：pid1=0，求值第二个 fork→P3；P1 中 pid2=1 为真，进入 if，fork→P4；P3 中 pid2=0 为假，结束。共 P0–P4 = 5 个 | **正确**（讲解文字里的 `true&&?` 笔误已改） |

### 具体修改

| 页 | 位置 | 修改前 | 修改后 | 原因 |
|---|---|---|---|---|
| 2 | TextBox 4 (id 5) para 12 | `⇥  wait(NULL);  // Wait for i…` | `            wait(NULL);  // Wait for i…` | Tab indentation misaligned wait(NULL) with the comment line above it; replaced by spaces (code box is monospace) |
| 2 | Content Placeholder 2 (id 3) para 4 | `…” here is the same as “exit()”` | `…” here is the same as “exit(0)”` | On a return from main, "return 0" equals exit(0); exit() without an argument is not valid C |
| 4 | Content Placeholder 2 (id 3) para 0 | `…following it (e.g., printf("Child\n")) will not be executed beca…` | `…following it (e.g., printf("Hello again %d\n", i)) will not be executed beca…` | Slide text referred to printf("Child\n"), which does not appear in the code box (code has printf("Hello again %d\n", i)) |
| 4 | TextBox 4 (id 5) para 11 | `⇥  return 0;  // Exit child p…` | `            return 0;  // Exit child p…` | Tab indentation misaligned (see S2) |
| 6 | TextBox 4 (id 5) para 2 | `(blank line)` | `    pid_t pid;` | pid was declared inside the for body (pid_t pid = fork();) but used in "if (pid > 0)" after the loop -> compile error (undeclared); moved the declaration before the loop |
| 6 | TextBox 4 (id 5) para 4 | `        pid_t pid = fork(); // Create a child…` | `        pid = fork(); // Create a child…` | declaration moved before loop (see above) |
| 7 | TextBox 4 (id 5) para 2 | `(blank line)` | `    pid_t pid;` | pid was declared inside the for body (pid_t pid = fork();) but used in "if (pid > 0)" after the loop -> compile error (undeclared); moved the declaration before the loop |
| 7 | TextBox 4 (id 5) para 4 | `        pid_t pid = fork(); // Create a child…` | `        pid = fork(); // Create a child…` | declaration moved before loop (see above) |
| 8 | 内容占位符 2 (id 7) para 2 | `…les, we omit the check for p<0 and assume fork() calls a…` | `…les, we omit the check for pid<0 and assume fork() calls a…` | Variable in the code is named pid, not p |
| 8 | object 3 (id 3) new para after #include <unistd.h> | `(none)` | `#include <stdlib.h>` | Code calls exit(1) but stdlib.h was not included (implicit declaration is an error in C99+/modern gcc) |
| 9 | Plassholder for innhold 2 (id 4) para 1 | `if (pid=fork()==0) {` | `if ((pid=fork())==0) {` | Precedence bug: pid=fork()==0 assigns (fork()==0) to pid; parenthesize so pid receives the return value of fork() |
| 9 | Plassholder for innhold 2 (id 4) para 3 | `    printf(“In child, a=%d, a memory address=%d\n", a, &a);` | `    printf("In child, a=%d, a memory address=%p\n", a, (void *)&a);` | Curly opening quote is a compile error; %d with an address is wrong, use %p with (void *)&a (slide output shows a hex address) |
| 9 | Plassholder for innhold 2 (id 4) para 7 | `    printf(“In parent, a=%d, a memory address=%d\n", a, &a);` | `    printf("In parent, a=%d, a memory address=%p\n", a, (void *)&a);` | same as above |
| 9 | Plassholder for innhold 2 (id 4) para 6 | `    a = a – 5;` | `    a = a - 5;` | En dash used as minus operator in code |
| 9 | 内容占位符 2 (id 7) para 0 | `… = 10; In Parent (u), a = a – 5 = 0. ` | `… = 10; In Parent (u), a = a - 5 = 0. ` | En dash used as minus sign |
| 9 | TextBox 7 (id 8) para 1 | `In parent, a = 0, a memory address=0x1234` | `In parent, a=0, a memory address=0x1234` | Output line must match printf format "a=%d" (child line already uses a=10) |
| 9 | TextBox 7 (id 8) para 5 | `In parent, a = 0, a memory address=0x1234` | `In parent, a=0, a memory address=0x1234` | same as above |
| 10 | 内容占位符 2 (id 95) para 5 | `…processes P0 to P7 prints a ”Hello”.` | `…processes P0 to P7 prints a “Hello”.` | Closing quote used as opening quote |
| 11 | object 3 (id 4) para 5 | `printf("Hello i\n"); } //inside for loop` | `printf("Hello %d\n", i); } //inside for loop` | printf printed the literal text "Hello i" instead of the loop index; the slide explanation expects "Hello 0/1/2" |
| 11 | object 3 (id 4) width | `5401464` | `5943600` | Code box widened (5.91in -> 6.5in) so the corrected printf line does not wrap/spill after the fix; no neighbour within 1in to the right |
| 12 | object 3 (id 4) para 1 | `While(true) fork(); ` | `while (1) fork(); ` | C keyword is lowercase "while"; "true" needs <stdbool.h> |
| 12 | 内容占位符 2 (id 67) para 2 | `Limit User Processes:  Use ulimit in Linux to restr…` | `Limit User Processes: Use ulimit in Linux to restr…` | Double space |
| 14 | object 3 (id 78) para 4 | `return 0:` | `return 0;` | "return 0:" -> "return 0;" (colon instead of semicolon) |
| 14 | object 3 (id 78) para 5 | `5 }` | `6 }` | Line number: the auto-numbered lines are 4 ({pid3=fork();}) and 5 (return 0;), so the closing brace is line 6, not a second 5 |
| 14 | 内容占位符 2 (id 88) para 2 | `…ondition (pid1>0\|\|?) = (true&&?)=true, so P0 skips the cal…` | `…ondition (pid1>0\|\|?) = (true\|\|?)=true, so P0 skips the cal…` | Wrong operator: the whole condition is (pid1>0||?) = (true||?) = true |
| 2 | NOTES para 37 | `text` | `(deleted)` | stray / unrelated notes text |
| 2 | NOTES para 26 | `text` | `(deleted)` | stray / unrelated notes text |
| 9 | NOTES para 2 | `ANS:` | `Options:` | Answer follows after the options |
| 9 | NOTES para 7 | `(blank)` | `ANS: (C) u + 10 = x and v = y. The parent prints a = 0 (u) and the child prints a = 10 (x); both print the same virtual address of a (v = y).` | Notes listed the question and options but never stated the answer |
| 13 | NOTES para 0 | `…e two processes: the parent and the child. executing fork on line 4. After fork returns both in P0 and P1, we have two ` | `…e two processes: the parent (P0) and the child (P1). ` | Garbled dangling fragment |
| 13 | NOTES para 8 | `…ocess P0) and the second form returned pid2==0 (i.e. we a…` | `…ocess P0) and the second fork returned pid2==0 (i.e. we a…` | Typo form -> fork |
| 14 | NOTES para 0 | `…ondition (pid1>0\|\|?) = (true&&?)=true, so it stops here and does not call any more fork(). (? stands for either true…` | `…ondition (pid1>0\|\|?) = (true\|\|?)=true, so the second operand pid2=fork() is not evaluated (short-circuit) and P0 enters the if body (line 4). (? stands for either true…` | Wrong operator (&&) and wrong conclusion ("stops here") contradicted the next note line |
| 14 | NOTES para 3 | `Line 4: In P0, since pid1 > 0 in P0, the condition (pid1=fork()\|\|pid2=fork())=(true\|\|?)=true, so P0 goes…` | `Line 4: In P0, the condition (pid1>0\|\|pid2>0)=(true\|\|?)=true, so P0 goes…` | Condition written inconsistently with the code (missing >0) |
| 14 | NOTES para 4 | `…ild process P3. In P3, (pid1=fork()\|\|pid2=fork())=(false\|\|false)=false, so i…` | `…ild process P3. In P3, (pid1>0\|\|pid2>0)=(false\|\|false)=false, so i…` | same |
| 14 | NOTES para 5 | `… pid2>0, the condition (pid1=fork()\|\|pid2=fork())=(false\|\|true)=true, so P1 …` | `… pid2>0, the condition (pid1>0\|\|pid2>0)=(false\|\|true)=true, so P1 …` | same |
| 14 | NOTES para 6 | `Each of the 5 processes P0 to P4 prints a ”Hello”.` | `In total there are 5 processes: P0 to P4.` | Code has no printf; sentence was left over from the previous exercise (and had a wrong quote) |
| 9 | NOTES（备注）共 21 个段落 | 重复的题干/选项，以及与本页无关的“fork() 三行 → 2^n 个进程”讲解（属于第 10 页） | （已删除） | 备注是从其他题复制过来的，与本页内容无关 |
| 8, 9, 10, 11, 12, 14 | 标题框位置 | top=0.30in，宽 12.4in（版式 “Tittel og innhold”，标题压在横线上） | 与第 2-7 页相同：left 1.44in, top 0.17in, 10.44×0.58in | 第 8-14 页标题比第 2-7 页低 0.13in 并压在分隔线上，已对齐（第 13 页没有标题，见下） |

## 已发现但未修改 / 需要你确认

1. **第 4、5 页**：`exec(SOME_COMMAND)` 不是真实存在的函数（应为 `execl`/`execvp` 等）。作为伪代码可以，但与第 14 页（L2 讲义）里的 exec 家族写法不一致；是否改成 `execvp(...)` 请你决定。
2. **第 13 页**：这一页**没有标题**（其余 Quiz 页都是 “Quiz: Fork”），因为代码框从页面最顶端 (top=0.06in) 开始。要加标题需要把整页内容下移，而页面下半部分已经排满（P5 框底部 7.3in），所以没有改动。建议拆页或缩小图。
3. **第 10、11 页**：右侧文字框（`内容占位符 2`）高度很大，第 11 页的文字框 top = -0.03in（超出页面上缘），并且和底部灰色说明框（“printf() (outside/inside for loop)…”）在渲染中有重叠，第 11 页标题右端会被文字框遮住一点。这取决于 PowerPoint 实际字体，LibreOffice 里确实有重叠；请在 PowerPoint 里看一眼，必要时缩字号。
4. **第 10 页**：“…their PCBs remain in the process table … resulting in zombie processes” 表述略强：这些子进程若其父进程也退出，会被 init/systemd 收养并回收，只有父进程还活着且没 wait 时才是僵尸进程。是否保留请你定。
5. **第 9 页**：“The physical addresses of ‘a’ in parent and child must be different” 在 copy-on-write 下，只有写入之后（本例确实都写了）才不同；可补一句。另外代码片段里 `pid`、`a` 没有声明（示意代码）。
6. **第 2-7 页**代码缺少 `#include <sys/wait.h>` 等头文件（第 8 页有完整 include），属于示意代码，未改。
7. **第 10 页备注**里的代码（三条连续的 `fork();`）与幻灯片上的 for 循环写法不同，结果相同；保留。
8. **第 9、14 页** 的 `if (pid=fork()==0)` / `if(pid1=fork()>0||...)` 中，赋值优先级低于比较（`pid1` 实际得到 0/1，而不是子进程 pid）。第 9 页我已加括号；第 14 页是故意考察短路求值的题目，且结果不受影响，未改，但讲解里可点明这一点。

## 观察 / 建议

- 本套 Exercise 只有 fork/wait/exec 题，没有覆盖 L2 讲义后半部分（线程、pthread_create/join 输出、用户态 vs 内核态线程、僵尸/孤儿进程、进程状态转换）。建议补 2-3 题。
- 第 2 页备注是 Perplexity 生成的大段英文，末尾保留了 “Answer from Perplexity: pplx.ai/share”；我只删掉了两个误带入的 “text” 行。
- 第 8-14 页使用的是挪威语/中文版式名（“Tittel og innhold”）和中文形状名，不影响显示，但和第 2-7 页版式不同，是标题位置漂移的根源。
- 第 1 页 “Department of Computer Science,” 末尾的逗号可以去掉（其它几个讲义同样如此）。
- 课程名称在本套 Exercise 里统一为 “CSC 112”，没有发现 CSC256 或旧学期遗留。
