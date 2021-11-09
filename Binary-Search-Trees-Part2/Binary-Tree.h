//************************  genBST.h  **************************
//                 generic binary search tree
using namespace std;

template<class T>
class BSTNode {
public:
    BSTNode() {
        left = right = 0;
    }
    BSTNode(const T& e, BSTNode<T>* l = 0, BSTNode<T>* r = 0) {
        el = e; left = l; right = r;
    }
    T el;
    BSTNode<T>* left, * right;
};

template<class T>
class BST {
public:
    BST() {
        root = 0;
    }
    ~BST() {
        clear();
    }
    void clear() {
        clear(root);
        root = 0;
    }
    bool isEmpty() const {
        return root == 0;
    }
    void preorder() {
        preorder(root);
    }
    void inorder() {
        inorder(root);
    }
    void postorder() {
        postorder(root);
    }
    T* search(const T& el) const {
        return search(root, el);
    }
    int height() {
        return height(root);
    }
    int nodeCount() {
        return nodeCount(root);
    }
    int leavesCount() {
        return leavesCount(root);
    }
    void printTree() const {
        printTree(root, 0);
    }
    int height(BSTNode<T>* p);
    int max(int x, int y);
    int nodeCount(BSTNode<T>* p);
    int leavesCount(BSTNode<T>* p);
    void insert(const T&);
    void deleteByCopying(BSTNode<T>*&);
    void findAndDeleteByCopying(const T&);
    void printTree(BSTNode<T>* p, int depth) const;

protected:
    BSTNode<T>* root;
    void clear(BSTNode<T>*);
    T* search(BSTNode<T>*, const T&) const;
    void preorder(BSTNode<T>*);
    void inorder(BSTNode<T>*);
    void postorder(BSTNode<T>*);
    virtual void visit(BSTNode<T>* p) {
        cout << p->el << ' ';
    }
};

template<class T>
void BST<T>::printTree(BSTNode<T>* p, int depth) const {
    if (p != 0) {
        printTree(p->right, depth + 1);
        for (int i = 1; i <= depth; i++) {
            cout << "   ";
        }
        cout << p->el << endl;
        printTree(p->left, depth + 1);
    }
}

template<class T>
int BST<T>::leavesCount(BSTNode<T>* p) {
    if (p == 0)
        return 0;
    else if (p->left == 0 && p->right == 0)
        return 1;
    else
        return leavesCount(p->left) + leavesCount(p->right);
}

template<class T>
int BST<T>::nodeCount(BSTNode<T>* p) {
    if (p != 0)
        return nodeCount(p->left) + nodeCount(p->right) + 1;
    else return 0;
}

template <class T>
int BST<T>::height(BSTNode<T>* p)
{
    if (p == 0)
        return 0;
    else
        return 1 + max(height(p->left), height(p->right));
}

template <class T>
int BST<T>::max(int x, int y)
{
    if (x >= y)
        return x;
    else
        return y;
}

template<class T>
void BST<T>::clear(BSTNode<T>* p) {
    if (p != 0) {
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

template<class T>
void BST<T>::insert(const T& el) {
    BSTNode<T>* p = root, * prev = 0;
    while (p != 0) {  // find a place for inserting new node;
        prev = p;
        if (el < p->el)
            p = p->left;
        else p = p->right;
    }
    if (root == 0)    // tree is empty;
        root = new BSTNode<T>(el);
    else if (el < prev->el)
        prev->left = new BSTNode<T>(el);
    else prev->right = new BSTNode<T>(el);
}

template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) const {
    while (p != 0)
        if (el == p->el)
            return &p->el;
        else if (el < p->el)
            p = p->left;
        else p = p->right;
    return 0;
}

template<class T>
void BST<T>::inorder(BSTNode<T>* p) {
    if (p != 0) {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template<class T>
void BST<T>::preorder(BSTNode<T>* p) {
    if (p != 0) {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template<class T>
void BST<T>::postorder(BSTNode<T>* p) {
    if (p != 0) {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

template<class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node) {
    BSTNode<T>* previous, * tmp = node;
    if (node->right == 0)                  // node has no right child;
        node = node->left;
    else if (node->left == 0)               // node has no left child;
        node = node->right;
    else {
        tmp = node->left;                  // node has both children;
        previous = node;                  // 1.
        while (tmp->right != 0) {         // 2.
            previous = tmp;
            tmp = tmp->right;
        }
        node->el = tmp->el;               // 3.
        if (previous == node)
            previous->left = tmp->left;
        else previous->right = tmp->left; // 4.
    }
    delete tmp;                            // 5.
}

// findAndDeleteByCopying() searches the tree to locate the node containing
// el. If the node is located, the function DeleteByCopying() is called.

template<class T>
void BST<T>::findAndDeleteByCopying(const T& el) {
    BSTNode<T>* p = root, * prev = 0;
    while (p != 0 && !(p->el == el)) {
        prev = p;
        if (el < p->el)
            p = p->left;
        else p = p->right;
    }
    if (p != 0 && p->el == el)
        if (p == root)
            deleteByCopying(root);
        else if (prev->left == p)
            deleteByCopying(prev->left);
        else deleteByCopying(prev->right);
    else if (root != 0)
        cout << "el " << el << " is not in the tree\n";
    else cout << "the tree is empty\n";
}


