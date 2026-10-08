# L8-Memory System II Paging.pptx 审查记录

- 文件：`PPTs/L8-Memory System II Paging.pptx`（75 张，修改后仍为 75 张）
- 原件备份：`PPTs/bak/audit-20261007/`
- 修改方式：只改 run 文本（python-pptx），再把仅有文本差异的 slide/notes XML 部分写回原包，其余所有部分（含 rels、[Content_Types].xml、媒体）与原件逐字节相同。
- 共 18 处文字修改（15 处在 12 张幻灯片上，3 处在备注里）；未修改但标记的项见第二节。

- 验证（三个 deck 相同）：`validate.py --original` 通过；逐部分 canonical XML（lxml c14n）比较，只有上述 slide（及备注/母版）XML 有差异，其余部分字节相同；改动过的页已重新渲染并查看；提交到原路径后用 python-pptx 重新打开，页数和可加载性已确认。

## 一、已修改

幻灯片编号为当前 1-based 位置。

| # | 位置 | 修改前 → 修改后 | 理由 |
|---|------|----------------|------|
| 2 | Outline 列表 | `Table Lookaside Buffer (TLB)` → `Translation Lookaside Buffer (TLB)` | 正确名称是 Translation（s31 已写对，全 deck 术语统一） |
| 6 | 文本框 "Virtual Address Space consists of 8 x 4K Byte pages, or ..." | `16768 Bytes` → `32768 Bytes` | 计算：8 × 4 KB = 8 × 4096 = 32768 B。16768 不是 8×4096；也不是 16384。原值是数值错误 |
| 11 | Page Translation Mechanism 首句 | `(# virtual pages ≥ # physical page)` → `(# virtual pages ≥ # physical pages)` | 单复数 |
| 26 | Inverted Page Table，"To translate a Virtual Address…" | `current process ID and the the VPN` → `current process ID and the VPN` | 重复 "the"（删除多余的第一个 run 末尾 "the "，保留第二个 run） |
| 26 | 同上，"Processors that use IPT" | `Itel IA-64 (Itanium)` → `Intel IA-64 (Itanium)` | 拼写 |
| 26 | 同上 | `Each PTE contain the pair <process ID, VPN>.` → `Each PTE contains the pair ...` | 主谓一致 |
| 31 | TLB 介绍，"TLB hit:" 行 | `VPN is in cached in TLB, hence …` → `VPN is cached in TLB, hence …` | "in" 多余（删除 'in' 及其后空格 run） |
| 32 | TLB is a Type of Cache | `(e.g.128-512 entries)` → `(e.g., 128-512 entries)` | 缺逗号和空格 |
| 38 | 标题 | `Table Lookaside Buffer (TLB)` → `Translation Lookaside Buffer (TLB)` | 术语 |
| 45 | 标题 | `Outlines` → `Outline` | 与 s2 的 "Outline" 一致。注意：s45 是隐藏幻灯片（见第二节） |
| 45 | 列表第一项 | `Table Lookaside Buffer (TLB)` → `Translation Lookaside Buffer (TLB)` | 术语 |
| 48 | Smaller Page Table | `Problem: Internal fragment` → `Problem: Internal fragmentation` | 术语完整 |
| 65 | Example 1 | `since A is references again right away` → `since A is referenced again right away` | 语法 |
| 69 | 标题 | `BeLady’s anomaly` → `Belady’s anomaly` | 人名大小写（s68、备注已写 Belady’s） |
| 74 | Summary | `Table Lookaside Buffer (TLB) for slow access` → `Translation Lookaside Buffer (TLB) for slow access` | 术语 |
| 备注 12 | | `physocal` → `physical` | 拼写 |
| 备注 28 | | `n computing, the prefix "0x"…` → `In computing, the prefix "0x"…` | 首字母丢失 |
| 备注 46 | | `Problem: verhead is too high…` → `Problem: Overhead is too high…` | 首字母丢失 |

