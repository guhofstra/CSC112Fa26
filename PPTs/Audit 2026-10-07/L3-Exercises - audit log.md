# L3-Exercises.pptx 审阅与修改记录

审阅范围：全部 18 页（含备注、表格、分组形状）。每道题都重新独立求解（并用 Python 枚举所有交错执行/状态空间验证），再与本 deck 里已有的答案、以及 `L3-Exercises ANS.pptx` 对照。页码为当前 1-based 位置，英文原文用引号标出。

修改方式：run 级文本修改，不增删或重排幻灯片，不改题意与分值，不换图。原件已备份在 `PPTs/bak/audit-20261007/`。共 19 处原子修改（合并后 15 个段落），涉及 11 页（第 2、5、6、7、8、11、12、14、15、17、18 页）。已通过 validate.py（--original）；lxml 逐部件比较确认只有这些幻灯片及第 5 页备注发生变化，页数仍为 18。

## 已修改

- 第 2 页（Concurrency I）：第二个代码框标签 "//Thread T0" -> "//Thread T1"（该框是 j 循环、加 2 的线程；与题目 "T0, T1" 以及答案页一致）。
- 第 5、6、7、8 页：题干 "Does it achieve one of more of the correctness properties" -> "one or more"（4 页）。
- 第 5 页备注：删除孤立的垃圾文字 "acd"。
- 第 11 页：`Addition operation x=y+z consist of` -> `consists of`；"(t2 sets z before execution instruction B of add. in t1)" -> "(t2 sets z before t1 executes instruction B of the addition)"。
- 第 12 页：括号说明末尾缺少右括号：`... sem_post(&s).` -> `... sem_post(&s)).`
- 第 14 页：代码 `printf(“7");` 的弯引号 -> `printf("7");`（复制会编译失败）。
- 第 15 页：
  - "Solution 2(right)" -> "Solution 2 (right)"。
  - "The rest of the same as Solution 1" -> "The rest is the same as in Solution 1"。
  - 小写的 "s2" -> "S2"（2 处，与代码和答案 deck 第 21 页一致）。
- 第 17 页（Deadlocks I）：Deadlock scenario 1 的最后一句有错：t2 执行到第 2 行已持有 lock2，第 4 行阻塞的是 `lock1.wait()`；t1 持有 lock1，第 5 行阻塞的是 `lock2.wait()`。原文 "t2 waits for lock2 in line 4; ... t1 waits for lock1 in line 5" -> "t2 waits for lock1 in line 4; ... t1 waits for lock2 in line 5"（`ANS` deck 第 23 页已是正确写法）。另外 "t2 grabs lock2 requests lock 1, t1 requests lock 2" -> "t2 grabs lock2 and requests lock1, t1 requests lock2"。
- 第 18 页（Deadlocks II，已含答案）：标题答案 "x=3, y=3, z=3" 不完整，因为后文 bullet 自己说明 z 可能因 lost update 变成 1 或 2，改为 "x=3, y=3, z=3 (z can also be 1 or 2, see below)"；"this exiting" -> "thus exiting"。

### 重新求解与答案核对（本 deck 内已带答案的页）

- 第 10-12 页 Race Conditions：t1 读到的 (y, z) 取值为 y in {0,1}、z in {0,2}，所以 x in {0, 1, 2, 3}（三种示例对应 0, 1, 3，值 2 即 y=0, z=2 的情形，第 11 页已解释）。用二进制信号量 mutex 保护 `x = y + z` 与 t2 的两条赋值之后，只剩两种顺序，x in {0, 3}。与本 deck 一致，正确。
- 第 13 页 Semaphores I：`s1=1, s2=0`，t1 打 w，t2 打 o r，再由 t1 打 d，t2 打 l e，总输出只能是 "wordle"，正确。
- 第 14、15 页 Semaphores II：两种解法都能保证输出 2 3 5 7 11 13；解法 2（S2 初值 1，f2 开头多一次 S2.wait()）与解法 1 等价，说明 "Solution 1 is better with one less call to wait()" 正确。
- 第 16 页 Semaphores III：输出为 (AB|BA)C 的重复，正则 `((AB|BA)C)+` 正确。
- 第 17 页 Deadlocks I：改正 lock 名称后，两种场景都是真实死锁（t1 持 lock1 等 lock2，t2 持 lock2 等 lock1）。
- 第 18 页 Deadlocks II：死锁状态 x=2, y=1, z=2（t1 执行到第 5 行 lock2.wait() 前已做 z+=2、x+=2；t2 做了 y+=1，阻塞在第 4 行 lock1.wait()），正确；正常结束时 x=3, y=3，z in {1,2,3}（z=z+2 与 z=z+1 不受锁保护）。
- 第 9 页 Readers/Writers 代码本身正确（偏向 writer）。

