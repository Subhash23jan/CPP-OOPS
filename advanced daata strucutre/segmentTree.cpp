#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> lazy, tree;

    void buildTree(vector<int>& vec, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = vec[l];
            return;
        }
        int mid = (l + r) / 2;
        buildTree(vec, 2 * idx + 1, l, mid);
        buildTree(vec, 2 * idx + 2, mid + 1, r);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void lazyUpdate(int ind, int val, int l, int r, int low, int high) {
        if (lazy[ind] != 0) {
            tree[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high < l || r < low) return;
        if (low >= l && high <= r) {
            tree[ind] += (high - low + 1) * val;
            if (low != high) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        int mid = (low + high) / 2;
        lazyUpdate(2 * ind + 1, val, l, r, low, mid);
        lazyUpdate(2 * ind + 2, val, l, r, mid + 1, high);
        tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
    }

    int sumQuery(int ind, int l, int r, int low, int high) {
        if (lazy[ind] != 0) {
            tree[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (r < low || high < l) return 0;
        if (low >= l && high <= r) {
            return tree[ind];
        }
        int mid = (low + high) / 2;
        return sumQuery(2 * ind + 1, l, r, low, mid) + sumQuery(2 * ind + 2, l, r, mid + 1, high);
    }

public:
    SegmentTree(vector<int>& vec) {
        this->n = vec.size();
        lazy.resize(4 * n, 0);
        tree.resize(4 * n, 0);
        buildTree(vec, 0, 0, n - 1);
    }

    void update(int l, int r, int val) {
        lazyUpdate(0, val, l, r, 0, n - 1);
    }

    int rangeSumQuery(int l, int r) {
        return sumQuery(0, l, r, 0, n - 1);
    }
};

int main() {
    vector<int> vec = {3, 4, 2, 6, 7, 1, 5};
    SegmentTree seg(vec);

    int choice, l, r, val;
    cout << "Segment Tree Operations:\n";
    cout << "1. Update Range\n";
    cout << "2. Range Sum Query\n";
    cout << "3. Exit\n";

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter range (l, r) and value to add: ";
            cin >> l >> r >> val;
            if (l < 0 || r >= vec.size() || l > r) {
                cout << "Invalid range!" << endl;
                continue;
            }
            seg.update(l, r, val);
            cout << "Range updated." << endl;
        } else if (choice == 2) {
            cout << "Enter range (l, r) for sum query: ";
            cin >> l >> r;
            if (l < 0 || r >= vec.size() || l > r) {
                cout << "Invalid range!" << endl;
                continue;
            }
            int ans = seg.rangeSumQuery(l, r);
            cout << "Range sum: " << ans << endl;
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
