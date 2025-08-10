#include <vector>
#include <string>
using namespace std;

// O(検索対象の文字列長)

// Trie<26, 'a'>

template <int char_size, int base>
struct Trie {
    struct Node {
        vector<int> nxt;      // 子の頂点番号を格納。存在しなければ-1
        vector<int> accept;   // 末端がこの頂点になる文字列の str_id を保存
        int c;                // a: 0, b: 1 ...
        int common;
        Node(int c_) : c(c_), common(0) {
            nxt.assign(char_size, -1);
        }
    };
    vector<Node> nodes;
    int root;
    Trie() : root(0) {
        nodes.push_back(Node(root));
    }

    void push(const string &word, int word_id) {
        int node_id = 0;
        for (int i = 0; i < (int) word.size(); i++) {
            int c = (int) (word[i] - base);
            int &nxt_id = nodes[node_id].nxt[c];
            if (nxt_id == -1) {
                nxt_id = (int) nodes.size();
                nodes.push_back(Node(c));
            }
            nodes[node_id].common++;
            node_id = nxt_id;
        }
        nodes[node_id].common++;
        nodes[node_id].accept.push_back(word_id);
    }

    void push(const string &word) {
        push(word, nodes[0].common);
    }

    bool search(const string &word, bool allow_prefix = false) {
        int node_id = 0;
        for (int i = 0; i < (int) word.size(); i++) {
            int c = (int) (word[i] - base);
            int &nxt_id = nodes[node_id].nxt[c];
            if (nxt_id == -1) {
                return false;
            }
            node_id = nxt_id;
        }
        return allow_prefix || nodes[node_id].accept.size() > 0;
    }

    // 挿入した単語の数
    int count() const {
        return (nodes[0].common);
    }

    // Trie木のノード数
    int size() const {
        return ((int)nodes.size());
    }
};
