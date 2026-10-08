# L5-Exercises.pptx 审计记录（8 页，修改后仍为 8 页）

核对方式：逐页读取正文、表格、备注，并与 `L5-Exercises ANS.pptx` 的题目页逐页对照。本文件是题目版，没有答案；我把每一题都重新做了一遍，用来检查题干本身和 ANS 版是否一致（计算见 `L5-Exercises ANS - audit log.md`）。原件已备份在 `PPTs/bak/audit-20261007/`。

## 已修改

| 页 | 修改前 → 修改后 | 理由 |
|---|---|---|
| 3 | "...Round-Robin (RR) with timeslice quantum = 1" → "...with time quantum = 1" | 术语统一：ANS 版和课件都是 "time quantum"，"timeslice quantum" 是拼接词 |
| 3 | "Compute the finish times and response times for all 5 processes" → "for all processes" | 本页题干同时用于第 4 页（3 个进程）和第 5 页（4 个进程），"5" 与两张表都不符，疑似旧题遗留 |
| 6 | "...arrival time and CPU/IO burst times are given below" → "...CPU burst times..." | 本题只有 CPU burst（Exec Time），没有 IO；ANS 版（第 10 页）就是 "CPU burst times" |
| 7 | "Consider the set of 4 processes" → "set of 3 processes" | 表里只有 PID 1–3；ANS 版（第 12 页）写 3 |
| 7 | "...computation and IO busts of different processes" → "IO bursts" | 拼写 |
| 8 | "Consider the set of 4 processes" → "set of 3 processes" | 表里只有 PID 1–3；ANS 版（第 14 页）写 3 |
| 4、5 | 备注 "So, the average of 2, 7, 5, 6, and 8 is 5.6. / The average of the numbers 2, 7, 5, 9, and 4 is 5.4. / ..." → 清空 | 与本题无关的残留文字（旧例子的平均数） |
| 4、5 | 删除幻灯片外（y=7629372，页高 6858000）的两个文本框 "B arrival" 和 "C arrival" | 看不到的残留物；本题进程是 1/2/3 而不是 A/B/C |
| 4、5 | PID 列宽 320287 → 600000，整表向左扩 279713 EMU（左边缘 850898→571185；530799→251086），右边缘不变 | "PID" 被折成 P/I/D 三行（device 上 PowerPoint 导出的 PDF 里就是如此） |
| 4、5 | 表列宽 [.., 1072097(SJF Finish), 1072097(SJF Resp), ...] → SJF/SRTF/RR 的 Finish 列 922097、Response 列 1222097（FCFS 两列不动） | 这三组表头是单段 "SJF Response Time"，在 1072097 宽的列里被拆成 "Respons/e Time"（device 上现有的 PowerPoint 导出 PDF 中可见；该 PDF 日期较旧，但这张表的列宽与当前文件相同）；FCFS 的两段式表头没有这个问题 |
| 6、7、8 | PID 列宽同上，整表左扩 279713 EMU | 同上（"PID" 竖排） |

## 已发现但未修改 / 需要你确认

- 表格末行的 "Average Turnaround"（已核对第 4 页；其余页同一模板）是被合并（hMerge）掉的单元格，实际不显示；但术语与课程定义不一致（本课把 turnaround 叫 response time）。想清理的话在每张表里删掉该格文字即可，我没动。
- 第 3 页示例 "write a fraction like 28/5 instead of 5.6" 是 5 个进程时代的例子，现在题目是 3 或 4 个进程；只是举例，不影响做题，建议改成 "like 13/3"。
- 第 2 页公式写成 τ_n = α·t_{n−1} + (1−α)·τ_{n−1}（τ 为预测值），课件第 24 页写成 t_n = αx_n + (1−α)t_{n−1}。两套记号都对，但同一周内出现两套，建议统一。
- 渲染限制：LibreOffice 字体比 PowerPoint 宽，LibreOffice 里 "Respons/e Time" 仍会换行；列宽依据 PowerPoint 的导出 PDF 调整，实际效果请你在 PowerPoint 里看一眼第 4、5 页。

## 观察 / 建议

- 题干与 ANS 版现已一致（除答案外）。
- 所有题的数据（PID、到达时间、执行时间、burst、优先级）与 ANS 版逐格相同。
