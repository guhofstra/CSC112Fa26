# L4-Deadlocks.pptx 审查记录

- 原文件备份：`PPTs/bak/audit-20261007/L4-Deadlocks.pptx`（已核对与改前文件 MD5 一致）
- 幻灯片数：45 张，修改前后不变。所有改动都在文字 run 层面完成，没有改动版式、图片、动画。
- 检查：`validate.py --original` 通过；逐部件 XML 规范化对比，只有下列幻灯片/备注页发生变化（`.rels` 与 `[Content_Types].xml` 仅是 python-pptx 重新序列化顺序，内容等价）；改动页用 LibreOffice 重新渲染并与原 PowerPoint 导出的 PDF 对照。
- 提交：已写回原路径并重新用 python-pptx 打开确认能加载、页数 45。该课件旁没有 `~$` 锁文件。
- 说明：下面的页码是当前的 1-based 位置。LibreOffice 会替换字体，所以排版以你 PowerPoint 导出的 PDF 为准。

## 已修改

| 页 | 修改前 → 修改后 | 原因 |
|---|---|---|
| 2 标题 | 标题 top 274639 → 152400 | 与其它页标题位置不一致（标题漂移） |
| 2 备注 | 备注里整段“Mutual exclusion / Hold and wait / ...”重复了两遍，并且 "Res 2" 后缺分号 → 去掉重复的一遍，补上 `;` | 备注重复/杂乱 |
| 7 | “lower-numbered fork before higher-numbered fork (modulo N)” → 去掉 “(modulo N)” | 先小编号后大编号的资源排序并不涉及取模，与 L3 "Semaphore-based Solution III" 的说法一致 |
| 9 | “completed a significant portion of it work” → “of its work” | 笔误 |
| 9 | “processes may not know all resources they will require in advance. ” → “Processes may not know ... in advance” | 首字母大写、去掉与其它要点不一致的句号 |
| 10 | “holds  certain resources” → “holds certain resources” | 双空格 |
| 10 | “Example; all processes requests sem1 before sem2” → “Example: all processes request sem1 before sem2” | 标点与语法 |
| 10 | “Dining Philosopher’s problem” → “Dining Philosophers problem” | 术语（与 L3 一致） |
| 10 备注 | “cannot request resource I and cause deadlock” → “resource 1” | 数字 1 被写成字母 I |
| 13 | RAG 符号说明里 request edge 的 “1” → “i”（即 Pi → Rj） | 与同页其它符号一致，原来写的是 P1 而不是一般的 Pi |
| 14 | “Resource 1 requested by process 2” → “...by process 1”；“Resource 2 held by process 2” → “...held by process 1” | 同一张图里 P2 持有 R1、请求 R2，P1 持有 R2、请求 R1；原标签把 R2 的持有者和 R1 的请求者都写成 process 2，与图矛盾 |
| 18 | “Banker's Algorithm was developed by” → “Banker’s algorithm was developed by” | 弯引号、大小写与全课件统一 |
| 23, 25, 35, 37, 38 | `Banker's Algorithm` / `Banker's algorithm` → `Banker’s algorithm`（弯引号、algorithm 小写） | 术语统一 |
| 25 | “Banker’s algorithm cont’” → “Banker’s algorithm (cont’d)” | 缩写不完整，其它页用 “(cont’d)” |
| 24 | “Repeat steps 1 and 2 until ...” → “Repeat steps 2 and 3 until ...” | 本页第 1 步是计算 Need，循环的是第 2、3 步（找行 → 释放并标记） |
| 34 | “All process can complete successfully. Therefore, the starting state is a safe state” → “All processes can complete ... the new state is a safe state” | 语法；并且这里检查的是假设分配之后的新状态，不是起始状态（slide 33 之前是对新状态做的检查） |
| 35 | “if this request is filled” → “if this request is fulfilled” | 用词 |
| 36 | “(Need)4 = [4, 2, 1, 0] not <= A” → “[4, 2, 0, 1]” | 与 slide 33 一致（Need4 = [4,2,0,1]），原来后两个数字写反了 |
| 40 标题 | “applied to Dinning Philosophers cont’” → “applied to Dining Philosophers (cont’d)” | 拼写 Dinning；缩写 |
| 40 正文 | “philosopher i has left fork numbered i, and right fork (i+1)%5. (Here indices start from 1 instead of 0 in Lecture 3.)” → “...right fork numbered (i % 5) + 1. (Here indices start from 1 instead of 0 in Lecture 3, where the right fork is (i+1)%5.)” | 哲学家和叉子编号为 1-5 时，P5 的右叉子应是 1，(i+1)%5 会得到 0（不存在）。与 L3 的 0-based 写法（左 = i，右 = (i+1)%N）并列写明 |
| 41 | “Philosophers 1-4 each is holding his left fork.” → “Each of philosophers 1-4 is holding his left fork.” | 语法 |
| 44 备注 | “unsafe safe state” → “unsafe state” | 笔误 |
| 45 | “process A sends a request message...” → “Process A ...” | 句首大写 |

