# L3-Synchronization.pptx — Content Audit

审阅范围：全部 53 页（含备注）。页码均指**原有页码**（新增的两页是第 53–54 页，原 References 现为第 55 页）。本次审阅**没有改动任何原有页面**，下面是建议修改清单，确认后可以一次性改好。

---

## A. 技术错误（建议优先修改）

| 页 | 问题 | 建议改法 |
|---|---|---|
| 29 | 死锁解释里 Producer / Consumer 角色写反。队列为空时 emptySlots = bufSize，Producer 不会卡在 `sem_wait(&emptySlots)`；"waiting for Consumer to put items into the queue" 也不对（Consumer 是取走）。队列为满时，fullSlots > 0，Consumer 也不会卡在 fullSlots。 | 空队列：**Consumer** 持有 mutex，阻塞在 `sem_wait(&fullSlots)`（=0）；Producer 阻塞在 `sem_wait(&mutex)`。满队列：**Producer** 持有 mutex，阻塞在 `sem_wait(&emptySlots)`（=0）；Consumer 阻塞在 `sem_wait(&mutex)`。 |
| 29 | "Incorrect code" 中 Consumer 调用的是 `enqueue(item)`，且签名为 `Consumer(item)`。 | 改为 `item = dequeue()`，签名 `Consumer()`（与第 28 页一致）。 |
| 28 | 说明文字："Producer and Consumer can enqueue/dequeue items. concurrently (within critical section protected by mutex)" 自相矛盾：mutex 保护的临界区内不可能并发；另有多余句号。 | 改为：当 fullSlots>0 且 emptySlots>0 时，二者都不会因 slot 而阻塞，但对 queue 的访问仍由 mutex 互斥。 |
| 37 | 右侧 Waiter 代码块第一行是 `unlock(&mutex);`，应为 `lock(&mutex);`（渲染图已确认）。 | 改为 `lock(&mutex);` |
| 37 | 把 "另一线程抢先修改状态" 称为 "spurious wakeups"，术语不对。Spurious wakeup 指没有任何 signal 却被唤醒（实现层面的现象）；这里描述的是 Mesa 语义下被别的线程"抢走"条件。 | 改为 "(Mesa semantics: signal is only a hint)"；spurious wakeup 另行一句说明（第 40 页用 while 也正确地提到了它）。 |
| 48 | 代码使用未定义的变量 `id`（应为 `i`）；且 i = N-1 时 `fork[i+1]` = `fork[N]` **数组越界**（应为 `fork[(i+1)%N]`）。pickup 和 putdown 两处都有。 | `if (i == N-1)`；先 `sem_wait(&fork[(i+1)%N])`，再 `sem_wait(&fork[i])`；putdown 同理。 |
| 50 | "A monitor self[i] is created for each philosopher i" —— self[i] 是 **condition variable**，monitor 只有一个（mutex + 所有 CV + state[]）。 | 改为 "A condition variable self[i] is created for each philosopher i"。 |
| 42 vs 48/代码 | 第 42 页说哲学家和叉子编号 1–5，但图、代码、第 48 页都是 0–4。 | 统一为 0–4：philosopher i 的左叉是 i，右叉是 (i+1)%N。 |
| 23 | `while (TestAndSet(guard));` 与第 11 页定义的 `TestAndSet(int *old_ptr, int new)` 不符（没传指针、没传新值）。 | 写成 `while (TestAndSet(&guard, 1));`。 |
| 24 | 把 "Binary Semaphore" 等同于 "mutex"，下文却说 pthread_mutex 有 ownership（只有加锁者能解锁），而且用 "Equivalently" 连接，前后矛盾；注释 "Initialize mutex to 1 (unlocked)" 对 pthread_mutex_t 不准确（它不是整数 1）。 | 改成 "binary semaphore can be used like a mutex, but has no owner"；"Equivalently" → "In contrast"；注释改为 "statically initialized (unlocked)"。新增的第 53 页已按此口径写（Ownership 一行）。 |
| 20 | "Dijkstra in late 60s"。信号量由 Dijkstra 在 1960 年代早中期提出（约 1962–65，*Cooperating Sequential Processes*）。 | 改为 "in the 1960s"。 |
| 5 | `ld` / `st` 不是 AArch64 助记符（应为 `ldr` / `str`）。 | 若想保持真实，改成 `ldr w8, [x9]` / `str w8, [x9]`（第 5、7 页图中也有）；若是伪汇编，标注 "pseudo-assembly"。 |
| 36 | "Xerox-Park" → **Xerox PARC**。 | 修改。 |
| 32 | `thread_mutex_t mutex` → `pthread_mutex_t mutex`。 | 修改。 |

## B. 不一致 / 表述不够准确

