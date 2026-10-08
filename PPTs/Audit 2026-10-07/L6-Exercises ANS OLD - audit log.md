# L6-Exercises ANS OLD.pptx 审计记录（只读审计，未修改）

**本文件没有被修改**：device 上的文件大小仍是 1382422 字节，MD5 3a620de0993a327aa7015c7242256c83，与审计开始时完全相同；也没有写入 `audit-work/`。以下是与当前 `L6-Exercises ANS.pptx`（35 页）的比较，OLD 为 32 页。

## 结论

**OLD 是当前 ANS 的旧草稿，差异是实质性的（题目与答案都不同、页数少 3 页），但当前版本已经覆盖并修正了 OLD 的全部内容，看起来可以安全退休。** 唯一的前提是：如果你还想保留 OLD 里 Q5 那个"任务 C 也用 s1"的变体题，需要先另存。

## 差异清单（OLD → 当前）

1. **页数/题序**：OLD 的最后三个题目页（第 30–32 页）标题是 "Q4 / Q5 / Q6 Schedulability with Shared Resources"，其中 "Q5" 与前面已有的 Q5（Task A–H）题号重复，并且这三题都没有答案页。当前版本改为 Q6/Q7/Q8，每题后面都有 ANS 页（第 31、33、35 页），所以多了 3 页。
2. **Q5 题目表（OLD 第 19 页）**：任务 C 的 sems 为 "s1"、CS Len 为 "30"；当前版本 C 为 "/"（不用信号量）。OLD 自身不一致：它的答案页（第 20 页）里任务 C 又是 "/ /"，而同一页的 ceiling 表写 s1 = 6，下一页（第 21 页）的 ceiling 表却写 s1 = 5。当前版本统一为 C 不用 s1、Cs1 = 5。
3. **Q1（OLD 第 2 页）**：缺逗号 "WCET Ci Period Ti"（当前已改为 "Ci, Period Ti"）。
4. **Q1 第 3 题（OLD 第 5 页）**：没有 "For RM:" / "For EDF:" 的标签；当前已加。
5. **Q2（OLD 第 11 页）**：写成 "0.75 ≤ 0.780 (UB for 2 tasks under RM)"，数值 0.780 是对的（3 任务），但 "2 tasks" 写错；当前版本这一页我改成了 "0.780 (UB for 3 tasks under RM)"（原先当前版本写的是 0.828，两个版本各错一半）。
6. **PCP 阻塞说明（OLD 第 17 页）**：OLD 写 "Note: this formula applies only when task i requests some semaphore. If task i does not require any semaphores itself, then it does not experience any blocking time, i.e., Bi = 0."，这在技术上是错的（不用信号量的中间优先级任务仍会有 push-through blocking，OLD 自己 Q6 的 τ2 就是例子）；当前版本已改为正确说法 "The blocking time is valid even for a task that does not require any semaphores/critical sections, as it may experience push-through blocking."
7. **措辞**：OLD 第 22 页 "Task D has a CS with length 3, associated with s4"，当前改为 "cs(D, s4)=3 means that Task D has a CS …"。
8. 其余 Q1–Q3、Q5 Task A–H 的数值与当前版本一致（我对照了文本导出，没有发现数值差异）。

## 已发现但未修改

- 由于不改 OLD，上面各项都不在 OLD 里修正；如果最终不删除 OLD，请注意它含有 PCP 的错误说法（第 6 项）和 Q5 的自相矛盾（第 2 项）。
- 当前 ANS 里的新问题（第 19 页答案泄露、Q7/Q8 题干等）在 OLD 里没有出现过（OLD 的 Q5 题目页 B/R 是空的），不是 OLD 的遗留。
