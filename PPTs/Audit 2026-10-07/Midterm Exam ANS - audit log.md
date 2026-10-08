# Midterm Exam ANS.pptx 审查记录

- 原文件备份：`PPTs/bak/audit-20261007/Midterm Exam ANS.pptx`。
- 幻灯片数：8 张，修改前后不变；没有改题目意图和分值（这套幻灯片本来也没有分值）。
- 检查：`validate.py --original` 通过；逐部件 XML 对比只有 slides 2-8 发生变化；改动页用 LibreOffice 渲染并检查（表格数值、Gantt 行）。
- 提交：已写回原路径，重新用 python-pptx 打开确认能加载、页数 8。该课件旁没有 `~$` 锁文件。
- **重要**：第 6、8 页的 response time 与 RR 甘特图是答案内容的改动，我按课程 L5-Scheduling 的定义重算后改的，请你确认（见下“需要你确认”）。

## 已修改

| 页 | 修改前 → 修改后 | 原因 |
|---|---|---|
| 2 | 删除左下角一个很小的圆 “Oval 4”（约 67420 EMU，无文字） | 没有意义的游离形状 |
| 3 | “Available after each completion” 表中 T2 行的 R2：“0” → “1”（行内数值 [1 0 1 3] → [1 1 1 3]） | T3 先完成后 A = [0 0 0 2] + [0 1 0 1] = [0 1 0 3]；T2 再完成释放 [1 0 1 0] 得 [1 1 1 3]；原表漏了 R2 的 1 |
| 4 | “Consider the set of 3 processes ...” → “2 processes” | 表中只有 P1、P2 |
| 4, 6 | 标题 “Scheduling with Bursts” / “... ANS” → “Scheduling with Bursts I” / “Scheduling with Bursts I ANS” | 与第 7、8 页的 “II” 对应，之前两题标题无法区分 |
| 5 | 空标题 → “Scheduling with Bursts I: Gantt Chart”；删除空的内容占位符 | 空占位符；标题缺失 |
| 6 | RR 行甘特图：第 5 格 “1” → “2”，第 6 格 “2” → “1”（整行变为 1 2 1 1 2 2 1 1 1 1） | 见下方验算：P1 的 IO 在 4-5，不可能在 slot 5 运行 |
| 6 | P2 的 Resp. Time：FCFS 11 → 10，SJF 11 → 10，SRTF 6 → 5，RR 7 → 5，FP 6 → 5 | 课程里 response time = Completion − Arrival（L5-Scheduling），P2 在 1 到达 |
| 6 | Avg RT：FCFS 10 → 9.5，SJF 10 → 9.5，SRTF 8 → 7.5，RR 8.5 → 7.5，FP 8 → 7.5 | 随上一项重算 |
| 7 | “Consider the set of 3 processes ...” → “2 processes” | 同第 4 页 |
| 8 | P1 的 Resp. Time（SRTF, RR, FP 三列）：10 → 12 | P1 在 slot 11 结束，完成时间 12，到达 0，所以 12 |
| 8 | P2 的 Resp. Time：SRTF 6 → 7，RR 7 → 9，FP 6 → 7 | 同上，按 Completion − Arrival |
| 8 | Avg RT：SRTF 8 → 9.5，RR 8.5 → 10.5，FP 8 → 9.5（FCFS、SJF 的 10 不变） | 随上一项重算 |

### 验算

**(1) Deadlock（第 2 页）**：Total = [1 1 2 3]；Allocation 列和：R1: 0+1+0 = 1，R2: 0+0+1 = 1，R3: 1+1+0 = 2，R4: 0 → Available = [0 0 0 3]（与表一致）。Need（表中）T1 [1 0 0 0]，T2 [0 1 0 0]，T3 [0 0 1 0]：A = [0 0 0 3] 满足不了任何一行 → 死锁，结论“Deadlock”在 Need 表为准时成立（但见下面“需要你确认”第 1 条）。

**(2) No Deadlock（第 3 页）**：Total = [1 1 2 3]，Allocation 列和 = [1 1 2 1]，A = [0 0 0 2]（与表一致）。Need = Max − Allocation：T1 [1 0 0 0]，T2 [0 1 0 0]，T3 [0 0 0 0]。T3 先（Need 0）→ A = [0 0 0 2] + [0 1 0 1] = [0 1 0 3]；T2（[0 1 0 0] ≤ A）→ + [1 0 1 0] = [1 1 1 3]；T1（[1 0 0 0]）→ + [0 0 1 0] = [1 1 2 3] = Total。安全序列 T3, T2, T1，页面上的 “Safe Sequence: T3, T2, T1” 正确。

