#Function to traverse binary search tree level by level from left to right
def levelOrder(root):
    queue = list()
    if root == None :
        return
    queue.append(root)
    while(len(queue)!=0) :
        ele = queue.pop(0)
        print(ele.info, end=" ")
        if ele.left :
            queue.append(ele.left)
        if ele.right :
            queue.append(ele.right)
