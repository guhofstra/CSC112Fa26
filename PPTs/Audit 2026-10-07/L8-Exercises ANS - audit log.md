# L8-Exercises ANS — 审核日志

**范围**:12 页 + 备注。

原文件备份:`PPTs/bak/audit-20261007/`。写回方式:仅把变更过的 slideN.xml / notesSlideN.xml 部分移植进原 zip(其余字节不变),`validate.py --original` 通过,c14n 比较确认只有预期部分变化,变更页已用 LibreOffice 重新渲染并目视检查。写回后在设备上重新用 python-pptx 打开确认页数与 sha256。该 deck 旁没有 `~$` 锁文件。

## 已修改

共 27 条 run 级编辑(逐条列于下表;只改 run 文本,未改幻灯片数量/顺序/图片/样式)。

| 幻灯片 | 位置 | 修改前 | 修改后 | 原因 |
|---|---|---|---|---|
| 4 | 正文 / Title 1 | Q1. Page Replacement | Q3. Page Replacement | duplicate Q numbering |
| 5 | 正文 / Title 1 | Q1. Page Replacement ANS | Q3. Page Replacement ANS | duplicate Q numbering |
| 6 | 正文 / Title 1 | Q2. Page Replacement | Q4. Page Replacement | duplicate Q numbering |
| 7 | 正文 / Title 1 | Q2. Page Replacement ANS | Q4. Page Replacement ANS | duplicate Q numbering |
| 8 | 正文 / Title 1 | Q2. Page Replacement References | Q4. Page Replacement References | duplicate Q numbering |
| 9 | 正文 / Title 1 | Q. Paging | Q5. Paging: Address Translation | duplicate title |
| 10 | 正文 / Title 1 | Q. Paging | Q6. Paging: Multi-level Page Table | duplicate title |
| 11 | 正文 / Title 1 | Q. Paging | Q7. Paging: Memory Accesses and TLB | duplicate title |
| 12 | 正文 / Title 1 | Q. Paging | Q8. Paging: Working Set, TLB and Thrashing | duplicate title |
| 5 | 正文 / TextBox 5 | (When referencing 4 and 6, you can replace any page, as long it page 1 is not replaced, since only it will be referenced again in the future) | (When referencing 4 and 6, you can replace any page, as long as page 1 is not replaced, since only it will be referenced again in the future) | typo |
| 9 | 正文 / Content Placeholder 2 | virtual memory address | virtual memory addresses | two addresses asked |
| 9 | 正文 / Content Placeholder 2 | 0xF74, 0x374? | 0xF74 and 0x374? | two addresses asked |
| 9 | 正文 / Content Placeholder 2 | Entry for VPN 00 (0 in decimal): Valid bit = 0. | Entry for VPN 00 (0 in decimal): Valid bit = 0, | punctuation |
| 9 | 正文 / Content Placeholder 2 | hence the page is not in physical memory | so the page is not in physical memory | punctuation (comma splice after previous fix) |
| 9 | 正文 / Content Placeholder 2 | , there will be a page fault and OS will bring the page into memory. The current PPN is not valid and shown as “/”. | ; there will be a page fault and OS will bring the page into memory. The current PPN is not valid and shown as “/”. | punctuation |
| 9 | 备注 / notes | The virtual page number is 3 with a page offset of 0x374. Looking up page table entry for virtual page 3, we see that the page is resident in memory (i.e. valid bit = 1) … | For 0xF74, the virtual page number is 3 with a page offset of 0x374. Looking up page table entry for virtual page 3, we see that the page is resident in memory (i.e. vali… | note clarifies which address |
| 9 | 备注 / notes | For 0xF74, the virtual page number is 3 with a page offset of 0x374. Looking up page table entry for virtual page 3, we see that the page is resident in memory (i.e. vali… | For 0xF74, the virtual page number is 3 with a page offset of 0x374. Looking up page table entry for virtual page 3, we see that the page is resident in memory (i.e. vali… | truncated note |
| 9 | 备注 / notes | 01 | 10 | note had wrong PPN bits: PPN=2 is 10, not 01 (0111 0111 0100 = 0x774 is PPN 1) |
| 9 | 备注 / notes | (binary) = 0x774 | (binary) = 0xB74 | wrong answer in note: (2<<10)+0x374 = 0xB74 |
| 10 | 正文 / Content Placeholder 2 | list: Offset / Level 1 / Level 2 / Level 3 (low to high bits) | list: Offset / Level 3 / Level 2 / Level 1 (low to high bits) | Level 1 = top level, as in L8 lecture (p1 = page directory index = most significant) |
| 10 | 正文 / Content Placeholder 3 (table) | L3 \| L2 \| L1 \| Offset | L1 \| L2 \| L3 \| Offset | table labelled top-level as L3; now L1 = top level (matches lecture and bullets) |
| 10 | 备注 / notes | 2048=2112048=211 | 2048 = 2^11. | garbled note (superscripts lost, duplicated) |
| 11 | 正文 / Content Placeholder 2 | Q: Without a cache or TLB, how many memory operations are required to read or write a single 32-bit word? | Q: Without a cache or TLB, how many memory operations are required to read or write a single 32-bit word (assume the 3-level page table from the previous question)? | question refers implicitly to 3-level table; makes 4 accesses answer self-contained |
| 12 | 正文 / Content Placeholder 2 | ANS: A process has a working set size of 256KB which means that the working set fits in 256KB/4KB=64 pages. This means our TLB should have 64 entries. If you have more en… | ANS: A process has a working set size of 256KB which means that the working set fits in 256KB/4KB=64 pages. This means our TLB should have 64 entries. If you have more en… | grammar (fewer) |
| 12 | 正文 / Content Placeholder 2 | 2. Suppose you run some benchmarks on the system and you see that the system is utilizing over 99% of its paging disk IO capacity, but only 10% of its CPU. What is a comb… | 2. Suppose you run some benchmarks on the system and you see that the system is utilizing over 99% of its paging disk IO capacity, but only 10% of its CPU. What is a comb… | typo |
| 12 | 备注 / notes | a Resident | Working set = 256 KB / 4 KB = 64 pages, so at least 64 TLB entries. Four processes x 256 KB = 1 MB aggregate working set; with less than 1 MB of physical memory the syste… | garbled/stale note fragment ("a Resident / Set Size (RSS) of 512MB and a") |
| 12 | 备注 / notes | Set Size (RSS) of 512MB and a | (空) | remove stale note fragment |

### 验算记录

- 第 9 页(Q5 地址翻译,页大小 1 KB、offset 10 位):0xF74 = 1111 0111 0100,VPN = 11₂ = 3,offset = 11 0111 0100 = 0x374;页表项 PPN = 2 = 10₂,物理地址 = (2<<10)+0x374 = 0x800+0x374 = **0xB74**。原备注写成 PPN 位 "01" 和 0x774,那是 PPN=1 的结果(0x400+0x374=0x774),与页表项不符,已改。幻灯片正文答案本身是对的。
- 第 10 页:多级页表三层标签原为 "L3 | L2 | L1 | Offset"(把最高位当 L3),与讲义 L8(p1 = page directory index = 最高位、第 1 级 = 最外层)和题干列表相反;已统一为 L1(最高位) | L2 | L3 | Offset,并把文字列表改为 "Offset / Level 3 / Level 2 / Level 1 (低到高)"。
- 第 11 页:三级页表、无 cache/TLB 时一次访问需 3 次页表访问 + 1 次数据访问 = 4 次,与答案一致;题干原来没说"三级",已在题干补上。
- 第 12 页:256 KB / 4 KB = 64 页,至少 64 个 TLB 项;四进程 4×256 KB = 1 MB 工作集合计,备注中残缺的 "a Resident / Set Size (RSS) of 512MB and a" 已替换为可读的计算说明。
- 第 4–12 页标题:原来 Q1、Q2 重复(第 2–3 页已是 Q1/Q2),且四页同名 "Q. Paging";现为 Q3–Q8 并带副标题。

## 已发现但未修改 / 需要你确认

1. **第 10 页 Level 编号约定属于判断**:我按 L8 讲义(Level 1 = 最外层/最高位)统一。如果你课堂上讲的是相反约定,请告诉我或手动改回;答案数字(各级位数)本身未改变。
2. **第 12 页备注**:原备注是残缺片段("Resident Set Size (RSS) of 512MB…"),我是按题面和答案重写的说明,请确认是否符合你想在备注里写的内容。
3. **标题重新编号(Q3–Q8)** 假设第 2–3 页的 Q1/Q2(Inverted Page Table)是正确的起点;若你另有一份无答案的 L8-Exercises.pptx 的编号要对齐,请同步(本次未改动其他文件)。
4. 第 5、7 页 FIFO/LRU/OPT 缺页数已用小程序按幻灯片参考串重新模拟:Q3(5,3,5,1,2,5,4,6,1;3 帧)= 8 / 7 / 6;Q4(7,0,1,2,0,3,0,4,2,3,0,3,1,2,0;3 帧)= 12 / 12 / 8,与幻灯片一致,未改。第 8 页 YouTube 链接我没有联网验证。

## 观察 / 建议

- 旁边的 PDF(L8)是旧 pptx 导出的,现在已落后于 pptx,需要你重新导出。
- LibreOffice 渲染中第 10 页出现的形状重叠是 LibreOffice 的误报:对照 PowerPoint 导出的参考 PDF 并不存在,因此没有改版式。
- 第 1 页标题里 "Memory System II: Paging" 与讲义命名一致,课程名 "CSC 112: Computer Operating Systems" 正确。
