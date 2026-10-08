# L5-Scheduling.pptx 审计记录（32 页，修改后仍为 32 页）

核对方式：逐页读取正文、表格、分组形状、数学公式（OMML）和备注；所有算例（FCFS/RR/SRTF/EMA）重新手算。修改只动了 `a:t`/`m:t` 文本、一张表的列宽和一个空占位符，未增删/重排幻灯片。原件已备份在 `PPTs/bak/audit-20261007/`。

## 已修改

| 页 | 修改前 → 修改后 | 理由 |
|---|---|---|
| 3 | "...a runnable entity  in the OS..." → "...a runnable entity in the OS..." | 多余空格 |
| 10 | "If the current CPU burst finishes before quantum expires, the job blocks for IO and is added to the end of the ready queue" → 末尾加 " when its IO completes" | 技术表述：进程因 IO 阻塞时进入等待队列，IO 完成后才回到就绪队列末尾；原句读起来像是"阻塞的同时就进了就绪队列" |
| 19 | 表格列宽 [381000, 996551, 945607, 1301670, 1301670, 1301670, 1301670] → [620000, 996551, 945607, 1182170, 1301670, 1182170, 1301670]（总宽不变） | "Job" 列太窄，表头被竖排成 J/o/b（device 上已有的 PowerPoint 导出 PDF 里同样如此）。宽度取自 "SJF/SRTF Finishing Time" 两列（只放两位数） |
| 21 | "A and B may arrive and keep CPU busy for two weeks before C is scheduled" → "...for two hours before C..." | 前文 A、B 各跑一小时，FCFS 下 C 要等 A+B = 两小时；"two weeks" 与题设矛盾（Berkeley CS162 原课件我记得是 two hours，未联网核对） |
| 23 | "Pros: Optimal in minimizing average response time)" → 去掉末尾 ")" | 多余右括号 |
| 26 | α=0.9：t6 行 "0.9∗13 + 0.1∗12.1 = 13.0" → "= 12.9"；t7 行 "0.9∗13 + 0.1∗13.0 = 13.0" → "0.9∗13 + 0.1∗12.9 = 13.0" | 重算：t6 = 11.7 + 1.21 = 12.91 ≈ 12.9（原写 13.0 是错的）；t7 = 11.7 + 1.29 = 12.99 ≈ 13.0，结果不变，只是操作数随之改为 12.9 |
| 27 | 删除空的 "Content Placeholder 2"（无文字） | 编辑视图会显示"单击此处添加文本"；表格和 ✓ 图标都独立于它，播放视图无变化 |
| 31 | "job éxecution time" → "job execution time" | 拼写（多余重音符） |
| 5（备注） | "n real-time scheduling theory..." → "In real-time scheduling theory..." | 备注句首缺字母 |

## 已发现但未修改 / 需要你确认

- 第 26 页：α=0.1 一栏每行显示的是四舍五入后的中间值，用显示出来的操作数重算会差 0.1。例如 t4：0.1×4 + 0.9×8.7 = 8.23，页面写 8.3；t5：0.1×13 + 0.9×8.3 = 8.77，页面写 8.7；t6：1.3 + 0.9×8.7 = 9.13，页面写 9.2；t7：1.3 + 0.9×9.2 = 9.58，页面写 9.5。按未舍入的链式计算（9.6、9.04、8.736、8.262、8.736、9.1625、9.546）页面结果全部正确，所以我没改。建议加一行 "intermediate values are rounded for display"，或显示两位小数。
- 第 26 页备注：内容是 α=0.5 的计算（与第 25 页备注重复），与本页 α=0.1/0.9 不符。
- 第 5 页备注：混入了教科书定义 "Response Time = Time at which job first gets CPU − Arrival Time" 以及一大段 real-time 与 interactive 的对比，与正文规定的课程定义（Response time = Completion − Arrival）相反，容易让人混淆；只是备注，学生看不到。
- 第 28 页备注："Deadlock: Priority Inversion"（优先级反转不是死锁）；"(Convention: smallest integer ≡ highest priority)" 与本页图（Priority 3 在上、数字大优先级高）以及 L5/L6 习题（larger number = higher priority）相反。
- 第 13 页备注 "Suppose jobs arrive in the order of P1, P2, P3 at time 0" 是别的例子的残留；第 31 页备注是半句残片（"demoted to lower priority / CPU-bound processes"）。
- 第 19 页表格末行有一格 "Average Turnaround"，它是被合并（hMerge）的单元格，实际不显示。但术语与课程定义（"turnaround" 即本课的 response time）不一致，顺手可删。"Avg RT 37" 是 36.67 的四舍五入。
- 第 15 页表头 "FIFO" 与全篇 "FCFS" 并用（第 7 页已说明二者同义），可统一。
- 第 24 页用 t_n = αx_n + (1−α)t_{n−1}（EMA 记号），L5-Exercises 用 τ_n = α·t_{n−1} + (1−α)τ_{n−1}（预测值记号）；两套记号同时出现，建议在习题页或第 24 页加一句说明。
- **数学公式的预览图（重要）**：第 7、24、25、26 页的公式和文字在 `mc:AlternateContent` 里，PowerPoint 读 `Choice`（我改的是这里），其它软件（LibreOffice、Keynote、Google Slides、缩略图）读 `Fallback` 里的位图。位图我不能也不应重画，所以第 26 页在这些软件里仍会显示旧的 13.0。请用 PowerPoint 打开本文件并保存一次，PowerPoint 通常会重新生成这些预览图。

## 观察 / 建议

- 全文算例重新核对无误：第 7 页 FCFS（24/3/3）初始等待 0、24、27，平均 17，response 24、27、30，平均 27；第 8 页换序后 3 和 13；第 11 页 RR q=20 的等待时间 72/20/85/88（平均 66¼）、response 125/28/153/112（平均 104½）；第 13 页 10.5 与 8.5；第 14 页 1.5/1.5/1.75；第 15 页 991…1000；第 19 页 SJF 70/70/70 与 SRTF 90/10/10；第 25 页 EMA 8、6、6、5、9、11、12。
- 第 27 页比较表的 ✓ 位置与课程内容一致（SJF/SRTF 平均 response 最优；FCFS/RR 不饥饿；SRTF/RR 避免 convoy；FCFS/RR 无需预测）。
- device 上的 `L5-Scheduling.pdf`（Dec 18 2025）与 pptx 同日，大概率是当前版本；改动后如需发 PDF 请重新导出（我没有动任何 PDF）。
- 渲染限制：LibreOffice 的字体替换比 PowerPoint 宽，因此列宽类修改以 PowerPoint 现有 PDF 的行为为依据，LibreOffice 里看到的换行不代表真实效果。
