#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode *next[26];
    int index;
    int *palList;
    int palCount;
} TrieNode;

TrieNode* createNode() {
    TrieNode *node = (TrieNode*)calloc(1, sizeof(TrieNode));
    node->index = -1;
    node->palList = NULL;
    node->palCount = 0;
    return node;
}

int isPalindrome(char *s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--])
            return 0;
    }
    return 1;
}

void addPalindromeIndex(TrieNode *node, int idx) {
    node->palList = realloc(node->palList, (node->palCount + 1) * sizeof(int));
    node->palList[node->palCount++] = idx;
}

void insert(TrieNode *root, char *word, int idx) {
    int len = strlen(word);

    for (int i = len - 1; i >= 0; i--) {

        if (isPalindrome(word, 0, i))
            addPalindromeIndex(root, idx);

        int c = word[i] - 'a';

        if (!root->next[c])
            root->next[c] = createNode();

        root = root->next[c];
    }

    root->index = idx;
    addPalindromeIndex(root, idx);
}

int** palindromePairs(char** words, int wordsSize,
                       int* returnSize, int** returnColumnSizes) {

    TrieNode *root = createNode();

    for (int i = 0; i < wordsSize; i++)
        insert(root, words[i], i);

    int capacity = wordsSize * wordsSize;
    int **result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < wordsSize; i++) {

        TrieNode *curr = root;
        char *word = words[i];
        int len = strlen(word);

        for (int j = 0; j < len; j++) {

            if (curr->index != -1 &&
                curr->index != i &&
                isPalindrome(word, j, len - 1)) {

                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = i;
                result[*returnSize][1] = curr->index;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }

            curr = curr->next[word[j] - 'a'];

            if (!curr)
                break;
        }

        if (!curr)
            continue;

        for (int k = 0; k < curr->palCount; k++) {

            int idx = curr->palList[k];

            if (idx == i)
                continue;

            result[*returnSize] = (int*)malloc(2 * sizeof(int));
            result[*returnSize][0] = i;
            result[*returnSize][1] = idx;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }

    return result;
}