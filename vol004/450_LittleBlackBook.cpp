#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    string title, firstName, lastName, address, homePhone, workPhone, mailbox, department;

    bool operator<(const Person& a) const
    {
        return lastName < a.lastName;
    }
};

int main(){
    int n;
    scanf("%d\n", &n);
    string line;
    vector<Person> arr;
    while(n--){
        getline(cin, line);
        string department = line;
        while(getline(cin, line) && line != ""){
            stringstream ss(line);
            string data;
            vector<string> datum = vector<string>();
            while(getline(ss, data, ',')){
                datum.push_back(data);
            }
            arr.push_back(Person{datum[0], datum[1], datum[2], datum[3], datum[4], datum[5], datum[6], department});
        }
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        printf("----------------------------------------\n");
        printf("%s %s %s\n", arr[i].title.c_str(), arr[i].firstName.c_str(), arr[i].lastName.c_str());
        printf("%s\n", arr[i].address.c_str());
        printf("Department: %s\n", arr[i].department.c_str());
        printf("Home Phone: %s\n", arr[i].homePhone.c_str());
        printf("Work Phone: %s\n", arr[i].workPhone.c_str());
        printf("Campus Box: %s\n", arr[i].mailbox.c_str());
    }
    return 0;
}