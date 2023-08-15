void PrintBstRecursive(Node* node)
{
    if (node != nullptr)
    {
        std::cout << node->val << " ";
    } else {
        return;
    }

    PrintBST(node->left);
    PrintBST(node->right);
}

