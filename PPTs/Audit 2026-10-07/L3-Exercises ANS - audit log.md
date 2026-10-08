# L3-Exercises ANS.pptx 审阅与修改记录

审阅范围：全部 24 页（含备注、表格、分组形状）。每道题都独立重新求解，并用 Python 做了状态空间穷举（所有交错执行）来验证答案，同时与 `L3-Exercises.pptx` 逐页对照。页码为当前 1-based 位置，英文原文用引号标出。

修改方式：run 级文本修改，不增删或重排幻灯片，不改题意与分值，不换图。原件已备份在 `PPTs/bak/audit-20261007/`。共 27 处原子修改（合并后 26 个段落），涉及 16 页（第 3、5、7、8、9、10、11、12、13、14、15、17、20、21、23、24 页）。已通过 validate.py（--original）；lxml 逐部件比较确认只有这些幻灯片及第 7、8 页备注发生变化，页数仍为 24。重新渲染了第 3、5、11、13、15、17、21、23、24 页确认正文没有溢出；第 13 页标题折行已通过缩短标题解决，第 15 页标题仍会折行（原件同样，见下）。

## 已修改

### 答案错误（2 处，已确定）

1. 第 3 页（Concurrency I Answer）：原答案 "Possible values of x ... 5,…15. Min: 5. Max: 15." 错误，最小值是 3，不是 5。
   - 验证计算：T0 做 5 次 `x=x+1`，T1 做 5 次 `x=x+2`，每次迭代是 load、store 两步。对 2×10 步所有交错的状态空间做穷举，可达终值恰为 {3,4,5,…,15}（13 个值）；最大 15 = 5×1+5×2（无更新丢失）。
   - 最小值 3 的一个调度：T1 先 load x=0（第 1 次迭代）；T0 完整执行 4 次迭代（x=4）；T1 store 0+2=2（x=2）；T0 load x=2（第 5 次迭代）；T1 执行完剩下的 4 次迭代（x=2+8=10）；T0 store 2+1=3，终值 x=3。
   - 原解释 "Since there are 5 of each type ... x has min 5" 忽略了一次覆盖可以抹掉多次更新。已改写为 Max 与 Min 两部分，附上上述调度，并说明 "Exhaustive enumeration of all interleavings shows x can never end below 3, and every value 3, 4, 5,…15 is possible."。原文最后的例子 "three increments from Thread T0 and two increments from Thread T1 are applied, then x=(3×1)+(2×2)=7" 已删除（7 确实可达，但该例子没有给出具体调度，且依赖错误的 "min 5" 推理）。
   - 为了容纳更长的文字，把正文占位符的 autofit 设为 fontScale 92.5%、lnSpcReduction 20%（原来是 10%）；渲染确认没有溢出。
2. 第 15 页（Peterson 变体的答案）：原答案 "Mutual Exclusion: Achieved" 错误，该变体（每个线程把 turn 设为自己的编号）**不满足**互斥。
   - 验证计算（反例）：初始 flag=(F,F)，turn=0。T0：flag[0]=true；turn=0；检查 `flag[1]==true && turn==1` 为 false（flag[1] 仍为 false），进入临界区。T1：flag[1]=true；turn=1；检查 `flag[0]==true && turn==0`：flag[0]=true 但 turn=1，条件为 false，T1 也进入临界区。此时两个线程同时在临界区内。状态空间穷举同样找到该可达状态：flags=(T,T)，turn=1，两线程均在临界区。
   - 已改为 "Mutual Exclusion: Not satisfied. T0 sets flag[0]=true, turn=0, sees flag[1]==false and enters the CS; T1 then sets flag[1]=true, turn=1, its wait condition (flag[0]==true && turn==0) is false, so T1 also enters the CS while T0 is still inside."
   - "Major Flaw: ... leads to potential livelock or starvation." -> "Major Flaw: Incorrect handling of the turn variable breaks mutual exclusion and allows starvation."（该变体不会 livelock：T0 等待需要 turn==1，T1 等待需要 turn==0，不可能同时成立，因此 Progress "Achieved" 是对的；Bounded Waiting "Not satisfied" 也是对的，T1 可以在 T0 未被调度时反复进入）。
   - 标题 "(Peterson’s Solution Variation) Sample Execution & Answer" -> "(Peterson’s Solution Variation): Sample Execution & Answer"（加冒号，与第 11、13 页一致）。该页正文原本 autofit 为 55%，新增文字约 100 个字符，渲染后仍可容纳。

