# CSC112Fa26 / PPTs — 全部 pptx Content Audit 总报告（2026-10-07）

范围：顶层 25 个 pptx（子文件夹 bak / Exam / LXX / Temp 未处理）。
原文件已备份到 `PPTs/bak/audit-20261007/`（改动前的版本）。每个 deck 的详细修改记录（before → after、验算过程、待确认项）在本文件夹的 `<deck> - audit log.md`。
所有 deck 均通过 `validate.py`，逐部件 XML 对比确认只有预期的页面/备注改变，页数全部不变，已重新打开确认可加载。**检查是在 LibreOffice 渲染下完成的，没有在 PowerPoint 里打开过**。

## 一、各 deck 概况

| Deck | 已修改 | 待你确认/未改 | 最重要的发现 |
|---|---|---|---|
| Lecture 0-course overview | 4 | 6 | 标题 "112/256"→112；网站 URL 仍含 CSC256Fa26；办公时间 8:00–9:40 AM 与上课时间 MW 4:20–5:45 PM 不符；S6 成绩标签 "F? C B A" |
| L1 What is OS | ~14 | 12 | 摩尔定律 "double every 18 months" 改为 1–2 years；S32 有 "??%/year" 占位符；S38 求和 410≠414；S34/36/38 数据过时；S30 备注是残留的 Berkeley 演讲 |
| L2-Processes Threads | ~70 | 15 | S12/S15 代码修正（pid/ret/myargs、弯引号）；S14 exec 成功不返回；S23 IP→PC；S33 "Linux 线程包"→用户级线程；S15 正文溢出待查 |
| L2-Exercises ANS | ~45 | 8 | 全部答案重算无误；修的是编译级代码错误（pid 未声明、`return 0:`、`(true&&?)`→`(true‖?)` 等）；S13 无标题 |
| L3-Synchronization | ~120 | ~12 | 见上一份报告：S29 死锁解释、S37 lock/unlock、S48 数组越界、S50 等；另 S16–18 标题被图遮住已修；References 加了 OSTEP 与 CS162 |
| L3-Exercises | 15 | 9 | S17 死锁场景 lock1/lock2 写反；S9 Readers/Writers 要求 "看讲义" 但讲义无对应页，ANS 也无答案 |
| L3-Exercises ANS | 26 | 9 | **S3 答案错误：最小值是 3，不是 5**（已给出具体调度）；**S15 Peterson 变体不满足互斥**（已写入反例）；S5 "100+10=10"→110 |
| L4-Deadlocks | 28 | 7 | S36 Need 数值写反；S14 RAG 进程号标签错；S40 1-based 叉子公式 `(i+1)%5` 对 P5 无效→`(i%5)+1`；S10 信号量缺初值、S17 环路标签不全（未改，会溢出） |
| L4-Exercises | 15 | 2 | S3/4 进程数写错；S8–11 题面补上与 ANS 对齐的前提（**请确认**） |
| L4-Exercises ANS | 31 | 4 | Banker's 与律师题全部重算正确；等待链顺序、安全序列 "P2,P2,P1" 等错误已改；Q0 没有答案 |
| L5-Scheduling | 9 | 10 | α=0.9 的 t6 应为 12.9（原 13.0）；S21 "two weeks"→"two hours"；S10 IO 完成才进就绪队列；S5/26/28 备注有与课程定义相反/残留内容（仅标记） |
| L5-Exercises | 11 | 3 | "4 processes" 实为 3 个；"all 5 processes" 与表不符；PID 列折行已加宽 |
| L5-Exercises ANS | 7 | 5 | 所有答案与 Gantt 重算无误；标题重复已改；平均值 4.3/27.3/9.67 写法不统一（仅标记） |
| L6-Exercises | 4 | 4 | 缺 Q4；Q5–Q8 无题目版 |
| L6-Exercises ANS | 17 | 6 | 数值答案无误；**S19（Q5 题目页）把 B/R 答案印出来了**（已清空）；3 任务利用率应为 0.780（原 0.828）；4/9→3/9；B_F/B_G 复制错 |
| L6-Exercises ANS OLD | 未改 | — | 旧草稿（题号重复、无答案页、含错误 PCP 说明），可以安全退休 |
| L6-RTScheduling I | 36 | 12 | 公式下标错（τi,1 重复→τi,2；R2 应与 D2 比较）；S45 重复 "Iteration 1"；缺参考文献页；S3 标题为空；S54 图片被裁切 |
| L6-RTScheduling II | 35 | 9 | S27 Dc=10→11；S39 max{P1,P2}→max{P1,P3}；S49 C(s1)→C(s2)；S47 表与公式矛盾已按图和正文修正；S31/32、S48 与 S47–49/S39–42 优先级约定相反（待你决定） |
| L7-Memory System I Cache | ~35 | 6 | FA 的 tag 应为 4 位、无 set index；S47–49 命中数 9996→39996；S46 for 循环语法错；S61 "FA (4-way)"→8-way；S28 "not inflexible"→"inflexible" |
| L7-Exercises ANS | ~14 | 3 | S10 FA 答案 T=27/O=5→T=28/O=4；S31 8 块 cache 写成 4 块；S19 0x1DD 二进制多一个前导 0 |
| L8-Memory System II Paging | 18 | 12 | S6 "8×4KB=16768"→32768；全 deck "Table Lookaside Buffer"→Translation；S45 是隐藏页；S21/S23 备注是整段 Perplexity 粘贴；S63 说页表能放进一页，与 S25 的 4MB 矛盾 |
| L8-Exercises ANS | ~12 | 4 | S9 备注答案错：PPN=2 时物理地址应为 0xB74（原 0x774）；S10 多级页表 Level 标签颠倒（**判断题，见下**）；Q1/Q2 重复标题改为 Q3–Q8 |
| Lxx-Final Review | 14 | 11 | 标题页 "CSC 256"→112；S15 t6=12.9；S12 补总量；母版页脚去掉 "Lec 16."；**L7、L8 整讲在复习里缺失** |
| CSC112 Review Questions | 24 页 | 24 | S42 SJF 行与表格错（平均 4.25）；S50 安全序列 T3,T2,T1 不成立→T2,T1,T3；S9 TLB Tag 1→0；S48/52/57–59 表格与说明不符；S73、S4 代码缺括号 |
| Midterm Exam ANS | 29 | 5 | S3 Available 表漏数；S6 RR 甘特图错；response time 按课程定义（完成−到达）重算；S2 Max 与 Need 不一致（未改） |

