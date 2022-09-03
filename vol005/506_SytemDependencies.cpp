#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int depCount = 0;
vector<vector<int>> depGraph, revDepGraph;
vector<int> installMode = vector<int>();
vector<string> installComps = vector<string>();
map<string, int> dict;
map<int, string> dictRev;
int findOrInsert(map<string,int> &dict, string value) {
    if(dict.find(value) == dict.end()){
        dictRev.insert({depCount, value});
        dict.insert({value, depCount++});
        depGraph.push_back({});
        revDepGraph.push_back({});
        installMode.push_back(0);
    }
    return dict[value];
}

void installRec(int node, int d) {
    if(installMode[node] != 0){
        if(d == 0)
            cout << "   " << dictRev[node] << " is already installed." << endl;
        return;
    }

    for(int i = 0; i < depGraph[node].size(); i++) {
        installRec(depGraph[node][i], d + 1);
    }

    if(d == 0){
        installMode[node] = 1;
    } else {
        installMode[node] = 2;
    }
    installComps.push_back(dictRev[node]);
    cout << "   Installing " << dictRev[node] << endl;

}

void install(string comp) {
    if(dict.find(comp) == dict.end()){
        auto pos = find(installComps.begin(), installComps.end(), comp);
        if(pos != installComps.end()){
            cout << "   " << comp << " is already installed." << endl;
        }else{
            cout << "   Installing " << comp << endl;
            installComps.push_back(comp);
        }
        
    } else {
        int node = dict[comp];
        installRec(node, 0);
    }
}

bool isNeeded(int node) {
    bool needs = false;
    for(int i = 0; i < revDepGraph[node].size(); i++) {
        if(installMode[revDepGraph[node][i]] == 1 || installMode[revDepGraph[node][i]] == 2){
            needs = true;
        }
    }
    return needs;
}

int neededcount(int node) {
    int needs = 0;
    for(int i = 0; i < revDepGraph[node].size(); i++) {
        if(installMode[revDepGraph[node][i]] == 1 || installMode[revDepGraph[node][i]] == 2){
            needs++;
        }
    }
    return needs;
}

void removeRec(int node, int d) {
    if(installMode[node] == 0){
        if(d == 0)
            cout << "   " << dictRev[node] << " is not installed." << endl;
        return;
    }

    if(installMode[node] == 1 && d > 0){
        return;
    }
    bool needed = isNeeded(node);
    if(needed){
        if(d == 0)
            cout <<  "   " << dictRev[node] << " is still needed." << endl;
        return;
    }

    auto pos = find(installComps.begin(), installComps.end(), dictRev[node]);
    if(pos != installComps.end()) {
        installComps.erase(pos);
        installMode[node] = 0;
        cout << "   Removing " << dictRev[node] << endl;
    }

    for(int i = 0; i < depGraph[node].size(); i++) {
        removeRec(depGraph[node][i], d + 1);
    }
}

void remove(string comp) {
    if(dict.find(comp) == dict.end()){
        auto pos = find(installComps.begin(), installComps.end(), comp);
        if(pos != installComps.end()){
            cout << "   Removing " << comp << endl;
            installComps.erase(pos);
        }else{
            cout << "   " << comp << " is not installed." << endl;
        }
    } else {
        int node = dict[comp];
        removeRec(node, 0);
    }
}

int main(){
    string cmd, line;
    // 0 - not installed, 1 - explicit, 2 - implicit
    while(getline(cin, line)){
        cout << line << endl;
        stringstream ss(line);
        ss >> cmd;
        string comp, dep;
        if(cmd == "END") break;
        if(cmd == "DEPEND"){
            ss >> comp;
            int u = findOrInsert(dict, comp);
            while(ss >> dep) {
                int v = findOrInsert(dict, dep);
                depGraph[u].push_back(v);
                revDepGraph[v].push_back(u);
            }
        } else if (cmd == "INSTALL") {
            ss >> comp;
            install(comp);
        } else if (cmd == "REMOVE") {
            ss >> comp;
            remove(comp);
        } else if (cmd == "LIST") {
            for(int i = 0; i < installComps.size(); i ++) {
                cout << "   " << installComps[i] << endl;
            }
        }
    }
    return 0;
}