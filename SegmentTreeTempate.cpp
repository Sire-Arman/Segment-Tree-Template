#include <bits/stdc++.h>
#define lli long long int
#define flp(a, b) for (int i = a; i < b; i++)
#define sz(a) a.size()
#define vi(a) vector<int> a
#define vin(a, n) vector<int> a(n)
using namespace std;
// building tree to store answers related to particular segments (here minimum value in the range)
class SegmentTree{
    public:
    vi(seg);
    SegmentTree(int n){
        seg.resize(4*n+1);
    }

void build(int ind, int low, int high, vi(arr))
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    // left
    build(2 * ind + 1, low, mid, arr);
    // right
    build(2 * ind + 2, mid + 1, high, arr);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

// Asking tree the answers for the given range
int query(int ind, int low, int high, int l, int r)
{
    // No overlap : return maximum (dont need this answer)
    if (low > r || high < l)
    {
        return INT_MAX;
    }
    // complete overlap : return value
    else if (low >= l && high <= r)
    {
        return seg[ind];
    }
    // partial overlap (go left and right to get No or complete overlap)
    else
    {
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
}
// changing and updating the seg tree
void update(int ind, int l, int r, int i, int val)
{
    if (l == r)
    {
        seg[ind] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid)
    {
        update(2 * ind + 1, l, mid, i, val);
    }
    else
    {
        update(2 * ind + 2, mid + 1, r, i, val);
    }
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}
};
// driver function
void solve()
{
    int n;
    cin >> n;
    vin(arr, n);
    // int arr[n];
    flp(0, n) cin >> arr[i];
    SegmentTree sg(n);
    // int seg[4 * n] = {0};
    // building seg tree
    sg.build(0, 0, n - 1, arr);
    // flp(0, 4 * n) cout << seg[i] << ' ';
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << sg.query(0, 0, n - 1, l, r) << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            sg.update(0, 0, n - 1, i, val);
            arr[i] = val;
        }
    }
}

void solve2()
{
    int n1;
    cin >> n1;
    vin(a1, n1);
    flp(0, n1) cin >> a1[i];
    int n2;
    cin >> n2;
    vin(a2, n2);
    flp(0, n2) cin >> a2[i];
    // vin(seg1, 4 * n1);
    // vin(seg2, 4 * n2);
    SegmentTree sg1(n1);
    SegmentTree sg2(n2);
    // int seg1[4*n1], seg2[4*n2];
    sg1.build(0, 0, n1 - 1,  a1);
    sg2.build(0, 0, n2 - 1, a2);

    int q;
    cin>>q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int first = sg1.query(0, 0, n1 - 1, l, r);
            cin >> l >> r;
            int second = sg2.query(0, 0, n2 - 1, l, r);
            cout << min(first, second);
        }
        else
        {
            int l, i, val;
            cin >> l >> i >> val;
            if (l == 1)
            {
                sg1.update(0, 0, n1 - 1, i, val);
                a1[i] = val;
            }
            else
            {
                sg2.update(0, 0, n2 - 1, i, val);
                a2[i] = val;
            }
        }
    }
}
// main
int main()
{
    // solve();
    solve2();
    return 0;
}
