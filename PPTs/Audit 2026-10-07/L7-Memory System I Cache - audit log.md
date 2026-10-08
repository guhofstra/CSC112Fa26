# L7-Memory System I Cache — 审核日志

**范围**:77 页 + 备注。

原文件备份:`PPTs/bak/audit-20261007/`。写回方式:仅把变更过的 slideN.xml / notesSlideN.xml 部分移植进原 zip(其余字节不变),`validate.py --original` 通过,c14n 比较确认只有预期部分变化,变更页已用 LibreOffice 重新渲染并目视检查。写回后在设备上重新用 python-pptx 打开确认页数与 sha256。该 deck 旁没有 `~$` 锁文件。

## 已修改

共 75 条 run 级编辑(逐条列于下表;只改 run 文本,未改幻灯片数量/顺序/图片/样式)。

| 幻灯片 | 位置 | 修改前 | 修改后 | 原因 |
|---|---|---|---|---|
| 42 | 正文 / Text Box 63 | address: 3-bit Tag, 1-bit Set Index, 2-bit Offset (each cache block is 4 Bytes/1 Word). | address: 4-bit Tag, 0-bit Set Index, 2-bit Offset (each cache block is 4 Bytes/1 Word). | FA example: no set index; 6-bit address = 4-bit tag + 0-bit SI + 2-bit offset (as slide 43 and the Tag\|Offset figure show) |
| 45 | 正文 / Text Box 84 | 000    Mem(0) | 0000   Mem(0) | FA cache tag is 4 bits (slide 44 shows 0000/0100) |
| 45 | 正文 / Text Box 85 | 000    Mem(0) | 0000   Mem(0) | FA cache tag is 4 bits (slide 44 shows 0000/0100) |
| 45 | 正文 / Text Box 138 | 000    Mem(0) | 0000   Mem(0) | FA cache tag is 4 bits (slide 44 shows 0000/0100) |
| 45 | 正文 / Text Box 139 | 000    Mem(0) | 0000   Mem(0) | FA cache tag is 4 bits (slide 44 shows 0000/0100) |
| 45 | 正文 / Text Box 136 | 010    Mem(1) | 0100   Mem(4) | FA cache: block 0100xx = Mem(4) with 4-bit tag 0100; slide text says addresses 0 and 4 (slide 40 shows Mem(4)) |
| 45 | 正文 / Text Box 137 | 010    Mem(1) | 0100   Mem(4) | FA cache: block 0100xx = Mem(4) with 4-bit tag 0100; slide text says addresses 0 and 4 (slide 40 shows Mem(4)) |
| 45 | 正文 / Text Box 140 | 010    Mem(1) | 0100   Mem(4) | FA cache: block 0100xx = Mem(4) with 4-bit tag 0100; slide text says addresses 0 and 4 (slide 40 shows Mem(4)) |
| 46 | 正文 / Content Placeholder 2 | for (int i=0; i++, i<10000) {sum += A[0] | for (int i=0; i<10000; i++) {sum += A[0] | for-loop header syntax (commas instead of semicolons) |
| 46 | 备注 / notes | for (int i=0; i++, i<10000) {sum += A[0] | for (int i=0; i<10000; i++) {sum += A[0] | same in note |
| 47 | 正文 / Rectangle 102 | After 10000 iterations, 4 cache misses, 9996 cache hits. | After 10000 iterations (40000 accesses to A[]), 4 cache misses, 39996 cache hits. | 4 reads of A[] per iteration x 10000 = 40000 accesses; hits = 40000 - 4 = 39996 (9996 counted one access per iteration) |
| 48 | 正文 / Rectangle 102 | After 10000 iterations, 4 cache misses, 9996 cache hits | After 10000 iterations (40000 accesses to A[]), 4 cache misses, 39996 cache hits | 4 reads of A[] per iteration x 10000 = 40000 accesses; hits = 40000 - 4 = 39996 (9996 counted one access per iteration) |
| 49 | 正文 / Rectangle 120 | After 10000 iterations, 4 cache misses, 9996 cache hits. | After 10000 iterations (40000 accesses to A[]), 4 cache misses, 39996 cache hits. | 4 reads of A[] per iteration x 10000 = 40000 accesses; hits = 40000 - 4 = 39996 (9996 counted one access per iteration) |
| 61 | 正文 / Content Placeholder 2 | FA (4-way SA): 1 set x 8 blocks per set | FA (8-way SA): 1 set x 8 blocks per set | 8-block cache: FA = 8-way |
| 24 | 正文 / Content Placeholder 2 | FA = N-way SA (N = cache capacity (total # cache blocks)) | FA = N-way SA (N = total # cache blocks) | "cache capacity" is defined (slide 20/55) as total size in bytes, not # blocks; slide 54 already uses this wording |
| 28 | 正文 / TextBox 1034 | Each cache set contains one block. A cache block can only go in one position in the cache. It makes a cache block easy to find, but it's not inflexible about where to put… | Each cache set contains one block. A cache block can only go in one position in the cache. It makes a cache block easy to find, but it's inflexible about where to put it. | logic reversed ("not inflexible") |
| 15 | 正文 / TextBox 45 | ReadData | Read Data | spacing (cf. "Write Data") |
| 16 | 正文 / Content Placeholder 2 | if each cache block is 4 Bytes (1 word), then binary address of each cache block always ends in 00 | If each cache block is 4 Bytes (1 word), then binary address of each cache block always ends in 00 | capitalisation consistent with next bullet |
| 16 | 正文 / Content Placeholder 2 | If each cache block is 8 Bytes (2 words), then binary address each cache block always ends in 000 | If each cache block is 8 Bytes (2 words), then binary address of each cache block always ends in 000 | missing "of" |
| 20 | 正文 / Content Placeholder 2 | ” indicates of a cache block contains valid data | ” indicates if a cache block contains valid data | typo "of" -> "if" |
| 26 | 正文 / Text Box 26 | higher way, less sets | higher way, fewer sets | grammar |
| 53 | 正文 / Content Placeholder 30 | Main memory can be viewed a “cache” for disk or Flash, and it is a Fully-Associative cache | Main memory can be viewed as a “cache” for disk or Flash, and it is a Fully-Associative cache | typo |
| 77 | 正文 / Content Placeholder 2 | Increasing associativity helps to reduce miss rate, but increases runtime overhead | Increasing associativity helps to reduce miss rate, but increases hit time (and hardware cost) | clarify: matches slide 30 (higher associativity increases hit time) |
| 29 | 正文 / Title 1 | Bookshelf Analogy | Bookshelf Analogy (cont.) | duplicate title |
| 66 | 正文 / Title 1 | AMAT Example | AMAT Example: Single-Level Cache | duplicate title |
| 75 | 正文 / Title 1 | AMAT Example | AMAT Example: With and Without L2 | duplicate title |
| 17 | 删除形状 | Content Placeholder 2 (id 3) | (deleted) | empty content placeholder (title is a separate text box) |
| 18 | 删除形状 | Title 1 (id 2) | (deleted) | empty title placeholder (visible title is a separate text box) |
| 19 | 删除形状 | Content Placeholder 2 (id 3) | (deleted) | empty content placeholder |
| 62 | 删除形状 | Content Placeholder 2 (id 3) | (deleted) | empty content placeholder |
| 38 | 删除形状 | Slide Number Placeholder 5 (id 101) | (deleted) | duplicate slide-number placeholder (slide also has the standard slide-number text box) |
| 9 | 备注 / notes | Virtual to physical address mapping assisted by the hardware (Translation LB) | Virtual to physical address mapping assisted by the hardware (Translation Lookaside Buffer, TLB) | typo |
| 10 | 备注 / notes | +1 = 15 min. (X:55) | (空) | leftover time-keeping cue from original (Berkeley) deck |
| 23 | 备注 / notes | +2 = 43 min. (Y:23) | (空) | leftover time-keeping cue from original (Berkeley) deck |
| 70 | 备注 / notes | +2 = 43 min. (Y:23) | (空) | leftover time-keeping cue from original (Berkeley) deck |
| 23 | 备注 / notes | For example, say using a 2-way set associative cache instead of directed mapped cache. | For example, say using a 2-way set associative cache instead of direct mapped cache. | typo |
| 70 | 备注 / notes | For example, say using a 2-way set associative cache instead of directed mapped cache. | For example, say using a 2-way set associative cache instead of direct mapped cache. | typo |
| 20 | 备注 / notes | Tag only needs enough bits to uniquely identify the block (jse) | Tag only needs enough bits to uniquely identify the block | stray "(jse)" |
| 25 | 备注 / notes | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ (jse) | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ | stray "(jse)" |
| 59 | 备注 / notes | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ (jse) | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ | stray "(jse)" |
| 31 | 备注 / notes | = 4 Byes | = 4 Bytes | typo Byes |
| 31 | 备注 / notes | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block One word blocks | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block. One word blocks | missing full stop |
| 32 | 备注 / notes | = 4 Byes | = 4 Bytes | typo Byes |
| 32 | 备注 / notes | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block One word blocks | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block. One word blocks | missing full stop |
| 33 | 备注 / notes | = 4 Byes | = 4 Bytes | typo Byes |
| 33 | 备注 / notes | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block One word blocks | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block. One word blocks | missing full stop |
| 36 | 备注 / notes | = 4 Byes | = 4 Bytes | typo Byes |
| 36 | 备注 / notes | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block One word blocks | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block. One word blocks | missing full stop |
| 37 | 备注 / notes | = 4 Byes | = 4 Bytes | typo Byes |
| 37 | 备注 / notes | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block One word blocks | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block. One word blocks | missing full stop |
| 38 | 备注 / notes | = 4 Byes | = 4 Bytes | typo Byes |
| 38 | 备注 / notes | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block One word blocks | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block. One word blocks | missing full stop |
| 41 | 备注 / notes | = 4 Byes | = 4 Bytes | typo Byes |
| 41 | 备注 / notes | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block One word blocks | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block. One word blocks | missing full stop |
| 42 | 备注 / notes | = 4 Byes | = 4 Bytes | typo Byes |
| 42 | 备注 / notes | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block One word blocks | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block. One word blocks | missing full stop |
| 43 | 备注 / notes | = 4 Byes | = 4 Bytes | typo Byes |
| 43 | 备注 / notes | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block One word blocks | Valid bit indicates whether an entry contains valid information – if the bit is not set, there cannot be a match for this block. One word blocks | missing full stop |
| 27 | 备注 / notes | . For fixed $ size, increasing | . For fixed $ size, increasing | missing space ("increasingassociativity") |
| 61 | 备注 / notes | . For fixed $ size, increasing | . For fixed $ size, increasing | missing space ("increasingassociativity") |
| 53 | 备注 / notes | (We will go over this slide in detail in the next lectures on caches). | (空) | stale: slide is part of this cache lecture (cf. slide 76) |
| 26 | 备注 / notes | , only a single comparator | (空) | orphan note fragment |
| 26 | 备注 / notes | , and a given block size | (空) | orphan note fragment |
| 57 | 备注 / notes | 16 Memory blocks = 16 words = 64 bytes => 6 bits to address all bytes (Memory and cache blocks always have the same size) 4 Cache blocks, 4 bytes (1 word) per block | 16 Memory blocks = 16 words = 64 bytes => 6 bits to address all bytes (Memory and cache blocks always have the same size) 8 cache blocks, 4 bytes (1 word) per block | note copied from DM example (slide 56); adapted to 2-way |
| 57 | 备注 / notes | 4 sets *1 block per set (direct mapped cache) = 4 blocks = | 4 sets * 2 blocks per set (2-way set associative cache) = 8 blocks | note copied from DM example (slide 56); adapted to 2-way |
| 57 | 备注 / notes | # Memory blocks (16) >> # Cache blocks (4) | # Memory blocks (16) > # Cache blocks (8) | note copied from DM example (slide 56); adapted to 2-way |
| 57 | 备注 / notes | 4 Memory blocks map to each cache block | 4 Memory blocks map to each cache set (a set holds 2 of them at a time) | note copied from DM example (slide 56); adapted to 2-way |
| 57 | 备注 / notes | A cache set may contain 1 of 4 possible memory blocks, which exact memory block is mapped to it? | A cache set may contain 2 of 4 possible memory blocks, which exact memory blocks are in it? | note copied from DM example (slide 56); adapted to 2-way |
| 57 | 备注 / notes | tag | tags | note adapted to 2-way |
| 58 | 备注 / notes | 16 Memory blocks = 16 words = 64 bytes => 6 bits to address all bytes (Memory and cache blocks always have the same size) 4 Cache blocks, 4 bytes (1 word) per block | 16 Memory blocks = 16 words = 64 bytes => 6 bits to address all bytes (Memory and cache blocks always have the same size) 16 cache blocks, 4 bytes (1 word) per block | note copied from DM example (slide 56); adapted to 4-way |
| 58 | 备注 / notes | 4 sets *1 block per set (direct mapped cache) = 4 blocks = | 4 sets * 4 blocks per set (4-way set associative cache) = 16 blocks | note copied from DM example (slide 56); adapted to 4-way |
| 58 | 备注 / notes | # Memory blocks (16) >> # Cache blocks (4) | # Memory blocks (16) = # Cache blocks (16) | note copied from DM example (slide 56); adapted to 4-way |
| 58 | 备注 / notes | 4 Memory blocks map to each cache block | 4 Memory blocks map to each cache set (a set can hold all 4 of them) | note copied from DM example (slide 56); adapted to 4-way |
| 58 | 备注 / notes | A cache set may contain 1 of 4 possible memory blocks, which exact memory block is mapped to it? | A cache set may contain all 4 possible memory blocks, which ones are in it right now? | note copied from DM example (slide 56); adapted to 4-way |
| 58 | 备注 / notes | tag | tags | note adapted to 4-way |

### 验算记录

- 第 42 页(FA 例子,6 位地址、4 字节块):offset 2 位,FA 无 set index → Tag = 6−0−2 = **4 位**。原写 "3-bit Tag, 1-bit Set Index",与第 43 页和图下的 Tag|Offset 条不符,已改为 4/0/2。
- 第 45 页(FA 无 ping-pong):FA 的 tag 是 4 位,缓存项应显示 0000 / 0100;原图文字为 3 位 "000" 和 "010 Mem(1)"。0100xx 是块 4 → 已改为 "0100  Mem(4)"(与正文"地址 0 和 4"及第 40 页一致)。该页共 8 次访问、2 次缺失(只有 0000xx、0100xx 各第一次),正确。
- 第 46 页 C 代码:`for (int i=0; i++, i<10000)` 不是合法 for 头(逗号应为分号,顺序也错),改为 `for (int i=0; i<10000; i++)`,备注同改。
- 第 47–49 页(DM / 2-way / FA):每次迭代读 A[0..3] 共 4 次,10000 次迭代 = 40000 次访问;只有首轮 4 次强制缺失,命中 = 40000−4 = **39996**。原写 "9996 hits" 是按"每次迭代 1 次访问"算的(10000−4),与 4 次读取矛盾。
- 第 61 页:8 块 cache 的 FA = 8-way(1 组 × 8 块),原写 "FA (4-way SA)",已改。
- 第 24 页:"N = cache capacity (total # cache blocks)" 中 capacity 在第 20/55 页定义为字节数,改为 "N = total # cache blocks"(第 54 页已是这种写法)。
- 第 28 页:"it's not inflexible about where to put it" 逻辑反了(DM 放置位置是固定的,即 inflexible),已删 "not"。
- 第 57–58 页备注:原是第 56 页 DM 例子(4 组×1 块 = 4 块)的复制;按 2-way(4 组×2 = 8 块)和 4-way(4 组×4 = 16 块)改写。
- 第 66 页 AMAT 例子:(1 + 0.02×50) × 200 ps = 2 × 200 = 400 ps(选项 B),幻灯片正确。第 75 页:无 L2:1 + 0.02×100 = 3;有 L2:1 + 0.02×(5 + 0.05×100) = 1 + 0.02×10 = 1.2,正确。

## 已发现但未修改 / 需要你确认

1. **第 47–49 页的"命中数"口径**:我把 "9996 hits" 改成 "(40000 accesses to A[]) … 39996 hits"。如果你想强调的是"按迭代计",请改回;现在的写法与 4 次读取的代码一致。
2. **第 77 页 Summary**:把 "increases runtime overhead" 改为 "increases hit time (and hardware cost)",依据是第 30 页的结论;这是措辞判断,请确认。
3. **第 45 页缓存项宽度**:4 位 tag 比原来的 3 位更宽。我在 LibreOffice 的低分辨率渲染里看是装得下的,但没有在 PowerPoint 里实际打开看,请你翻一下这一页。
4. **来源致谢**:第 29、61 页的插图来源(csillustrated.berkeley.edu)只写在备注里,第 62 页的 YouTube 链接我没有联网验证是否仍有效;备注中的 "(jse)" 和 "+2 = 43 min. (Y:23)" 之类痕迹说明内容改编自别处的课件。整个 deck 没有致谢/参考页,如需要请你自己决定是否添加(我不增页)。
5. **第 45 页底部日期**:是自动更新的日期字段(type=datetime1),原本就有,未改,打开时会显示当天日期。
6. 第 55–56 页之后的 DM/2-way/4-way 例子的 "4 Memory blocks map to each cache set" 等备注我只修了明显的复制错误,其余讲稿用语未润色。

## 观察 / 建议

- 旁边的 PDF(L7)现已落后于 pptx,需要重新导出。
- 删除的空/重复占位符:第 17、19、62 页空内容占位符,第 18 页空标题占位符(可见标题是另一个文本框),第 38 页多余页码占位符;改了第 29/66/75 页的重复标题(Bookshelf Analogy (cont.)、AMAT Example: Single-Level Cache、AMAT Example: With and Without L2)。
- 备注里的时间提示("+1 = 15 min. (X:55)"、"+2 = 43 min. (Y:23)")和第 53 页 "We will go over this slide in detail in the next lectures on caches"(本讲就是 cache 讲)已清除。
- 备注中 "4 Byes"→"4 Bytes"、"directed mapped"→"direct mapped"、"increasingassociativity" 等拼写问题已统一修正。
- 重新渲染并目视检查了变更页 17、18、19、29、38、42、45、46、47、53、61、62、66、75、77,没有发现新的版式问题。
