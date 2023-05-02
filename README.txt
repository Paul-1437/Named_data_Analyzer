This is a program that analyzes data with name or tags. It helps you to find out
-The sum of data
-The amount of data
-The middle of the data (mean, median and mode)
-The spread of the data (minimum, Q1, median, Q3,  maximum and interquartile range*)
-The most frequent category(or categories, when there are less than 10)

Feature of this program
-No need to input the amount of data
-Low space complexity using vector O(N)

Possible updates in the future
Abandon "map" container and switch to variables (2*2=4 variables in total) to calculate the mode and the most frequent category, in order to reduce both time complexity and space complexity.

本程序将分析用户输入的标签化数据，它可以实现输出
-数据总和
-数据量
-平均值，众数和中数
-数据分布（最小值，25%低数值，中值，25%高数值，最高值）
-最频繁的类别（在10个以内时）

程序特色：
-用户无需输入数据量，简化用户工作流程
-使用vector可变数组，降低空间复杂度

未来可能的更新
弃用map容器，改用2*2=4个变量来统计众数和最频繁类别，同时减少时间复杂度和空间复杂度