# L5-Exercises ANS.pptx 审计记录（15 页，修改后仍为 15 页）

核对方式：逐页读取正文、表格、形状文字和备注；每一题从头重新做，逐格核对答案表和 Gantt 行；题目页与 `L5-Exercises.pptx` 对照。原件已备份在 `PPTs/bak/audit-20261007/`。

## 已修改

| 页 | 修改前 → 修改后 | 理由 |
|---|---|---|
| 4 | "...response times for all 5 processes..." → "for all processes" | 后面的表只有 3 个（第 5 页）或 4 个（第 7 页）进程，"5" 不符，疑似旧题遗留（题目版第 3 页同改） |
| 9 | 标题 "Scheduling II ANS" → "Scheduling II ANS (RR Explanation)" | 与第 8 页标题完全重复；本页内容是 RR 说明 |
| 12 | "...overlap of computation and IO busts..." → "IO bursts" | 拼写 |
| 15 | 标题 "Scheduling with Bursts ANS" → "Scheduling with Bursts II ANS" | 对应题目页（第 14 页）是 "Bursts II"，第 13 页是 "Bursts I ANS"，原标题无法分辨 |
| 5、6、7、8、9、11 | 备注 "So, the average of 2, 7, 5, 6, and 8 is 5.6. / The average of the numbers 2, 7, 5, 9, and 4 is 5.4. / ..." → 清空 | 与本题无关的旧残留，且数字与本页答案不符 |
| 5、6、7、8、10、11、12、14、15 | PID 列加宽到 600000 EMU，表向左扩（15 页：293496→600000，表左缘 3200401→2893897）；第 5–8 页另把 SJF/SRTF/RR 的 Finish 列改为 922097、Response 列改为 1222097（表总宽不变） | "PID" 被折成 P/I/D 三行；"SJF/SRTF/RR Response Time" 被折成 "Respons/e Time"（device 上现有 PowerPoint 导出 PDF 可见） |
| 13 | PID 列 285577 → 560000；从三个 Burst 列各取约 91475 EMU（该表左缘 95422，已贴近页边，不能左扩） | 同上 |

## 答案核对（重新计算）

**第 3 页 指数平均**（τ_n = α·t_{n−1} + (1−α)·τ_{n−1}，τ0=10，t0..t3 = 4,8,6,7，α=0.5）：τ1 = 0.5×4 + 0.5×10 = 7；τ2 = 0.5×8 + 0.5×7 = 7.5；τ3 = 0.5×6 + 0.5×7.5 = 6.75；τ4 = 0.5×7 + 0.5×6.75 = 6.875。与页面一致。

**第 5/6 页**（P1: 0/2，P2: 1/6，P3: 4/2）：
- FCFS：P1 0–2，P2 2–8，P3 8–10；finish 2/8/10，response 2/7/6，平均 15/3 = 5 ✓
- SJF 同 FCFS（P2 先到，非抢占）= 5 ✓
- SRTF：P1 0–2，P2 2–4，P3 4–6（剩余 2 < P2 剩余 4，抢占），P2 6–10；finish 2/10/6，response 2/9/2，平均 13/3 ≈ 4.33（页面 4.3）✓；Gantt 行 1 1 2 2 3 3 2 2 2 2 ✓
- RR q=1（到达者排队头）：1 2 1 2 3 2 3 2 2 2；finish 3/10/7，response 3/9/3，平均 15/3 = 5 ✓

**第 7/8/9 页**（P1: 0/3，P2: 1/5，P3: 3/2，P4: 9/2）：
- FCFS：finish 3/8/10/12，response 3/7/7/3，平均 20/4 = 5 ✓
- SJF：P1 0–3，P3 3–5，P2 5–10，P4 10–12；finish 3/10/5/12，response 3/9/2/3，平均 17/4 = 4.25 ✓
- SRTF：与 SJF 相同（P2 在 t=1 到达时剩余 5 > P1 剩余 2，不抢占），4.25 ✓
- RR：1 2 1 3 2 1 3 2 2 4 2 4；finish 6/11/7/12，response 6/10/4/3，平均 23/4 = 5.75 ✓；第 9 页的 RR 文字说明与 Gantt 行一致（"12,12"、"321,321" 循环）

**第 11 页**（P1: 0/2，P2: 3/1，P3: 5/6）FCFS：0–2，3–4，5–11；finish 2/4/11，response 2/1/6，平均 3 ✓

**第 13 页**（三进程同时到达，IO 2/CPU 7/IO 1、IO 4/CPU 14/IO 2、IO 6/CPU 21/IO 3，SRTF）：P1 在 2–9 运行，IO 9–10 结束，finish 10；P2 在 9–23 运行（P3 剩余 21 > 14），IO 23–25，finish 25；P3 在 23–44 运行，IO 44–47，finish 47。平均 82/3 = 27.33（页面 27.3）✓；页内说明各时刻剩余时间（P2 在 t=10 剩 13）✓

**第 15 页**（固定优先级，大者优先；P1: 优先级 2，CPU1/IO5/CPU3；P2: 到达 2，优先级 1，CPU3/IO3/CPU1；P3: 到达 3，优先级 3，CPU2/IO3/CPU1）：P1 0–1；P2 2–3；P3 3–5；P2 5–6；P1 6–8；P3 8–9（P3 的 IO 5–8 结束）；P1 9–10 → finish 10；P2 10–11，IO 11–14，14–15 → finish 15；P3 finish 9。response 10/13/6，平均 29/3 = 9.67 ✓

## 已发现但未修改 / 需要你确认

- 平均值的写法不统一：第 6 页 "4.3"、第 13 页 "27.3"、第 15 页 "9.67"，而第 4 页（题干）要求"除不尽写分数"。建议答案页写 13/3、82/3、29/3。
- 第 1 页标题 "Exercises Solution"，L6 同类文件用 "Exercises ANS"，其它页标题用 "ANS"；术语可统一。
- 各表末行 "Average Turnaround" 是被合并掉的隐藏单元格（与课程用语不一致，但不显示），未动。
- 第 13 页：标题框位置 x=−902050（一部分在幻灯片外，文字居中仍可见），右上角的解释文本框（x=6317409，y=28244）在 LibreOffice 里因字体较宽会压住标题右端和 Gantt 图顶部的数字；PowerPoint 里该框的自适应高度（3477875）刚好止于 Gantt 图上缘（3505200），应无重叠，我按作者的设计意图没有动。建议你在 PowerPoint 里看一眼。
- device 上 `L5-Exercises ANS.pdf`（Sep 2 2025）早于 pptx（Oct 3 2025），内容是旧版（例如第 13 页布局与当前 pptx 不同）；需要的话请重新导出（我没动 PDF）。
- 渲染限制：LibreOffice 里 "Respons/e Time" 仍可能换行，请在 PowerPoint 里确认。

## 观察 / 建议

- 所有答案、Gantt 行、箭头标注（P1/P2/P3/P4 arrival 位置）与重算结果一致，没有发现答案错误。
- 第 9 页的"cyclic pattern of “12, 12”"文字可读但略含糊，可改为 "ready queue order P2, P1 repeats"，纯文字风格问题，未改。
