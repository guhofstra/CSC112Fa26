# L4-Exercises ANS.pptx 审查记录

- 原文件备份：`PPTs/bak/audit-20261007/L4-Exercises ANS.pptx`。
- 幻灯片数：22 张，修改前后不变；只改文字 run 与备注，没有增删、重排幻灯片。
- 检查：`validate.py --original` 通过；逐部件 XML 对比只有下列幻灯片与 4 页备注变化；改动页用 LibreOffice 渲染查看（slide 10 的标题保持原来的 top，仅改用 24pt 并与 slide 9 的左边距/宽度对齐，没有盖住 “Need” 标签）。
- 提交：已写回原路径，重新用 python-pptx 打开确认能加载、页数 22。该课件旁没有 `~$` 锁文件。
- 与 L4-Exercises 对照：两份文件的题目逐页一一对应（ANS 版第 3-21 页对应 Exercises 第 3-11 页），题面已对齐（见 L4-Exercises 日志）。

## 已修改

| 页 | 修改前 → 修改后 | 原因 |
|---|---|---|
| 2 | 等待链 “thread 1 waiting for L2 (held by thr. 3) → thr. 2 waiting for L1 (held by thr. 1) → thr. 3 waiting for L3 (held by thr. 2).” → “thread 1 waiting for L2 (held by thr. 3) → thr. 3 waiting for L3 (held by thr. 2) → thr. 2 waiting for L1 (held by thr. 1).” | 链的顺序不衔接：thr. 1 等的 L2 被 thr. 3 持有，所以下一环应当写 thr. 3（等 L3，被 thr. 2 持有），再接 thr. 2（等 L1，被 thr. 1 持有）才闭合；原文第二环写成 thr. 2，不是 “held by thr. 3” 所指的线程 |
| 3, 4 | “Banker’s Algorithm I” → “Banker’s algorithm I”（两个标题） | 大小写统一 |
| 5 | “4 processes P1, P2, P3” → “3 processes P1, P2, P3” | 只有 3 个进程 |
| 6 | “P2, P2, P1” → “P3, P2, P1”（Or 之后的第二个安全序列） | 笔误；表格里 Or 的右边是 P3 → P2 → P1 |
| 8 | “safe sequences of P2, P2, P1” → “P2, P3, P1 or P3, P2, P1” | 同上，序列写错 |
| 9, 11 | “Banker’s Algorithm: ...” → “Banker’s algorithm: ...”（slide 9, 10 的副标题含 ANS，slide 11） | 大小写统一 |
| 9 | “right fork R(i+1)%5” → “R(i%5+1)” | 编号 1-5 时 P5 的右叉子应是 R1 |
| 12 | “>=” → “≥”；“CS162” → “CS 162”；备注 “Bankers algorithm” → “Banker’s algorithm” | 符号、课程名、笔误 |
| 13 | “Q2: ... Check it using Banker’s algorithm. Check it using Banker’s algorithm.” → 删除重复的一句 | 重复 |
| 14 | “Q1: Two lawyers each grab two chopsticks and start eating. ” → 加上 “One lawyer grabs one chopstick.” | 与第 13 页的 Q1 一致，并且与本页 Allocation [2,2,1,0,0] 对应 |
| 17 | 图中标签：“Resource 2 (a knife) held by Thread 2” → “held by P1”；“Resource 1 (a fork) requested by Thread 2” → “requested by P1”；“Resource 2 (a knife) requested by Thread 2” → “requested by P2”；“Resource 1 (a fork) held by Thread 2” → “held by P2” | 图里的节点是 P1、P2，标签却写 Thread 2，并且 “held by” 与 “requested by” 的主体互相矛盾，不能构成环 |
| 19, 21 | 同上，分别对应 “(2 forks / 2 knives)” 和 “(a knife)” 两张图的 4 个标签 | 同上 |
| 21 | “If a thread holds  certain resources” → 去掉双空格 | 双空格 |
| 10 备注 | 原备注只有一条 Berkeley 链接与一句题面 → 改为验证说明：“Check: Available A = [0 0 0 0 1]. Only P4 can run ... P4, P3, P2, P1, P5 is the only safe sequence.” | 原备注重复了第 12 页的备注，与本页（哲学家）无关 |
| 17 备注 | 原：“there is only deadlock when you hold a fork and waits for a fork. No deadlock if you hold a fork and waits for a knife as no cycle is formed.” → 改为按“先刀后叉”顺序解释为什么不会形成环 | 原备注的前提与本题不符（本题的律师先拿刀，不会持有叉去等叉），并且有语法错误 |
| 19 备注 | 原：“A” → 改为：先原子拿 2 把刀、再原子拿 2 把叉，等刀的人什么都不持有，等叉的人只持有刀，持有叉的人已在吃，因此无环 | 备注是个孤零零的 “A” |

### 逐题验算（我重新解了每一题）

