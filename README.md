LeetCode
====
LeetCode上的算法题使用golang和c++实现
----
* 目录结构
    >c++
    >>LeetCode [^使用说明]:使用vs2019打开此路径下的sln文件，LeetCode.cpp中main函数用于测试
    >
    >go
    >>src [^分包说明]:按照不同类型的题目建包，每个包下有相同类型的不同的题目
    >>>array [^包说明]:数组类型题目
    >>>>twosum.go [^文件说明]:题目的具体算法实现
    >>>>
    >>>>twosum_test.go [^文件说明]:单元测试与基准测试使用模板
    >>>
    >>>list [^包说明]:链表类型题目
    >>>
    >>>string [^包说明]:字符串类型题目
    >>>
    >>>backtracking [^包说明]:回溯类型题目
***