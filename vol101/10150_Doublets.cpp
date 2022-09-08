#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> graph;

string fastScan() {
    string s;
    char c;
    while(true) {
        c = getchar();
        if(c == '\n' || c == EOF || c == ' ') return s;
        s.push_back(c);
    }
    return s;
}

void fastPrint(string s) {
    for(int i = 0; i < s.size(); i++){
        putchar(s[i]);
    }
}

// TODO trie should improve runtime
int main() {
    unordered_map<string, int> wordIndex;
    unordered_map<int, string> indexWord;
    int count = 0;
    while(true) {
        string word = fastScan();
        if(word.empty()) break;
        if(wordIndex.find(word) == wordIndex.end()) {
            wordIndex.insert({word, count});
            indexWord.insert({count++, word});
        }
    }

    graph g = graph(wordIndex.size(), vi());

    for(int i = 0; i < g.size(); i++){
        auto w = indexWord[i];
        for(int j = 0; j < w.size(); j++){
            for(int k = 0; k < 25; k++){
                if(w[j] == k + 'a') continue;
                auto aux = w;
                aux[j] = k + 'a';
                if(wordIndex.find(aux) != wordIndex.end()) {
                    auto l = wordIndex[aux];
                    g[i].push_back(l);
                    g[l].push_back(i);
                }
            }
        }
    }

    int aux = 0;
    while(true) {
        
        string u = fastScan();
        if(u.empty())break;
        string v = fastScan();
        int iu = wordIndex[u], iv = wordIndex[v];
        queue<int> q;
        vi visited = vi(wordIndex.size(), -1), parent = vi(wordIndex.size());
        q.push(iu);
        visited[iu] = 1;
        parent[iu] = -1;

        if(aux != 0) {
            putchar('\n');
        }
        while(!q.empty()){
            auto node = q.front(); q.pop();
            if(node == iv) break;

            for(int i = 0; i < g[node].size(); i++){
                auto ad = g[node][i];
                if(visited[ad] == -1){
                    q.push(ad);
                    parent[ad] = node;
                    visited[ad] = 1;
                }
            }
        }
        if(visited[iv] == -1) {
            fastPrint("No solution.");
            putchar('\n');
            continue;
        }
        stack<int> s;
        int n = iv;
        while(n != -1) {
            s.push(n);
            n = parent[n];
        }

        while(!s.empty()){
            auto ans = indexWord[s.top()];
            fastPrint(ans);
            putchar('\n');
            s.pop();
        }
        aux++;
    }
    return 0;
}