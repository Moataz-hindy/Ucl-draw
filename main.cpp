#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <random>
using namespace std;


string generate_team(string club, string country, map <string, vector <string> > pot, vector<string> nations){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 8);

    string selected_country;
    int random_number;
    
    do {
        random_number = dist(gen);
        selected_country = nations[random_number];
    }while (selected_country == country);

        if(pot[ nations[random_number] ].size() > 1){
            std::random_device rd_2;
            std::uniform_int_distribution<int> dist_2(0, pot[ nations[random_number] ].size() - 1);
            int rand_num = dist(rd_2);
            return pot[nations[random_number]][rand_num];
        }else{
            return pot[nations[random_number]][0];
        }
    }

string get_country(string club, map <int, map <string, vector <string> > > clubs_pots){
    string key;
    for(auto& pot_pair : clubs_pots){
        for(auto& country : pot_pair.second){
            for(auto& c : country.second){
                if(c == club){
                    key = country.first;
                }
            }
        }
    }
    return key;
}


int main ()
{
    vector <string> pot_1_nations = {"ENG", "ENG", "ESP", "ESP", "GER", "GER", "GER", "FRA", "ITA"};
    vector <string> pot_2_nations = {"ENG", "ESP", "GER", "POR", "ITA", "ITA", "ITA", "BEL", "UKR"};
    vector <string> pot_3_nations = {"POR", "NED", "NED", "CRO", "FRA", "AUT", "SRB", "SUI", "SCO"};
    vector <string> pot_4_nations = {"ENG", "ESP", "GER", "FRA", "FRA", "ITA", "SVK", "AUT", "CZE"};

    map <string, vector <string> > pot_1 = {
        {"ENG", {"Liverpool", " ManchesterCity"}},
        {"ESP", {"Real Madrid", "Barcelona"}},
        {"GER", {"Bayern Munich", "Borussia Dortmund", "RB Leipzig"}},
        {"FRA", {"Paris Saint-Germain"}},
        {"ITA", {"Inter Milan"}}
    };


    map <string, vector <string> > pot_2 = {
        {"ENG", {"Arsenal"}},
        {"ESP", {"Atlético Madrid"}},
        {"GER", {"Bayer Leverkusen"}},
        {"POR", {"Benfica"}},
        {"ITA", {"Juventus", "Atalanta", "AC Milan"}},
        {"BEL", {"Club Brugge"}},
        {"UKR", {"Shakhtar Donetsk"}}
    };

    map <string, vector <string> > pot_3 = {
        {"POR", {"Sporting CP"}},
        {"NED", {"Feyenoord", "PSV Eindhoven"}},
        {"CRO", {"Dinamo Zagreb"}},
        {"FRA", {"Lille"}},
        {"AUT", {"Red Bull Salzburg"}},
        {"SRB", {"Crvena Zvezda"}},
        {"SUI", {"Young Boys"}},
        {"SCO", {"Celtic"}}
    };

    map <string, vector <string> > pot_4 = {
        {"ENG", {"Aston Villa"}},
        {"ESP", {"Girona"}},
        {"GER", {"VfB Stuttgart"}},
        {"FRA", {"Monaco", "Brest"}},
        {"ITA", {"Bologna"}},
        {"SVK", {"Slovan Bratislava"}},
        {"AUT", {"Sturm Graz"}},
        {"CZE", {"Sparta Phraha"}}
    };


    map <int, map <string, vector <string> > > clubs_pots = {
        {1, pot_1}, {2, pot_2}, {3, pot_3},{4, pot_4}
    };

    vector <string> clubs = {"Liverpool", "Manchester City", "Real Madrid", "Barcelona", 
    "Bayern Munich", "Borussia Dortmund", "RB Leipzig", "Paris Saint-Germain", "Inter Milan",
    "Arsenal", "Atlético Madrid", "Bayer Leverkusen", "Benfica", "Juventus", "Atalanta", "AC Milan", "Club Brugge", 
    "Shakhtar Donetsk", "Sporting CP", "Feyenoord", "PSV Eindhoven", "Dinamo Zagreb", "Lille", "Red Bull Salzburg", 
    "Crvena Zvezda", "Young Boys", "Celtic", "Aston Villa", "Girona", "VfB Stuttgart", "Monaco", "Brest", 
    "Bologna", "Slovan Bratislava", "Sturm Graz", "Sparta Praha"};

    map<string, vector<vector<string>>> fixtures = {
    {"Liverpool", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Manchester City", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Real Madrid", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Barcelona", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Bayern Munich", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Borussia Dortmund", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"RB Leipzig", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Paris Saint-Germain", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Inter Milan", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Arsenal", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Atlético Madrid", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Bayer Leverkusen", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Benfica", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Juventus", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Atalanta", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"AC Milan", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Club Brugge", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Shakhtar Donetsk", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Sporting CP", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Feyenoord", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"PSV Eindhoven", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Dinamo Zagreb", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Lille", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Red Bull Salzburg", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Crvena Zvezda", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Young Boys", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Celtic", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Aston Villa", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Girona", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"VfB Stuttgart", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Monaco", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Brest", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Bologna", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Slovan Bratislava", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Sturm Graz", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}},
    {"Sparta Praha", {{"0,0"}, {"0,0"}, {"0,0"}, {"0,0"}}}
    };


    /*for(int i = 0; i < 36; i++){
        string country = get_country(clubs[i], clubs_pots);
        for(int j = 0; j < 4; j++){
            map <string, vector <string>> pot;
            vector<string> pot_nation;
            if(j == 0){
                pot = pot_1;
                pot_nation = pot_1_nations;
            }else if(j == 1){
                pot = pot_2;
                pot_nation = pot_2_nations;
            }else if(j == 2){
                pot = pot_3;
                pot_nation = pot_3_nations;
            }else{
                pot = pot_4;
                pot_nation = pot_4_nations;
            }
            while(fixtures[clubs[i]][j].size() < 2){
                fixtures[clubs[i]][j].push_back(generate_team(clubs[i], country, pot, pot_nation));
                if(i <= 8){
                    fixtures[generate_team(clubs[i], country, pot, pot_nation)][0].push_back(clubs[i]);
                }else if(8 < i && i <= 17){
                    fixtures[generate_team(clubs[i], country, pot, pot_nation)][1].push_back(clubs[i]);
                }else if(17 < i && i <= 26){
                    fixtures[generate_team(clubs[i], country, pot, pot_nation)][2].push_back(clubs[i]);
                }else{
                    fixtures[generate_team(clubs[i], country, pot, pot_nation)][3].push_back(clubs[i]);
                }
            }
        }
    }*/

    cout << generate_team(clubs[0], pot_1_nations[0], pot_1, pot_1_nations) << endl;
    cout << generate_team(clubs[0], pot_1_nations[0], pot_1, pot_1_nations) << endl;
    cout << generate_team(clubs[0], pot_1_nations[0], pot_2, pot_2_nations) << endl;
    cout << generate_team(clubs[0], pot_1_nations[0], pot_2, pot_2_nations) << endl;
    cout << generate_team(clubs[0], pot_1_nations[0], pot_3, pot_3_nations) << endl;
    cout << generate_team(clubs[0], pot_1_nations[0], pot_3, pot_3_nations) << endl; 
    cout << generate_team(clubs[0], pot_1_nations[0], pot_4, pot_4_nations) << endl;
    cout << generate_team(clubs[0], pot_1_nations[0], pot_4, pot_4_nations) << endl;
    return 0;
}
