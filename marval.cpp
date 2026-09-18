
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Character{
protected:

    string name;
    string role;
    int health;
    int attackPower;
    int defense;
    string powerName;

public:

    // Default Constructor
    Character(){  
        name = "";
        role = "";
        health = 0;
        attackPower = 0;
        defense = 0;
        powerName = "";
    }

    // Parameterized Constructor
    Character(string n,string r,int h,int a,int d,string p)
    {
        name = n;
        role = r;
        health = h;
        attackPower = a;
        defense = d;
        powerName = p;
    }

    // Virtual Destructor
    virtual ~Character(){
        
    }

    // Get Name
    string getName()
    {
        return name;
    }

    // Get Role
    string getRole()
    {
        return role;  
    }

    // Get Health
    int getHealth()
    {
        return health;  
    }

    // Get Defense
    int getDefense()
    {
        return defense;
    }

    // Reduce Health
    void takeDamage(int damage)
    {
        health = health - damage;
        if (health < 0){
            health = 0;
        }  
    }

    // Check character alive or not 
    bool isAlive()
    {
        return health > 0;
    }

    // Attack Function  
    virtual void attack(Character &enemy)
    {
        int bonus;
        int damage;

        bonus = rand() % 20 + 1;

        damage =(attackPower + bonus)
            - enemy.getDefense();

        if (damage <= 0){
            damage = 1;  
        }

        enemy.takeDamage(damage);

        cout << endl;

        cout << "***********************************"
             << endl;

        cout << role
             << " SPECIAL ATTACK"
             << endl;

        cout << "***********************************"
             << endl;

        cout << "Character Name : "
             << name
             << endl;

        cout << "Role           : "
             << role
             << endl;

        cout << "Special Power  : "
             << powerName
             << endl;

        cout << "Bonus Damage   : "
             << bonus
             << endl;

        cout << "Total Damage   : "
             << damage
             << endl;

        cout << enemy.getName()
             << " Remaining Health : "
             << enemy.getHealth()
             << endl;
    }

    // Display Character
    virtual void display()
    {
        cout << "Name           : "
             << name
             << endl;

        cout << "Role           : "
             << role
             << endl;

        cout << "Health         : "
             << health
             << endl;

        cout << "Attack Power   : "
             << attackPower
             << endl;

        cout << "Defense        : "
             << defense
             << endl;

        cout << "Special Power  : "
             << powerName
             << endl;
    }
};  

class Team{
    private:
    string teamName;
    Character* members[100];
    int totalMembers;
public:
    // Constructor
    Team(){
        teamName = "";
        totalMembers = 0;
    }

    // give team name  
    void setTeamName(string n)
    {
        teamName = n;
    }

    // get team name  
    string getTeamName()
    {
        return teamName;
    }

    // add team member  
    void addMember(Character* c){
        if (totalMembers < 100){
            members[totalMembers] = c;
            totalMembers++;
        }
        else
        {
            cout << "Team Full!"
                 << endl;
        }
    }

    // Check Alive Members
    bool hasAliveMembers()
    {
        for (int i = 0; i < totalMembers; i++)
        {
            if (members[i]->isAlive())
            {
                return true;
            }
        }

        return false;
    }

    // get first alive member  
    Character* getFirstAliveMember(){
        for (int i = 0; i < totalMembers; i++)
        {
            if (members[i]->isAlive()){
                return members[i];
            }
        }
        return NULL;
    }

    //  display team 
    void displayTeam(){
        cout << endl;

        cout << "***********************************"
             << endl;  

        cout << "TEAM NAME : "
             << teamName
             << endl;

        cout << "***********************************"
             << endl;

        for (int i = 0; i < totalMembers; i++){    
            cout << endl;

            cout << "Member "
                 << i + 1
                 << endl;

            cout << "=============================="
                 << endl;  

            members[i]->display();
        }

        cout << endl;
    }

    // destructor
    ~Team(){
        for (int i = 0; i < totalMembers; i++){
            delete members[i];
        }
    }
};


