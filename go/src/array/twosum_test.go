package array

import (
	"fmt"
	"testing"
)

//单元测试
func TestTwoSum(t *testing.T) {
	var nums []int = []int{2, 7, 11, 15}
	var target = 9
	rslt := twoSum(nums, target)
	t.Logf("get a + b = %d from %v, result = %v", target, nums, rslt)
}

//基准测试
func BenchmarkTwoSum(b *testing.B) {
	var nums []int = []int{2, 7, 11, 15}
	var target = 9

	b.ResetTimer()

	for i := 0; i < b.N; i++ {
		twoSum(nums, target)
	}
}

func BenchmarkTest(b *testing.B) {
	num := 10

	b.ResetTimer()

	for i := 0; i < b.N; i++ {
		fmt.Sprintf("%d", num)
	}
}