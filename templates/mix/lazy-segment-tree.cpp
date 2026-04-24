struct LazySegmentTree {
    int n;
    vector<long long> tree;
    vector<long long> lazy;

    LazySegmentTree(int n, const vector<int>& a) : n(n) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int id, int l, int r, const vector<int>& a) {
        if (l == r) {
            tree[id] = a[l];
            return;
        }
        
        int mid = (l + r) / 2;
        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);
        tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }

    long long update(int id, int l, int r, int ql, int qr, int val) {
        if (lazy[id]) {
            tree[id] += (r - l + 1) * lazy[id];
            if (l < r) {
                lazy[id << 1] += lazy[id];
                lazy[id << 1 | 1] += lazy[id];
            }
            lazy[id] = 0;
        } 

        if (ql > r || l > qr)
            return 0;

        if (ql <= l && r <= qr) {
            tree[id] += (r - l + 1) * val;
            if (l < r) {
                lazy[id << 1] += val;
                lazy[id << 1 | 1] += val;
            }
            return tree[id];
        }

        int mid = (l + r) / 2;
        update(id << 1, l, mid, ql, qr, val);
        update(id << 1 | 1, mid + 1, r, ql, qr, val);
        return tree[id] = tree[id << 1] + tree[id << 1 | 1]; 
    }

    long long query(int id, int l, int r, int ql, int qr) {
        if (lazy[id]) {
            tree[id] += (r - l + 1) * lazy[id];
            if (l < r) {
                lazy[id << 1] += lazy[id];
                lazy[id << 1 | 1] += lazy[id]; 
            }
            lazy[id] = 0;
        }

        if (ql > r || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return tree[id];

        int mid = (l + r) / 2;
        return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
    }
};