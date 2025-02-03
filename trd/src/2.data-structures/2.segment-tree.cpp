struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n, const vector<int> &a) : n(n) {
        tree.assign(4 * n, 0);
        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, i, a[i]);
        }
    }

    int combine(int x, int y) {
        return x + y;
    }

    int update(int id, int s, int e, int pos, int val) {
        if (s == e) {
            return tree[id] = combine(tree[id], val);
        }
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            update(id << 1, s, mid, pos, val);
        } else {
            update(id << 1 | 1, mid + 1, e, pos, val);
        }
        return tree[id] = combine(tree[id << 1], tree[id << 1 | 1]);
    }

    int query(int id, int s, int e, int lq, int rq) {
        if (rq < s || lq > e) {
            return 0;
        }
        if (lq <= s && e <= rq) {
            return tree[id];
        }
        int mid = (s + e) >> 1;
        return combine(query(id << 1, s, mid, lq, rq),
               query(id << 1 | 1, mid + 1, e, lq, rq));
    }
};
