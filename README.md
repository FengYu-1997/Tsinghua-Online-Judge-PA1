# Tsinghua-Online-Judge-PA1
邓俊辉老师的数据结构与算法课程，Programming Assignment1 Range

用到归并排序、二分查找

二分查找返回有序数组中不大于查找元素的最后一个元素的秩r。对于一个包含n个元素的有序数组，r∈[-1, n-1]

分别找到左右边界的秩rl、rr，相减得到序列中位于左右边界内的元素个数

如果序列中不包含左侧边界，则序列中位于左右边界内的元素个数 = rr-rl

如果序列中包含左侧边界，则序列中位于左右边界内的元素个数 = rr - rl + 1

判断序列中是否包含左侧边界时，要避免rl越界
