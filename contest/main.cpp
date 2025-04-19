#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define inf 1000000007
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define srep(i, a, b) for (int i = (int)a; i < (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
#define SZ(c) (int)(c).size()
template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    os << "{";
    for (int i = 0; i < (int)vec.size(); i++) {
        os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// pair出力
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// map出力
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
    os << "{";
    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << "(" << itr->first << ", " << itr->second << ")";
        itr++;
        if (itr != map_var.end()) {
            os << ", ";
        }
        itr--;
    }
    os << "}";
    return os;
}
// set 出力
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
    os << "{";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << (*itr);
        ++itr;
        if (itr != set_var.end()) {
            os << ", ";
        }
        itr--;
    }
    os << "}";
    return os;
}
// tuple 出力
template <int N, class Tuple>
void out(ostream& os, const Tuple& t) {
}
template <int N, class Tuple, class H, class... Ts>
void out(ostream& os, const Tuple& t) {
    if (N) {
        os << ", ";
    }
    os << get<N>(t);
    out<N + 1, Tuple, Ts...>(os, t);
}
template <class... Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
    os << "(";
    out<0, tuple<Ts...>, Ts...>(os, t);
    os << ")";
    return os;
}
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                       \
    vector<vector<type>> name(h, vector<type>(w)); \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define INT(...)     \
    int __VA_ARGS__; \
    IN(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    IN(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    IN(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    IN(__VA_ARGS__)
#define DBL(...)        \
    double __VA_ARGS__; \
    IN(__VA_ARGS__)
int scan() {
    return getchar();
}
void scan(int& a) {
    cin >> a;
}
void scan(long long& a) {
    cin >> a;
}
void scan(char& a) {
    cin >> a;
}
void scan(double& a) {
    cin >> a;
}
void scan(string& a) {
    cin >> a;
}
template <class T, class S> void scan(pair<T, S>& p) {
    scan(p.first), scan(p.second);
}
template <class T> void scan(vector<T>&);
template <class T> void scan(vector<T>& a) {
    for (auto& i : a) {
        scan(i);
    }
}
template <class T> void scan(T& a) {
    cin >> a;
}
void IN() {
}
template <class Head, class... Tail> void IN(Head& head, Tail&... tail) {
    scan(head);
    IN(tail...);
}
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) {
    cout << YESNO[t] << endl;
}
void NO(bool t = 1) {
    YES(!t);
}
void Yes(bool t = 1) {
    cout << YesNo[t] << endl;
}
void No(bool t = 1) {
    Yes(!t);
}
void yes(bool t = 1) {
    cout << yesno[t] << endl;
}
void no(bool t = 1) {
    yes(!t);
}
#ifdef LOCAL
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define dbg(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define dbg(...) (void(0))
#define dump(x) (void(0))
#endif
template <typename A, typename T>
std::enable_if_t<std::is_convertible<T, A>::value> fill(A& array, const T& val) {
    array = val;
}
template <typename A, typename T>
std::enable_if_t<!std::is_convertible<T, A>::value> fill(A& array, const T& val) {
    for (auto& a : array) {
        fill(a, val);
    }
}
template <typename T, typename S> T ceil(T x, S y) {
    assert(y);
    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
}
template <typename T, typename S> T floor(T x, S y) {
    assert(y);
    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
}
vector<int> iota(int n) {
    vector<int> a(n);
    iota(all(a), 0);
    return a;
}
template <class T> T POW(T x, int n) {
    T res = 1;
    for (; n; n >>= 1, x *= x) {
        if (n & 1) {
            res *= x;
        }
    }
    return res;
}
ll pow2(int i) {
    return 1LL << i;
}
int topbit(signed t) {
    return t == 0 ? -1 : 31 - __builtin_clz(t);
}
int topbit(ll t) {
    return t == 0 ? -1 : 63 - __builtin_clzll(t);
}
int lowbit(signed a) {
    return a == 0 ? 32 : __builtin_ctz(a);
}
int lowbit(ll a) {
    return a == 0 ? 64 : __builtin_ctzll(a);
}
// int allbit(int n) { return (1 << n) - 1; }
ll allbit(ll n) {
    return (1LL << n) - 1;
}
int popcount(signed t) {
    return __builtin_popcount(t);
}
int popcount(ll t) {
    return __builtin_popcountll(t);
}
bool ispow2(int i) {
    return i && (i & -i) == i;
}

template <class S> void fold_in(vector<S>& v) {
}
template <typename Head, typename... Tail, class S> void fold_in(vector<S>& v, Head&& a, Tail&&... tail) {
    for (auto e : a) {
        v.emplace_back(e);
    }
    fold_in(v, tail...);
}
template <class S> void renumber(vector<S>& v) {
}
template <typename Head, typename... Tail, class S> void renumber(vector<S>& v, Head&& a, Tail&&... tail) {
    for (auto&& e : a) {
        e = lb(v, e);
    }
    renumber(v, tail...);
}
template <class S, class... Args> void zip(vector<S>& head, Args&&... args) {
    vector<S> v;
    fold_in(v, head, args...);
    sort(all(v)), v.erase(unique(all(v)), v.end());
    renumber(v, head, args...);
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

string D = "ULDR";

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int init_a[21][21];
int a[21][21];

const int LEFT = 1;
const int UP = 0;
const int DOWN = 2;
const int RIGHT = 3;

const int HOLE = 4;
const int CRYSTAL = 1;
const int ROCK = 2;

void output(vector<pair<int, int>> res) {
    for (auto [x, y] : res) {
        cout << x << " " << D[y] << "\n";
    }
}

void show() {
    cerr << "Field:" << endl;
    rep(i, 20) {
        rep(j, 20) {
            cerr << a[i][j];
        }
        cerr << endl;
    }
    cerr << endl;
}

int n;
vector<pair<int, int>> solve() {
    vector<int> cur;
    vector<int> hole;
    rep(i, n) rep(j, n) {
        if (a[i][j] == 4) {
            cur = {i, j};
            hole = {i, j};
        }
    }
    vector<pair<int, int>> res;
    auto check = [&](int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < n;
    };

    auto mov = [&](vector<pair<int, int>>& actions, int dir) -> void {
        actions.push_back({1, dir});
        cur[0] += dx[dir];
        cur[1] += dy[dir];
        return;
    };

    auto carry = [&](vector<pair<int, int>>& actions, int dir) -> void {
        dbg(cur, dir);
        assert(a[cur[0]][cur[1]] == 1 || a[cur[0]][cur[1]] == 2);
        int x = a[cur[0]][cur[1]];
        a[cur[0]][cur[1]] = 0;
        actions.push_back({2, dir});
        cur[0] += dx[dir];
        cur[1] += dy[dir];
        assert(a[cur[0]][cur[1]] != 1 && a[cur[0]][cur[1]] != 2);
        if (a[cur[0]][cur[1]] != 4) {
            a[cur[0]][cur[1]] = x;
        }
        return;
    };

    auto kick = [&](vector<pair<int, int>>& actions, int dir) -> void {
        assert(a[cur[0]][cur[1]] == CRYSTAL || a[cur[0]][cur[1]] == ROCK);
        actions.push_back({3, dir});
        int cx = cur[0];
        int cy = cur[1];
        while (1) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (check(nx, ny)) {
                if (a[nx][ny] == HOLE) {
                    a[cx][cy] = 0;
                    break;
                } else if (a[nx][ny] == CRYSTAL || a[nx][ny] == ROCK) {
                    break;
                }
                swap(a[cx][cy], a[nx][ny]);
                swap(cx, nx);
                swap(cy, ny);
            } else {
                break;
            }
        }
        return;
    };

    auto is_block = [&](int i = -1, int j = -1) -> bool {
        if (i == -1 && j == -1) {
            i = cur[0];
            j = cur[1];
        }
        if (!check(i, j)) {
            return true;
        }
        return a[i][j] == CRYSTAL || a[i][j] == ROCK;
    };

    int most_right = -inf, most_left = inf;
    rep(x, n) rep(y, n) {
        if (a[x][y] == CRYSTAL) {
            chmax(most_right, y);
            chmin(most_left, y);
        }
    }

    dbg(cur, n);
    // 右側を全て消す
    while (cur[1] < most_right) {
        if (a[cur[0]][cur[1]] == CRYSTAL || a[cur[0]][cur[1]] == ROCK) {
            kick(res, LEFT);
        } else {
            mov(res, RIGHT);
        }
    }
    // output(res);

    // 列の削除 part1
    for (int y = most_right; y > hole[1]; y--) {
        // TODO: 上 -> 下, 下 -> 上 のどちらかがよいかを確認する

        // 上側の Crystal 削除
        {
            bool exist = false;
            int upper = inf;
            rep(x, cur[0]) {
                if (a[x][y] == CRYSTAL) {
                    exist = true;
                    chmin(upper, x);
                }
            }
            if (exist) {
                // 石を下に置く
                if (is_block(cur[0], cur[1])) {
                    if (is_block(cur[0] + 1, cur[1])) {
                        kick(res, LEFT);
                    } else {
                        carry(res, DOWN);
                        mov(res, UP);
                    }
                } else {
                    if (!is_block(cur[0] + 1, cur[1])) {
                        // 上部から石を取ってきて下に置く
                        while (!is_block(cur[0], cur[1])) {
                            mov(res, UP);
                        }
                        while (cur[0] != hole[0] + 1) {
                            carry(res, DOWN);
                        }
                        mov(res, UP);
                    }
                }
                while (cur[0] >= upper) {
                    if (a[cur[0]][cur[1]] == ROCK) {
                        // 右に蹴れるなら蹴る
                        if (!is_block(cur[0], cur[1] + 1)) {
                            kick(res, RIGHT);
                        } else {
                            // 左に蹴れるなら蹴る
                            if (!is_block(cur[0], cur[1] - 1)) {
                                kick(res, LEFT);
                            } else {
                                kick(res, DOWN);
                            }
                        }

                    } else if (a[cur[0]][cur[1]] == CRYSTAL) {
                        kick(res, DOWN);
                    }
                    if (cur[0] != upper) {
                        mov(res, UP);
                    } else {
                        break;
                    }
                }

                while (cur[0] != hole[0]) {
                    mov(res, DOWN);
                }

                while (1) {
                    exist = false;
                    rep(x, cur[0] + 1) {
                        if (a[x][y] == CRYSTAL) {
                            exist = true;
                        }
                    }
                    if (!exist) {
                        break;
                    }
                    // 現在 cur[0] == hole[0]

                    if (is_block()) {
                        kick(res, LEFT);
                        continue;
                    }
                    while (!is_block()) {
                        mov(res, UP);
                    }
                    while (cur[0] != hole[0]) {
                        carry(res, DOWN);
                    }
                    kick(res, LEFT);
                }
            }
        }

        // 下側の Crystal 削除
        {
            bool exist = false;
            int lower = -inf;
            srep(x, cur[0] + 1, n) {
                if (a[x][y] == CRYSTAL) {
                    exist = true;
                    chmax(lower, x);
                }
            }
            if (exist) {
                // 石を上に置く
                if (is_block(cur[0], cur[1])) {
                    if (is_block(cur[0] - 1, cur[1])) {
                        kick(res, LEFT);
                    } else {
                        carry(res, UP);
                        mov(res, DOWN);
                    }
                } else {
                    if (!is_block(cur[0] - 1, cur[1])) {
                        // 下部から石を取ってきて下に置く
                        while (!is_block(cur[0], cur[1])) {
                            mov(res, DOWN);
                        }
                        while (cur[0] != hole[0] - 1) {
                            carry(res, UP);
                        }
                        mov(res, DOWN);
                    }
                }
                while (cur[0] <= lower) {
                    if (a[cur[0]][cur[1]] == ROCK) {
                        // 右に蹴れるなら蹴る
                        if (!is_block(cur[0], cur[1] + 1)) {
                            kick(res, RIGHT);
                        } else {
                            // 左に蹴れるなら蹴る
                            if (!is_block(cur[0], cur[1] - 1)) {
                                kick(res, LEFT);
                            } else {
                                kick(res, UP);
                            }
                        }

                    } else if (a[cur[0]][cur[1]] == CRYSTAL) {
                        kick(res, UP);
                    }
                    if (cur[0] != lower) {
                        mov(res, DOWN);
                    } else {
                        break;
                    }
                }

                while (cur[0] != hole[0]) {
                    mov(res, UP);
                }

                while (1) {
                    exist = false;
                    srep(x, cur[0], n) {
                        if (a[x][y] == CRYSTAL) {
                            exist = true;
                        }
                    }
                    if (!exist) {
                        break;
                    }
                    // 現在 cur[0] == hole[0]

                    if (is_block()) {
                        kick(res, LEFT);

                        continue;
                    }
                    while (!is_block()) {
                        mov(res, DOWN);
                    }
                    while (cur[0] != hole[0]) {
                        carry(res, UP);
                    }
                    kick(res, LEFT);
                }
            }
        }
        if (is_block(cur[0], cur[1])) {
            carry(res, LEFT);
        } else {
            if (check(cur[0] - 1, cur[1]) && is_block(cur[0] - 1, cur[1])) {
                mov(res, UP);
                carry(res, DOWN);
                carry(res, LEFT);
            } else if (check(cur[0] + 1, cur[1]) && is_block(cur[0] + 1, cur[1])) {
                mov(res, DOWN);
                carry(res, UP);
                carry(res, LEFT);
            } else {
                mov(res, LEFT);
            }
        }
    }
    // output(res);

    // 列の削除 part2
    // x = hole[0] の場合　そのまま

    {
        int y = hole[1];
        {
            bool exist = false;
            int upper = inf;
            rep(x, cur[0]) {
                if (a[x][y] == CRYSTAL) {
                    exist = true;
                    chmin(upper, x);
                }
            }
            if (exist) {
                // 石を下に蹴る
                while (cur[0] >= upper) {
                    if (a[cur[0]][cur[1]] == ROCK) {
                        kick(res, DOWN);
                    } else if (a[cur[0]][cur[1]] == CRYSTAL) {
                        kick(res, DOWN);
                    }
                    if (cur[0] != upper) {
                        mov(res, UP);
                    } else {
                        break;
                    }
                }
                while (cur[0] != hole[0]) {
                    mov(res, DOWN);
                }
            }
        }
        {
            bool exist = false;
            int lower = -inf;
            srep(x, cur[0] + 1, n) {
                if (a[x][y] == CRYSTAL) {
                    exist = true;
                    chmax(lower, x);
                }
            }
            if (exist) {
                while (cur[0] <= lower) {
                    if (a[cur[0]][cur[1]] == ROCK) {
                        kick(res, UP);
                    } else if (a[cur[0]][cur[1]] == CRYSTAL) {
                        kick(res, UP);
                    }
                    if (cur[0] != lower) {
                        mov(res, DOWN);
                    } else {
                        break;
                    }
                }
                while (cur[0] != hole[0]) {
                    mov(res, UP);
                }
            }
        }
        if (check(cur[0], cur[1] - 1)) {
            mov(res, LEFT);
        }
    }
    // 列の削除 part3
    for (int y = hole[1] - 1; y >= most_left; y--) {
        // TODO: 上 -> 下, 下 -> 上 のどちらかがよいかを確認する
        dbg(cur);

        // 上側の Crystal 削除
        {
            bool exist = false;
            int upper = inf;
            rep(x, cur[0]) {
                if (a[x][y] == CRYSTAL) {
                    exist = true;
                    chmin(upper, x);
                }
            }
            if (exist) {
                // 石を下に置く
                if (is_block(cur[0], cur[1])) {
                    if (is_block(cur[0] + 1, cur[1])) {
                        kick(res, RIGHT);
                    } else {
                        carry(res, DOWN);
                        mov(res, UP);
                    }
                } else {
                    if (!is_block(cur[0] + 1, cur[1])) {
                        // 上部から石を取ってきて下に置く
                        while (!is_block(cur[0], cur[1])) {
                            mov(res, UP);
                        }
                        while (cur[0] != hole[0] + 1) {
                            carry(res, DOWN);
                        }
                        mov(res, UP);
                    }
                }
                dbg(cur);
                dbg(upper);
                while (cur[0] >= upper) {

                    if (a[cur[0]][cur[1]] == ROCK) {
                        // 右に蹴れるなら蹴る
                        if (!is_block(cur[0], cur[1] + 1)) {
                            kick(res, RIGHT);
                        } else {
                            // 左に蹴れるなら蹴る
                            if (!is_block(cur[0], cur[1] - 1)) {
                                kick(res, LEFT);
                            } else {
                                kick(res, DOWN);
                            }
                        }

                    } else if (a[cur[0]][cur[1]] == CRYSTAL) {
                        kick(res, DOWN);
                    }
                    if (cur[0] != upper) {
                        mov(res, UP);
                    } else {
                        break;
                    }
                }

                while (cur[0] != hole[0]) {
                    mov(res, DOWN);
                }

                while (1) {
                    dbg(cur);
                    exist = false;
                    rep(x, cur[0] + 1) {
                        if (a[x][y] == CRYSTAL) {
                            exist = true;
                            dbg(x, y);
                        }
                    }
                    dbg(exist);
                    if (!exist) {
                        break;
                    }
                    // 現在 cur[0] == hole[0]

                    if (is_block()) {
                        kick(res, RIGHT);
                        continue;
                    }
                    while (!is_block()) {
                        mov(res, UP);
                    }
                    while (cur[0] != hole[0]) {
                        dbg(cur);
                        carry(res, DOWN);
                    }
                    kick(res, RIGHT);
                }
            }
        }

        // show();
        dbg("test");
        // 下側の Crystal 削除
        {
            bool exist = false;
            int lower = -inf;
            srep(x, cur[0] + 1, n) {
                if (a[x][y] == CRYSTAL) {
                    exist = true;
                    chmax(lower, x);
                }
            }
            if (exist) {
                // 石を上に置く
                if (is_block(cur[0], cur[1])) {
                    if (is_block(cur[0] - 1, cur[1])) {
                        kick(res, RIGHT);
                    } else {
                        dbg(cur);
                        carry(res, UP);
                        mov(res, DOWN);
                    }
                } else {
                    if (!is_block(cur[0] - 1, cur[1])) {
                        // 下部から石を取ってきて上に置く
                        while (!is_block(cur[0], cur[1])) {
                            mov(res, DOWN);
                        }
                        while (cur[0] != hole[0] - 1) {
                            carry(res, UP);
                        }
                        mov(res, DOWN);
                    }
                }
                while (cur[0] <= lower) {
                    if (a[cur[0]][cur[1]] == ROCK) {
                        // 右に蹴れるなら蹴る
                        if (!is_block(cur[0], cur[1] + 1)) {
                            kick(res, RIGHT);
                        } else {
                            // 左に蹴れるなら蹴る
                            if (!is_block(cur[0], cur[1] - 1)) {
                                kick(res, LEFT);
                            } else {
                                kick(res, UP);
                            }
                        }

                    } else if (a[cur[0]][cur[1]] == CRYSTAL) {
                        kick(res, UP);
                    }
                    if (cur[0] != lower) {
                        mov(res, DOWN);
                    } else {
                        break;
                    }
                }

                while (cur[0] != hole[0]) {
                    mov(res, UP);
                }

                while (1) {
                    exist = false;
                    srep(x, cur[0], n) {
                        if (a[x][y] == CRYSTAL) {
                            exist = true;
                        }
                    }
                    if (!exist) {
                        break;
                    }
                    // 現在 cur[0] == hole[0]
                    if (is_block()) {
                        kick(res, RIGHT);

                        continue;
                    }
                    while (!is_block()) {
                        mov(res, DOWN);
                    }
                    while (cur[0] != hole[0]) {
                        carry(res, UP);
                    }
                    kick(res, RIGHT);
                }
            }
        }
        dbg(cur);
        if (is_block(cur[0], cur[1])) {
            if (!is_block(cur[0], cur[1] - 1)) {
                carry(res, LEFT);
            } else {
                kick(res, RIGHT);
                if (y != most_left) {
                    mov(res, LEFT);
                }
            }
        } else {
            if (check(cur[0] - 1, cur[1]) && is_block(cur[0] - 1, cur[1])) {
                mov(res, UP);
                carry(res, DOWN);
                if (is_block(cur[0], cur[1] - 1)) {
                    kick(res, RIGHT);
                    if (y != most_left) {
                        mov(res, LEFT);
                    }
                } else {
                    if (y != most_left) {
                        carry(res, LEFT);
                    } else {
                        kick(res, RIGHT);
                    }
                }
            } else if (check(cur[0] + 1, cur[1]) && is_block(cur[0] + 1, cur[1])) {
                mov(res, DOWN);
                carry(res, UP);
                if (is_block(cur[0], cur[1] - 1)) {
                    kick(res, RIGHT);
                    if (y != most_left) {
                        mov(res, LEFT);
                    }
                } else {
                    if (y != most_left) {
                        carry(res, LEFT);
                    } else {
                        kick(res, RIGHT);
                    }
                }
            } else {
                if (y != most_left) {
                    mov(res, LEFT);
                }
            }
        }
    }
    if (is_block(cur[0], cur[1])) {
        kick(res, RIGHT);
    }
    return res;
}

vector<pair<int, int>> solve2() {
    vector<int> cur;
    vector<int> hole;
    rep(i, n) rep(j, n) {
        if (a[i][j] == 4) {
            cur = {i, j};
            hole = {i, j};
        }
    }
    auto check = [&](int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < n;
    };

    auto mov = [&](vector<pair<int, int>>& actions, int dir) -> void {
        actions.push_back({1, dir});
        cur[0] += dx[dir];
        cur[1] += dy[dir];
        return;
    };

    auto carry = [&](vector<pair<int, int>>& actions, int dir) -> void {
        dbg(cur, dir);
        assert(a[cur[0]][cur[1]] == 1 || a[cur[0]][cur[1]] == 2);
        int x = a[cur[0]][cur[1]];
        a[cur[0]][cur[1]] = 0;
        actions.push_back({2, dir});
        cur[0] += dx[dir];
        cur[1] += dy[dir];
        assert(a[cur[0]][cur[1]] != 1 && a[cur[0]][cur[1]] != 2);
        if (a[cur[0]][cur[1]] != 4) {
            a[cur[0]][cur[1]] = x;
        }
        return;
    };

    auto kick = [&](vector<pair<int, int>>& actions, int dir) -> void {
        assert(a[cur[0]][cur[1]] == CRYSTAL || a[cur[0]][cur[1]] == ROCK);
        actions.push_back({3, dir});
        int cx = cur[0];
        int cy = cur[1];
        while (1) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (check(nx, ny)) {
                if (a[nx][ny] == HOLE) {
                    a[cx][cy] = 0;
                    break;
                } else if (a[nx][ny] == CRYSTAL || a[nx][ny] == ROCK) {
                    break;
                }
                swap(a[cx][cy], a[nx][ny]);
                swap(cx, nx);
                swap(cy, ny);
            } else {
                break;
            }
        }
        return;
    };

    auto is_block = [&](int i = -1, int j = -1) -> bool {
        if (i == -1 && j == -1) {
            i = cur[0];
            j = cur[1];
        }
        if (!check(i, j)) {
            return true;
        }
        return a[i][j] == CRYSTAL || a[i][j] == ROCK;
    };

    auto calculate_turn = [&](int i, int j) -> pair<int, vector<pair<int, int>>> {
        vvv(int, dist, n, n, 2, inf);
        using tii = tuple<int, int, int>;
        vvv(tii, par, n, n, 2);
        queue<tuple<int, int, int>> q;
        for (int y = hole[1]; y < n; y++) {

            dist[hole[0]][y][1] = 0;
            q.push({hole[0], y, 1});
            if (is_block(hole[0], y)) {
                break;
            }
        }
        for (int y = hole[1] - 1; y >= 0; y--) {
            dist[hole[0]][y][1] = 0;
            q.push({hole[0], y, 1});
            if (is_block(hole[0], y)) {
                break;
            }
        }

        for (int x = hole[0] + 1; x < n; x++) {
            dist[x][hole[1]][1] = 0;
            q.push({x, hole[1], 1});
            if (is_block(x, hole[1])) {
                break;
            }
        }

        for (int x = hole[0] - 1; x >= 0; x--) {
            dist[x][hole[1]][1] = 0;
            q.push({x, hole[1], 1});
            if (is_block(x, hole[1])) {
                break;
            }
        }

        while (!q.empty()) {
            auto [x, y, has] = q.front();
            q.pop();
            if (x == i && y == j && has) {
                if (chmin(dist[x][y][0], dist[x][y][1])) {
                    par[x][y][0] = {x, y, 1};
                    q.push({x, y, 0});
                }

            } else {
                rep(dir, 4) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (check(nx, ny)) {
                        if (has && (a[nx][ny] == ROCK || a[nx][ny] == CRYSTAL)) {
                            if (nx == i && ny == j) {

                            } else {
                                continue;
                            }
                        }
                        if (chmin(dist[nx][ny][has], dist[x][y][has] + 1)) {
                            q.push({nx, ny, has});
                            par[nx][ny][has] = {x, y, has};
                        }
                    }
                }
            }
        }
        if (dist[cur[0]][cur[1]][0] == inf) {
            return {inf, {}};
        }
        vector<pair<int, int>> actions;
        int x = cur[0];
        int y = cur[1];
        int has = 0;
        while (1) {
            if (dist[x][y][has] == 0) {
                // どっちの方向に蹴るかを確認
                if (x == hole[0] && y == hole[1]) {
                    break;
                }
                if (x == hole[0] && y < hole[1]) {
                    actions.push_back({3, RIGHT});
                } else if (x == hole[0] && y > hole[1]) {
                    actions.push_back({3, LEFT});
                } else if (x < hole[0]) {
                    actions.push_back({3, DOWN});
                } else {
                    actions.push_back({3, UP});
                }
                break;
            } else {
                auto [px, py, phas] = par[x][y][has];
                if (px == x + 1) {
                    actions.push_back({1 + has, DOWN});
                } else if (px == x - 1) {
                    actions.push_back({1 + has, UP});
                } else if (py == y + 1) {
                    actions.push_back({1 + has, RIGHT});
                } else if (py == y - 1) {
                    actions.push_back({1 + has, LEFT});
                }
                x = px;
                y = py;
                has = phas;
            }
        }

        return {dist[cur[0]][cur[1]][0], actions};
    };

    vector<pair<int, int>> res;
    auto action = [&](pair<int, int> info) -> void {
        if (info.first == 1) {
            mov(res, info.second);
        } else if (info.first == 2) {

            carry(res, info.second);
        } else {
            kick(res, info.second);
        }
        return;
    };

    while (1) {
        if (is_block()) {
            kick(res, LEFT);
        }
        if (cur[1] == n - 1) {
            break;
        }
        mov(res, RIGHT);
    }

    while (1) {
        if (is_block()) {
            kick(res, RIGHT);
        }
        if (cur[1] == 0) {
            break;
        }
        mov(res, LEFT);
    }
    while (1) {
        if (cur[1] != hole[1]) {
            mov(res, RIGHT);
        } else {
            break;
        }
    }

    while (1) {
        if (is_block()) {
            kick(res, DOWN);
        }
        if (cur[0] == 0) {
            break;
        }
        mov(res, UP);
    }

    while (1) {
        if (is_block()) {
            kick(res, UP);
        }
        if (cur[0] == n - 1) {
            break;
        }
        mov(res, DOWN);
    }

    while (1) {
        int cnt = 0;
        int mi = inf;
        int ti = -1;
        int tj = -1;
        vector<pair<int, int>> best_path;
        rep(i, n) {
            rep(j, n) {
                if (a[i][j] == CRYSTAL || (a[i][j] == ROCK && (i == hole[0] || j == hole[1]))) {
                    cnt++;
                    auto [score, path] = calculate_turn(i, j);
                    if (chmin(mi, score)) {
                        ti = i;
                        tj = j;
                        best_path = path;
                    }
                }
            }
        }
        if (cnt == 0) {
            break;
        }
        if (mi == inf) {
            return {};
        }
        for (auto x : best_path) {
            action(x);
        }
    }
    cerr << "solve2: " << res.size() << endl;
    return res;
}

int main() {
    int M;
    cin >> n >> M;
    VEC(string, s, n);

    vector<int> cur;
    vector<int> hole;
    rep(i, n) rep(j, n) {
        if (s[i][j] == 'A') {
            cur = {i, j};
            hole = {i, j};
            a[i][j] = 4;
        } else if (s[i][j] == 'a') {
            a[i][j] = 1;
        } else if (s[i][j] == '@') {
            a[i][j] = 2;
        }
    }

    vector<pair<int, int>> res;
    {
        vector<pair<int, int>> fars;
        rep(i, n) {
            rep(j, n) {
                if (s[i][j] != 'a') {
                    continue;
                }
                if (abs(i - hole[0]) > n / 2 && abs(j - hole[1]) > n / 2) {
                }
            }
        }
        // TSPにしたい
    }

    rep(i, n) rep(j, n) {
        init_a[i][j] = a[i][j];
    }

    rep(dir, 4) {
        dbg("test");
        rep(i, n) rep(j, n) a[i][j] = init_a[i][j];
        auto tmp = solve2();
        rep(z, dir) {
            // 逆回転
            for (auto& [x, y] : tmp) {
                y++;
                y %= 4;
            }
        }

        if (!tmp.empty()) {
            if (res.empty()) {
                res = tmp;
            } else {
                if (res.size() > tmp.size()) {
                    res = tmp;
                }
            }
        }

        // 回転
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(init_a[i][j], init_a[j][i]);
            }
        }

        // 2. 各行を左右反転（これにより 90 度時計回りの回転が実現される）
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(init_a[i][j], init_a[i][n - j - 1]);
            }
        }
    }

    rep(dir, 4) {
        dbg("test");
        rep(i, n) rep(j, n) a[i][j] = init_a[i][j];
        auto tmp = solve();
        rep(z, dir) {
            // 逆回転
            for (auto& [x, y] : tmp) {
                y++;
                y %= 4;
            }
        }

        if (res.empty()) {
            res = tmp;
        } else {
            if (res.size() > tmp.size()) {
                res = tmp;
            }
        }

        // 回転
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(init_a[i][j], init_a[j][i]);
            }
        }

        // 2. 各行を左右反転（これにより 90 度時計回りの回転が実現される）
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(init_a[i][j], init_a[i][n - j - 1]);
            }
        }
    }

    output(res);

    return 0;
}

// TODO: 上 -> 下, 下 -> 上 のどちらかがよいかを確認する
// TODO: 盤面を回転する
