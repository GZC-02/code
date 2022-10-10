[TOC]

# 二叉树的遍历 及 leetcode题解

去遍历root.left 和root.right 之前先对节点处理就是先序遍历，相应的在遍历完左子树再来处理节点就是就是中序遍历, 遍历完右子树最后处理根节点就是后续遍历，



迭代：自己利用栈去模拟递归过程（用栈模拟系统栈







## [144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

给你二叉树的根节点 `root` ，返回它节点值的 **前序** 遍历。

 

**示例 1：**

![img](../../../picture/inorder_1-16653689071351-16653704413646.jpg)

```
输入：root = [1,null,2,3]
输出：[1,2,3]
```

**示例 2：**

```
输入：root = []
输出：[]
```

**示例 3：**

```
输入：root = [1]
输出：[1]
```

**示例 4：**

![img](../../../picture/inorder_5.jpg)

```
输入：root = [1,2]
输出：[1,2]
```

**示例 5：**

![img](../../../picture/inorder_4.jpg)

```
输入：root = [1,null,2]
输出：[1,2]
```

 

**提示：**

- 树中节点数目在范围 `[0, 100]` 内
- `-100 <= Node.val <= 100`

 

**进阶：**递归算法很简单，你可以通过迭代算法完成吗？

题目链接：https://leetcode.cn/problems/binary-tree-preorder-traversal/

### 1.递~~龟~~归

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v) {
        if( nullptr == root) return ;
        v.push_back(root->val);
        inorder(root->left,v);       
        inorder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        return v;
    }
};
```





### 2.迭代



```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>s;
        while(nullptr != root || !s.empty()) {
            while(nullptr != root ) {
                s.emplace(root);
                v.emplace_back(root->val);
                root=root->left;
            }
            root = s.top();
            s.pop();
            root=root->right;
        }
        return v;
    }
};
```



3.morris前序遍历

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 不改变树结构版Morris遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
```





## [94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)



给定一个二叉树的根节点 `root` ，返回 *它的 **中序** 遍历* 。

 

**示例 1：**

![img](../../../picture/inorder_1.jpg)

```
输入：root = [1,null,2,3]
输出：[1,3,2]
```

**示例 2：**

```
输入：root = []
输出：[]
```

**示例 3：**

```
输入：root = [1]
输出：[1]
```

 

**提示：**

- 树中节点数目在范围 `[0, 100]` 内
- `-100 <= Node.val <= 100`

 

**进阶:** 递归算法很简单，你可以通过迭代算法完成吗？

题目链接：https://leetcode.cn/problems/binary-tree-inorder-traversal/

### 1.递~~龟~~归



```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v) {
        if( nullptr == root) return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        return v;
    }
};
```



时间复杂度：O(n)

空间复杂度：O(n)



### 2.迭代

​		递归的实现就是：每一次递归调用都会把函数的局部变量、参数值和返回地址等压入调用栈中，而**迭代的时候就需要显式地将这个栈模拟出来，其他都相同**。



```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>s;
        while(nullptr != root || !s.empty()) {
            while(nullptr != root) {
                s.push(root);
                root=root->left;
            }

            root=s.top();
            s.pop();
            v.push_back(root->val);
            root=root->right;
        }
        return v;
    }
};
```



时间复杂度：O(n)

空间复杂度：O(n)





### 3.Morris(莫里斯）中序遍历

morris遍历是二叉树遍历算法的超强进阶算法
morris遍历利用的是树的叶节点左右孩子为空（树的大量空闲指针），实现空间开销的极限缩减。

#### morris遍历的实质

> 建立一种机制，**对于没有左子树的节点只到达一次，对于有左子树的节点会到达两次**

> 记当前节点为node
>
> 如果node无左孩子，node向右移动
>
> 如果node有左孩子 ，找到node左子树最右节点，记作rightnode
>
> ​        如果rightnode的right指针指向空，让其指向node，node向左移动
>
> ​		如果rightnode的right指针指向node，让其指向空，node向右移动

​		

​		假设当前遍历到的节点为 xx，将 xx 的左子树中最右边的节点的右孩子指向 xx，这样在左子树遍历完成后我们通过这个指向走回了 xx，且能通过这个指向知晓我们已经遍历完成了左子树，而不用再通过栈来维护，省去了栈的空间复杂度。


​		一种遍历二叉树的方法，它能将非递归的中序遍历空间复杂度降为 O(1).

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 不改变树结构版Morris遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
```

```