### 其他错误与笔误

- 第 5 页（Concurrency II Answer）："Other possible results include 100 + 10 = 10" -> "100 + 10 = 110"。验证：D 初值 100，三个线程各一次读-改-写，穷举得到终值 {50, 60, 70, 80, 110, 120, 130}，所以最小 50（T2 最后写回 100-50）、最大 130（无更新丢失）正确；"100 + 20 = 120"、"100 + 20 - 50 = 70" 都在集合内，110 也在（只有 T3 的更新保留）。标题前导空格 " Concurrency II Answer" 去掉。
- 第 7、10、12、14 页："one of more" -> "one or more"（4 页）；第 7、8 页备注里孤立的 "acd" 删除。
- 第 8 页："strict alternation order ." -> "strict alternation order."；第 9 页标题 "Mutual Exclusion I  Answer " 的双空格与尾部空格去掉。
- 第 11 页：`flag[0] = true;T1 sets` 缺空格 -> `flag[0] = true; T1 sets`。
- 第 13 页：
  - 标题 "Mutual Exclusion III (Peterson’s Solution): Sample Execution & Answer" 太长，折成两行并撞到标题横线（你的 PowerPoint 导出的 PDF 里同样如此），改为 "Mutual Exclusion III: Sample Execution & Answer"（与第 11 页同一模式，Peterson 在上一页已点明）。
  - 正文 "so no mutual exclusion is needed for flag variables" -> "so no atomic read-modify-write (TestAndSet) is needed for the flag variables"（概念错误：这里要说的是不需要原子指令）。
- 第 17 页：`consist` -> `consists`；"before execution instruction B of add. in t1" -> "before t1 executes instruction B of the addition"。
- 第 20 页：`printf(“7");` 弯引号 -> `printf("7");`。
- 第 21 页："The rest of the same as Solution 1" -> "The rest is the same as in Solution 1"。
- 第 23 页：`t2 grabs lock2 requests lock 1` -> `t2 grabs lock2 and requests lock1`；`requests lock 2` -> `requests lock2`。
- 第 24 页：标题答案 "x=3, y=3, z=3" -> "x=3, y=3, z=3 (z can also be 1 or 2, see below)"（下方 bullet 已经说明 z 的更新可能丢失）；"this exiting" -> "thus exiting"。

### 核对无误（未改动）

- 第 8、9 页 strict alternation：互斥成立；状态表 (F,F) -> (F,T) -> (T,T) -> (T,F) -> (F,F) 正确（T1 先、T0 后、再 T1、T0 轮流）。穷举：无互斥违例，无死锁。
- 第 10、11 页仅用 flag 的方案：互斥成立；死锁序列正确（T0 置 flag[0]=true，T1 置 flag[1]=true，之后两者都在 while 中自旋）。穷举：无互斥违例，存在死锁。
- 第 12、13 页 Peterson：互斥、无死锁、有界等待成立；第 13 页状态表逐行核对正确，包括 "T0 in CS (T1 cannot enter CS)"。
- 第 16-18 页 Race Conditions：x in {0,1,2,3}（t1 读到的 y in {0,1}、z in {0,2}）；加信号量 mutex 后 x in {0,3}，正确。
- 第 19 页 Semaphores I（wordle）：s1=1, s2=0，唯一输出 "wordle"，正确。
- 第 20、21 页 Semaphores II：两种解法都输出 2 3 5 7 11 13，解法 2 与解法 1 等价，正确。
- 第 22 页 Semaphores III：输出为 `((AB|BA)C)+`，正确；第 22 页新增的段落（调度器可能先运行任一线程）也正确。
- 第 23 页 Deadlocks I：两种场景都是真实死锁；"按相同顺序加锁可避免死锁" 正确。
- 第 24 页 Deadlocks II：死锁状态 x=2, y=1, z=2；正常结束 x=3, y=3，z in {1,2,3}，下方两个 lost-update 例子（z=1 与 z=2）都成立。

## 已发现但未修改 / 需要你确认