### 逐项验算（讲授例题，Banker's 算法，slides 26-36）

数据来自幻灯片文字（矩阵本身是嵌入的 OLE 图片，无法在文件内编辑，我对照文字逐步重算）：

- 起始：E = [10 5 6 5]，Allocation 各列和使 A = [2 3 2 4]（slide 26 的减法算式成立）。
- P2 请求 +2 个 R1、+1 个 R3：A = [0 3 1 4]（slide 28：10-(1+7+2+0)=0，6-(0+2+1+2)=1），与文字一致。
- slide 29：(Need)1 = [2,2,2,1] 的 R1 = 2 > 0，不能执行；slide 30：(Need)2 = [0,0,1,0] ≤ A，运行后 A = [0 3 1 4] + [7 1 2 1] = [7 4 3 5]；slide 31：P1 → [8 4 3 5]；slide 32：P3 → [10 5 4 5]；slide 33：P4 → [10 5 6 5] = E。所有加法正确，安全序列 P2, P1, P3, P4 成立。
- 下一个请求（slide 35-36）：P1 再要 1 个 R3，A = [0 3 0 4]。(Need)1 = [2 2 1 1]（R1 = 2 > 0），(Need)2 = [0 0 1 0]（R3 = 1 > 0），(Need)3 = [1 0 3 0]（R1 = 1 > 0），(Need)4 = [4 2 0 1]（R1 = 4 > 0），无人能完成 → 不安全，拒绝，结论正确（slide 36 原文 Need4 的数字写反了，已改）。
- 哲学家例题（slides 40-42）：4 人各持左叉，A = [0 0 0 0 1]，只有 P4 需求 [0 0 0 0 1] 可运行，释放 R4 后依次 P3, P2, P1, P5，序列 P4, P3, P2, P1, P5 成立；第 5 人也拿左叉后 A = 0，所有人的 Need 非零 → 死锁。

## 已发现但未修改 / 需要你确认

1. **第 10 页 两段信号量代码**：`semaphore sem1, sem2;` 没有初始值。若按 L3 的写法应是 `semaphore sem1 = 1, sem2 = 1;`（互斥锁）。我试过改，但等宽代码框很窄（约 22 个字符），改完会折行溢出，所以撤销了。建议你在 PowerPoint 中手动缩小字号或把框拉宽后再改，或在备注里说明“两个信号量初始值均为 1”。
2. **第 17 页 中间那张 RAG 的标签**：“Deadlock (cycle R3->T2->R2->T3” 与 “And cycle R3->T1->R1->T2->R2->T3” 都没有闭合（缺少 “->R3”，第一句也缺右括号）。我试着补全，但文本框是自动大小的居中框，补上之后会换行并盖到下方图形，所以撤销了。建议把框拉宽后补上 `->R3)`。
3. **第 6 页 与 第 18 页 的术语**：第 6 页把 Banker's 算法列在 “Deadlock detection” 下，第 18 页标题也是 “Banker’s algorithm for deadlock detection”，而本页备注和文字（“avoidance”“look one step ahead”）说的是 deadlock avoidance。严格讲 Banker's 是避免（avoidance），检测只是它的子步骤 CheckSafety。涉及课程框架的措辞，我没有改。
4. **第 13 页 标题 “Symbols”**：内容其实是 System Model 与 Resource-Allocation Graph 的符号。标题和内容不完全对应，可能是想用图例标题；未改。
5. **第 12 页 备注**只有一个 tenor.com 的搜索链接，不是讲解内容。第 17、37、38 页引用的外部链接（uttyler 动画、两个 YouTube 视频）我没有联网核实是否仍然有效。
6. **第 37、38 页 视频教程里的总资源数**（[8, 5, 9, 8] 和 [3, 14, 12, 12]）来自外部视频，无法在此核对。
7. 嵌入的矩阵图片（OLE）不能在文件里编辑；我只核对了与它们配套的文字和算式。

## 观察 / 建议

- 全课件对 Dining Philosophers 的编号：L3 是 0-based（左 = i，右 = (i+1)%N），本讲 slides 40-42 是 1-based（右 = (i%5)+1）。我已在 slide 40 里并列写明。如果想彻底统一，建议改成 L3 的 0-based，但需要重做图片/矩阵，所以没动。
- 结构：先讲四个必要条件、再讲预防（slides 7-12），然后是 RAG（13-17），最后是 Banker's（18-44）。流程清楚。slide 15、16 只有图片，建议在备注里补一句想表达的要点。
- 内容缺口：没有专门一页总结“预防 / 避免 / 检测与恢复”三类处理方式的对比；Banker's 算法只讲了安全性检查和请求检查，没有给出复杂度（O(m·n²)）。可以作为可选补充。