### 重新计算过、结果正确（未改动）
- s12：32 位虚拟地址、4 KB 页 → 偏移 12 位，VPN = 32−12 = 20 位；物理地址 29 位（2^29 = 0.5 GB）→ PPN = 29−12 = 17 位。正确。
- s25：2^32/2^12 = 2^20 页；PTE 4 B → 4 MB/进程；50 进程 = 200 MB。正确。s47：100 进程 = 400 MB 正确。
- s26 倒排页表示例：表项 (pid,VPN) 依次为 (1,1)(1,2)(2,0)(2,1)(1,0)(2,2)；pid=1,VPN=2 的索引为 1 → PPN=1，与图及前向页表一致；pid=1,VPN=6 无匹配 → page fault。正确。
- s30：16 位地址、4 KB 页 → VPN = 16−12 = 4 位。正确。
- s41：EAT = (m+s)h + (2m+s)(1−h) = (m+s)h + (2m+s) − (2m+s)h = 2m + s − m·h。正确。
- s48：32 位地址、16 KB 页 → 2^32/2^14 = 2^18 项 × 4 B = 1 MB，是 4 MB 的 1/4，"reduce by 4x" 正确。
- s52：30 位地址、512 B 页 → 偏移 9 位、VPN 21 位；每页可放 512/4 = 128 = 2^7 个 PTE → 21/7 = 3 级。与幻灯片一致。
- s65–s69 页面置换（用独立脚本重新模拟）：
  - `A B C A B D A D B C B`，3 帧：FIFO 7、LRU 5、OPT 5。
  - `A B C D A B C D A B C D`，3 帧：FIFO 12、LRU 12、OPT 6。
  - `A A B B C D B A B A`，3 帧：FIFO 6、LRU 5、OPT 4。
  - `A B C D A B E A B C D E`：3 帧 FIFO 9，4 帧 FIFO 10（Belady 异常成立）。
  - 表格逐列与模拟一致。

## 二、已发现但未修改 / 需要你确认

1. **s45 是隐藏幻灯片**（`show="0"`）。中途 Outline 不在放映和 PDF 导出中。该页列出 Translation Lookaside Buffer、Multi-level TLB、Inverted page table、Page swapping、Page replacement policy，与 s2 的 Outline（Paging / Page Translation / Page Table / TLB / Multi-level paging / Page Swapping / Page Replacement）不完全一致（s2 没有 Inverted page table，s45 没有 Multi-level paging）。请确认是否保持隐藏，以及两份大纲是否要对齐。
2. **s6 备注是旧例子**：备注写 "6-bit memory address, 2^6 = 64 Bytes, page size 16 bytes, 4 pages"，但幻灯片是 4 KB 页、8 个页。备注与幻灯片不符，建议改写或删除（未改，因为可能是你的讲稿）。
3. **s12 备注与幻灯片不符**：备注 "Physical memory 2GB … 2GB/4KB = 2^19 … page number is 19 bits"（内部计算正确），但幻灯片是 29 位物理地址 = 0.5 GB、PPN 17 位。只改了拼写；请确认以哪个为准。
4. **s63** 写 "The page table itself is designed to fit within one memory page (e.g., 4 KB), so table lookup is easy"，与 s25（线性页表 4 MB/进程）、s47（页表太大）矛盾。可能是对教学例子（s35–s40 的 "page table is stored within one physical memory page"）的简化，但作为一般陈述不准确。建议改为 "In our simplified example …" 之类。
5. **s33** "TLB is write-through (not write-back)" 与 s42 "TLB entries have valid bits and dirty bits"（脏位在 TLB 中被修改，之后写回 PTE）在术语上有张力；不同教材说法不同，未改，请确认你想表达的意思。
6. **s47** `2 ^ (32-log(4KB)) * 4` 中的 `log` 应为 log₂；结果 4 MB 正确。未改（需要在文本中引入下标/说明）。
7. **s21、s23 备注**：粘贴了整段 Perplexity 回答（含 Markdown 的 `###`、`**`、表格竖线和约 33 条引用网址，末尾 "Answer from Perplexity: pplx.ai/share"）。不属于乱码所以未替换，但它们作为讲稿很难读，且引用里有无关链接（例如 help.x.com、xbitdcm）。建议清理，并注意引用来源/署名。
8. **s74 备注** "Scheduler is an important topic in OS / CFS 17,900 lines of code" 与本讲（分页）无关，疑似从 L5 复制遗留。
9. **s26 字体很小**（渲染时约 10 pt，列表很密），投影时可读性差；未改（会涉及版式）。
10. **s11** 图中 "Offset"/"offset" 在 LibreOffice 渲染中折行成 "Offse/t"，应是字体替换造成（Comic Sans 缺失），不一定是真实缺陷，请在 PowerPoint 里看一眼。
11. 与 PDF：同目录的 `L8-Memory System II Paging.pdf` 是旧导出，未改动，里面仍是旧文字（如 16768 Bytes、Table Lookaside Buffer）。需要的话请重新导出。
12. 课程代码/学期：标题页为 "CSC 112"，未发现遗留的 CSC256 或旧学期。

## 三、观察 / 建议

- 全 deck 里除上述 5 处外，TLB 的全称都已写对（s31、s44）。
- 参考页 s75 的 YouTube 链接都是第三方内容，请确认引用时署名方式；s28 的 EZCSE 视频同理。
- 我只检查了 PowerPoint 内容；Comic Sans MS 以外的渲染差异不作为缺陷。
