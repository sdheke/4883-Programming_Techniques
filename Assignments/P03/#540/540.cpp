// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 09/18/2020
// Problem 540

#include <iostream>
#include <string>
#include <map>

using namespace std;

struct TeamUnit {
  int n;
  TeamUnit* next;
};

class TeamQueue {
  public:
    TeamQueue(int teams);
    ~TeamQueue();
    void push(int team_member, int team);
    int pop();

  private:
    int teams;
    TeamUnit* front;
    TeamUnit* back;
    TeamUnit** team_tail;
};

TeamQueue::TeamQueue(int teams) {
  this->teams = teams;
  front = NULL;
  back = NULL;
  team_tail = new TeamUnit*[teams];
  for (int i = 0; i < teams; i++) {
    team_tail[i] = NULL;
  }
}

TeamQueue::~TeamQueue() {
  TeamUnit* tu;
  while (front != NULL) {
    tu = front;
    front = front->next;
    delete tu;
  }
  delete [] team_tail;
}

void TeamQueue::push(int team_member, int team) {
  TeamUnit* tu = new TeamUnit;
  tu->n = team_member;
  tu->next = NULL;

  if (front == NULL) {
    front = tu;
  }

  if (back == NULL) {
    back = tu;
  }

  if (team_tail[team] == NULL) {
    team_tail[team] = tu;
    back->next = tu;
    back = tu;
  } else {
    if (team_tail[team] == back) {
      back = tu;
    }
    tu->next = team_tail[team]->next;
    team_tail[team]->next = tu;
    team_tail[team] = tu;
  }
}

int TeamQueue::pop() {
  int result = front->n;
  TeamUnit* tu = front;
  front = front->next;

  for (int i = 0; i < teams; i++) {
    if (team_tail[i] == tu) {
      team_tail[i] = NULL;
      break;
    }
  }

  if (back == tu) {
    back = NULL;
  }
  
  delete tu;

  return result;
}

int main(void) {
  int teams;
  int n;
  int team_member;
  int scenario = 0;
  string element;

  while (cin >> teams)
  {
    if (!teams)
      break;

    scenario++;
    map<int,int> team_members; // team number for each team member
    TeamQueue tq(teams);

    for (int i = 0; i < teams; i++) {
      cin >> n;
      while (n--) {
        cin >> team_member;
        team_members[team_member] = i;
      }
    }

    cout << "Scenario #" << scenario << endl;

    while (cin >> element) {
      if (element == "ENQUEUE") {
        cin >> team_member;
        tq.push(team_member, team_members[team_member]);
      } else if (element == "DEQUEUE") {
        cout << tq.pop() << endl;
      } else { 
        
        break;
      }
    }

    cout << endl;
  }

  return 0;
}