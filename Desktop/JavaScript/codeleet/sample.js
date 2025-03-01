/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {  
    let dummy = new ListNode();
    let cur = dummy;

    while(list1 && list2) {
        if (list1.val > list2.val) {
            cur.next = list2;
            list2 = list2.next
        } else {
            cur.next = list1;
            list1 = list1.next;
        }
        cur = cur.next;
    }

    cur.next = list1 || list2; //мжно суммировать таким образом 

    return dummy.next;
};

var hasCycle = function(head) {
    // floyd algorithm
    let slow = head;
	let fast = head;

    while (fast) {
        slow = slow.next;
        if (!fast.next) {
            break
        }
        fast = fast.next.next;
        if (slow === fast) {
            return true;
        }
    }
    return false;

/*
	let slow = head;
    let fast = head;
    while(fast && fast?.next) {
       slow = slow.next;
       fast = fast.next.next;
       if(slow === fast) return true;
    }
    return false;
*/

};

var addTwoNumbers = function(l1, l2) {
    let p = 0;
    let result = new ListNode(-1);
    let curr = result;
    while (l1 || l2 || p) {
        let s = 0;
        if (l1) {
            s += l1.val;
            l1 = l1.next;
        }
        if (l2) {
            s += l2.val;
            l2 = l2.next;
        }
        s += p;
        p = Math.floor(s / 10);
        curr.next = new ListNode(s%10);
        curr = curr.next;
        
    }
    return result.next;
    
};

var rotateRight = function(head, k) {
    if (head === null || head.next === null || k ===0) {
        return head;
    }
    let l = 1;
    let list = head;
    while (list.next) {
        ++l;
        list = list.next;
    }

    k = l - k%l;

    list.next = head; //make circle
    while (k) {
        k--;
        list = list.next;

    head  = list.next;
    list.next = null;
    return head;
};

var getIntersectionNode = function(headA, headB) {
    let curA = headA;
    let curB = headB;
    while (curA !== curB) {
        if (curA) {
            curA = curA.next;
        } else {
            curA = headA;
        }
        if (curB) {
            curB = curB.next;
        } else {
            curB = headB;
        }
        
    }
    return curA;
};

var deleteDuplicates_I = function(head) { // 1123 -> 123
    let current = head;
    while (current !== null && current.next !== null) {
        if (current.val === current.next.val) {
            current.next = current.next.next;
        } else {
            current = current.next;
        }
    }  
    return head;  
};
var deleteDuplicates_II = function(head) { // 1123 -> 23
    let list = new ListNode(0, head)
    let current = list;
    while (current && current.next && current.next.next) {
        if (current.next.val === current.next.next.val) {
            let v = current.next.val;
            while (current.next && current.next.val === v) {
                current.next = current.next.next;
            }
        } else {
            current = current.next;
        }
    }  
    return list.next; 
}
