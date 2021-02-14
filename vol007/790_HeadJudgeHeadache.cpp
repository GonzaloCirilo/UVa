#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
struct Problem {
    int time, penalty;
};

struct Team {
    int id, solved, time;
    map<char, Problem> submission;

    void calculate(){
        solved = 0; time = 0;
        for(auto it = submission.begin(); it != submission.end(); it++){
            solved++;
            time += (*it).second.time + (*it).second.penalty;
        }
    }

    bool operator<(const Team& t) const {
        return solved > t.solved || (solved == t.solved && time < t.time) || 
            (solved == t.solved && time == t.time && id < t.id);
    }
};
vector<Team> teams;
Team* findOrCreate(int id){
    for(int i = 0; i < teams.size(); i++){
        if(teams[i].id == id)
            return &teams[i];
    }
    teams.push_back(Team{id, 0, 0});
    return &teams[teams.size() - 1];
}

int main(){
    char c;
    int t;
    scanf("%d\n", &t);
    int aux = 0;
    while(t--){
        teams.clear();
        if(aux != 0){
            putchar('\n');
        }
        aux++;
        
        // Process lines
        vector<vector<int>> lines = vector<vector<int>>();
        int maxTeamId = 0;
        while (true) {
            c = getchar();
            if(c == '\n' || c == EOF) break;
            int id = c - '0';
            while(true){
                c = getchar();
                if(c == ' ') break;
                id *= 10;
                id += (c - '0');
            }
            vector<int> l = vector<int>();
            l.push_back(id);
            if(maxTeamId < id)
                maxTeamId = id;
            // problem letter
            c = getchar();
            l.push_back(c - 'A');
            getchar(); // space
            // time
            c = getchar();
            int hh = c - '0';
            while(true){
                c = getchar();
                if(c == ':') break;
                hh *= 10;
                hh += (c - '0');
            }
            int time = hh * 60;
            c = getchar();
            time += ((c - '0') * 10);
            c = getchar();
            time += (c - '0');
            l.push_back(time);
            getchar(); // space
            c = getchar();
            l.push_back(c - 'A');
            getchar();

            lines.push_back(l);

        }
        sort(lines.begin(), lines.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            return a[3] > b[3] || (a[3] == b[3] && a[2] < b[2]);
        });

        for(int i = 0; i < lines.size(); i++){
            auto team = findOrCreate(lines[i][0]);
            if(lines[i][3] + 'A' == 'Y'){
                team->submission.insert({lines[i][1] + 'A', Problem{lines[i][2], 0}});
            }else{
                if(team->submission.find(lines[i][1] + 'A') == team->submission.end())
                    continue;
                if(lines[i][2] <= team->submission[lines[i][1] + 'A'].time){
                    team->submission[lines[i][1] + 'A'].penalty += 20;
                }
            }
            
        }
        set<int> participants;
        for(int i = 1; i <= maxTeamId; i++){
            participants.insert(i);
        }
        for(int i = 0; i < teams.size(); i++){
            teams[i].calculate();
        }

        sort(teams.begin(), teams.end());

        printf("RANK TEAM PRO/SOLVED TIME\n");
        int auxPlace = 0;
        for(int i = 0; i < teams.size(); i++){
            if(teams[i].solved == 0){
                auxPlace = i;
                break;
            } 
            if(!(i != 0 && teams[i].solved == teams[i-1].solved && teams[i].time == teams[i-1].time)){
                auxPlace = i;
            }
            printf("%*d", 4, auxPlace + 1);
            printf("%*d", 5, teams[i].id);
            printf("%*d", 5, teams[i].solved);
            printf("%*d\n", 11, teams[i].time);
            participants.erase(teams[i].id);
        }
        for(auto it = participants.begin(); it != participants.end(); it++){
            printf("%*d", 4, maxTeamId - participants.size() + 1);
            printf("%*d\n", 5, *it);
        }       
    }

    return 0;
}