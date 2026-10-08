# L6-RTScheduling II.pptx 审计记录

范围：56 页（含备注、表格、数学公式）。修改只在 run 级别进行，未增删或重排幻灯片。原件备份：`PPTs/bak/audit-20261007/L6-RTScheduling II.pptx`。页码为当前 1 起始位置。

验证流程：validate.py（--original）通过；逐 part c14n 对比，变化的幻灯片恰为 5、6、7、9、11、12、22、25、27、30、34、36、37、39、41、47、49、51、52、53 页，备注恰为 12、19、20、22、23、27、29、54、55 页（.rels 与 [Content_Types].xml 仅序列化顺序不同，语义一致）；重渲染第 5、12、30、47 页目视确认（LibreOffice 对公式使用过期 fallback 图片，公式以 XML 文本为准）；写回后用 python-pptx 重新打开，页数仍为 56。该文件无 `~$` 锁文件。

## 已修改

| 页 | 修改前 → 修改后 | 原因 |
|---|---|---|
| 5、6、7、12 | 标题框位置恢复到统一位置（x=104pt, y=12pt, w=752pt） | 与其他页相比标题左移/变宽 |
| 9 | "scheduling theory are applicable" → "theory is applicable" | 主谓一致 |
| 11 | ”bins” → “bins”；”full” → “full”；"a NP-complete" → "an NP-complete" | 引号方向、冠词 |
| 22 | "𝑇>1 is some constant value" → "𝑇≥2" | 轻任务 Ci=1、Ti=Di=T−1，需 T−1 ≥ 1，T>1 允许 T=1.5（此时 T−1<C） |
| 25 | "experiences inference" → "experiences interference" | 拼写 |
| 27 | "Rc=12>Dc=10" → "Rc=12>Dc=11" | Tc=Dc=11（第一个作业截止期在 11，第二个作业为 12>Dc=11，同页后文也是 Dc=11） |
| 30 | 时间轴标签 "0 2 2 4 6 …" 中重复的 "2"（x=312pt）→ "3" | 位置恰在 2 与 4 之间，且文字使用 t=3 |
| 34 | "then starts working again" → "start"；"cannot pre-empt" → "cannot preempt" | 语法、拼写一致 |
| 36、51 | "It prevents priority inversion" → "It prevents unbounded priority inversion"（36 页 PIP，51 页 PCP） | 准确性：PIP/PCP 只是把优先级反转限制为有界，并不消除 |
| 37 | "Task τi is blocked for … min(3,3)=3 critical sections" → "Task τ1 …" | 示例是具体任务（最高优先级任务），不是泛指 τi |
| 39 | "Cs = max{P1, P2} = P1" → "max{P1, P3} = P1" | 该例的两个任务是 τ1、τ3（参见第 30 页），P2 与此例无关 |
| 41 | "τ2¨will enter" → "τ2 will enter" | 多余字符 |
| 47 | 公式 "C(s2)=max{P2,P3}=2" → "max{P1,P2}=2"；任务表 sems 列：τ1 "S1"、τ2 "s1, s2"、τ3 "s2" → τ1 "s1, s2"、τ2 "s2"、τ3 "s1"；上限表 s2 的 3 → 2 | 依据图与正文：τ2 持有 s2 时 τ3 可锁 s1（P3=3>C(s2)=2），τ1 因 P1=2≤C(s2)=2 被拒；故 s2 的使用者是 τ1、τ2，C(s2)=max{2,1}=2，C(s1)=max{P1,P3}=max{2,3}=3 不变。原表与公式互相矛盾 |
| 49 | "P3=3 ≤ C(s1)=3" → "C(s2)=3" | 阻止 τ3 的是被 τ2 持有的 s2 的上限 |
| 52 | "Pi = Di"、"period Pi" → "Ti"（两处）；"L6-RT Scheduling I" → "L6-RTScheduling I" | P 在第 39-49 页表示优先级；文件名无空格 |
| 53 | "schdulability" → "schedulability" | 拼写 |
| 备注 12 | 删除两段重复的 "greedy" 段落；”greedy” → “greedy”；"assumtion" → "assumption" | 重复、引号、拼写 |
| 备注 19 | "ot feasible" → "Not feasible" | 残词 |
| 备注 20 | "Not feasible for partitioned scheduling, since any two tasks’ combined utilization will exceed 1." → "Not feasible for global scheduling: U=2.0 on 2 processors leaves no slack, so any idle interval makes the taskset unschedulable." | 原句抄自第 19 页，与第 20 页相反（此页 partitioned 可行、global 不可行）；验证 4/6+7/12+4/12+10/24 = 16/24+14/24+8/24+10/24 = 48/24 = 2.0 |
| 备注 22 | 原为第 21 页备注的复制 → 改写为 Dhall 效应说明 | 备注与本页无关；轻任务在 [0,1] 占满 m 个处理器，重任务 t=1 才开始，完成于 T+1 > T，总利用率 m/(T−1)+1 随 T 增大趋近 1 |
| 备注 23 | 补全两个残句 | 残句 |
| 备注 27 | "critical instant" / "it arrives at the same time …" 两个残句 → 一句完整说明 | 数值依据本页：第 1 个作业 7+3=10，第 2 个 7+5=12 |
| 备注 29 | 删除重复句 "Examples of common resources …" | 重复 |
| 备注 54 | "cccc" → "Critical sections associated with semaphores s1, s2 and s3"；A/B/C → "Task 1 (A)/Task 2 (B)/Task 3 (C)" | 乱码；对应关系与本页一致（A 锁 s1；B 锁 s2、s3；C 锁 s3、s2） |
| 备注 55 | "Cccc" → "Critical sections" | 乱码 |