class BattleArena{
public:
    static void startBattle(Team &team1,Team &team2){
        cout << endl;

        cout << "***********************************"
             << endl;

        cout << "        BATTLE STARTS"
             << endl;

        cout << "***********************************"
             << endl;

        int round = 1;

        while (team1.hasAliveMembers() && team2.hasAliveMembers())
        {
            cout << endl;

            cout << "========== ROUND "
                 << round
                 << " =========="
                 << endl;

            Character* fighter1;
            Character* fighter2;

            fighter1 =team1.getFirstAliveMember();

            fighter2 =team2.getFirstAliveMember();

            if (fighter1 == NULL ||fighter2 == NULL)
            {
                break;
            }

            cout << endl;

            cout << fighter1->getName()
                 << " (" << fighter1->getRole() << ")"
                 << " VS "
                 << fighter2->getName()
                 << " (" << fighter2->getRole() << ")"
                 << endl;  

            // First Fighter Attack
            fighter1->attack(*fighter2);  

            // Counter Attack  
            if (fighter2->isAlive()){
                fighter2->attack(*fighter1);
            }  

            // Defeat Check
            if (!fighter1->isAlive()){
                cout << endl;

                cout << fighter1->getName()
                     << " has been defeated!"
                     << endl;
            }

            if (!fighter2->isAlive())
            {
                cout << endl;

                cout << fighter2->getName()
                     << " has been defeated!"
                     << endl;
            }

            round++;
        }

        cout << endl;

        cout << "***********************************"
             << endl;

        cout << "        BATTLE FINISHED"
             << endl;

        cout << "***********************************"
             << endl;

        if (team1.hasAliveMembers())
        {
            cout << endl;

            cout << "WINNER TEAM : "
                 << team1.getTeamName()
                 << endl;
        }
        else
        {
            cout << endl;

            cout << "WINNER TEAM : "
                 << team2.getTeamName()
                 << endl;
        }
    }
};

void createTeam(Team &team)
{
    string teamName;

    int totalMembers;

    cout << endl;

    cout << "Enter Team Name : ";
    getline(cin, teamName);

    team.setTeamName(teamName);

    cout << "Enter Number Of Members : ";
    cin >> totalMembers;

    cin.ignore();

    // Create Members
    for (int i = 0; i < totalMembers; i++)
    {
        cout << endl;

        cout << "***********************************"
             << endl;

        cout << "CREATE MEMBER "
             << i + 1
             << endl;

        cout << "***********************************"
             << endl;

        string role;
        string name;
        string powerName;

        int health;
        int attack;
        int defense;

        // take role of character from 
        cout << "Enter Role Of Character : ";
        getline(cin, role);

        // take charater name 
        cout << "Enter Character Name : ";
        getline(cin, name);

        // take health  
        cout << "Enter Health : ";
        cin >> health;

        // attak 
        cout << "Enter Attack Power : ";
        cin >> attack;

        // defence
        cout << "Enter Defense : ";
        cin >> defense;

        cin.ignore();

        // power  
        cout << "Enter Special Power : ";
        getline(cin, powerName);

        // create character  
        Character* character;
        character = new Character(
            name,
            role,
            health,
            attack,
            defense,
            powerName
        );

        // Add Member To Team
        team.addMember(character);
    }
}

int main(){  

    srand(time(0));

    cout << "**********************************";
    cout<<endl;

    cout << "        BATTLE ARENA GAME    ";

    cout<<endl;
    cout << "**********************************";
    cout<< endl;

    
    Team teams[10];

    int totalTeams;

    cout << endl;

    cout << "Enter Total Number Of Teams : ";
    cin >> totalTeams;

    cin.ignore();

    // create teams 
    for (int i = 0; i < totalTeams; i++){
        cout << endl;

        cout << "***********************************"
             << endl;

        cout << "CREATE TEAM "
             << i + 1
             << endl;

        cout << "***********************************"
             << endl;

        createTeam(teams[i]);
    }

    // display teams
    cout << endl;

    cout << "***********************************"
         << endl;

    cout << "          TEAM DETAILS"
         << endl;

    cout << "***********************************"
         << endl;

    for (int i = 0; i < totalTeams; i++){
        cout << endl;

        cout << "TEAM NUMBER : "
             << i + 1
             << endl;

        teams[i].displayTeam();
    }

    // team selection
    int team1;
    int team2;

    cout << endl;

    cout << "***********************************"
         << endl;

    cout << "         SELECT TEAMS"
         << endl;

    cout << "***********************************"
         << endl;

    cout << endl;

    cout << "Enter First Team Number : ";
    cin >> team1;

    cout << "Enter Second Team Number : ";
    cin >> team2;

    // Validation
    if (team1 < 1 ||
        team1 > totalTeams ||
        team2 < 1 ||
        team2 > totalTeams)
    {
        cout << endl;

        cout << "Invalid Team Number!"
             << endl;

        return 0;
    }

    // Same Team Check
    if (team1 == team2)
    {
        cout << endl;

        cout << "Both Teams Cannot Be Same!"
             << endl;

        return 0;
    }

    // Start Battle
    BattleArena::startBattle(
        teams[team1 - 1],
        teams[team2 - 1]
    );

    cout << endl;

    return 0;
}