void Morris_inorderTraversal_PLUS(TreeNode* root) {
	TreeNode* curr = root;
	TreeNode* pre;
	while (curr != NULL) {
		if (curr->left == NULL) {    // 左孩子为空
			cout << curr->val;
			curr = curr->right;
		}
		else {   // 左孩子不为空
			// 找左子树中的最右节点
			// ***** 修改处 *****
			pre = curr->left;
                        // 新增一个条件，防止循环
			while (pre->right != NULL && pre->right != curr) { 
				pre = pre->right;
			}
            
			// 第一次访问curr节点:
                        // 找到左子树中的最右节点，添加link，节点移动向左子树；
			if (pre->right == NULL) {  
				pre->right = curr;
				curr = curr->left;
			}
                       // 由于左子树中的最右节点已经建立起link，
                       // 所以这是第二次访问curr节点
                       // 这次访问curr节点时断开link,
                       // 并移动到右子树，避免循环。（断开link后树结构不变）
			else {
				pre->right = NULL;
				cout << curr->val;
				curr = curr->right;
			}
			
		}
	}
}
```

时间复杂度：O(n)

空间复杂度：O(1)





在树的深度优先遍历中（包括前序、中序、后序遍历），递归方法最为直观易懂，但考虑到效率，我们通常不推荐使用递归。

栈迭代方法虽然提高了效率，但其嵌套循环却非常烧脑，不易理解，容易造成“一看就懂，一写就废”的窘况。而且对于不同的遍历顺序（前序、中序、后序），循环结构差异很大，更增加了记忆负担。

因此，我在这里介绍一种“颜色标记法”（瞎起的名字……），兼具栈迭代方法的高效，又像递归方法一样简洁易懂，更重要的是，这种方法对于前序、中序、后序遍历，能够写出完全一致的代码。

其核心思想如下：

使用颜色标记节点的状态，新节点为白色，已访问的节点为灰色。
如果遇到的节点为白色，则将其标记为灰色，然后将其右子节点、自身、左子节点依次入栈。
如果遇到的节点为灰色，则将节点的值输出。
使用这种方法实现的中序遍历如下：

```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        WHITE, GRAY = 0, 1
        res = []
        stack = [(WHITE, root)]
        while stack:
            color, node = stack.pop()
            if node is None: continue
            if color == WHITE:
                stack.append((WHITE, node.right))
                stack.append((GRAY, node))
                stack.append((WHITE, node.left))
            else:
                res.append(node.val)
        return res
```


如要实现前序、后序遍历，只需要调整左右子节点的入栈顺序即可。

颜色标记法

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, int> > stk;
        stk.push((make_pair(root, 0)));
        
        while(!stk.empty()) {
            auto [node, type] = stk.top();
            stk.pop();
            if(node == nullptr) continue;
            if(type == 0) {
                stk.push(make_pair(node->right, 0));
                stk.push(make_pair(node, 1));
                stk.push(make_pair(node->left, 0));
            }
            else result.emplace_back(node->val);
        }

        return result;

    }
};
/*auto [node, type] = stk.top();//这个复制赋值操作，感觉上没有比java引用赋值操作快
你好，这里不可以用 auto& [temp, flag] = st.top();
引用的本质是指针，使用 & 后, temp 指向了当前 st 的栈顶位置 下一行代码 st.pop(), 会弹出栈顶元素，但是 temp 依旧指向栈顶，而不是指向弹出的那个值 下一次 push 时，新的元素入栈，temp会指向了这个新元素，成了这个新元素的引用，而这不是我们想要的
*/
```

## [145. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

给你一棵二叉树的根节点 `root` ，返回其节点值的 **后序遍历** 。

 

**示例 1：**

![img](../../../picture/pre1.jpg)

```
输入：root = [1,null,2,3]
输出：[3,2,1]
```

**示例 2：**

```
输入：root = []
输出：[]
```

**示例 3：**

```
输入：root = [1]
输出：[1]
```

 

**提示：**

- 树中节点的数目在范围 `[0, 100]` 内
- `-100 <= Node.val <= 100`

 

**进阶：**递归算法很简单，你可以通过迭代算法完成吗？

题目链接：https://leetcode.cn/problems/binary-tree-postorder-traversal/



### 1.递归



```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v) {
        if( nullptr == root) return ;
        inorder(root->left,v);      
        inorder(root->right,v);
        v.push_back(root->val);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        return v;
    }
};
```







### 2.迭代



```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>s;
        TreeNode *pre = nullptr; //前驱节点
        while(nullptr != root || !s.empty()) {
            while(nullptr != root) {
                s.emplace(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if (root->right == nullptr || root->right == pre) {
                v.emplace_back(root->val);
                pre = root;
                root = nullptr;
            } else {
                s.emplace(root);
                root = root->right;
            }
        }
        return v;
    }
};
```



### 3.morris后序遍历

```c++
class Solution {
public:
    void addPath(vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.emplace_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                    addPath(res, p1->left);
                }
            }
            p1 = p1->right;
        }
        addPath(res, root);
        return res;
    }
};
```

