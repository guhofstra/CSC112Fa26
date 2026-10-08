# L7-Exercises ANS — 审核日志

**范围**:52 页 + 备注。

原文件备份:`PPTs/bak/audit-20261007/`。写回方式:仅把变更过的 slideN.xml / notesSlideN.xml 部分移植进原 zip(其余字节不变),`validate.py --original` 通过,c14n 比较确认只有预期部分变化,变更页已用 LibreOffice 重新渲染并目视检查。写回后在设备上重新用 python-pptx 打开确认页数与 sha256。该 deck 旁没有 `~$` 锁文件。

## 已修改

共 34 条 run 级编辑(逐条列于下表;只改 run 文本,未改幻灯片数量/顺序/图片/样式)。

| 幻灯片 | 位置 | 修改前 | 修改后 | 原因 |
|---|---|---|---|---|
| 10 | 正文 / Content Placeholder 2 | ANS: T=27, I=0, O=5 | ANS: T=28, I=0, O=4 | FA 16KB, 16B blocks: O=4, I=0, T=32-0-4=28 (the working lines below already said 28) |
| 19 | 正文 / Content Placeholder 55 | 00001 1101 11 | 0001 1101 11 | 0x1DD = 0001 1101 1101; extra leading 0 (13 bits) |
| 19 | 正文 / Content Placeholder 55 | 00001110111 | 0001110111 | Tag of 0x1DD is 10 bits = 0001110111 (=0x77); extra leading 0 (11 bits) |
| 31 | 正文 / Title 1 | 4-block cache | 8-block cache | content is the 8-block case (DM: Tag 2b, SI 3b; 2-way: SI 2b) |
| 31 | 正文 / Title 1 | ） | ) | full-width paren |
| 31 | 正文 / Content Placeholder 2 | # cache blocks = 32; Block #12 in decimal is 01100 in binary | # cache blocks = 8 (memory has 32 blocks); Block #12 in decimal is 01100 in binary | cache has 8 blocks (3-bit SI for DM => 8 sets); 32 is the number of memory blocks |
| 31 | 正文 / Content Placeholder 2 | Set Index=0, hence it is set 0 (2 blocks) | Set Index=0, hence it is set 0 (4 blocks) | 4-way SA: a set has 4 blocks (slide 30 says 4 blocks) |
| 31 | 正文 / Content Placeholder 2 | Can be anywhere for SA cache | Can be anywhere in the cache (any of the 8 blocks) | FA cache, not SA; clearer |
| 25 | 正文 / Title 1 | ） | ) | full-width paren in title (caused wrapping) |
| 26 | 正文 / Title 1 | ） | ) | full-width paren in title (caused wrapping) |
| 27 | 正文 / Title 1 | ） | ) | full-width paren in title (caused wrapping) |
| 29 | 正文 / Title 1 | ） | ) | full-width paren in title (caused wrapping) |
| 28 | 正文 / Title 1 | （ | ( | full-width paren |
| 28 | 正文 / Title 1 | ） | ) | full-width paren |
| 30 | 正文 / Title 1 | （ | ( | full-width paren |
| 30 | 正文 / Title 1 | ） | ) | full-width paren |
| 5 | 正文 / Title 1 | Quiz | Quiz: Locality and Block Size | duplicate title |
| 6 | 正文 / Title 1 | Quiz | Quiz: Cache Size from T-I-O Bits | duplicate title |
| 9 | 正文 / Title 1 | Quiz | Quiz III | duplicate title (continues Quiz I, Quiz II) |
| 10 | 正文 / Title 1 | Quiz | Quiz IV | duplicate title |
| 4 | 删除形状 | Slide Number Placeholder 2 (id 3) | (deleted) | stray second slide number (hard-positioned, showed a blue "4" at left) |
| 7 | 删除形状 | Slide Number Placeholder 3 (id 4) | (deleted) | stray second slide number (showed a grey "7" at bottom centre) |
| 25 | 备注 / notes | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ (jse) | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ | stray "(jse)" in note |
| 27 | 备注 / notes | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ (jse) | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ | stray "(jse)" in note |
| 28 | 备注 / notes | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ (jse) | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ | stray "(jse)" in note |
| 30 | 备注 / notes | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ (jse) | Simplest scheme is to extract bits from ‘block number’ to determine ‘set’ | stray "(jse)" in note |
| 6 | 备注 / notes | Online hex converter: | (空) | duplicated "Online hex converter:" in note |
| 36 | 备注 / notes | Online hex converter: | (空) | duplicated "Online hex converter:" in note |
| 37 | 备注 / notes | Online hex converter: | (空) | duplicated "Online hex converter:" in note |
| 42 | 备注 / notes | 8 word blocks => 32 bytes / block => | 4 word blocks => 16 bytes / block => | stale note copied from previous slide |
| 42 | 备注 / notes | O = 5 | O = 4 | stale note |
| 42 | 备注 / notes | 32 KB / (32 bytes / block) = 2^10 blocks total | 16 KB / (16 bytes / block) = 2^10 blocks total | stale note |
| 42 | 备注 / notes | 2^10 blocks / (4 blocks / set) = 2^8 sets total | 2^10 blocks / (1 block / set) = 2^10 sets total (direct mapped) | stale note |
| 42 | 备注 / notes | Index bits will index into sets => I = 8 | Index bits will index into sets => I = 10; T = 32 - 10 - 4 = 18 | stale note |

