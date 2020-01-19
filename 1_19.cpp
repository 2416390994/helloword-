//void RotateRight(Node* pParent_1)  //特殊结点1
//{
//	Node* pSubL = pParent_1->_pLeft;  //特殊结点2
//	Node* pSubLR = pSubL->_pRight;  //特殊结点3
//	pParent->_pLeft = pSubLR;
//	//这里的判空主要是为了避免第三种情况，左单支
//	if (pSubLR)  //如果特殊结点3不为空的话，就让特殊节点3的双亲指针域指向特殊结点1
//		pSubLR->_pParent = pParent_1;
//	pSubL->_pRight = pParent_1;
//	//接着就是处理特殊节点中的pParent_1结点
//	//由于pParent_1我们不知道是不是根节点,因为我们局部画出来的pParent就是一个根结点，但是我们不能保证上面就没有其他的结点了
//	//所以这里要分情况讨论
//	//如果是pParent_1是子树的话，也就是说pParent的上面还有树
//	//为了防止丢失pParent_1的双亲结点，这里我们先将pParent的双亲保存起来
//	Node* pPParent = pParent_1->_pParent;   //特殊结点1的双亲结点有可能是空
//	pParent_1->_pParent = pSubL;  //重新设置双亲
//	pSubL->_pParent = pPParent;
//
//
//	if (pPParent == nullptr)  //说明特殊结点1没有双亲，
//	{
//		_pRoot = pSubL;  //没有双亲的话，就直接更新类中的根节点为特殊结点2
//	}
//	else //说明特殊结点1有双亲
//	{
//		if (pPParent->_pLeft == pParent_1)  //此时虽然更新了特殊节点1的双亲，但是特殊节点1原来的双亲，还是将特殊结点1，视为自己的孩子
//			//所以说如果，特殊节点1是之前双亲的左孩子的话，就需要让他的左孩子现在指向特殊节点2，反之就是让右孩子指向特殊节点2
//			pPParent->_pLeft = pSubL;
//		else
//			pPParent->_pRight = pSubL;
//	}
//
//	//接着是更新平衡因子
//	//选装更新完毕之后，特殊节点1和特殊结点2的平衡因子都变成0
//	//特殊结点1的双亲结点平衡因子不变
//	pParent_1->_bf = pSubL->_bf = 0;
//}
//
