#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *input_tree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    Node *root = new Node(data);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int left_data, right_data;
        cin >> left_data;
        if (left_data != -1)
        {
            temp->left = new Node(left_data);
            q.push(temp->left);
        }
        cin >> right_data;
        if (right_data != -1)
        {
            temp->right = new Node(right_data);
            q.push(temp->right);
        }
    }
    return root;
}

void preorder_traversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    preorder_traversal(root->left);
    cout << root->data << " ";
    preorder_traversal(root->right);
}

void print_left_outer(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left&& root->right)
    {
        print_left_outer(root->left);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        print_left_outer(root->left);
        cout << root->data << " ";
    }
    else if (root->right)
    {
        print_left_outer(root->right);
        cout << root->data << " ";
    }
    else if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }
}

void print_right_outer(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left != nullptr && root->right != nullptr)
    {
        cout << root->data << " ";
        print_right_outer(root->right);
    }
    else if (root->left != nullptr && root->right == nullptr)
    {
        cout << root->data << " ";
        print_right_outer(root->left);
    }
    else if (root->right != nullptr && root->left == nullptr)
    {
        cout << root->data << " ";
        print_right_outer(root->right);
    }
    else if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->data << " ";
        return;
    }
}
int count_total_Node(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return count_total_Node(root->left) + count_total_Node(root->right) + 1;
}

int return_level(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int l = return_level(root->left);
    int r = return_level(root->right);

    return max(l, r) + 1;
}

int return_sum_without_leaf(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }
    int l = return_sum_without_leaf(root->left);
    int r = return_sum_without_leaf(root->right);
    return l + r + root->data;
}

void print_level_x(Node *root, int x)
{
    queue<Node *> q;
    q.push(root);

    int level = 0;

    while (!q.empty())
    {

        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (level == x)
            {
                cout << temp->data << " ";
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        level++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *root = input_tree();

    // cout << return_sum_without_leaf(root) << "\n";

    int level = return_level(root);

    // int total_Node = pow(2, level) - 1;
    // cout << total_Node << "\n";
    // if (total_Node == count_total_Node(root))
    // {
    //     cout << "YES\n";
    // }
    // else
    // {
    //     cout << "NO\n";
    // }

    // int x;
    // cin >> x;

    // if(level < x){
    //     cout << "Invalid\n";
    // }
    // else {
    //     print_level_x(root, x);
    // }

    // preorder_traversal(root);
    if (root->left && root->right)
    {
        print_left_outer(root);
        print_right_outer(root->right);
    }

    else if (root->left)
    {
        print_left_outer(root);
    }
    else if (root->left == NULL)
    {
        print_right_outer(root);
    }
    else{
        cout << root->data << " ";
    }

    return 0;
}
