# CSC112 Review Questions.pptx 审查记录

- 文件：`PPTs/CSC112 Review Questions.pptx`（74 张，修改后仍为 74 张，无隐藏页）
- 原件备份：`PPTs/bak/audit-20261007/`
- 修改方式：只改 run 文本、表格单元格 run、标题的字号/位置（python-pptx + lxml），再把有差异的 24 个 slide XML 写回原包；其余部分（rels、媒体、母版、版式、备注）与原件逐字节相同。改动涉及 24 张幻灯片（共 70 处记录，其中标题格式 11 处、新增标题 2 处）。
- s4 有动画（`p:timing`），目标是 s4 的内容占位符（shape 3）的前 9 段，我只改了代码文本框（shape 6），没有动动画目标；s42 的动画目标是 shape 11/42，不是我改的表格。
- 说明：渲染用 LibreOffice，字体被替换；下面的"溢出/折行"判断参考了原件在 LibreOffice 里的表现，同时按 PowerPoint 的字体宽度估算过。

- 验证（三个 deck 相同）：`validate.py --original` 通过；逐部分 canonical XML（lxml c14n）比较，只有上述 slide（及备注/母版）XML 有差异，其余部分字节相同；改动过的页已重新渲染并查看；提交到原路径后用 python-pptx 重新打开，页数和可加载性已确认。

## 一、已修改

幻灯片编号为当前 1-based 位置。

### 答案/数值错误（每处都重新计算过）