## 已发现但未修改 / 需要你确认

1. 第 9 页：题目 "Q: Rewrite it to prefer readers (See lecture slides)" 指向讲义，但 L3-Synchronization 里没有 Readers/Writers 的幻灯片，答案 deck 里也没有对应答案页。建议补一页答案或把讲义页加回去，需要你决定。
2. 本 deck 的第 10-18 页已经包含解答（不是纯题目版），如果打算发给学生需要确认这是有意的。
3. 第 14 页：题目要求 "give the correct initial values"，但代码里已经预填 `S1=0; S2=0; S3=0`；备注里提到的 "// SYNC" 标记在页面上并不存在。答案页第 21 页保持一致。
4. 第 15 页：标题框与左侧代码框重叠（"Semaphores II Solution" 被代码框遮挡一部分）；未改动版面。
5. 第 5-8 页：幻灯片里的 "ANS:" 是空占位；第 5 页备注是原始（GATE 风格）题干，使用 T1/T2 和 S1/S2，与页面上的 T0/T1、S0/S1 不一致；第 7、8 页备注里的 `int i=0, j=1;` 与页面不符。属于旧残留，未改。
6. 第 8 页：Peterson 变体的标题与答案页相同，没有提示这是"错误的变体"，这是教学设计，没改。
7. Peterson 算法在真实硬件上需要内存屏障/顺序一致性，课件没有提及。
8. 标题页副标题为 "Lecture 3 / Synchronization"，建议加 "Exercises"，以便与讲义区分；文档元数据标题也是旧的，未改。
9. 全 deck 没有发现 CSC256 等旧课程代码或旧年份。

## 观察 / 建议

- 第 5-8 页的 "ANS:" 空占位与答案 deck 一一对应，考虑到你会在课堂上现场讲解，保留即可。
- 本 deck 的答案页（第 10-18 页）与 `L3-Exercises ANS.pptx` 已一致；ANS deck 里有两处答案本身是错的（第 3、15 页），已在那边修正，详见 `L3-Exercises ANS - audit log.md`。

## 附录：完整修改记录（自动生成，按页码顺序；同一段落的多次修改已合并为 原文 -> 最终文本）

说明：where = 形状名称/段落序号（段落序号为修改前的编号），reason 为英文原始记录。

- 第 2 页 / Plassholder for innhold 2 p0
  - 修改前: `//Thread T0`
  - 修改后: `//Thread T1`
  - 理由: second code box (the j-loop adding 2) was labelled T0 like the first box; it is thread T1
- 第 5 页 / Content Placeholder 2 p0
  - 修改前: `Does it achieve one of more of the correctness properties of a concurrent program:`
  - 修改后: `Does it achieve one or more of the correctness properties of a concurrent program:`
  - 理由: typo: 'one of more' -> 'one or more'
- 第 5 页 / notes p7
  - 修改前: `acd`
  - 修改后: `(paragraph deleted)`
  - 理由: stray leftover text 'acd' in notes
- 第 6 页 / Content Placeholder 2 p0
  - 修改前: `Does it achieve one of more of the correctness properties of a concurrent program:`
  - 修改后: `Does it achieve one or more of the correctness properties of a concurrent program:`
  - 理由: typo: 'one of more' -> 'one or more'
- 第 7 页 / Content Placeholder 2 p0
  - 修改前: `Does it achieve one of more of the correctness properties of a concurrent program:`
  - 修改后: `Does it achieve one or more of the correctness properties of a concurrent program:`
  - 理由: typo: 'one of more' -> 'one or more'
