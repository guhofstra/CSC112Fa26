# L4-Exercises.pptx 审查记录

- 原文件备份：`PPTs/bak/audit-20261007/L4-Exercises.pptx`。
- 幻灯片数：11 张，修改前后不变；只改文字 run，没有改题目的意图或分值。
- 检查：`validate.py --original` 通过；逐部件 XML 对比只有下列幻灯片和 1 页备注变化；改动页用 LibreOffice 渲染查看，与原 PowerPoint 导出的 PDF 对照，没有新增溢出或换行问题。
- 提交：已写回原路径，重新用 python-pptx 打开确认能加载、页数 11。该课件旁没有 `~$` 锁文件。
- 与 ANS 版对照：题目页逐页对比了 L4-Exercises 与 L4-Exercises ANS（见“已修改”中标注“与 ANS 对齐”的几项）。重新解了每道题，ANS 版答案正确，所以这里的改动都是题面文字，没有改答案。

## 已修改

| 页 | 修改前 → 修改后 | 原因 |
|---|---|---|
| 3 | “4 processes P1 through P5” → “5 processes P1 through P5” | P1 到 P5 是 5 个进程；ANS 版 Need 矩阵也是 5 行 |
| 3 标题 | “Quiz: Banker’s Algorithm I” → “Quiz: Banker’s algorithm I” | 与全课程 “Banker’s algorithm” 统一 |
| 4 | “4 processes P1, P2, P3” → “3 processes P1, P2, P3” | 只列了 3 个进程 |
| 5 | “Banker’s Algorithm: 4 philosophers each holding his left fork” → “Banker’s algorithm: ...” | 大小写统一 |
| 5 | “right fork R(i+1)%5” → “right fork R(i%5+1)” | 叉子编号是 1-5，P5 的右叉子应是 R1；(i+1)%5 对 i=5 得到 0 |
| 6 | “Banker’s Algorithm: 5 philosophers each holding his left fork” → “Banker’s algorithm: ...” | 大小写统一 |
| 7 | “Assume total number of chopsticks >= number of hands” → “≥” | 符号 |
| 7 | “UC Berkeley CS162 course” → “CS 162 course” | 课程名写法与封面页 “CS 162” 一致 |
| 7 备注 | “Bankers algorithm” → “Banker’s algorithm” | 笔误 |
| 8（与 ANS 对齐） | “If each lawyer has 2 arms, and there is a pile of 5 chopsticks at the ...” → “There are 5 lawyers, each lawyer has 2 arms, and there is a pile of 5 chopsticks at the ...” | ANS 版是这一说法；原题没有说明有几个律师，无法做 Banker’s 题 |
| 8（与 ANS 对齐） | “Q1: Two lawyers each grab two chopsticks and start eating. Is the current state safe?...” → “...start eating. One lawyer grabs one chopstick. Is the current state safe?...” | ANS 版的 Allocation 是 [2,2,1,0,0]，即第三个律师拿了 1 根；原题漏了这一句，学生无法得到 ANS 的状态 |
| 8 | “Q2: ... Check it using Banker’s algorithm. Check it using Banker’s algorithm.” → 只保留一次 | 句子重复 |
| 9, 10, 11（与 ANS 对齐） | “If each lawyer has 2/4/4 arms, and there is a pile of knives and forks at ...” → “There are N ≥ 2 lawyers, each lawyer has 2/4/4 arms, and there is a pile of knives and forks at ...” | ANS 版有 “N ≥ 2 lawyers”，题目要判断死锁，必须知道有多个律师 |

“与 ANS 对齐”的 5 处改的是题面里缺的前提，没有改变题目要考什么，也没有改分值，但属于改了学生看到的题，请你确认。

### 逐题复核（以 ANS 版答案为准，我重新解了一遍）

- 第 3 页（Banker’s I）：E = [7 3 6]，Allocation 各列和 [7 2 5]，A = [0 1 1]；Need = Max − Allocation，P4 的 Need [0 1 1] ≤ A，先运行 P4 → A = [2 2 2]；P2 的 Need [1 2 2] ≤ A → [4 2 2]；剩下 P1 [7 4 3]、P3 [6 0 0]、P5 [4 3 1] 都不满足 → 不安全。ANS 版结论一致。
- 第 4 页（Banker’s II）：A = [3 2 2]；(1) P2 → P3 → P1 或 P3 → P2 → P1 安全；(2) P1 再要 2 个 R3，A = [3 2 0]，P2 的 Need [3 0 0] 可运行 → [6 4 0]，P1 [8 4 0]、P3 [1 1 2] 都不行 → 不安全，拒绝；(3) P2 再要 2 个 R1，A = [1 2 2]，P2 Need [1 0 0] 可运行 → [6 4 2]，P3 → [8 6 3]，P1 → [8 6 4] 安全，批准。
- 第 5 页：4 个哲学家各持左叉，A = [0 0 0 0 1]，序列 P4, P3, P2, P1, P5 是唯一安全序列，安全；第 6 页：5 个哲学家各持左叉，A = 0 且每人 Need 都非零 → 死锁，不安全。
- 第 8 页：Q0（会不会死锁）：会，例如 Q2 的状态；Q1 的状态 [2,2,1,0,0] 安全（先 P1，释放 2 → 再 P2 → 再 P3）；Q2 每人 1 根，A = 0，每人还需 1 根 → 死锁。
- 第 9 页：先拿刀再拿叉，所有人按同样顺序，不会形成环，不会死锁；第 10 页：先原子地拿 2 把刀再原子地拿 2 把叉，同样不会死锁；第 11 页：刀、叉不原子拿取，2 个律师、2 把刀 2 把叉时各拿 1 把刀即死锁。

## 已发现但未修改 / 需要你确认

1. 第 3、4 页的 Max / Allocation / Total 矩阵是嵌入的 OLE 图片，无法在文件里编辑；我对照 ANS 版文字重算后确认一致，但没有逐个像素检查图片内容。
2. 第 8、9、10、11 页的题面补充（上表“与 ANS 对齐”）：我是按 ANS 版往回补的。如果你更希望由 ANS 版去精简，请告诉我。

## 观察 / 建议

- 题目页没有给出分值（因为是课堂练习），第 3 页的“You will be graded on ...”像是从考试题复制来的，建议统一措辞。
- 这个 Exercises 版与 ANS 版共享题面；建议以后用 ANS 版为主稿、再删去答案生成题目版，减少两份文件漂移。
- 题目覆盖：Banker’s 算法（2 题）、哲学家（2 题）、多臂律师死锁（4 题）。缺少一道 RAG 画图/判断死锁的练习，可作为可选补充。