| # | 位置 | 修改前 → 修改后 | 理由与计算 |
|---|------|----------------|-----------|
| 9 | TLB 表（Tag/PPN）第 1 行 | Tag `1` → `0` | 访问序列 VPN = 0,2,1,2,3,2,3,0,0（地址 >>10：0x294=660→0，0xA76=2678→2，0x5A4=1444→1，0x923=2339→2，0xCFF=3327→3，0xA12→2，0xF9F=3999→3，0x392=914→0，0x341=833→0）；TLB 里最终有 VPN 0,2,1,3，PPN = VPN+1 = 1,3,2,4。原表第 1 行写成 Tag 1（与第 3 行重复），应为 0。TLB 命中 5 次（0x923,0xA12,0xF9F,0x392,0x341）、未命中 4 次、缺页 3 次（VPN 0,2,3），与 s8 的表一致 |
| 42 | 第二组调度题 SJF（非抢占）表格 | P2 完成/响应：`8`/`7` → `10`/`9`；P3：`10`/`7` → `5`/`2`；SJF 平均：`Avg RT 5` → `Avg RT 4.25`；Gantt 行 SJF：`1 1 2 2 2 2 2 2 3 3 4 4` → `1 1 1 3 3 2 2 2 2 2 4 4` | 题：P1(到达0,执行3) P2(1,5) P3(3,2) P4(9,2)。SJF：t=0 只有 P1，跑到 t=3；t=3 时 P2（剩 5）和 P3（刚到，2）都就绪，选最短的 P3：3–5，完成 5，响应 5−3=2；然后 P2：5–10，完成 10，响应 10−1=9；t=10 P4（t=9 到）：10–12，完成 12，响应 3。P1 完成 3，响应 3。平均 (3+9+2+3)/4 = 17/4 = 4.25。原表把 SJF 填成了与 FCFS 相同的结果（P2 先于 P3），不符合 SJF 定义。该结果与同页 SRTF 一致（t=9 时 P4 到达，P2 只剩 1，SRTF 不会抢占，所以 SJF=SRTF） |
| 48 | Banker's 答案，"Available" 表 T2 行 | `1 0 1 3` → `1 1 1 3` | Available 初始 (0,0,0,2)；T3 需求 0 先完成：+Alloc T3 (0,1,0,1) → (0,1,0,3)；T2 需求 (0,1,0,0) ≤ 可用，完成后 +Alloc T2 (1,0,1,0) → (1,1,1,3)；T1 完成后 +(0,0,1,0) → (1,1,2,3) = Total。原表 T2 行 R2 写成 0，与 T1 行和 Total 都对不上 |
| 50 | Evening exam：第一张 "Available after completion" 表 + 说明文字 | 行序 `T3,T2,T1` (0 1 0 3 / 1 1 1 3 / 1 1 2 3) → `T2,T1,T3` (1 0 1 3 / 1 0 2 3 / 1 1 2 3)；文字 `Safe sequence T3, T2, T1 or T2, T3, T1` → `Safe sequence T2, T1, T3 or T2, T3, T1` | Available=(0,0,0,3)；Need：T1 (1,0,0,0)，T2 (0,0,0,0)，T3 (0,0,1,0)。T3 需要 R3=1，而可用 R3=0，所以 T3 不能第一个跑；T2 需求为 0，先跑 → (1,0,1,3)；之后 T1 (需求 1,0,0,0) 可跑 → (1,0,2,3)，再 T3 (0,0,1,0) → (1,1,2,3)；或先 T3 → (1,1,1,3) 再 T1 → (1,1,2,3)。原来的第一张表是 T3 先跑，是错的（从早场题抄来未改）；第二张表 (T2,T3,T1) 本来就是对的，未动 |
| 52 | 3 位律师、3 刀 2 叉；死锁状态下的 Total | `4 2` → `3 2` | 本题 Total 是 (3,2)（左侧初始状态也是 3 2，Available 3 2）；状态为每人拿 1 把刀：Alloc (1,0)×3，Need (1,2)×3，Available = (3,2)−(3,0) = (0,2)，与表一致，只有 Total 错写成 4 2 |
| 52 | "Available resources after completion" 表 Init 行 | `0 0` → `0 2` | 死锁状态的 Available = (0,2)（见上），不是 (0,0) |
| 52 | 状态说明文字 | `P1 grabs 2 knives and 1 fork; P2 grabs 2 knives and 1 fork.` → `P1, P2 and P3 each grab 1 knife.` | 原文是 s53（4 刀）的说明，抄过来未改；与 s52 的 Alloc 表（每人 1 把刀）矛盾 |
| 57 | 2 位律师、3 刀 2 叉：Need 表 P1 行 | `1 2` → `0 2` | Max (2,2) − Alloc (2,0) = (0,2)。验证：Available (0,2)；P1 需求 (0,2) 可跑 → (2,2)；P2 需求 (1,2) 可跑 → (3,2)，与右侧 "Init 0 2 / P1 2 2 / P2 3 2" 完全一致，所以原 `1 2` 是笔误 |
| 58 | 状态说明 | `P1 grabs 1 knife; P2 grabs 1 knife.` → `P1 grabs 2 knives and 1 fork; P2 grabs 2 knives and 1 fork.` | Alloc 表是 (2,1),(2,1)，Available = (4,2)−(4,2) = (0,0)，每人 2 刀 1 叉，说明文字抄自 s56 |
| 59 | 状态说明 | `P1 grabs 1 knife; P2 grabs 1 knife.` → `P1 grabs 2 knives and 2 forks; P2 grabs 2 knives and 1 fork.` | Alloc 表是 (2,2),(2,1)，与文字不符 |
| 59 | Need 表 P1 行 | `0 1` → `0 0` | Max (2,2) − Alloc (2,2) = (0,0) |
| 59 | 结论文字 | `Current state is deadlocked on forks.` → `Current state is safe: P1 can finish first, so it is not possible for deadlock.` | Total (4,3)，Available = (4,3)−(4,3) = (0,0)；P1 需求 (0,0) 可立即完成 → (2,2)；P2 需求 (0,1) 可完成 → (4,3)，与右侧 "Init 0 0 / P1 2 2 / P2 4 3" 一致，是安全状态，不是死锁。与 s55 的 "4 knives and 3 forks (No deadlock)" 也一致 |
| 63 | Wait() IV 的约束说明（3 条） | 原：`Each "Parent X" and "Child X" message pair appears before the corresponding "Parent again X" message, i.e.,` / `“Hello from Parent 0”, “Hello from Child 0” must appear before “Hello from Parent again 0”` / `“Hello from Parent 1”, “Hello from Child 1” must appear before “Hello from Parent again 1”`<br>新：`The parent prints in program order (Parent 0, Parent again 0, Parent 1, Parent again 1). wait(NULL) reaps any one child, so:` / `“Hello from Parent again 0” must appear after at least one of “Hello from Child 0” and “Hello from Child 1”` / `“Hello from Parent again 1” must appear after both “Hello from Child 0” and “Hello from Child 1”` | 程序：父进程先把两个子进程都 fork 出来（循环里 `continue`），再在第二个循环里依次 `Parent i` → `wait(NULL)` → `Parent again i`。`wait(NULL)` 等待的是任意一个子进程，不一定是第 i 个：例如 Child 1 先输出并退出，则 `Parent 0`、`Parent again 0` 可以在 `Child 0` 之前出现，所以原约束 "Child 0 必须在 Parent again 0 之前" 不成立；第二次 wait 返回时两个子进程都已结束，所以两条 Child 都在 Parent again 1 之前。此外 `Parent 0 < Parent again 0 < Parent 1 < Parent again 1` 是父进程自身的顺序，原文没有写。"Parent exiting" 最后输出这条原文已写对。**这是改动较大的一处答案修正，请你确认措辞** |
| 74 | Quiz: Fork 说明 | `Updates to global variable x` → `Updates to variable x` | 代码里 `int x = 1;` 在 `main` 内部，是局部变量，不是全局变量；输出 Parent x=0（`--x`）、Child x=2（`++x`）正确 |