- **第 2 页**：线程 1 持有 L1 等 L2，线程 2 持有 L3 等 L1，线程 3 持有 L2 等 L3：1→3→2→1 成环，是死锁；统一加锁顺序 L1, L2, L3 可以消除环（线程 2 改为先 L1 后 L3，线程 3 改为先 L2 后 L3）。ANS 结论正确。
- **第 4 页（Banker’s I）**：E = [7 3 6]；Allocation 列和 = [0+2+3+2+0, 1+0+0+1+0, 0+0+2+1+2] = [7 2 5]；A = E − 列和 = [0 1 1]。Need：P1 [7 4 3]，P2 [1 2 2]，P3 [6 0 0]，P4 [0 1 1]，P5 [4 3 1]（与图中矩阵相同）。只有 P4 的 Need ≤ A，运行后 A = [0 1 1] + [2 1 1] = [2 2 2]；P2 的 [1 2 2] ≤ [2 2 2]，运行后 A = [2 2 2] + [2 0 0] = [4 2 2]；剩下 P1 [7 4 3]、P3 [6 0 0]、P5 [4 3 1]（R2：3 > 2）都不行 → 不安全，与 ANS 表一致。
- **第 6 页**：Allocation 列和 [5 4 2]，E = [8 6 4]，A = [3 2 2]。Need：P1 [8 4 2]，P2 [3 0 0]，P3 [1 1 2]。P1 不可先行（8 > 3）。P2 先：A = [3 2 2] + [3 2 0] = [6 4 2]；P3：+ [2 2 1] = [8 6 3]；P1：+ [0 0 1] = [8 6 4]。P3 先：A = [3 2 2] + [2 2 1] = [5 4 3]；P2：+ [3 2 0] = [8 6 3]；P1 同上。两个序列都安全，ANS 表一致。
- **第 7 页**：P1 要 2 个 R3：Need1(R3) = 2 ≥ 2，A(R3) = 2 ≥ 2，请求合法。假设分配后 A = [3 2 0]，P1 的 Need = [8 4 0]。P2 [3 0 0] ≤ A，运行 → A = [3 2 0] + [3 2 0] = [6 4 0]；P1 [8 4 0] 需 R1 = 8 > 6，P3 [1 1 2] 需 R3 = 2 > 0 → 死锁，拒绝。ANS 表一致。
- **第 8 页**：P2 要 2 个 R1：Need2(R1) = 3 ≥ 2，A(R1) = 3 ≥ 2。假设分配后 A = [1 2 2]，P2 的 Need = [1 0 0]。P2 先：A = [1 2 2] + [5 2 0] = [6 4 2]；P3 [1 1 2] → + [2 2 1] = [8 6 3]；P1 [8 4 2] → + [0 0 1] = [8 6 4]。或 P3 先：[1 2 2] + [2 2 1] = [3 4 3]，再 P2 → [8 6 3]，再 P1。安全，批准。ANS 表一致。
- **第 10 页**：P1-P4 各持左叉 R1-R4，A = [0 0 0 0 1]。Need：P1 [R2]，P2 [R3]，P3 [R4]，P4 [R5]，P5 [R5, R1]。只有 P4 可运行 → 释放 R4 → P3 → 释放 R3 → P2 → 释放 R2 → P1 → 释放 R1 → P5。每一步只有一个进程能运行，所以唯一安全序列是 P4, P3, P2, P1, P5，ANS 表正确（Available 表：[0 0 0 0 1] → [0 0 0 1 1] → [0 0 1 1 1] → [0 1 1 1 1] → [1 1 1 1 1] → [1 1 1 1 1]）。
- **第 11 页**：5 个哲学家各持左叉，A = [0 0 0 0 0]，每个人 Need 都非零 → 死锁，不安全。
- **第 13-15 页**：5 个律师、5 根筷子，每人最多要 2 根。Q1：Allocation [2,2,1,0,0]，A = 0；P1、P2 的 Need = 0，P1 完成后 A = 2，P2 后 4，P3（Need 1）后 5 ……安全，表中 0, 2, 4, 5, 5, 5 正确。Q2：每人 1 根，A = 0，每人 Need = 1 → 死锁。Q0（会不会死锁）幻灯片上没有写答案；按 Q2 的状态，答案应是“会”。
- **第 17、19 页**：先刀后叉（19 题为先原子取 2 刀再原子取 2 叉）的统一顺序，不会形成环，无死锁。
- **第 21、22 页**：Q1 的答案“会死锁”成立：2 个律师、2 把刀 2 把叉，每个人先拿 1 把刀，A = [K 0, F 2]，每人还需要 1 把刀，无人能前进，死锁；第 21 页备注给出了 Q2 的处理思路。

## 已发现但未修改 / 需要你确认

1. 第 4、6、7、8、10、11、14、15、22 页的 Max / Allocation / Need / Total 矩阵是嵌入的 OLE 图片，无法在文件里编辑；我按图中数值（读取渲染图）重算过，与答案表一致。
2. 第 10 页和第 11 页的哲学家 Need 矩阵、Max 矩阵分别是单独的文本框，每个单元格一个数字（TextBox 23…55 等）；我核对了数值但没有改动。
3. 第 14 页的 Allocation 为 [2,2,1,0,0]，题面已补上“One lawyer grabs one chopstick”，请确认你想要的就是这个状态。
4. 第 12 页备注：“Design a deadlock-free algorithm using monitors and Banker’s algorithm.” 只是 Berkeley 原题的说明，与幻灯片正文无直接对应，保留。

## 观察 / 建议

- 答案版 slide 17/19/21 的图中标签原来是 “Thread 2” 误写，改成 P1/P2 之后与图一致；如果以后改图，请保持这一点。
- 第 6、8 页的“Or”两条序列是并列的合法答案，建议在备注里写明“两种都对”，以免被当作评分标准。
- Q0（第 13 页）没有对应答案，建议在第 14 或 15 页补一句“Q0 ANS: Yes, deadlock is possible (see Q2)”。
- 这个答案版的 slide 10 标题位置原来比 slide 9 略高（顶端与 “Need” 标签接近），我把字号改为 24pt、左右与 slide 9 对齐后没有盖住其它元素。
