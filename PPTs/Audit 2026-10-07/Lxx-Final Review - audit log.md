# Lxx-Final Review.pptx 审查记录

- 文件：`PPTs/Lxx-Final Review.pptx`（18 张，修改后仍为 18 张）
- 原件备份：`PPTs/bak/audit-20261007/`
- 修改方式：只改 run 文本（python-pptx / lxml 改 OMML 的 `m:t`），再把只有文字差异的 XML 部分写回原包；其余部分（含 rels、图片）与原件逐字节相同。
- 共 14 处改动（幻灯片正文 5 处、s15 公式 1 处、备注段落 7 处、母版页脚 1 处）。
- 重要说明：s15 的公式有 PowerPoint 动态公式（`mc:Choice`）和预渲染图片（`mc:Fallback`，image22/23.png）两层。我只改了动态公式层，没有替换图片（按规则不换图）。因此 **PowerPoint 里看到的是改后的 12.9；LibreOffice/Keynote 等不支持该公式层的软件仍显示旧图片（13.0）**。在 PowerPoint 里打开并保存一次会重新生成回退图片；PDF 请重新导出。

- 验证（三个 deck 相同）：`validate.py --original` 通过；逐部分 canonical XML（lxml c14n）比较，只有上述 slide（及备注/母版）XML 有差异，其余部分字节相同；改动过的页已重新渲染并查看；提交到原路径后用 python-pptx 重新打开，页数和可加载性已确认。

## 一、已修改

| # | 位置 | 修改前 → 修改后 | 理由 |
|---|------|----------------|------|
| 1 | 标题页 | `CSC 256: Final Review` → `CSC 112: Final Review` | 遗留课程编号 |
| 2 | fork() | `imaging you are a process` → `imagine you are a process` | 拼写 |
| 2 | fork() | `Child and parents have different` → `Child and parent have different` | 单数（子进程与父进程） |
| 11 | Banker’s algorithm 第 4 步 | `Repeat steps 1 and 2 until …` → `Repeat steps 2 and 3 until …` | 步骤为 1 Compute Need、2 找可完成的进程、3 假定其完成并回收资源、4 重复。Need 只算一次，应重复的是 2 和 3；"1 and 2" 会让人重新计算 Need 却不回收资源，循环永远不会推进 |
| 12 | Video tutorial of Banker's algorithm I | `Total resources: [8, 5, 9, 8]` → `Total resources: [8, 5, 9, 8] (left), [8, 5, 9, 7] (right)` | 截图左例 "R3 has 8 instances"，右例 "R3 has 7 instances"（右例结论 "NOT safe"）。原文只写了左例的总量 |
| 15 | α=0.9 的公式（t6、t7 两行，OMML） | t6：`0.9*13 + 0.1*12.1 = 13.0` → `= 12.9`；t7：`0.9*13 + 0.1*13.0 = 13.0` → `0.9*13 + 0.1*12.9 = 13.0` | 重新计算：t6 = 11.7 + 1.21 = 12.91 ≈ 12.9（不是 13.0）；t7 = 11.7 + 0.1×12.91 = 12.99 ≈ 13.0（用 12.9 或 12.91 都得 13.0），所以 t7 结果不变 |
| 备注 4 | wait() | `…terminated child arbitrarily. process (preventing it from becoming a zombie process` → `…terminated child arbitrarily (preventing it from becoming a zombie process).` | 句子残缺、括号未闭合 |
| 备注 8 | Semaphores | `semaphorerywait()` → `sem_trywait()` | 乱码（与下一行 "non-blocking wait" 描述对应） |
| 备注 8 | | 两处单独的 `text` 段落 → 清空 | Markdown 代码块标签残留 |
| 备注 8 | | `This of this as the signal() operation` → `Think of this as the signal() operation` | 拼写 |
| 备注 8 | | `No otjhTechnically examining value after initialization is not allowed.` → `Technically, examining value after initialization is not allowed.` | 乱码 `otjh`；去掉游离的 "No " |
| 备注 18 | PCP Blocking Time | `. Blocking delay is MAX length…` → `Blocking delay is MAX length…` | 开头多余的句号 |
| 母版 | 页脚（右下） | `Lec 16.` + 页码 → 只剩页码 | 之前每张幻灯片显示 "Lec 16.12" 之类，"16" 是别的课件/旧编号遗留，且本 deck 是 Lxx；改后与 L8 等 deck 一致，只显示页码 |

### 重新计算过、结果正确（未改动）
- s14（α=0.5，τ0=10，x = 6,4,6,4,13,13,13）：τ1 = 0.5×6+0.5×10 = 8；τ2 = 0.5×4+0.5×8 = 6；τ3 = 0.5×6+0.5×6 = 6；τ4 = 0.5×4+0.5×6 = 5；τ5 = 0.5×13+0.5×5 = 9；τ6 = 0.5×13+0.5×9 = 11；τ7 = 0.5×13+0.5×11 = 12。与备注一致。
- s15（α=0.1）：9.6、9.04→9.0、8.74→8.7、8.26→8.3、8.73→8.7、9.16→9.2、9.54→9.5，全部与幻灯片一致。
- s15（α=0.9）：6.4、4.24→4.2、5.82→5.8、4.18→4.2、12.12→12.1，一致；t6/t7 见上。
- s12 截图 Banker's 例：左例 Available = 总量 − Σ Allocation = (8,5,9,8) − (8,3,7,6) = (0,2,2,2)；Need = Max − Alloc：P0 1202、P1 0132、P2 1102、P3 0220、P4 2003；序列 P3(0220≤0222)→(1,4,3,2)、P0(1202)→(3,4,4,4)、P1、P2、P4 均可满足，视频给出的 safe sequence P3,P0,P1,P2,P4 正确。右例 R3 总量 7，Available = (0,2,2,1)：只有 P3 可跑 → (1,4,3,1)，之后 P0/P1/P2 需要 R3=2 > 1，P4 需要 R0=2 > 1，无进程可完成 → 不安全，与 "No, it is NOT safe" 一致。
- s16：结论页的 "Optimal (in terms of average response time)"：L5 课件中 response time 定义为 completion − arrival（即周转时间），在此定义下 SJF/SRTF 平均值最优，因此没有改。
- s18：PCP blocking = 所有低优先级任务临界区的最大长度（PIP 为总和）：说法正确，仅备注开头句号已修。