### 代码/引号/拼写

| # | 位置 | 修改前 → 修改后 | 理由 |
|---|------|----------------|------|
| 2 | Q. Fork 答案 3 | `the same ”file”.` → `the same “file”.` | 开引号用成了闭引号 |
| 4 | Q. Fork 代码框 | 原：第 12 行 `}`（自动编号）之后直接是 `12 return 0;`、`13 }` → 新：插入一行 `13 }`，并改为 `14 return 0;`、`15 }` | 代码括号不平衡：`for {` 没有闭合的 `}`，并且 `return 0;` 与上一行的 `}` 编号都是 12（前 6 段是手打行号，7–12 是自动编号，最后两行手打）。`if (i == 3) {` 的 `}` 是 12，补上 for 的 `}` 为 13，`return 0;` 为 14，`main` 的 `}` 为 15 |
| 10 | Q. Paging 第 2 题 | `a combination of the of disk space` → `a combination of the disk space` | 重复 "of" |
| 16 | LRU 答案页下方两个游离文本框 | `FIFO: 6 page faults` → `FIFO: 12 page faults`；`OPT: 4 page faults` → `OPT: 8 page faults` | 重新模拟：序列 7 0 1 2 0 3 0 4 2 3 0 3 1 2 0、3 个帧：FIFO 12 次、LRU 12 次、OPT 8 次。OPT 逐步：7,0,1 缺页；2 缺页换 7；3 缺页换 1；4 缺页换 0；0 缺页换 4；1 缺页换 3，共 8。两张表（FIFO、LRU）本身逐格核对正确，没动。**该页没有 OPT 表**，只有一个标签 |
| 35 | Fork 题代码 | `print (“A”);` / `print (“B”);` / `print (“C”);` → `printf("A");` / `printf("B");` / `printf("C");` | `print` 不是 C 函数（s64 的同一题用 printf）；代码里不应用弯引号 |
| 63 | Wait() IV 代码 | `continue();` → `continue;` | `continue` 是语句，不是函数，原写法无法编译（该页备注里的 Perplexity 回答也指出了这点） |
| 64, 65, 66 | 代码框 | `printf(“A”)` 等的弯引号 → 直引号 `printf("A")` 等 | 代码里的弯引号 |
| 73 | Quiz: Fork 代码 | `if(pid1=fork()>0&&pid2=fork()>0)` → `if((pid1=fork())>0&&(pid2=fork())>0)` | `=` 优先级低于 `>` 和 `&&`，原写法被解析为 `pid1 = (fork()>0 && pid2) = ...`，无法编译；幻灯片的解释和进程树（共 4 个进程 P0–P3）都是按加括号的写法分析的 |

### 缺失标题 / 标题溢出

| # | 位置 | 修改 | 理由 |
|---|------|------|------|
| 8 | 标题为空 | 新增标题 `Q. Paging ANS` | 空标题占位符；风格对应其他答案页 "… ANS" |
| 9 | 标题为空 | 新增标题 `Q. Paging ANS: TLB and Page Table at the End` | 同上；该页只有最终页表和 TLB |
| 6 | 标题 `Q. Dining Lawyers Solution: 3 Lawyers, each with 1,2,3 arms, 3 forks` | 字号 28 → 24 pt，位置改为与大多数页相同（x=448883, y=182430, 宽 11336392, 高 532956 EMU） | 原标题框 y = −0.27 in（超出幻灯片顶端），两行文字被上边缘裁切并压在母版横线上 |
| 52, 53, 54, 56, 57, 58, 59 | `Quiz 2: Dining Lawyers Solution: …` | 字号 32（部分 run 继承）→ 20 pt，位置同上 | 同样 y = −0.22 in，标题两行被裁切并压线。s55 的标题正常，未改 |
| 64, 65, 66 | `Q2 d) (5 pts) Modify it to distinguish between parent and child` | 字号 32（继承）→ 28 pt，位置不变 | 标题折成两行并压在内容上（第二行 "child" 压到正文）。以上字号改动属于版式修补，其他页的标题仍是 32 pt，如不喜欢可以改回来 |

