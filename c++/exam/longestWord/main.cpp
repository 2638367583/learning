#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    struct DictTree {
        char c;
        struct DictTree *dict[26];
        bool isWords;
    };

    string m_longestWord = "";

    DictTree* dictTreeCreate(vector<string> &words) {
        //创建字典树
        DictTree *root = new DictTree;
        memset(root, 0, sizeof(DictTree));
        for (auto str : words) {
            DictTree *q = root;
            for (int i = 0; i < str.size(); i++) {

                int index = str[i] - 'a';
                assert(index < 26 && index >= 0);

                if (q->dict[index] == NULL) {
                    DictTree *node = new DictTree;
                    memset(node, 0, sizeof(DictTree));
                    node->c = str[i];
                    node->isWords = false;
                    q->dict[index] = node;
                }

                if (i == str.size() - 1) {
                    q->dict[index]->isWords = true;
                }

                q = q->dict[index];
            }
        }
        return root;
    }

    void dictTreeTraverse(DictTree *root, string &str){
        if (root == NULL || root->isWords == false) return;
        str += root->c;
        if (str.size() >= m_longestWord.size()) {
            m_longestWord = str;
        }
        for (int i = 25; i >= 0; i--) {
            dictTreeTraverse(root->dict[i], str);
        }
        if (!str.empty())
            str.pop_back();
    }

    string longestWord(vector<string>& words) {
        DictTree *dict = dictTreeCreate(words);
        for (int i = 25; i >= 0; i--) {
            string str = "";
            dictTreeTraverse(dict->dict[i], str);
        }
        return m_longestWord;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution solu;
    vector<string> vec = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    vector<string> vec1 = {"m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat"};
    cout << solu.longestWord(vec1) << endl;
    return 0;
}