## 二、已发现但未修改 / 需要你确认

1. **s15 备注是旧内容**：备注里的 τ1…τ7 是 α=0.5 的计算（0.5*6+0.5*10 = 8 等），与 s14 的备注完全相同，但幻灯片 s15 讲的是 α=0.1 / 0.9。建议改为 0.1/0.9 的值，或删除。未改（不是乱码，且需你决定怎么写）。
2. **s15 公式的回退图片仍是旧值**（见开头说明）。如果你用 PowerPoint 编辑，保存后会自动更新；否则 Keynote/LibreOffice/导出的 PDF 可能仍显示 13.0。
3. **s15 标题折行**：`Predicting the Length of the Next CPU Burst: α=0.1 or 0.9` 在渲染中折成两行并压在标题下划线上（s14 的标题较短没有此问题）。因为用的是 LibreOffice 替代字体，PowerPoint 里可能不明显，请你确认；若要改可缩短标题。
4. **s12 标题 "…algorithm I"**：deck 里没有 "II"。如果原本有第二部分，被删掉了；否则可以去掉 "I"。
5. **s10 / s12 / s11 撇号不一致**：s10、s12 用直引号 `Banker's`，s11 标题用弯引号 `Banker’s`。纯排版问题，未改。
6. **s16 的 "response time"**：与 L5 的定义一致，但与多数教材（response time = 首次得到 CPU − 到达）不同；讲课时请强调本课程的定义，或改成 "average turnaround/waiting time"。
7. **图片来源/致谢**：s2（fork 示意图）、s9（"Not a perfect analogy, just a fun image!" 的图片）、s12 的视频截图（YouTube AvPjOyeJbBM）、s14（YouTube 视频链接）以及 s17 的汇总表图片没有写明出处；s12/s14 有视频链接但没有作者名。请确认是否需要署名。
8. **s17、s18 全是图片**（s17 的 "Summary of Schedulability Analysis Algorithms" 表、s18 的 PCP 例），文字不可搜索、不可编辑；我没有重新核对表中每一个公式。
9. **s5 标题 "L2 Summary"**：本 deck 里只有 L2 有一页总结，其他讲没有对应总结页（s16 是 "Lecture 5 Scheduling Conclusion"）。命名风格不一致。
10. **s16 备注** 提到 Lottery Scheduling，但幻灯片正文没有，属于备注与正文不同步。
11. 同目录的 `Lxx-Final Review.pdf` 是旧导出，未改动，仍含 "CSC 256" 等旧文字，需要重新导出。

### 相对 L1–L8 缺少的主题（只列出，未添加）
根据 18 张幻灯片的标题和内容：
- **L1**：操作系统概念、内核态/用户态、系统调用、中断/陷阱 —— 没有。
- **L2**：只有 fork/exec/wait 和 Summary；缺少线程模型（kernel vs user threads 的对比只在 Summary 中一句话）、上下文切换、进程状态/PCB、IPC。
- **L3**：只有 race condition、锁/临界区、信号量；缺少 monitor/条件变量、锁的实现（test-and-set、自旋锁与互斥锁的对比只在 s8 一小段）、经典同步问题（生产者-消费者、读者-写者、哲学家就餐）。
- **L4**：有死锁定义与四条件、Banker's；缺少资源分配图、死锁预防/检测/恢复。
- **L5**：有 CPU 突发预测与调度结论；缺少 FCFS/SJF/SRTF/RR 的时间线例题和平均等待/周转时间计算、MLFQ 细节、lottery。
- **L6（实时调度）**：只有 s17、s18 两页（schedulability 汇总、PCP blocking）；缺少 RM/EDF 的可调度性测试、利用率界、优先级反转/PIP 的单独讲解。
- **L7（缓存）**：整讲缺失（缓存结构、直接映射/组相联、命中率/AMAT 等）。
- **L8（分页）**：整讲缺失（页表、地址转换、TLB 与 EAT、多级/倒排页表、缺页、页面置换 FIFO/LRU/OPT、Belady 异常）。

## 三、观察 / 建议
- 本 deck 的 L7 和 L8 完全没有覆盖。如果期末考试包含这两讲，建议至少补一页概览。
- 同样的 "Repeat steps 1 and 2" 写法出现在 L4-Deadlocks（其他 deck，不在我的范围内，未改动），建议同步检查。
- 目录中的 `~$L3-Synchronization.pptx` 锁文件属于 L3 deck，与本 deck 无关。