- 第 8 页 / Content Placeholder 2 p0
  - 修改前: `Does it achieve one of more of the correctness properties of a concurrent program:`
  - 修改后: `Does it achieve one or more of the correctness properties of a concurrent program:`
  - 理由: typo: 'one of more' -> 'one or more'
- 第 11 页 / object 3 p0
  - 修改前: `Addition operation x=y+z consist of multiple machine instructions in assembly language:`
  - 修改后: `Addition operation x=y+z consists of multiple machine instructions in assembly language:`
  - 理由: subject-verb agreement
- 第 11 页 / object 3 p7
  - 修改前: `z is read as 2 (t2 sets z before execution instruction B of add. in t1)`
  - 修改后: `z is read as 2 (t2 sets z before t1 executes instruction B of the addition)`
  - 理由: garbled wording
- 第 12 页 / object 3 p2
  - 修改前: `(Line “int x” can be outside or inside the critical section with no difference. We use a slightly different notation of s.wait()/s.signal() to denote sem_wait(&s) and sem_post(&s).`
  - 修改后: `(Line “int x” can be outside or inside the critical section with no difference. We use a slightly different notation of s.wait()/s.signal() to denote sem_wait(&s) and sem_post(&s)).`
  - 理由: missing closing parenthesis of the parenthetical remark
- 第 14 页 / object 4 p11
  - 修改前: `printf(“7"); `
  - 修改后: `printf("7"); `
  - 理由: curly opening quote in printf code (would not compile if copied)
- 第 15 页 / Content Placeholder 2 p1
  - 修改前: `Solution 2(right): s2 has initial value 1, so f2 calls S2.wait() and runs first. The rest of the same as Solution 1. You can see that initializing s2=0 has the same effect as initializing s2=1 and let f2 call S2.wait() first. So Solution 1 is better with one less call to wait().`
  - 修改后: `Solution 2 (right): S2 has initial value 1, so f2 calls S2.wait() and runs first. The rest is the same as in Solution 1. You can see that initializing S2=0 has the same effect as initializing S2=1 and let f2 call S2.wait() first. So Solution 1 is better with one less call to wait().`
  - 理由: spacing; grammar; semaphore is named S2 in the code
- 第 17 页 / object 3 p3
  - 修改前: `t2 waits for lock2 in line 4; switch to t1, waits for lock1 in line 5`
  - 修改后: `t2 waits for lock1 in line 4; switch to t1, waits for lock2 in line 5`
  - 理由: scenario 1: t2 has lock2 (line 2) and is blocked at line 4, which is lock1.wait(); the old text said it waits for lock2, which it already holds; scenario 1: t1 has lock1 (line 3) and is blocked at line 5, which is lock2.wait()
- 第 17 页 / object 3 p4
  - 修改前: `(Other interleavings are possible, e.g., t1 grabs lock1, t2 grabs lock2 requests lock 1, t1 requests lock 2)`
  - 修改后: `(Other interleavings are possible, e.g., t1 grabs lock1, t2 grabs lock2 and requests lock1, t1 requests lock2)`
  - 理由: missing 'and'; lock names written as in the code (lock1/lock2)
- 第 18 页 / Content Placeholder 2 p3
  - 修改前: `t1 runs first to the end, then t2 (or vice versa): x=3, y=3, z=3`
  - 修改后: `t1 runs first to the end, then t2 (or vice versa): x=3, y=3, z=3 (z can also be 1 or 2, see below)`
  - 理由: the headline answer is incomplete: the next bullets show lost updates on z, so z in {1,2,3}
- 第 18 页 / Content Placeholder 2 p4
  - 修改前: `In t1, lock1.signal() sets lock1=1, lock2.signal() sets lock2=1, this exiting the critical sections protected by lock1 and lock2.`
  - 修改后: `In t1, lock1.signal() sets lock1=1, lock2.signal() sets lock2=1, thus exiting the critical sections protected by lock1 and lock2.`
  - 理由: typo
