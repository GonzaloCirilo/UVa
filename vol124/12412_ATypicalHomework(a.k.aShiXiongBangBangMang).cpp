#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Student
{
    int cid, scores[4], rank, time;
    string sid, name;

    int totalScore() {
        return scores[0] + scores[1] + scores[2] + scores[3];
    }

    double avgScore() {
        return totalScore() * 1.0 / 4 + 1e-5;
    }
    
    void print() {
        printf("%d %s %d %s %d %d %d %d %d %.2f\n", rank, sid.c_str(), cid, name.c_str(), scores[0], scores[1], scores[2], scores[3], totalScore(), avgScore());
    }
};

map<string, Student> arr;
int c = 0;

bool cmpRank(pair<string, Student>& a, pair<string, Student>& b) { 
    return a.second.totalScore() > b.second.totalScore(); 
} 

bool cmpOrderDb(pair<string, Student>& a, pair<string, Student>& b) { 
    return a.second.time < b.second.time; 
} 

void printMenu() {
    printf("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
}

void addOption() {
    char sid[11] = {}, name[11] = {};
    int cid, cs, ms, es, ps;
    while (true) {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s", sid);
        if (string(sid) == "0") break;
        scanf("%d %s %d %d %d %d", &cid, name, &cs, &ms, &es, &ps);
        bool inserted = arr.insert({string(sid), Student{cid, {cs, ms, es, ps}, -1, c++, string(sid), string(name)}}).second;
        if (!inserted) {
            printf("Duplicated SID.\n");
        }
    }
}

void removeOption() {
    char q[11] = {};
    while (true) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", q);
        int removed = 0;
        string query = string(q);
        if (query == "0") break;
        removed = arr.find(query) != arr.end();
        arr.erase(query);
        vector<string> toDelete;
        for (auto it = arr.begin(); it != arr.end(); it++){
            if ((*it).second.name == query) {
                toDelete.push_back((*it).first);
            }
        }

        for (int i = 0; i < toDelete.size(); i++) {
            arr.erase(toDelete[i]);
            removed++;
        }

        printf("%d student(s) removed.\n", removed);
    }
}

void queryingOption() {
    char q[11] = {};
    while (true) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", q);
        string query = string(q);
        if (query == "0") break;
        // Declare vector of pairs 
        vector<pair<string, Student>> aux; 
        for (auto& it : arr) { 
            aux.push_back(it); 
        } 
    
        // Sort using comparator function 
        sort(aux.begin(), aux.end(), cmpRank); 
        int snapshot = 0;
        for(int i = 0; i < aux.size(); i++) {
            if (i > 0 && arr[aux[i].first].totalScore() == arr[aux[i - 1].first].totalScore()) {
                snapshot = snapshot;
            } else {
                snapshot = i;
            }
            arr[aux[i].first].rank = snapshot + 1;
        }

        aux = vector<pair<string, Student>>();
        for (auto& it : arr) { 
            aux.push_back(it); 
        }
        sort(aux.begin(), aux.end(), cmpOrderDb);
        for(int i = 0; i < aux.size(); i++) {
            if (aux[i].first == query || aux[i].second.name == query) {
                aux[i].second.print();
            }
        } 
    }
}

void showStatistics() {
    printf("Please enter class ID, 0 for the whole statistics.\n");
    int cid;
    scanf("%d", &cid);
    int passed[4] = {0, 0, 0 , 0}, failed[4] = {0, 0, 0, 0};
    double avg[4] = {0.0, 0.0, 0.0, 0.0};
    string courses[4] = {"Chinese", "Mathematics", "English", "Programming"};
    int ap = 0, p3 = 0, p2 = 0, p1 = 0, p0 = 0;

    for (auto it = arr.begin(); it != arr.end(); it++) {
        auto s = (*it).second;
        if (cid != s.cid && cid != 0) continue;
        int pass = 0;
        for(int i = 0; i < 4; i++) {
            avg[i] += s.scores[i];
            if (s.scores[i] >= 60) {
                passed[i]++;
                pass++;
            } else {
                failed[i]++;
            }
        }
        
        switch (pass) {
        case 4:
            ap++;
            break;
        case 3:
            p3++;
            break;
        case 2:
            p2++;
            break;
        case 1:
            p1++;
            break;
        case 0:
            p0++;
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < 4; i++) {
        avg[i] /= (passed[i] + failed[i]);
        printf("%s\n", courses[i].c_str());
        if (passed[i] + failed[i] == 0) {
            printf("Average Score: -nan\n");
        } else {
            printf("Average Score: %.2f\n", avg[i] + 1e-5);
        }
        
        printf("Number of passed students: %d\n", passed[i]);
        printf("Number of failed students: %d\n\n", failed[i]);
    }

    printf("Overall:\n");
    printf("Number of students who passed all subjects: %d\n", ap);
    printf("Number of students who passed 3 or more subjects: %d\n", p3 + ap);
    printf("Number of students who passed 2 or more subjects: %d\n", p2 + p3 + ap);
    printf("Number of students who passed 1 or more subjects: %d\n", p1 + p2 + p3 + ap);
    printf("Number of students who failed all subjects: %d\n\n", p0);
}

int main () {
    int option;
    while (true) {
        printMenu();
        scanf("%d", &option);
        if (!option) break;
        switch (option) {
        case 1:
            addOption();
            break;
        case 2:
            removeOption();
            break;
        case 3:
            queryingOption();
            break;
        case 4:
            printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
            break;
        case 5:
            showStatistics();
            break;
        default:
            break;
        }
    }

    return 0;
}