1. 第 9 页（strict alternation）：幻灯片写 "Progress (Deadlock-Free): Achieved"。按讲义（L3-Synchronization 第 6 页备注）里的 progress 定义，strict alternation 违反 progress（一个线程不再请求时另一个线程会被永久挡住），而同一页 "Major Flaw" 自己也这么说，两者矛盾；备注里写的是 "Not guaranteed"/"Not satisfied"，与幻灯片正文也不一致。如果 progress 只理解为"不死锁"，则 Achieved 成立。需要你决定采用哪个口径，我没有改。
2. 第 11 页："Bounded Waiting: Achieved" 对仅用 flag 的方案有争议（存在死锁状态，此时等待是无界的）。未改。
3. 第 4 页（Concurrency II 题目）的正文末尾是空的 "ANS: "，答案在第 5 页，属于有意的"题目页 + 答案页"结构，未改。
4. 第 13、15 页标题：第 15 页标题 "Mutual Exclusion III (Peterson’s Solution Variation): Sample Execution & Answer" 在 LibreOffice 渲染中折成两行并压住标题横线（原件同样如此），请在 PowerPoint 里确认实际效果；第 14 页标题在 LibreOffice 里也折行。未改版面。
5. 第 7、8 页备注里仍有题目原文（T1/T2、S1/S2 命名）和空的 "ANS:"，与页面上的 T0/T1、S0/S1 不一致；第 12、14 页备注里的 `int i=0, j=1;` 同样是旧残留。未改。
6. 本 deck 没有 Readers/Writers 的答案页（Exercises deck 第 9 页要求 "Rewrite it to prefer readers"）。
7. 第 20 页：题目预填了 `S1=0; S2=0; S3=0` 却又要求给出初始值；备注里提到的 "// SYNC" 标记页面上没有。
8. 标题页副标题为 "Lecture 3 / Synchronization"，没有 "Exercises ANS" 字样；元数据标题也过时。
9. 全 deck 没有发现 CSC256 等旧课程代码或旧年份。

## 观察 / 建议

- Peterson 算法在真实硬件上需要内存屏障（或顺序一致的原子操作），课件没有说明，可以在备注里加一句。
- 第 3 页的 "Min: 3" 是一个容易让学生意外的结论，建议课上用上面的调度逐步演示。
- 第 15 页的答案现在与 `L3-Exercises` 中第 8 页的题目一致；如果以前给学生讲过 "Peterson 变体满足互斥"，请更新课堂讲稿。

## 附录：完整修改记录（自动生成，按页码顺序；同一段落的多次修改已合并为 原文 -> 最终文本）

说明：where = 形状名称/段落序号（段落序号为修改前的编号），reason 为英文原始记录。

- 第 3 页 / Content Placeholder 2 p0
  - 修改前: `ANS: Possible values of x after the two threads have completed execution: 5,…15. Min: 5. Max: 15. `
  - 修改后: `ANS: Possible values of x after the two threads have completed execution: 3, 4, 5,…15. Min: 3. Max: 15. `
  - 理由: WRONG ANSWER: the minimum is 3, not 5 (verified by exhaustive enumeration of all interleavings of the load/store steps: the reachable final values are exactly 3..15). See log for the schedule.
- 第 3 页 / Content Placeholder 2 p1
  - 修改前: `The x=x+2 statements can be “erased” by “sneaking in between” the load and store of an x=x+1 statement, and vice versa. Each x=x+1 statement can either do nothing (if erased by Thread T1) or increase x by 1. Each x=x+2 statement can either do nothing (if erased by Thread T0) or increase x by 2. Since there are 5 of each type, and since x starts at 0, x has min 5 and max (5*1)+(5*2)=15. Possible values are 5, 6, 7,…15, e.g., If three increments from Thread T0 and two increments from Thread T1 are applied, then x=(3×1)+(2×2)=7.`
  - 修改后: `The x=x+2 statements can be “erased” by “sneaking in between” the load and store of an x=x+1 statement, and vice versa. Max: if no update is erased, x=(5×1)+(5×2)=15. Min: one erasure can wipe out many earlier updates, so the minimum is below 5. Schedule giving x=3: T1 loads x=0 (1st iteration); T0 runs 4 iterations (x=4); T1 stores 0+2=2; T0 loads x=2 (5th iteration); T1 runs its other 4 iterations (x=10); T0 stores 2+1=3. Exhaustive enumeration of all interleavings shows x can never end below 3, and every value 3, 4, 5,…15 is possible.`
  - 理由: WRONG ANSWER: 'Since there are 5 of each type ... x has min 5' ignores that an erased store can discard several earlier updates (min is 3). Also removed the unverified '3 increments + 2 increments = 7' example (7 is reachable, but not by 'applying' 3+2 increments in a controlled way)
