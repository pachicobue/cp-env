#include "internal.hpp"
#include "internal/md_seq_op.hpp"
#include "internal/seq_op.hpp"
#include "utility/md_vec.hpp"
#include "utility/printer.hpp"
#include "utility/rng.hpp"
#include "utility/scanner.hpp"

#include <iostream>
#include <memory>
#include <vector>

// モノイドの型定義
struct Monoid {
    int len;
    Arr<i64, 2> sum;
    friend Monoid& operator+=(Monoid& x, const Monoid& y) {
        x.sum[0] += y.sum[x.len % 2];
        x.sum[1] += y.sum[(x.len + 1) % 2];
        x.len += y.len;
        return x;
    }
    friend auto operator<<(Ostream& os, const Monoid& x) -> Ostream& {
        return os << "{len=" << x.len << ", sum=" << x.sum << "}\n";
    }
};

// モノイドの演算と単位元
Monoid op(Monoid x, Monoid y) {
    x.sum[0] += y.sum[x.len % 2];
    x.sum[1] += y.sum[(x.len + 1) % 2];
    x.len += y.len;
    return x;
}

Monoid e() {
    return Monoid{};
}

// 動的セグメント木のノード
struct Node {
    int L, R;                          // ノードが担当する区間 [L, R)
    Monoid val;                        // このノードが管理する区間の値（モノイド）
    std::unique_ptr<Node> left, right; // 左右の子ノード

    // コンストラクタ
    Node(int l, int r)
        : L(l), R(r), val(e()), left(nullptr), right(nullptr) {
    }

    // 中間点を計算
    int mid() const {
        return L + (R - L) / 2;
    }

    // 左の子ノードを取得（存在しなければ作成）
    Node* get_left() {
        if (!left) {
            left = std::make_unique<Node>(L, mid());
        }
        return left.get();
    }

    // 右の子ノードを取得（存在しなければ作成）
    Node* get_right() {
        if (!right) {
            right = std::make_unique<Node>(mid(), R);
        }
        return right.get();
    }
};

// 動的セグメント木本体
class DynamicSegmentTree {
private:
    std::unique_ptr<Node> root;
    const int n; // 配列サイズ（2^kにする）

    // 添字pの値をxに更新する内部関数
    void update_impl(Node* node, int p, Monoid x) {
        if (node->R - node->L == 1) { // 葉ノード
            node->val = x;
            return;
        }

        if (p < node->mid()) {
            update_impl(node->get_left(), p, x);
        } else {
            update_impl(node->get_right(), p, x);
        }

        // 子ノードの値を集約
        node->val = op(node->left ? node->left->val : e(),
                       node->right ? node->right->val : e());
    }

    // 区間[l, r)のモノイド値を求める内部関数
    Monoid query_impl(Node* node, int l, int r) {
        if (!node || r <= node->L || node->R <= l) { // 範囲外
            return e();
        }
        if (l <= node->L && node->R <= r) { // 完全に含まれる
            return node->val;
        }

        // 分割して再帰
        Monoid vl = node->left ? query_impl(node->left.get(), l, r) : e();
        Monoid vr = node->right ? query_impl(node->right.get(), l, r) : e();
        return op(vl, vr);
    }
public:
    // コンストラクタ：最大のインデックスを指定
    DynamicSegmentTree(int max_size)
        : n(max_size) {
        root = std::make_unique<Node>(0, max_size);
    }

    // 添字pの値をxに更新
    void update(int p, Monoid x) {
        if (p < 0 || p >= n) {
            return;
        }
        update_impl(root.get(), p, x);
    }

    // 区間[l, r)のモノイド値を取得
    Monoid query(int l, int r) {
        if (l >= r) {
            return e();
        }
        return query_impl(root.get(), l, r);
    }

    // k番目の要素を取得（0-indexed）
    Monoid get(int k) {
        return query(k, k + 1);
    }
};

int main() {
    constexpr int L = 1 << 30;
    DynamicSegmentTree seg(L);
    const auto Q = in.val<int>();
    i64 z = 0;
    LOOP (Q) {
        const auto y = in.val<i64>();
        const i64 x = ((z + y) % 1000000000) + 1;
        SHOW(x);
        const auto px = seg.get(x);
        seg.update(x, op(px, Monoid{
                                 1,
                                 {x, 0}
        }));
        z = seg.query(0, L).sum[0];
        out.ln(z);
        // SHOW(bit);
    }

    return 0;
}
