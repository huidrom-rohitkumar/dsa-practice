// Check if Subtree — GFG
// Approach: Recursive identity check at every node of T
// Time: O(N * M)  |  Space: O(H_T) recursion stack
//
// For O(N + M): serialize both trees with null markers + KMP substring search.
// Recursive approach is preferred in interviews for its clarity and directness.

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
    bool identical(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return a->data == b->data &&
               identical(a->left,  b->left)  &&
               identical(a->right, b->right);
    }
public:
    bool isSubTree(Node* T, Node* S) {
        if (!S) return true;
        if (!T) return false;
        if (identical(T, S)) return true;
        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};

// -----------------------------------------------------------------------
// O(N + M) Serialization Approach (for reference)
// -----------------------------------------------------------------------
//
// void serialize(Node* root, string& s) {
//     if (!root) { s += "#,"; return; }
//     s += to_string(root->data) + ",";
//     serialize(root->left,  s);
//     serialize(root->right, s);
// }
//
// bool isSubTree_linear(Node* T, Node* S) {
//     string ts, ss;
//     serialize(T, ts);
//     serialize(S, ss);
//     return ts.find(ss) != string::npos;  // replace find() with KMP for strict O(N+M)
// }
