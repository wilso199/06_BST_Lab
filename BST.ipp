#define NULL 0
#include <string>

template <class Key, class T>
BST<Key,T>::BST(){
  root = NULL;
}

template <class Key, class T>
BST<Key,T>::~BST(){//this calls remove(root->k) as long as size() > 0. Assume remove and size work.
	for(numItems; numItems>0; numItems--){ //Only want to call size() once if possible. 
		remove(root->k);
	}
}
  
//Return the number of items currently in the SSet
template <class Key, class T>
unsigned long BST<Key,T>::size(){ //public, got rid of need to call private method.
  return numItems;
}

template <class Key, class T> /*Got rid of the need to call this method :)*/
unsigned long BST<Key,T>::size(Node<Key,T>* r){ //private. Also, no size variable this time. Really gonna force us to use recursion? Bah...
    unsigned long total = 0;					//Check if root is NULL, then add up left children and right children... Simple?

    if (r==NULL){
        return total;
    }
	total++; //each recursive step adds 1 for the node and maximum of 2 for its children + maximum 2log(h-subtree).
    total += size(r->right);
    total += size(r->left);
   
    return total;
}

//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
template <class Key, class T>
void BST<Key,T>::add(Key k, T x){ //this calls private version, gets back a Node*
  root = add(k, x, root);
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void BST<Key,T>::remove(Key k){//public, calls private version
  root = remove(k, root);
}

//Return the item with Key k. 
// If there is no such item, throw an exception.
template <class Key, class T>
T BST<Key,T>::find(Key k){
   Node<Key, T>* myNode = find(k, root);
    if (myNode==NULL) {
        throw std::string("Your desired key is not in the tree.");
    }
    return myNode->data;
}
//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool BST<Key,T>::keyExists(Key k){//calls private version
	Node<Key,T>* myNode = find(k, root);
	
    if (myNode==NULL) {
        return false;
    } else 
		return true;
}

//If there is a key in the set that is > k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::next(Key k){//calls private version
  Node<Key,T> myNode = next(k, root);
  if(myNode->k > k)
	  return myNode->k;
  return k;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::next(Key k, Node<Key,T>* r){
	Node<Key,T>* cur = r, above = r, below = r; //no need for an explicit stack, just 3 trace pointers
	if(k > r->k){//easy case
		while(k >= cur->k){ //go to the right until you blow past k or run into a NULL
			if(cur->right==NULL)
				return cur;
			cur = cur->right;
		}//end while(k > cur->k)
		while(cur->left != NULL){//go to the left as far as you can to guarantee you find the thing least greater than k
			cur = cur->left;
		}
		return cur;
	}else{
		while(k < cur->k){
			if(cur->left==NULL)
				return cur;//because our parameters are stupid and we don't have to assume k exists in the tree...
			cur = cur->left;
			if(above->left != cur)//this makes sure we have both a greater node above and below to study in the final comparison.
				above = above->left;
		}
		below = cur;//revamp this lower algorithm. Must check each freaking subtree.

		/*if(below->right != NULL){
			below = below->right;
			while(below->left != NULL){ //searching for that which is least greater
				below = below->left;
			}
		}
		if((below->k)-k < 0)
			return above;
		if(below->k < above->k) */
	}
	
 
}

//If there is a key in the set that is < k,
// return the first such key. If not, return k
template <class Key, class T>
Key BST<Key,T>::prev(Key k){//calls private version
  //TODO
  return NULL;
}

//return the first key < k, or return k if no smaller key exists.
template <class Key, class T>
Node<Key,T>* BST<Key,T>::prev(Key k, Node<Key,T>* r){
  //TODO
  return NULL;
}


//Recursion when building is for stupid people...
template <class Key, class T>
Node<Key,T>* BST<Key,T>::add(Key k, T x, Node<Key,T>* r){ //must check if r is null, if the key of root is the same, 
    if(r==NULL){										  //return r if r is not NULL
        Node<Key,T>* myNode = new Node<Key, T>;
        myNode->k = k;
        myNode->data = x;
		numItems++;
        return myNode;
    } //else if(keyExists) -- no need to call this method. I can just take care of it in add()
		//return r;

	Node<Key,T>* cur = r;
	Node<Key,T>* toAdd = new Node<Key, T>; toAdd->k = k; toAdd->data = x;
	while(true){ //using infinite loops for good ;)
		while(k < cur->k){
			if(cur->left == NULL){
				cur->left = toAdd;
				numItems++;
				return r;
			} else
				cur = cur->left;
		}
		while(k > cur->k){
			if(cur->right == NULL){
				cur->right = toAdd;
				numItems++;
				return r;
			} else
				cur = cur->right;
		}
		if(k == cur->k){
			cur->data = x;
			delete toAdd;
			return r;
		}
	}//end while(true)
}//end private version of add

template <class Key, class T>
Node<Key,T>* BST<Key,T>::remove(Key k, Node<Key,T>* r){//private version, make intelligent recurse right/left choices based on k. (check if r is NULL?)
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::find(Key k, Node<Key,T>* r){
	if (r==NULL) {
		return NULL;
    }
	node<Key,T>* cur = r;
    while(true){ //using infinite loops for good ;)
		while(k < cur->k){
			if(cur->left == NULL){
				return NULL;
			} else
				cur = cur->left;
		}
		while(k > cur->k){
			if(cur->right == NULL){
				return NULL;
			} else
				cur = cur->right;
		}
		if(k == cur->k)
			return cur;
	}//end while(true)
}

}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::max(Node<Key,T>* r){
  //TODO
  return NULL;
}

template <class Key, class T>
Node<Key,T>* BST<Key,T>::min(Node<Key,T>* r){
  //TODO
  return NULL;
}