### 重新计算过、结果正确（未改动）
- s2：a=1，父子各自 `a++` → 2；地址相同（虚拟地址），文件描述符被复制 → 3 个答案正确。
- s3、s4：s3 的程序打印 0–3 后 exec；s4 父进程打印 0–9，子进程 exec ls。正确。
- s6：1/2/3 只手的律师、3 把叉。P2 拿 1、P3 拿 2：Alloc (0,1,2)，Need (1,1,1)，Available 0 → 死锁，表格一致。
- s7–s8：页表中 VPN 1,5,6 有效；s8 表里 TLB 命中/未命中、缺页逐行与我的模拟一致（见 s9）。
- s10：256 KB/4 KB = 64 页 → 64 个 TLB 项；4 × 256 KB = 1 MB 物理内存阈值。正确。
- s16：FIFO、LRU 两张表按 3 帧模拟逐格一致（FIFO 12 次，LRU 12 次）。
- s21：L0 L1 Bye Bye Bye L2 不可能（L2 之后子进程 2 还要输出 Bye，所以 L2 不可能最后），L0 Bye L1 L2 Bye Bye 可能，答案 B（No / Yes）正确。
- s28、s29（PCP Example II，图片数据）：s2 的上限 4、s3 的上限 2、s5 的上限 6；对 D（优先级 4），低优先级任务 E,F,G,H 持有的 s2 (H, 13)、s3 (E, 4) 的上限 ≥ 优先级 D，s5 的上限 6 不满足；B_D = max(13,4) = 13。R_D = 20 + 13 + ⌈R/250⌉·14 + ⌈R/500⌉·50 + ⌈R/800⌉·90，R=187 时 = 33+14+50+90 = 187，正确。
- s31 选择题：C（等待 I/O 不进入 ready）、D（FIFO 与 RR 无饥饿）正确。
- s36：ABBCC、ABCBC 两种输出正确（见 s64 同题）。
- s37–s40 / s42 其余各项（FCFS/SRTF/RR）逐行重算：第一组 P1(0,2) P2(1,6) P3(4,1) P4(7,4) P5(8,3)：FCFS 平均 28/5=5.6，SJF 27/5=5.4（P1,P2,P3,P5,P4），SRTF 24/5=4.8，RR(q=1) 32/5=6.4，Gantt 行全部一致；第二组 FCFS 20/4=5，SRTF 17/4=4.25（P1,P3,P2,P4），RR 23/4=5.75，Gantt 行一致。本课程把 response time 定义为 finish − arrival，所以此处 "Avg RT" 与 "Average Turnaround" 同义。
- s47–s49：s47 的 Need = Max − Alloc 正确，Available (0,0,0,2)；s48 T3→T2→T1 的 Available 序列修正后正确（见上）；s49 死锁（Available (0,0,0,3)，Need T1 1000 T2 0100 T3 0010，无进程可跑）正确。
- s51、s55 的 4 种情况结论（死锁/不死锁）：s51 的 3 位律师：3 刀 2 叉 → 刀死锁；4 刀 2 叉 → 叉死锁（最多 2 人拿到刀，各拿 1 叉）；4 刀 3 叉 → 无死锁。s55 的 2 位律师：2 刀 2 叉 → 刀死锁；3 刀 2 叉 → 无；4 刀 2 叉 → 叉死锁；4 刀 3 叉 → 无。正确。
- s53：4 刀 2 叉，每人 2 刀 1 叉 → Available (0,0)，Need (0,1),(0,1),(2,2)，叉死锁，正确。s56：2 刀 2 叉，每人 1 刀，Available (0,2)，正确。
- s61：父子输出的交错数 2×2=4，正确；s64–66：s64 输出 {ABBCC, ABCBC} 正确；s65 有 wait 的 3 种输出 (Parent B, Child B, C 的交错，父进程的 C 最后)；s66 无 wait 的 4 种不同输出（6 种交错，因两个 "C" 相同去重后 4 种），正确。
- s69/s70：mutex 的信号量初值 1；5 位律师每人 2 根筷子至少需要 5×(2−1)+1 = 6 根，正确。
- s71–72：三个陈述 T/T/F → 选项 4（TTF），正确。
- s73：4 个进程（P0 创建 P1、P2、P3），解释正确（代码修正见上）。

