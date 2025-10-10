#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    vector<string> words;
};

struct Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;

        for (const char& c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->words.emplace_back(word);
        }
    }

    vector<string> query_prefix(const string& prefix) {
        TrieNode* node = root;

        for (const auto& c : prefix) {
            if (!node->children.count(c)) {
                return {}; // prefix not found
            }
            node = node->children[c];
        }

        return node->words; // all words starting with prefix
    }
};

template<typename T>
void print_vector(const vector<T>& vec) {
    bool is_first = true;

    cout << "[";

    for (const auto& ele : vec) {
        if (!is_first) {
            cout << ", ";
        }

        is_first = false;
        cout << ele;
    }

    cout << "]\n";
}

int main() {
    int n; cin >> n;
    string word;

    Trie trie;

    while (n--) {
        cin >> word;
        trie.insert(word);
    }

    int q; cin >> q;

    string prefix;

    while (q--) {
        cin >> prefix;
        print_vector(trie.query_prefix(prefix));
    }
    return 0;
}