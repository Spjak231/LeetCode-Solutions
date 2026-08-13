class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int len;
        int prefix;
        int suffix;
        int best;

        Node() {
            leftChar = rightChar = '#';
            len = 0;
            prefix = suffix = best = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node left, Node right) {

        if (left.len == 0)
            return right;

        if (right.len == 0)
            return left;

        Node ans;

        ans.len = left.len + right.len;

        ans.leftChar = left.leftChar;
        ans.rightChar = right.rightChar;

        // Initially
        ans.prefix = left.prefix;
        ans.suffix = right.suffix;

        ans.best = max(left.best, right.best);

        // Can join left suffix + right prefix
        if (left.rightChar == right.leftChar) {

            ans.best = max(ans.best,
                           left.suffix + right.prefix);

            // IMPORTANT:
            // left segment must be completely same
            if (left.prefix == left.len) {
                ans.prefix = left.len + right.prefix;
            }

            // right segment must be completely same
            if (right.suffix == right.len) {
                ans.suffix = left.suffix + right.len;
            }
        }

        return ans;
    }

    void build(string &s, int node, int start, int end) {

        if (start == end) {

            tree[node].leftChar = s[start];
            tree[node].rightChar = s[start];

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = start + (end - start) / 2;

        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);

        tree[node] = merge(tree[2 * node],
                           tree[2 * node + 1]);
    }

    void update(int node, int start, int end,
                int index, char ch) {

        if (start == end) {

            tree[node].leftChar = ch;
            tree[node].rightChar = ch;

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid) {
            update(2 * node, start, mid, index, ch);
        }
        else {
            update(2 * node + 1, mid + 1, end, index, ch);
        }

        tree[node] = merge(tree[2 * node],
                           tree[2 * node + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};