## 二、已发现但未修改 / 需要你确认

1. **空白幻灯片**：s11、s12、s13、s14、s34、s45 只有母版横线，没有标题和内容（s11–14 夹在 s10 与 s15 之间，像是图片丢失）。没有删除。
2. **s7 题干自相矛盾**："12-bit virtual address space" 但 "8 KB of virtual memory"、页表有 8 项（8 页需要 13 位）。解答（s8）按 12 位、VPN = 高 2 位（0–3），页表后 4 项实际用不到。建议去掉 "12-bit" 或把虚拟内存改为 4 KB。
3. **s9 页表无标题的页**（已加标题）；s8/s9 没有明确给出 "TLB 命中 5 次、缺页 3 次" 的文字结论，建议补一行。
4. **s10**：备注里是残缺片段 "a Resident // Set Size (RSS) of 512MB and a"（未动）；正文字号很小。
5. **s15**：答案表是空的（"ANS:" 后面一张空表），s16 是答案。**s17**（图片，YouTube 来源）里的序列是 `7 0 1 2 0 3 0 4 2 3 0 3 2 1 2`，与 s15 题目序列 `… 3, 1, 2, 0` 末尾不同，图里的缺页 F 标记也属于另一序列；若用作答案请注意不一致。
6. **s26/s27（PCP 与共享资源）**：
   - s26 的任务表有 D 列（A: D=50，B: D=100，C: D=300），s27 答案表写 "T=D"（100/200/300）。**两者矛盾**：若 D_A = 50，则 R_A = C_A + B_A = 25 + 30 = 55 > 50，**任务集在 PCP 下不可调度**；若 T=D，则 55 ≤ 100 可调度。答案页写的是 "schedulable"，对应 T=D。请确认哪一个是原意。
   - 命名：s26 用 A/B/C，s27 和备注用 1/2/3。
   - s27 的答案不完整：只写了 PCP（case b）；题目要的 case (a)（无 PIP/PCP）没有答案，B 和 R 两列是空的。若 T=D，我算得 PCP 下：B_1 = 30（任务 3 的临界区 30 ≥ 3），R_1 = 25+30 = 55 ≤ 100；B_2 = 30，R_2 = 50+30+⌈R/100⌉·25：R=105 → ⌈1.05⌉=2 → 130 → ⌈1.3⌉=2 → 130 ≤ 200；B_3 = 0，R_3：100+⌈R/100⌉·25+⌈R/200⌉·50，R=175 → 200 → 200 ≤ 300。三个任务均可调度。
   - s27 中 "utilization bound for 2 tasks" 对任务 1 不合适（任务 1 对应 1 个任务的界 1.0）；0.55 ≤ 0.828 不等式成立，所以结论不变，只是标注不严谨。
   - s26 备注被截断（"use utilization bound and/or Response Time Analysis (RTA) to"）。