- 第 3 页 / Content Placeholder bodyPr
  - 修改前: `normAutofit lnSpcReduction=10%`
  - 修改后: `normAutofit fontScale=92.5% lnSpcReduction=20%`
  - 理由: corrected answer text is longer; keep it inside the placeholder
- 第 5 页 / Title 1 p0
  - 修改前: ` Concurrency II Answer`
  - 修改后: `Concurrency II Answer`
  - 理由: leading space in title
- 第 5 页 / Content Placeholder 2 p1
  - 修改前: `Since each thread may read the value of int D, then write them in arbitrary order, overwriting each other’s updates. Other possible results include 100 + 10 = 10, 100 + 20 = 120, 100 + 20 – 50 = 70, and so on.`
  - 修改后: `Since each thread may read the value of int D, then write them in arbitrary order, overwriting each other’s updates. Other possible results include 100 + 10 = 110, 100 + 20 = 120, 100 + 20 – 50 = 70, and so on.`
  - 理由: typo/arithmetic: 100+10 = 110 (T3 alone, other updates lost)
- 第 7 页 / Content Placeholder 2 p0
  - 修改前: `Does it achieve one of more of the correctness properties of a concurrent program:`
  - 修改后: `Does it achieve one or more of the correctness properties of a concurrent program:`
  - 理由: typo
- 第 7 页 / notes p7
  - 修改前: `acd`
  - 修改后: `(paragraph deleted)`
  - 理由: stray leftover text 'acd' in notes
- 第 8 页 / Content Placeholder 2 p0
  - 修改前: `T0 and T1 take turns to enter the critical section in strict alternation order .`
  - 修改后: `T0 and T1 take turns to enter the critical section in strict alternation order.`
  - 理由: stray space before period
- 第 8 页 / notes p7
  - 修改前: `acd`
  - 修改后: `(paragraph deleted)`
  - 理由: stray leftover text 'acd' in notes
- 第 9 页 / Title 1 p0
  - 修改前: `Mutual Exclusion I  Answer `
  - 修改后: `Mutual Exclusion I Answer`
  - 理由: double space / trailing space in title
- 第 10 页 / Content Placeholder 2 p0
  - 修改前: `Does it achieve one of more of the correctness properties of a concurrent program:`
  - 修改后: `Does it achieve one or more of the correctness properties of a concurrent program:`
  - 理由: typo
- 第 11 页 / TextBox p2
  - 修改前: `Progress (Deadlock-Free): Not satisfied. If both threads set their flags simultaneously (T0 sets flag[0] = true;T1 sets flag[1] = true;), then both will spin-wait in while() loop, blocking each other indefinitely, resulting in deadlock.`
  - 修改后: `Progress (Deadlock-Free): Not satisfied. If both threads set their flags simultaneously (T0 sets flag[0] = true; T1 sets flag[1] = true;), then both will spin-wait in while() loop, blocking each other indefinitely, resulting in deadlock.`
  - 理由: missing space: 'flag[0] = true;T1 sets' -> 'flag[0] = true; T1 sets'
- 第 12 页 / Content Placeholder 2 p0
  - 修改前: `Does it achieve one of more of the correctness properties of a concurrent program:`
  - 修改后: `Does it achieve one or more of the correctness properties of a concurrent program:`
  - 理由: typo
- 第 13 页 / Title 1 p0
  - 修改前: `Mutual Exclusion III (Peterson’s Solution): Sample Execution & Answer`
  - 修改后: `Mutual Exclusion III: Sample Execution & Answer`
  - 理由: title wrapped onto two lines and ran into the title rule / slide top (also in the PowerPoint-exported PDF); shortened to the same pattern as slide 11 (Peterson is named on the previous slide)
- 第 13 页 / Content Placeholder 2 p2
  - 修改前: `TestAndSet Instruction: Not required. T0 reads flag[1] and updates flag[0]; T1 reads flag[0] and updates flag[1]; They do not update the same flag variable, so no mutual exclusion is needed for flag variables. Both threads read and write the turn variable, but it is write followed by read, so no race condition, unlike previous slide with race due to read followed by write to flag variable.`
  - 修改后: `TestAndSet Instruction: Not required. T0 reads flag[1] and updates flag[0]; T1 reads flag[0] and updates flag[1]; They do not update the same flag variable, so no atomic read-modify-write (TestAndSet) is needed for the flag variables. Both threads read and write the turn variable, but it is write followed by read, so no race condition, unlike previous slide with race due to read followed by write to flag variable.`
  - 理由: 'no mutual exclusion is needed' is the wrong concept here (the point is that no atomic instruction is needed)
