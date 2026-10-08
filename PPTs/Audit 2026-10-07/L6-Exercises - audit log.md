# L6-Exercises.pptx 审计记录（4 页，修改后仍为 4 页）

核对方式：读取全部正文（含 `mc:AlternateContent` 里的 Q2 页）、表格和备注；题干与 `L6-Exercises ANS.pptx` 对应页逐字对照；Q1–Q3 的数据都重新做过（计算见 ANS 的审计记录）。原件已备份在 `PPTs/bak/audit-20261007/`。

## 已修改

| 页 | 修改前 → 修改后 | 理由 |
|---|---|---|
| 2 | "...with WCET Ci Period Ti, Deadline Di" → "...with WCET Ci, Period Ti, Deadline Di" | 缺逗号（ANS 版是 "WCET Ci, Period Ti"） |
| 4 | 标题 "Q3 RM, EDF, LLF" → "Q3. RM, EDF, LLF" | 与 "Q1." "Q2." 的标题格式统一（缺句点） |
| 4 | 表格最后一行 "T=9" → "t=9" | 其余行都是 "t=0 … t=8"，只有最后一行用大写 T |
| 4 | "2. Under RM scheduling,  use utilization bound and ..." → 去掉双空格 | 多余空格 |

## 已发现但未修改 / 需要你确认

- 题号：本文件只有 Q1、Q2、Q3；ANS 文件里还有 Q5–Q8 的题目页（并且题号从 Q3 直接跳到 Q5，没有 Q4）。如果你要给学生发题目版，Q5–Q8 目前只在 ANS 文件里（而且 Q5 的题目页含答案，见 ANS 日志，我已在 ANS 里清掉）。
- 第 2 页 "(c.f. Slide 33 in Lecture 6)"："c.f." 一般写成 "cf."；引用的是 L6-RTScheduling I 的第 33 页（τi(Ci, Ti, Di) 记号），我核对过该页存在。该页（"Utilization Bound Test Examples"）上同样的句子也缺逗号（"WCET Ci Period Ti"），属于另一组负责的文件，我没有动。
- 第 4 页的 "Task ID" 列在 LibreOffice 里被折成 "Tas/k ID"；这是 LibreOffice 字体较宽造成的，我无法在 PowerPoint 里确认，未改。
- 渲染限制：Q2 页的任务集（τ1=(0.5,3,3)…）是 `mc:AlternateContent`（公式对象），LibreOffice 只能显示其旧版位图，无法用来目视核对；我是读 XML 文本核对的。

## 观察 / 建议

- Q1–Q3 题干与 ANS 版数字逐项一致：Q1 六组 (C,T,D)、RM 利用率界表（1.00/0.828/0.780）、Q2 三组任务集、Q3 的 τ1(C=3,T=D=8)、τ2(C=4,T=D=10)。
- 题干表述中 Q1 用 "τ1 (3, 6, 6)" 而 Q2 用 "τ1=(0.5, 3, 3)"，两种记号都清楚，但可统一。
