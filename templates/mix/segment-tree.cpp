struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n, const vector<int> &a) : n(n) {
        tree.assign(4 * n, 0);
        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, i, a[i]);
        }
    }

    int update(int id, int l, int r, int pos, int val) {
        if (l == r)
            return tree[id] = combine(tree[id], val);

        int mid = (l + r) >> 1;
        if (pos <= mid) {
            update(id << 1, l, mid, pos, val);
        } else {
            update(id << 1 | 1, mid + 1, r, pos, val);
        }

        return tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }

    int query(int id, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return 0;

        if (ql <= l && r <= qr)
            return tree[id];

        int mid = (l + r) >> 1;

        return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
    }
};
