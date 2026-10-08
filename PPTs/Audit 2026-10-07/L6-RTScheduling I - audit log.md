# L6-RTScheduling I.pptx 审计记录

范围：65 页（含备注、表格、数学公式，公式位于 mc:AlternateContent 内，已逐一读取）。修改只在 run 级别进行，未增删或重排幻灯片。原件备份：`PPTs/bak/audit-20261007/L6-RTScheduling I.pptx`。页码为当前 1 起始位置。

验证流程：validate.py（--original）通过；逐 part 做 c14n 对比，变化的幻灯片恰为下表所列 24 页，备注恰为 18、19、46、53、63 页（.rels 与 [Content_Types].xml 仅因 python-pptx 重新序列化而顺序/Default→Override 不同，语义一致）；重渲染第 6、12、17、32、39、45、46 页目视确认；写回后重新用 python-pptx 打开，页数仍为 65。注意：LibreOffice 渲染使用过期的 fallback 图片显示公式，所以公式修改以 XML 文本为准，未在 LO 渲染中体现。该文件无 `~$` 锁文件。

## 已修改

| 页 | 修改前 → 修改后 | 原因 |
|---|---|---|
| 4 | "co´nsists" → "consists" | 多余重音符 |
| 6 | "visual−based navigation"（U+2212）→ "visual-based navigation"；该文本框加宽 20pt（左移 10pt） | 减号误用；导出 PDF 中折行为 "visual-base / d" |
| 6、17 | 标题框位置恢复为统一位置（x=104pt, y=12pt, w=752pt） | 标题位置偏移（原 x=97/86pt） |
| 7 | "is not a necessarily a real fast system" → "is not necessarily a fast system" | 语法 |
| 12 | 标题 "Nonpreemptive" → "Non-Preemptive" | 与大纲及第 60-61 页写法一致 |
| 13 | "Quality-of-Service(QoS)" → "Quality-of-Service (QoS)" | 缺空格 |
| 19 | 作业序列 "τi,1, τi,1, …, τi,k" → "τi,1, τi,2, …, τi,k" | 下标重复 |
| 23 | "Left upper:" / "Left lower:" → "Upper right:" / "Lower right:" | 图在文字右侧 |
| 26 | "Online scheduling;" → "Online scheduling" | 多余分号 |
| 27 | "hyperperiod" → "hyper-period" | 与同页第一条一致 |
| 29 | 标题 "Fixed Priority Scheduling" → "Fixed-Priority Scheduling" | 连字符，与章节标题一致 |
| 30 | "RMS priority assignment" → "RM priority assignment" | 全篇使用 RM |
| 31 | "Taui" → "τi" | 符号 |
| 32 | 假设中 "Pi = Di"、"period Pi" → "Ti = Di"、"period Ti"；表格 "inf" → "∞" | P 在 Part II 表示优先级，周期统一用 T；"inf" 在单元格内折成 "in/f" |
| 33 | "WCET Ci Period Ti, Deadline Di" → "WCET Ci, period Ti, and deadline Di" | 标点/大小写 |
| 36 | "3 task with" → "3 tasks with" | 语法 |
| 39、45 | 删除覆盖在迭代列表上的多余文本框 "0"（x=131pt, y=260pt） | 残留坐标轴标签，压在 "Iteration" 行上 |
| 45 | 第二个 "Iteration 1" → "Iteration 2" | 标签重复 |
| 46 | "R2 … =2>D1=1" → "=2>D2=1"；"since task periods are equal" → "since task deadlines are equal" | R2 应与 D2 比较；这是 DM 页，依据应为截止期相同（本例周期也相同） |
| 51 | "Pi = Di" → "Ti = Di" | 同第 32 页 |
| 53 | "Lateless" → "Lateness"；"i. e.," → "i.e.," | 拼写 |
| 55 | "schedulabiity" → "schedulability" | 拼写 |
| 58 | "Your must give" → "You must give" | 拼写 |
| 61 | "Less context switches" → "Fewer context switches" | 可数名词 |
| 备注 18 | 公式 "(tk – ak) – (fk-1 – ak-1)" → "(fk – ak) – …" | 完工时间抖动应为 fk-ak（"t" 为笔误） |
| 备注 19 | "τ1,s" → "τ1,2" | 笔误 |
| 备注 46、53 | 46 页备注中的 "Overhead: EDF …" 与 "Overrun behavior (U > 1) …" 两段移到 53 页备注 | 属于 RM/EDF 比较，与 DM 页无关；53 页备注原来只有残句 |
| 备注 63 | 重复句 "Non preemption reduces schedulability (…); Non preemption reduces …" 合并为一句 | 重复 |

### 数值示例的验证计算（未发现需要改数值的错误）
- 第 33-39、45 页任务集 (C,T,D) = (10,30,30)、(10,40,40)、(12,52,52)：U = 10/30+10/40+12/52 = 0.333+0.25+0.231 = 0.814 > 0.780（n=3 的 RM 界），所以需要 RTA。R3：12 → 12+⌈12/30⌉10+⌈12/40⌉10 = 32 → 12+2·10+1·10 = 42 → 12+2·10+2·10 = 52 → 52，收敛，52 ≤ D3 = 52，可调度。
- 第 45 页 C2=20：R3：12 → 42 → 12+2·10+2·20 = 72 → 12+3·10+2·20 = 82 → 12+3·10+3·20 = 102 …… 发散，与幻灯片一致（Iteration 1/2/3/4 = 42/72/82/102）。
- 第 46 页：R2 = 1+⌈R2/2⌉·1，R2=2 时 1+1=2 > D2=1，不可调度。
- 利用率界 n(2^{1/n}−1)：0.828、0.780、0.757、0.743、0.718、0.693 表中数值均正确。

## 已发现但未修改 / 需要你确认
1. 第 3 页：标题占位符为空（"标题 3"）；第 28、48、57、60 页（节分隔页）没有标题占位符，导航/大纲视图中不会显示。
2. 第 14 页用 a_i 表示释放时刻，第 19、24 页用 r_i，建议统一。
3. 第 50 页备注称 "not widely used in the auto industry, we will not consider it further"，与第 49-56 页继续讲解该内容矛盾，备注可能过期。
4. 第 52 页备注引用 "L6-Exercises ANS.pptx p7"，需确认页码仍然正确；该页表格与图的右上角重叠。
5. 第 54 页图片右下角被裁切，残留 "12" 字样。
6. 第 64 页备注是过期的结论文字（"TimeSys/Tripac"），应属于最后一页。
7. 第 7 页备注开头残句 " response time of a task set."；第 53 页备注残句 "Not transient overload // This occurs"（现与移入的两段共存）。
8. 无参考文献页：致谢只列出 Buttazzo，但课件使用了 Wolf 视频、Cervin 2003、Dertouzos 等。
9. 第 43、44 页：T3 的剩余执行矩形约 39pt 宽（2 个单位应约 24pt），刻度位置不精确（仅外观问题，未动）。
10. 第 65 页 URL 未联网验证。
11. 第 40-44、52 页标题框刻意变窄以给右侧表格让位，未当作偏移处理。
12. LibreOffice 渲染下第 56、59 页出现嵌套表格递归显示，用户导出的 PDF 正常，判断为渲染器问题。

## 观察 / 建议
- 建议在结尾增加参考文献页，并把第 64 页备注的结论内容放到总结页。
- 符号：周期 T、优先级 P、释放时刻 r 与 a 的用法应在课件首次出现处统一定义。
- 空标题占位符及节分隔页缺少标题会影响导航与无障碍。
