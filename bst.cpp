/*
 * bst.cpp
 *
 */

#ifndef BST_CPP
#define BST_CPP


/* TODO
 * Goal: To search for an item x with key k from the BST tree
 * Return: A pointer to the subtree whose root node contains the item if found,
 *         otherwise a NULL pointer.
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::search(const K& k)
{
    //write your codes here
	if (this->is_empty()) {
		return NULL;
	}
	if (this->root->key == k) {
		return this;
	}
	else {
		if (k < this->root->key) {
			return this->left_subtree()->search(k);
		}
		else {
			return this->right_subtree()->search(k);
		}
	}
}


/* TODO
 * Goal: To find the minimum node stored in a BST tree.
 * Return: A pointer to the subtree whose root node contains the minimum key
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::find_min()
{
    //write your codes here
	if (this->left_subtree()->is_empty()) {
		return this;
	}
	else {
		return this->left_subtree()->find_min();
	}
}


/* TODO
 * Goal: To insert an item x with key k to a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::insert(const T& x, const K& k)
{
    //write your codes here
	if (this->is_empty()) {
		this->root = new typename BST<T,K>::node(x,k);
		this->root->left = new BST<T,K>;
		this->root->right = new BST<T,K>;

	}
	else if (k < this->root->key)
		this->left_subtree()->insert(x, k);



	else if (k > this->root->key)
		this->right_subtree()->insert(x,k);

}


/* TODO
 * Goal: To remove an item with key k in a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::remove(const K& k)
{    
    //write your codes here
	if (this->is_empty()) {
		return;
	}
	if (k < this->root->key) {
		this->left_subtree()->remove(k);
	}
	else {
		if (k > this->root->key) {
			this->right_subtree()->remove(k);
		}
		else {
			if (dynamic_cast<BST*>(this->left_subtree())->root && dynamic_cast<BST*>(this->right_subtree())->root ) {
				this->root->value = dynamic_cast<BST*>(this->root->right->find_min())->root->value;
				this->root->key = dynamic_cast<BST*>(this->root->right->find_min())->root->key;
				this->root->right->remove(this->root->key);
			}
			else {
				typename BST<T,K>::node* deleting_node = this->root;
				this->root = (this->root->left->is_empty())
						? dynamic_cast<BST*>(this->root->right)->root : dynamic_cast<BST*>(this->root->left)->root;
				dynamic_cast<BST*>(deleting_node->left)->root = dynamic_cast<BST*>(deleting_node->right)->root = NULL;
				delete deleting_node;
			}
		}
	}
}



/* TODO
 * Goal: Clear the node stack and set current pointer to the root
 */
template<typename T, typename K>
void BST<T,K>::iterator_init()
{
    //write your codes here
	while (!this->istack.empty()) {
		this->istack.pop();
	}
	this->current = this->root;
}

/* TODO
 * Goal: Check whether the next smallest node exists
 */
template<typename T, typename K>
bool BST<T,K>::iterator_end()
{
     //write your codes here
	if(this->root->left->is_empty()) {
		return false;
	}
	return true;
}

/* TODO
 * Goal: Return the value of next smallest node from the tree
 */
template<typename T, typename K>
T& BST<T,K>::iterator_next()
{
    //write your codes here
	return dynamic_cast<BST*>(this->left_subtree())->root->value;
}

#endif /* BST_CPP */