- 第 14 页 / Content Placeholder 2 p0
  - 修改前: `Does it achieve one of more of the correctness properties of a concurrent program:`
  - 修改后: `Does it achieve one or more of the correctness properties of a concurrent program:`
  - 理由: typo
- 第 15 页 / Title 1 p0
  - 修改前: `Mutual Exclusion III (Peterson’s Solution Variation) Sample Execution & Answer`
  - 修改后: `Mutual Exclusion III (Peterson’s Solution Variation): Sample Execution & Answer`
  - 理由: colon, consistent with S11/S13 titles
- 第 15 页 / Content Placeholder 2 p2
  - 修改前: `Mutual Exclusion: Achieved. Only one thread can enter its critical section at a time due to the conditions on flag and turn.`
  - 修改后: `Mutual Exclusion: Not satisfied. T0 sets flag[0]=true, turn=0, sees flag[1]==false and enters the CS; T1 then sets flag[1]=true, turn=1, its wait condition (flag[0]==true && turn==0) is false, so T1 also enters the CS while T0 is still inside.`
  - 理由: WRONG ANSWER: with turn = (own index) neither thread yields, so mutual exclusion is violated. Counterexample found by exhaustive state-space search: flags (T,T), turn=1, both threads in the CS
- 第 15 页 / Content Placeholder 2 p10
  - 修改前: `Major Flaw: Incorrect handling of the turn variable leads to potential livelock or starvation.`
  - 修改后: `Major Flaw: Incorrect handling of the turn variable breaks mutual exclusion and allows starvation.`
  - 理由: livelock is not possible here (see log); the real flaws are the mutual-exclusion violation and starvation
- 第 17 页 / object 3 p0
  - 修改前: `Addition operation x=y+z consist of multiple machine instructions in assembly language:`
  - 修改后: `Addition operation x=y+z consists of multiple machine instructions in assembly language:`
  - 理由: subject-verb agreement
- 第 17 页 / object 3 p7
  - 修改前: `z is read as 2 (t2 sets z before execution instruction B of add. in t1)`
  - 修改后: `z is read as 2 (t2 sets z before t1 executes instruction B of the addition)`
  - 理由: garbled wording
- 第 20 页 / object 4 p11
  - 修改前: `printf(“7"); `
  - 修改后: `printf("7"); `
  - 理由: curly opening quote in printf code
- 第 21 页 / Content Placeholder 2 p1
  - 修改前: `Solution 2 (right): S2 has initial value 1, so f2 calls S2.wait() and runs first. The rest of the same as Solution 1. You can see that initializing S2=0 has the same effect as initializing S2=1 and let f2 call S2.wait() first. So Solution 1 is better with one less call to wait().`
  - 修改后: `Solution 2 (right): S2 has initial value 1, so f2 calls S2.wait() and runs first. The rest is the same as in Solution 1. You can see that initializing S2=0 has the same effect as initializing S2=1 and let f2 call S2.wait() first. So Solution 1 is better with one less call to wait().`
  - 理由: grammar
- 第 23 页 / TextBox 49 p0
  - 修改前: `Thread t1 grabs lock1 and requests lock 2; t2 grabs lock2 requests lock 1`
  - 修改后: `Thread t1 grabs lock1 and requests lock2; t2 grabs lock2 and requests lock1`
  - 理由: missing 'and'; consistent lock names (lock1) as in the code; consistent lock names as in the code
- 第 24 页 / Content Placeholder 2 p3
  - 修改前: `t1 runs first to the end, then t2 (or vice versa): x=3, y=3, z=3`
  - 修改后: `t1 runs first to the end, then t2 (or vice versa): x=3, y=3, z=3 (z can also be 1 or 2, see below)`
  - 理由: headline answer incomplete: the following bullets show lost updates on z, so z is in {1,2,3}
- 第 24 页 / Content Placeholder 2 p4
  - 修改前: `In t1, lock1.signal() sets lock1=1, lock2.signal() sets lock2=1, this exiting the critical sections protected by lock1 and lock2.`
  - 修改后: `In t1, lock1.signal() sets lock1=1, lock2.signal() sets lock2=1, thus exiting the critical sections protected by lock1 and lock2.`
  - 理由: typo
