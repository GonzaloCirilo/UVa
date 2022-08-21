#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Block {
    Block *top = nullptr;
    Block *bottom = nullptr;
    int val;
};
vector<Block*>piles;

bool isSameStack(Block* a, Block* b){
    auto top = a->top;
    while(top != nullptr){
        if(top == b) return true;
        top = top->top;
    }

    auto bottom = a->bottom;
    while(bottom != nullptr){
        if(bottom == b) return true;
        bottom = bottom->bottom;
    }
    return false;
}

void removeBlocksFromTop(Block* block) {
    auto top = block->top;
    while(top != nullptr){
        auto aux = top->top;
        top->top = nullptr;
        top->bottom = nullptr;
        top = aux;
    }
    block->top = nullptr;
}

void moveOnto(Block* a, Block* b) {
    removeBlocksFromTop(a);
    removeBlocksFromTop(b);
    if(a->bottom != nullptr) {
        a->bottom->top = nullptr;
    }
    b->top = a;
    a->bottom = b;
}

void moveOver(Block* a, Block* b) {
    removeBlocksFromTop(a);
    Block* block = b;
    while(block->top != nullptr){
        block = block->top;
    }
    if(a->bottom != nullptr) {
        a->bottom->top = nullptr;
    }
    block->top = a;
    a->bottom = block;
}

void pileOnto(Block* a, Block* b) {
    removeBlocksFromTop(b);
    if(a->bottom != nullptr) {
        a->bottom->top = nullptr;
    }
    b->top = a;
    a->bottom = b;
}

void pileOver(Block* a, Block* b) {
    Block* block = b;
    while(block->top != nullptr){
        block = block->top;
    }
    if(a->bottom != nullptr) {
        a->bottom->top = nullptr;
    }
    block->top = a;
    a->bottom = block;
}

int main(){
    string s;
    int n;
    cin >> n;
    piles = vector<Block*>();
    for(int i = 0; i < n; i++) {
        auto aux = new Block{};
        aux->val = i;
        piles.push_back(aux);
    }
    while (true) {
        getline(cin,s);
        if(s == "quit") break;
        stringstream ss(s);
        string cmd, df;
        int a, b;
        ss >> cmd >> a >> df >> b;
        if(isSameStack(piles[a], piles[b]) || a == b) continue;
        if(cmd == "move"){
            if(df == "onto")
                moveOnto(piles[a], piles[b]);
            else if(df == "over")
                moveOver(piles[a], piles[b]);
        }else if(cmd == "pile"){
            if(df == "onto")
                pileOnto(piles[a], piles[b]);
            else if(df == "over")
                pileOver(piles[a], piles[b]);
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d:", i);
        if(piles[i]->bottom == nullptr){
            auto aux = piles[i];
            while(aux != nullptr){
                printf(" %d", aux->val);
                aux = aux->top;
            }
        }
        printf("\n");
    }

    
}