**(3) Scheduling with Bursts I（P1：到达 0，CPU 3 / IO 2 / CPU 4；P2：到达 1，CPU 1 / IO 2 / CPU 2）**
- FCFS：P1 在 slot 0-2 运行，随后进入 IO（slot 3-4）；P2 在 slot 3 运行 1 个单位后进入 IO（slot 4-5）；slot 4 两个进程都在 IO，所以空闲 X；P1 在 5-8 运行，P2 在 9-10 运行。甘特图 1 1 1 2 X 1 1 1 1 2 2，P1 完成于 9，P2 完成于 11；Resp = 完成 − 到达 → P1 9，P2 10，平均 9.5。SJF 在这个例子里同 FCFS。
- SRTF / RR（时间片 1）/ FP：1 2 1 1 2 2 1 1 1 1。P1 完成于 10 → 10；P2 完成于 6 → 5；平均 7.5。原来的 RR 行在 slot 5、6 写成 “1, 2”，但 P1 此时在 IO（slot 4-5），不能运行。
- RR 的假设：时间片 1，新到达进程优先于刚被抢占的进程排队。这个假设能复现原题的 Problem II 甘特图（见下），所以保持这个约定。

**(4) Scheduling with Bursts II（P2：CPU 1 / IO 3 / CPU 3，其它同上）**
- FCFS / SJF：1 1 1 2 X 1 1 1 1 2 2 2；P1 9，P2 12 − 1 = 11；平均 10（原值正确）。
- SRTF：1 2 1 1 X 2 2 2 1 1 1 1；P1 完成 12 → 12，P2 完成 8 → 7；平均 9.5。
- RR（时间片 1，新到达优先）：1 2 1 1 X 2 1 2 1 2 1 1（页面原来的甘特图，不变）；P1 完成 12 → 12，P2 完成 10 → 9；平均 10.5。
- FP（P2 优先）：1 2 1 1 X 2 2 2 1 1 1 1；P1 12，P2 7；平均 9.5。
- 原来的 P1 值 10 对应的是第 6 页（Problem I）的完成时间，没有随 Problem II 更新（slide 8 中的 SRTF/RR/FP 的 P1 应为 12），很可能是复制后没有改。

## 已发现但未修改 / 需要你确认

1. **第 2 页 Max 与 Need 不一致**：T2 的 Max = [1 0 1 0]，Allocation = [1 0 1 0]，所以 Max − Allocation = [0 0 0 0]，但页面上 Need 写的是 T2 [0 1 0 0]。其余两行都一致（T1: [1 0 1 0] − [0 0 1 0] = [1 0 0 0]；T3: [0 1 1 0] − [0 1 0 0] = [0 0 1 0]）。如果 T2 的 Max 应是 [1 1 1 0]（与第 3 页的 T2 的 Max 相同），则 Need 和“死锁”结论都成立；如果 Max 是对的，则 T2 的 Need 为 0，T2 可以先完成，释放后 A = [1 0 1 3]，T1 [1 0 0 0] 再能完成，系统并不死锁。我不能确定哪一个是本意，所以没有改。右侧的 RAG 图是否画了 T2 → R2 的请求边，也请你核对。
2. **Response time 的约定**：我按课程 L5-Scheduling 的定义（Response time = Completion − Arrival）重算。如果你想沿用“完成时间”（即原答案里的 11、10 等），那么第 6、8 页的 P2 值和平均值需要还原；原来的数值在备份里。注意原答案本身并不统一：Problem II 的 FCFS/SJF 已经用了完成 − 到达（P2 = 11），而其它列用了不同的口径。
3. **RR 约定**：时间片 1；P1 第二个 CPU burst 与 P2 同时就绪时新到达者先排队。如果你的课程约定不同（例如被抢占者先排队），第 6、8 页 RR 行与相关数值都会不同。页面上没有写这个约定，建议在题面里加上。
4. 题目页（第 4、7 页）和答案页（第 6、8 页）交错在同一个 ANS 文件中；没有单独的无答案版，如果期中要打印发给学生，需要另存一份去掉 ANS 页的版本。
5. 第 3 页的 Need 矩阵、第 2 页的 RAG 图都是原样保留；我没有对图中边的方向做核对（图是分组形状，不是文字）。

## 观察 / 建议

- 封面写 “Midterm Exam Answer Key” 但没有学期、日期和学生姓名栏；如果要正式用，可以补上 Fall 2026 的标识。
- 题目与答案页之间标题现已区分（I / II，ANS）。第 2、3 页的标题是 “(1) Deadlock / (1) No Deadlock”，可考虑改成 “Problem 1: Deadlock (state A / state B)”。
- 题目里“Gantt chart / response time”的假设（RR 时间片、新到达排队顺序、IO 是否占用 CPU）建议写进题面，减少同学争议。
- 题目覆盖：死锁判定 / Banker's 安全序列与 CPU 调度。缺少同步（信号量/监视器）和内存方面的题目，如果期中范围包含 L3 或后续章节，可以考虑补充。