7. **s30 "Exam TODO"**：遗留的待办笔记，"…single threaded program.2." 末尾有游离的 "2."。建议删除该页。
8. **s32、s43、s44、s67–s70 全部是图片**（s32 是一个学生提问的聊天截图，带 "Prof. Zonghua Gu … you may try alpha 0.1 or 0.9"；s43 是另一份试卷的扫描；s67–s70 来自视频/他人的习题）。我没有逐一核对图片里的答案；请确认来源标注和截图中的学生信息是否需要匿名。
9. **s46**：文字 "Deadlock (cycle R3->T2->R2->T3 / And cycle R3->T1->R1->T2->R2->T3" 没有回到 R3 形成闭环（应为 `…->T3->R3`），我没有看清图里的边是否一定如此，未改。
10. **s48**：文字 "Safe Sequence: T3, T2, T1" 右半被右边的资源分配图遮住（渲染效果）。
11. **s50 标题** "(1) Deadlock Evening Exam"：内容是有安全序列（不死锁），而 s49 是 "Deadlock"，标题易误导，建议改为 "(1) No Deadlock ANS Evening Exam"（未改，因为命名由你决定）。
12. **s51**：第 3 项和第 4 项完全相同（"4 knives and 3 forks (No deadlock)"），疑似其中一项应该是别的数值（例如 6 刀 3 叉 → 每人 2 刀，3 叉各 1 叉 → 叉死锁）。备注里仍是 "3 knives, all 3 lawyers blocked on knives…" 的旧稿；s55 的备注是 s51 的复制（还写着 "3 lawyers"）。
13. **s54**："Available resources after completion" 表是残留：Init `4 2`、P1 `1`、P2 空；对应状态（Alloc P1 (2,1)，P2 (2,2)，P3 (0,0)，Available (0,0)）正确的序列应为 Init (0,0) → P2 (2,2) → P1 (4,3) → P3 (4,3)，而且表只有两个进程行。因为不确定你想放哪些内容，没改。
14. **s57**：说明 "P1 grabs 2 knives and then 2 forks; P2 grabs 1 knife" 描述的是一个运行过程，但表里的状态是 P1 只拿了 2 刀（Alloc (2,0)，Available (0,2)）。未改。
15. **s63、s64–66 备注**：s63 备注是整段 Perplexity 回答（含 `c`、`text` 代码块标签、"Answer from Perplexity: pplx.ai/share"），s64–s66 备注末尾粘贴了与本题无关的 `fork(); fork(); fork(); printf("hello")` 程序；s74 备注是另一道 fork 题，且 "2n"、"23 = 8" 丢了上标（应为 2^n、2^3）。都不是乱码所以没有替换。
16. **s65/s66**：答案正文第 2 个大块（"Parent prints A … ABBCC and ABCBC"）是从 s64 原样复制，没有按 "Parent A / Child B" 的新输出改写；s66 没有 wait()，但文字仍写 "then waits for child to finish"。**s64** 的标题 "Q2 d) … Modify it to distinguish between parent and child" 与内容（输出 ABBCC/ABCBC）可能是沿用上一小问的标题，请确认。
17. **s61**："Output: 4 possible outputs" 之后的 1)–4) 其实是输出的 4 个步骤，不是 4 种输出（4 种输出来自两对输出各 2 种交错）；容易混淆。
18. **s73、s74 版式**：这两页的内容整体偏向左上角、缩小，标题被正文压住或挤到一旁（s73 的 "Q:" 文本框盖在标题上），像是从另一尺寸的幻灯片粘贴的。涉及二十多个形状的重排，没有动。s73 的程序里没有 `printf("Hello")`，题干却问 "How many Hellos are printed"；也没有变量声明。
19. **s18–s25**（CS61C/CALL 的幻灯片）：每页都有一个写死数字的 slide number 占位符，与页脚页码重叠，渲染出现 "18 18" 这样的重复页码（s2–s17 没有）。这些页、s71–s72 的 Quiz V 以及 "This is the loading part of CALL!"（CALL = CS61C 的 Compile/Assemble/Link/Load 课程术语）明显取自 UC Berkeley CS61C，**没有任何出处/致谢**；s15 的 YouTube 链接、s68–s70 备注里的视频链接有链接但没有署名。
20. **s33**：说父进程不调用 wait 会 "resulting in zombie processes after the program finishes execution"；严格说，父进程结束后子进程会被 init 收养并回收，僵尸只存在于父进程仍在运行时。另外答案空白处没有答案。
21. **s60**：只有一张表格，没有题干文字。
22. **s37/38/41**：表头同时写 "Average Turnaround" 和 "Avg RT"，本课程里两者同义，但可能让学生困惑。
23. s4 的代码行号是手打文字 + 自动编号混用（7–12 自动编号，其他手打），以后改代码要手动维护。
24. 同目录的 `CSC112 Review Questions.pdf`（如存在）未改动。

## 三、观察 / 建议
- 答案和题目不同步的集中区域是 s50、s52–s59（Banker's / Dining Lawyers）：这些页是反复复制再改数值，改了表格但没改说明文字，建议你统一核对一次。
- 未发现遗留的课程代码（CSC256）或旧学期。
- 目录中的 `~$L3-Synchronization.pptx` 锁文件属于 L3 deck，与本 deck 无关；本 deck 在提交时没有对应锁文件。
