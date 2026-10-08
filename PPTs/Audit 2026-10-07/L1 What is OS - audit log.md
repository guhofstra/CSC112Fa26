# L1 What is OS.pptx - audit log

共 50 页。读过全部文字/备注/分组内容并渲染检查。页脚 “Lec 1.N” 来自母版里的页码域（“Lec 1.” + 域），不是写死的页码，没有问题。

## 已修改

| 页 | 位置 | 修改前 | 修改后 | 原因 |
|---|---|---|---|---|
| 31 | Rectangle 9 (id 20485) para 0 | `…would double roughly every 18 months` | `…would double roughly every 1–2 years` | Moore 1965: doubling every year; revised 1975: every two years. The popular "18 months" figure is attributed to David House (Intel), not to Moore's 1965 prediction |
| 41 | TextBox 6 (id 7) para 0 | `…sions usually (much) larger older versions!` | `…sions usually (much) larger than older versions!` | Missing word "than" |
| 42 | Rectangle 3 (id 16389) para 1 | `20Mhz processor, 128MB of DRAM, …` | `20 MHz processor, 128MB of DRAM, …` | Unit: MHz, with space |
| 42 | Rectangle 3 (id 16389) para 16 | `Complexity, QoS, Inaccessbility, Power limitations … …` | `Complexity, QoS, Inaccessibility, Power limitations … …` | Typo |
| 39 | TextBox 51 (id 52) para 0 | `…l’s Law: new computer class per 10 years` | `…l’s Law: new computer class every 10 years` | Same wording as slide 2 ("New computer class every 10 years") |
| 5 | NOTES para 0 | `…ty of applications we use does not run on our system. Social networks, e-mail, google docs, online gamming, etc. ` | `…ty of applications we use do not run on our system. Social networks, e-mail, google docs, online gaming, etc. ` | Grammar |
| 4, 5, 31, 38, 39, 41, 28 | 标题框位置 | 第 4/5/31/38/39/41 页标题位置、宽度各不相同（例如 left 2.08–2.45in、top 0.17–0.26in、高 0.40–0.58in） | 统一为 1.44in, 0.17in, 10.44×0.58in | 标题位置漂移（水平中心偏移最多约 0.1in，第 31 页高度只有 0.4in） |

## 已发现但未修改 / 需要你确认

1. **第 31 页**：我把 “double roughly every 18 months” 改成 “every 1–2 years”。事实：Moore 1965 年预测每年翻倍，1975 年修正为每两年；“18 个月”通常归功于 Intel 的 David House。左边的图注 “2X transistors/Chip Every 1.5 years” 和第 34 页的 “every 18 months” 是通俗说法，我没动，可考虑统一成你想要的口径。
2. **第 32 页**：“RISC + x86 : ??%/year 2002 to present” 是没有填的占位符。H&P 第 4 版给出的是约 20%/年（我记忆中如此，但没有核对原书），所以仅标出。另外 “Joy’s law” 与 “Moore’s law” 在此页混用，可检查。
3. **第 38 页**：2011 年数据 210M+112M+63M+25M = 410M，而页面写 414M PC clients（差 4M）；另外 “1.53B / 262.5M / 164M / 39.5M in 2017” 的气泡在静态视图中压在正文文字上（若有动画则无问题）；整页数据已过时（2011/2017）。
4. **第 34 页**：“Moore’s Law has (officially) ended – Feb 2016”“May have only 2-3 smallest geometry fabrication plants left” 是 2016 年的说法，2026 年需要更新（TSMC/Samsung/Intel 近年的先进制程、chiplet、AI 加速器等）。
5. **第 36、37、35 页**：Hootsuite 2019 数据、网络容量与存储容量图均为旧数据，建议刷新；**第 3 页** Jeff Dean “Numbers Everyone Should Know” 为 2009 年版数字（可附年份）。
6. **第 2 与第 39 页**：标题写 “People-to-Computer Ratio”，坐标轴却写 “Computers Per Person”，刻度为 1:10^6 … 10^3:1，两者方向相反；Berkeley 原版同样如此，但容易让学生混淆。我没改，因为不确定你想改标题还是改坐标轴。
7. **第 41 页**：标题 “Recall: Increasing Software Complexity” —— 这是第一讲，前面没有可 “Recall” 的内容（Berkeley 旧讲义遗留）。
8. **第 5 页备注**：“In this course we are not focusing on a single node system but on the end-to-end system” 与 CSC 112（单机 OS）的实际范围不符，是 Berkeley CS162 的口吻；只修了语法，未改动含义。
9. **第 30 页备注**是 Berkeley CITRIS 演讲稿（“Ruzena mentioned…”, “I will present one set …”），与本讲无关，疑为遗留；备注不会显示在幻灯片上，未动。
10. **第 30、32、42 页**标题字号被手工设为 24/28pt（其它页默认），且第 30 页标题 left 2.17in、宽 7.83in 偏左约 0.58in；第 48 页标题宽 12.17in。这些是为了容纳长标题，我没有改变其几何位置。渲染中第 4、32、42 页的长标题会换行压到分隔线（字体替换所致，需在 PowerPoint 里确认）。
11. **第 14 页**：说明框盖住了两个 “Compiled Program” 方块的上半部分（可能是动画叠加，需要确认）。
12. **第 38 页**文本里有 Wingdings 箭头字符 (U+F0E0)，在 LibreOffice 中显示为方框，在 PowerPoint 里正常，未动。

## 观察 / 建议

- 幻灯片 2/39、8/15/24、16-20、21-23 是同一标题的多页动画拆分，属于有意重复。
- 没有课程大纲/路线图页，也没有结尾的参考文献页；除第 1 页的 Berkeley 致谢外，图片来源只在个别页标注（第 37、41 页）。
- 第 28 页 “Why take CSC 112?” 的内容完全是通用说法；可以补充本课程的具体主题（进程/线程、同步、死锁、调度、内存、文件系统）以匹配 L0。
- 第 29 页是章节页，只有标题。
