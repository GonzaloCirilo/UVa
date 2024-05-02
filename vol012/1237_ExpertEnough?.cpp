#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Maker
{
    int l, h;
    string name;
};

int main() {
    int t, l, h, d, q, p, count = 0;
    char m[20];
    scanf("%d\n", &t); 
    while (t--) {
        if (count != 0) {
            printf("\n");
        }
        count++;
        scanf("%d\n", &d);
        vector<Maker> arr;
        for (int i = 0; i < d; i++) {
            scanf("%s %d %d\n", m, &l, &h);
            arr.push_back(Maker{l, h, m});
        }
        scanf("%d\n", &q);
        while(q--) {
            scanf("%d\n", &p);
            Maker* ans = nullptr;
            for (int i = 0; i < arr.size(); i++) {
                //printf("==EVAL: %s\n", arr[i].name.c_str());
                if (p >= arr[i].l && p <= arr[i].h) {
                    //printf("==%s\n", arr[i].name.c_str());
                    if (ans != nullptr) {
                        ans = nullptr;
                        break;
                    }
                    ans = &arr[i];
                }
            }

            if (ans != nullptr) {
                printf("%s\n", ans->name.c_str());
            } else {
                printf("UNDETERMINED\n");
            }
        }
    }
}
