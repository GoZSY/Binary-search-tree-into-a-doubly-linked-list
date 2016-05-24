/*********************************************************************
类似于树的中序遍历，先处理左子树，然后将左子树得到的链表的最后与根结点
连接，接着处理右子树，右子树的最小的结点与根节点连接，遍历的过程中记录
一直记录最后的结点，最终需要返回起始的结点
**********************************************************************/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        TreeNode* lastNode = NULL;
        ConvertNode(pRootOfTree, &lastNode);
        TreeNode* pHead = lastNode;
        while(pHead && pHead->left)
            pHead = pHead->left;
        return pHead;
        
    }
private:
    void ConvertNode(TreeNode* pRoot, TreeNode** lastNode)
    {
        if(pRoot == NULL)
            return;
        TreeNode* pCur = pRoot;
        if(pCur->left)
            ConvertNode(pRoot->left, lastNode);
        pCur->left = *lastNode;
        if(*lastNode)
        {
            (*lastNode)->right = pCur;
        }
        *lastNode = pCur;
        if(pCur->right)
            ConvertNode(pRoot->right, lastNode);
    }
};