### 验算记录

- 第 10 页(FA、16 KB cache、16 B 块、32 位地址):O = log₂16 = 4,FA 无 set index 故 I = 0,T = 32−0−4 = **28**。原答案行写 "T=27, I=0, O=5"(O=5 对应 32 B 块),与下方推导的 28 不一致,已改为 T=28, I=0, O=4。
- 第 19 页(0x1DD):0x1DD = 0001 1101 1101(12 位);offset 2 位,tag 10 位 = 0001 1101 11 = 0001110111 = 0x77(477/4 = 119 = 0x77)。原文多了一个前导 0(13 位 / 11 位),已改。
- 第 31 页(8 块 cache,32 块内存):DM 为 8 组、SI = 3、Tag = 5−3 = 2;2-way 为 4 组、SI = 2;4-way 为 2 组,一组 4 块(原写 "2 blocks");FA 为 "任一块"。标题从 "4-block cache" 改为 "8-block cache","# cache blocks = 32" 改为 8(32 是内存块数)。
- 第 36–37 页:DM 2¹⁵ 块 × 4 B = 2¹⁷ B;2-way 2¹⁶ 块 × 4 B = 2¹⁸ B,正确。第 38 页:64 块 × 4 B = 256 B;2-way 32 组、4-way 16 组,正确。
- 第 41–43 页:32 KB 4-way 8 字块 → T19/SI8/O5;16 KB DM 4 字块 → T18/SI10/O4;2 KB、128 B 块、2 组 → 16 块 = 8-way,SI1/O7/T8,均正确。
- 第 42 页备注原为第 41 页的旧备注(32 KB 4-way),已按 16 KB DM 重写:16 KB/16 B = 2¹⁰ 块;DM → 2¹⁰ 组,I = 10,T = 32−10−4 = 18。

## 已发现但未修改 / 需要你确认

1. **第 38 页 "Answer: Cache Capacity 3"** 没有对应的 "Question: Cache Capacity 3" 页(题与答案在同一页)。看起来是原有设计,未改;如果想与 Capacity 1/2/4 保持一致,可以拆成两页(我不增删幻灯片)。
2. **第 41–45 页标题** 为 "Q. Bits in Memory Address n"/无标题文本框,且答案与题目同页,与前后的 Question/Answer 分页风格不同;未改。
3. 上面"验算记录"列出的题目是我逐题重算并留有记录的;其余题目审核时未发现错误,但本日志没有逐题演算,如需要请告知。

## 观察 / 建议

- 旁边的 PDF(L7)现已落后于 pptx,需要重新导出。
- LibreOffice 渲染中第 11/14/17/52 页的重叠是误报(对照 PowerPoint 导出的 PDF 不存在),没有改版式。
- 第 4、7 页多余的第二个页码占位符已删除(原来会在左侧显示蓝色 "4"、底部显示灰色 "7")。
- 标题中的全角括号 "）" 导致换行,已改成半角。