## 二、需要你拍板的事项（agent 没有擅自决定）

1. **L8-Exercises ANS S10**：多级页表 Level 标签。已按 L8 讲义改成 L1 = 最外层 = 最高位，请确认课堂约定。
2. **L4-Exercises S8–11**：为与 ANS 对齐，题面补了 5 处前提，请确认。
3. **Midterm Exam ANS**：S6/S8 的 response time 按课程定义重算（C − A，见 L5-Scheduling S5 "called turnaround time in most textbooks"）。如果考试其实要的是 "首次运行−到达"，需要改。RR 的时间片和新到达排队约定题面没写明。
4. **Midterm Exam ANS S2**：T2 的 Max−Alloc=0，页面 Need 是 [0 1 0 0]，未改。
5. **L6-RTScheduling II**：S31/32 临界区长度或时间点差 0.3；S48 图、表、上限互相冲突；S47–49 与 S39–42 优先级约定相反。
6. **CSC112 Review Questions**：S26 与 S27 的 D 列矛盾（D=50 时答案变为不可调度）；S11–14、34、45 是空白页；S51 第 3、4 项重复。
7. **L3-Exercises ANS**：S9 strict alternation 的 Progress "Achieved" 与同页 Major Flaw 矛盾；S11 Bounded Waiting "Achieved" 有争议。
8. **Lecture 0**：网站 URL（仍含 CSC256Fa26）、办公时间、助教/Discord/Zoom 链接是否正确，agent 无法联网核实。
9. **L4-Deadlocks S10/S17、L2 S15/S19**：改了会溢出或需对照截图，保持原样。

## 三、跨 deck 的共性问题（建议整体处理）

- **没有任何 deck 带来源致谢/参考文献页**（L3 已补）：L7/L8/L6-RT 等多处图文看起来来自教材/Berkeley CS61C、CS162。
- **PDF 已落后于 pptx**：同目录下所有 `.pdf` 都是旧版，需要重新导出。
- **公式在 AlternateContent 里**（L5/L6-RT/Final Review）：python-pptx / LibreOffice 看不到，修改写入了 XML 文本，但回退位图预览仍是旧值（例如 α=0.9 的 t6 仍显示 13.0）。**请在 PowerPoint 里打开这些 deck 并保存一次**，让预览刷新。
- **课程编号残留**：CSC256 在 Lecture 0、Final Review、网站 URL 等处出现过。
- **母版/标题位置漂移**：多数 deck 由两套母版拼接，标题位置不一（L1、L2 已统一，其余未动）。
- **页码**：多处手写页码文本框与占位符混用。
- **LibreOffice 渲染误报**：L7-Exercises ANS 第 11/14/17/52 页、L8 第 10 页的重叠是 LibreOffice 的误报（对照你的 PowerPoint PDF 确认），未改版式。
- **L3-Synchronization 正在 PowerPoint 里打开**（存在 `~$` 锁文件）：磁盘上已是新版，但窗口里是旧版。请**关闭后不要保存**，再重新打开文件。

## 四、没有做的事

- 没有联网核实外部链接（YouTube、uttyler 等）。
- 没有改动 PDF、bak、Exam、LXX、Temp 里的任何文件。
- 嵌入的 OLE 图片（如 L4 的矩阵图）无法编辑，只对照文字重算。
