#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        // init initial node without children
        this -> value = 0;
        this -> left = NULL;
        this -> right = NULL;   
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        Node *newNode = new Node;
        newNode -> value = value;
        if(newNode->value < this->value){
            this -> left = newNode;
        }
        else{
            this -> right = newNode;
        }
        
    }

	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        int heightLeft =0;
        int heightRight =0;
        if (this->left==NULL && this->right==NULL){
            return 1;
        }
        else{
            while(this->left==value ){
                heightLeft =+1;
            }
            while(this->right == value){
                heightRight =+1;
            }
        }
        if (heightLeft<heightRight){
            return heightRight;
        }
        else {
            return heightLeft;
        }
        
        
    }

	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        int countLeft = 0;
        int countRight =0;
        if (this->left==NULL && this->right==NULL){
           return 1;
        }
        else {
            while(this->left !=nullptr){
                countLeft+=1;
            }
            while(this->right !=nullptr){
                countRight+=1;
            }
            return countLeft+countRight;
        }
        
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if (this->left==NULL && this->right==NULL){
            return true;
        }
        else{
            return false;
        }
        
	}

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
        if (this->isLeaf()){
            leaves[leavesCount]=this;
            leavesCount ++;
        }

        while (this->right !=nullptr){
            leaves[leavesCount]=this->right;
            leavesCount ++;
        }
        while (this->left !=nullptr){
            leaves[leavesCount]=this->left;
            leavesCount ++;
        }
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
	}

	Node* find(int value) {
        // find the node containing value
        if (this->value == value){
            return this;
        }
        else{
            if (this->value<value){
                this->left->find(value);
            }
            else {
                this->right->find(value);
            }
        }
		return nullptr;
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}
