/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function (head) {
  let node = head;
  let bfrNode = null;
  if (node == null || node.next == null) return head;
  while (true) {
    let nextNode = node.next;
    node.next = nextNode.next;
    if (bfrNode) {
      bfrNode.next = nextNode;
    } else {
      head = nextNode;
    }
    nextNode.next = node;
    bfrNode = node;
    node = node.next;
    if (node == null || node.next == null) break;
  }
  return head;
};
