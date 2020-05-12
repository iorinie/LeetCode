package array

/*
    题目描述：
        给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
        你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

    示例：
        给定 nums = [2, 7, 11, 15], target = 9
        因为 nums[0] + nums[1] = 2 + 7 = 9
        所以返回 [0, 1]
*/

/*
	解法2：顺序遍历，利用额外存储空间map，将当前数字的差值做key，当前数字下标做value，key存在，则返回value中下标及当前下标
 */
func twoSum(nums []int, target int) []int {
	rslt := make([]int, 2)
	rslt[0] = -1
	rslt[1] = -1
	diffMap := make(map[int]int)
	for idx, num := range nums {
		if _, ok := diffMap[num]; ok {
			rslt[0] = diffMap[num]
			rslt[1] = idx
			break
		}
		diffMap[target - num] = idx
	}
	return rslt
}