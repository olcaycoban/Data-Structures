class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/



void pre0rder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data;
    pre0rder(root->left);
    pre0rder(root->right);
}