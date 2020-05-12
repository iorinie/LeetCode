package list

/*
    题目描述：
        给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
        如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
        您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    示例：
        输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
        输出：7 -> 0 -> 8
        原因：342 + 465 = 807
*/

/*
    解法1：同步并顺序遍历两个链表，两数相加，保留进位
*/
type ListNode struct {
	Val int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	rslt := new(ListNode)
	rslt.Next = nil
	adv := 0
	p, p1, p2 := rslt, l1, l2
	for {
		if p1 == nil && p2 == nil && adv == 0 {
			break
		}
		a, b := 0, 0
		if p1 != nil {
			a = p1.Val
			p1 = p1.Next
		}
		if p2 != nil {
			b = p2.Val
			p2 = p2.Next
		}
		temp := new(ListNode)
		temp.Val = (a + b + adv) % 10
		temp.Next = nil
		p.Next = temp
		p = p.Next
		adv = (a + b + adv) / 10
	}

	return rslt.Next
}