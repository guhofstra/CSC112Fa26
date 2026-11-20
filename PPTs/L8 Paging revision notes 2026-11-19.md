# L8 Paging 两份 PPT 修订记录（2026-11-19）

原文件备份：`PPTs/bak/L8-Memory System II Paging (before revision 2026-11-19).pptx`、`PPTs/bak/L8-Exercises ANS (before HW8 2026-11-19).pptx`

## 一、L8-Memory System II Paging.pptx

### 技术错误修正（按原幻灯片编号）

| 原页 | 问题 | 修改 |
|---|---|---|
| 30, 35–40 | 页表起始物理地址写成 0x200C。0x200C 其实是 VPN 3 的 PTE 地址（0x2000 + 3×4）。S40 访问 VPN 2 时又写成 load 0x200C (PT)，这是错的 | 改为“页表起始 0x2000（PFN 2），PTE[3] 在 0x200C”；S40 第二次读页表改为 **load 0x2008 (PT)** |
| 31 | 说 TLB “should be small enough to fit in CPU cache” | TLB 是 MMU 内独立的硬件缓存，不放在 L1/L2 数据 cache 里 |
| 32 | 说 TLB “can fit within cache (L1 or L2)”；cache 按“memory address granularity”存储 | 改为 cache 按块（如 64 B）存储；补充 TLB reach = 条目数 × 页大小 |
| 33 | “TLB is write-through”；“miss penalty 是一次内存访问” | miss 代价是一次页表遍历（每级一次访存）；A/D 位更新写回 PTE；OS 修改 PTE 后必须失效 TLB 条目（invlpg / TLB shootdown） |
| 10 | 页表“Part of PCB” | 每个进程一张页表，存放在内存中；PCB 只存指向它的指针（xv6：struct proc 的 pagetable 字段） |
| 4 | “Kernel accesses physical memory directly without translation” | 只有部分 CPU 允许内核绕过地址转换；Linux/xv6 内核同样使用虚拟地址 |
| 22–23 | 暗示全局/静态数据默认在进程间共享；把“共享库的可写数据”当作共享例子 | 全局变量默认是进程私有的（fork 后为 copy-on-write），只有显式使用 shm_open/mmap(MAP_SHARED) 才共享；共享库共享的是代码，可写数据每个进程各有一份 |
| 26 | 倒排页表优点写成“Scales better with large physical memories” | 改为：表大小与物理内存成正比，与虚拟地址空间大小和进程数无关（适合 64 位）；缺点补充 hashed IPT |
| 53 | “XV6-Sv48 – 4 level” | xv6 只用 Sv39（3 级）；Sv48 和 x86-64 是 4 级 |
| 55 | “total **physical** address space of all processes” 超过物理内存 | 改为 virtual memory |
| 57 | Present bit = 0 表示 “in-disk” | 0 表示不在内存中（在磁盘上，或从未分配） |
| 63 | “页表本身设计成放进一页（4 KB）” | 错误（32 位线性页表就有 4 MB）；改为“用 VPN 直接索引页表，无需比较 tag” |
| 6、12 备注 | 备注里的数字与幻灯片不符（6-bit 例子、2 GB / 19-bit PPN） | 改为与幻灯片一致（32 KB 地址空间；0.5 GB / 17-bit PPN） |
| 6 | 未映射的页一律“go to disk” | 改为：只有地址合法时，OS 才从磁盘调入该页 |
| 9 | cache 块大小举例 8 Bytes | 改为 64 Bytes |
| 48 | “16KB for MacOS” | Apple-silicon Mac 为 16 KB，x86 Linux/Windows 为 4 KB |
| 54 | SSD 500 MB/s | 0.5–7 GB/s（SATA–NVMe） |
| 64、65、68 | LRU 优缺点表述；“page not referenced farthest in the future”；页面错误“should go down” | 改写为准确的表述（LRU 精确实现代价高，用 Clock 近似；“下一次引用最远”；“通常会下降”） |

已用代码逐一核对：全部页面置换表格（Example 1–3、Belady 3/4 帧）、EAT 公式、各处地址位数与页表大小，均正确。

### 结构与可读性
- 新顺序共 6 个部分，每部分前有一页 Outline，当前部分以蓝色高亮：① 分页与地址转换 → ② 每进程页表、保护与共享 → ③ TLB → ④ 更小的页表（多级、倒排）→ ⑤ 按需调页与换页 → ⑥ 页面置换。
- “Steps in Handling Page Faults”（原 S7）移到换页部分；“Main Memory as Cache for Disk”（原 S63）移到 Demand Paging 之后；“Putting It Together”三页移到多级页表和倒排页表之后。
- 原 S44 是课件中间的一页 Summary，内容并入最后的 Summary 后隐藏（未删除）。
- 重写了文字过密的页（S21、S23、S25、S26、S30、S33、S41、S42、S47、S49、S52、S63、S74）；S21、S23 备注中从 Perplexity 粘贴的大段文字和引用链接换成了简明备注。
- S41 加入 EAT 数值例子：m = 100 ns，σ = 20 ns，η = 0.98 → 122 ns（无 TLB 时为 200 ns）。
- S52 补充 3 级页表的推导：offset 9 位、VPN 21 位、每页 128 个 PTE → 每级 7 位 → 3 级。
- 统一了标题（如 S38 改为 TLB Example，S68 改为 Page Faults vs. Number of Frames，Putting It Together 系列）。

## 二、L8-Exercises ANS.pptx

把 HW8 的 4 道题并入题库，并按讲课顺序重新编号（共 17 页）：

| 新题号 | 内容 | 来源 |
|---|---|---|
| Q1 | 32 位 ISA + 8 GB 内存，虚拟内存有何作用（答案 D） | HW8 Q1（新增） |
| Q2 | VPN 位数多于 PPN 位数意味着什么（答案 C） | HW8 Q2（新增） |
| Q3 | Page sizing A/B/C（题目页 + 答案表格页） | HW8 Q3（新增） |
| Q4 | 地址转换 | 原 Q5 |
| Q5、Q6 | 倒排页表 | 原 Q1、Q2 |
| Q7 | 多级页表 | 原 Q6 |
| Q8 | 访存次数与 TLB（“previous question” 仍指 Q7，引用不变） | 原 Q7 |
| Q9 | TLB reach | HW8 Q4（新增） |
| Q10 | 工作集、TLB 与抖动 | 原 Q8 |
| Q11、Q12 | 页面置换（含答案和参考视频） | 原 Q3、Q4 |

- HW8 答案中的数字全部用代码核对过。顺手修正了原答案里的拼写 “SanyBridge” → Sandy Bridge，并把 “2.3 MB” 写成精确值 (512+64)×4 KB = 2,304 KB ≈ 2.25 MB。
- Q1、Q2 的解释比原 HW8 更完整（例如说明需要超过 32 位的物理地址，如 x86 PAE）。
- 新页没有使用 HW8 原件的署名和页眉。
