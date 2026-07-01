/*
// Definition for a Node.
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};
*/

struct Node* connect(struct Node* root) {
    if (root == NULL)
        return NULL;

    struct Node *curr = root;

    while (curr != NULL) {

        struct Node *head = NULL;
        struct Node *prev = NULL;

        while (curr != NULL) {

            if (curr->left != NULL) {
                if (prev != NULL)
                    prev->next = curr->left;
                else
                    head = curr->left;

                prev = curr->left;
            }

            if (curr->right != NULL) {
                if (prev != NULL)
                    prev->next = curr->right;
                else
                    head = curr->right;

                prev = curr->right;
            }

            curr = curr->next;
        }

        curr = head;
    }

    return root;
}