- **11、12**：多处 `lock-flag`（应为 `lock->flag`，箭头丢失）；第 12 页文字用变量名 `original`，代码里是 `old`，且说 "lock() returns old==0"（返回的是 CAS，不是 lock()）。
- **19（Recap）**："mutual execution" 出现 2 次，应为 **mutual exclusion**；"atomical" → "atomic"。
- **S43 与 S45 同名** "Semaphore-based Solution: Deadlock"，但分别是 "朴素版" 和 "全局 mutex 版"；建议 S45 改成 "Solution 0 (variant): Deadlock"。
- **46**：正文先说 `pickup_mutex`，下一段又说 "protected by mutex"，统一为 pickup_mutex。
- **47**："permitted to start eating concurrently" 更准确的说法是 "compete for forks"；最后一句缺句号。
- **7**："Progress (deadlock-free)" 把 progress 等同于 deadlock-free，略粗；可写 "(no deadlock; a free lock can always be acquired)"。
- **21**：标题 "POSIX pthreads API" 但表里含 `sem_*`（POSIX 信号量，`<semaphore.h>`，并非 pthreads）；建议标题改为 "POSIX Threads & Semaphores API"。
- **API 命名混用**：`sem_wait/sem_post`、`wait/signal`、`P/V`；`pthread_mutex_lock` 与 `mutex_lock`（49–51）；`pthread_cond_wait` 与 `cond_wait`；`mutex_t mutex = 1`。第 21 页声明了简写，但 49–51 页未再提示。
- **40**：`cond_wait (&c)` 缺第二个参数 `&m`。
- **18（备注）**："turn = 0: No threads are currently holding the lock" 不准确（turn=0 表示轮到 ticket 0）；备注到 C unlock 就结束，与幻灯片后面 A 再次加锁的表格不一致。

## C. 错别字 / 排版

- **4**：`"common_threads.h”` 结尾是弯引号，复制代码会编译失败。
- **8**：`lock_t mutex` 和 `unlock(&mutex)}` 缺分号。
- **14、15**：弯引号方向混用（`”turn”`、`number.“`）。
- **26**："Consumers picks" → "pick"。
- **34**：代码末尾多余的 `` ` ` ``。**45**：正文末尾多余的反引号。
- **35**：`return item` 缺分号。
- **41**：`Pthread_mutex_unlock`（大写 P）。
- **42**："Dinning" → **Dining**；"Each philosophers" → "Each philosopher"。
- **32**：`pthread_cond_broadcast(&cond): Broadcast(): ...` 多余的 "Broadcast():"。
- **36**：标题 "Boolean flag" 大小写与全 deck 标题风格不一致。
- **37**（可能）：渲染中 "Waiter thread / Signaler thread" 标签压在下面的 bullet 上，PowerPoint 里请确认是否重叠（大量空段落用作占位）。

## D. 结构 / 流程

- **33**：正文占位符为空（只有图片），标题与第 32 页完全重复且前面多一个空格；建议改成 "Monitor Structure"。
- **51**：标题占位符为空（没有标题），建议 "Dining Philosophers: Semaphores vs. Monitors"。
- **页码**：只有第 20、22、23、24、27、29 页有手写页码文本框，第 21 页显示 "2.21"，其余页没有；建议统一用母版的页码占位符。
- **标题位置/尺寸漂移**：第 2–19 页（Norwegian 版式 "Tittel og innhold"）与第 20 页起（"Title and Content"）标题 y 位置不同；第 39–41、48–50 页又各不相同。属于两套母版拼接的后果。
- **Outline（第 2 页）** 只有 3 项，但 deck 实际还包含 Producer/Consumer、Deadlock、Thread Join、Dining Philosophers。
- **第 52 页** 标题 "Semaphores vs. Monitors" 现与新增的第 53–54 页标题接近；建议改为 "Recap: Semaphores vs. Monitors"。
- **Hoare vs. Mesa**：只在第 36 页备注中出现（且 "Mesa-style:" 备注为空）；幻灯片里只讲了 Mesa。可加一行 Hoare（signal 后立即把锁交给 waiter，因此可以用 if）作对比。
- **References（原 53 页）**：只有两个 YouTube 链接；第 1 页提到的 UC Berkeley CS162 / NTNU 未列入，课件中的 `thr_join/thr_exit`、ticket lock、TAS/CAS 等例子看起来改编自 OSTEP（Arpaci-Dusseau），建议补充教材/章节引用。

## E. 备注（speaker notes）清理

- **20**：备注里有乱码/残片："semaphorerywait()"、"No otjhTechnically"、"This of this as the signal() operation"。
- **21**：备注里的 `pthread_signal`、`pthread_wait(t)` 并不存在（应为 `pthread_cond_signal`、`pthread_join`）。
- **23**：备注引用了本 deck 中不存在的幻灯片 "Interrupt re-enable in going to sleep"；同时 `guard = 0` 与 `sleep()` 必须原子执行这一点只在备注里，建议放到页面上（这是个很好的 lost-wakeup 讨论点）。
- **30**："Res 2Process B" 缺换行。**39**："incremente1d"。
- **49、50**：备注里出现 "maintain.4"（遗留脚注编号）；**49 是信号量版，备注却写 "Because the monitor enforces…"**（从 50 页复制过来）。
- **48**：备注 "Philosopher 2 picks up left fork 1" → Philosopher 1。

---

## 新增页面

- **第 53 页 "Semaphore vs. Monitor: Key Differences"**：7 个维度的对照表（抽象层次、互斥、等待条件、信号是否有记忆、临界区内等待、ownership、适用场景）。
- **第 54 页 "Semaphore vs. Monitor: Trade-offs"**：用 monitor 实现 semaphore 的代码（说明二者表达能力等价）、各自适用/注意事项、并映射回本讲的 Thread Join / Bounded Buffer / Dining Philosophers 三个例子。
- 两页均带讲稿备注，风格（蓝色标题、红色关键词、浅蓝表头）与第 21、52 页一致。
- 注意：同目录下的 `L3-Synchronization.pdf` 是旧版，需要重新导出才会包含新页面。
