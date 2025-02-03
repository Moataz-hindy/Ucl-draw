import random

clubs = ["Liverpool", "Manchester City", "Real Madrid", "Barcelona", 
        "Bayern Munich", "Borussia Dortmund", "RB Leipzig", "Paris Saint-Germain", "Inter Milan",
        "Arsenal", "Atlético Madrid", "Bayer Leverkusen", "Benfica", "Juventus", "Atalanta", "AC Milan", "Club Brugge", 
        "Shakhtar Donetsk", "Sporting CP", "Feyenoord", "PSV Eindhoven", "Dinamo Zagreb", "Lille", "Red Bull Salzburg", 
        "Crvena Zvezda", "Young Boys", "Celtic", "Aston Villa", "Girona", "VfB Stuttgart", "Monaco", "Brest", 
        "Bologna", "Slovan Bratislava", "Sturm Graz", "Sparta Praha"]

pot_1 = {
    "ENG": ["Liverpool", "Manchester City"],
    "ESP": ["Real Madrid", "Barcelona"],
    "GER": ["Bayern Munich", "Borussia Dortmund", "RB Leipzig"],
    "FRA": ["Paris Saint-Germain"],
    "ITA": ["Inter Milan"]
}

pot_2 = {
    "ENG": ["Arsenal"],
    "ESP": ["Atlético Madrid"],
    "GER": ["Bayer Leverkusen"],
    "POR": ["Benfica"],
    "ITA": ["Juventus", "Atalanta", "AC Milan"],
    "BEL": ["Club Brugge"],
    "UKR": ["Shakhtar Donetsk"]
}

pot_3 = {
    "POR": ["Sporting CP"],
    "NED": ["Feyenoord", "PSV Eindhoven"],
    "CRO": ["Dinamo Zagreb"],
    "FRA": ["Lille"],
    "AUT": ["Red Bull Salzburg"],
    "SRB": ["Crvena Zvezda"],
    "SUI": ["Young Boys"],
    "SCO": ["Celtic"]
}

pot_4 = {
    "ENG": ["Aston Villa"],
    "ESP": ["Girona"],
    "GER": ["VfB Stuttgart"],
    "FRA": ["Monaco", "Brest"],
    "ITA": ["Bologna"],
    "SVK": ["Slovan Bratislava"],
    "AUT": ["Sturm Graz"],
    "CZE": ["Sparta Praha"]
}

club_pots = {
    1 : pot_1, 2 : pot_2, 3 : pot_3, 4 : pot_4
}


fixtures = { team: [[] for _ in range(4)] for team in clubs } 


def print_fixture(club, fixtures):
    if club in fixtures:
        for matches in fixtures[club]():
            print(matches)
                    


def get_country(club, pot):
    for country, clubs in pot.items():
        for team in clubs:
            if(club == team):
                return country



def generate_team(club, pot):
    random.seed()
    club_nation = get_country(club, pot)
    filtered_pot = {nation: team for nation, team in pot.items() if nation != club_nation}
    possible_clubs = [team for team_list in filtered_pot.values() for team in team_list]
    random_club = random.choice(possible_clubs)
    return random_club


pot = list()


for i in range(36):
    for j in range(4):
        if(j == 0):
            pot = pot_1
        elif(j == 1):
            pot = pot_2
        elif(j == 2):
            pot = pot_3
        else:
            pot_4
        while(len(fixtures[clubs[i]][j]) < 2):
            generated_team = generate_team(clubs[i], pot)
            fixtures[clubs[i]][j].append(generated_team)
            if(i <= 8):
                fixtures[generated_team][0].append(clubs[i])
            elif(8 < i and i <= 17):
                fixtures[generated_team][1].append(clubs[i])
            elif(17 < i and i <= 26):
                fixtures[generated_team][2].append(clubs[i])
            else:
                fixtures[generated_team][3].append(clubs[i])


print(get_country("Liverpool", pot_1))
#print(fixtures["Liverpool"].append(generate_team("Liverpool", pot_1)))
print(len(fixtures["Liverpool"][0]))
#print_fixture("Liverpool", fixtures)
print(fixtures)