### 数值示例的验证计算
- 第 53 页：U = 5/50+250/500+1000/3000 = 0.1+0.5+0.333 = 0.933 > 0.780；R2：250 → 250+⌈250/50⌉·5 = 275 → 280 → 280 ≤ 500；R3：1000+⌈2500/50⌉·5+⌈2500/500⌉·250 = 1000+250+1250 = 2500 ≤ 3000。
- 第 54 页：B2 = max{3,4} = 4；U2 = 5/50+(250+4)/500 = 0.1+0.508 = 0.608 ≤ 0.828；R2：254 → 254+⌈254/50⌉·5 = 284 → 284，≤ 500。
- 第 55 页：B1 = max(2,5,3,4) = 5；U1 = (5+5)/50 = 0.2；R1 = 5+5 = 10 ≤ 50。
- 第 25-27 页异常示例：第 27 页 Rc = 12，第 2 个作业 7+5 = 12，完成于 11+12 = 23，错过截止期 22，与文字一致。

## 已发现但未修改 / 需要你确认
1. 第 31/32 页（t=4.2 与 t=98.5）：场景一 C2=95.8、临界区长度 4.2；场景二 C2=95.5、长度 4.5，二者差 0.3。把 4.2 改为 4.5，或把 98.5 改为 98.8 均可消除不一致，需作者决定。
2. 第 47/48 页：第 47 页已按图与正文修正；第 48 页的图（τ1→s1,s2；τ2→s2；τ3→s1）与它自己的表（τ1:s1；τ2:s2；τ3:s1,s2）和上限（3,3）互相冲突，意图不明，未改。第 49 页的表与正文（τ3 使用 s1 和 s2）一致。
3. 第 47-49 页优先级约定（τ3 最高）与第 39-42 页（P1 最高）相反，建议统一或在页面中说明。
4. 第 5-7 页标题与正文占位符互换，第 8 页要点放在标题占位符里，导致大纲视图异常；涉及改动占位符，未动。
5. 第 11 页：由 bin-packing 是 NP-complete 推出分区调度 NP-complete 的论述较松，"best-fit / worst-fit" 被写成目标函数，其实是启发式。
6. 第 20 页：文本框贴近标题下划线并挤压下一条要点。
7. 第 32 页备注使用 A/B 命名；第 42 页备注有残句；第 21 页与原第 22 页备注曾重复（22 页已替换）；第 29 页备注 5 为残句；第 55 页备注 A/B/C 沿用第 54 页（Task 1 在第 55 页还使用 s2、s3），与本页不完全对应。
8. 第 56 页备注署名 Srinivas YouTube；第 56 页是最后一页，没有总结页或参考文献页。
9. 第 4 页标题 "Multiprocessor models" 与第 5-7 页 "Multiprocessor Models" 大小写不一致，未改。

## 观察 / 建议
- 建议在 Part II 末尾增加一页总结（全局 vs 分区、Dhall 效应、PIP vs PCP 的取舍）和参考文献页。
- 全篇统一符号：T 为周期、P 为优先级，并统一优先级大小约定。
- 第 22 页建议在备注中保留 Dhall 效应的推导，以便口头讲解。
