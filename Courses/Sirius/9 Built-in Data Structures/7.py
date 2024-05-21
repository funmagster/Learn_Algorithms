def calculate_team_points(num_teams, num_entries):
    word_to_team = {}
    team_points = [0] * num_teams

    for _ in range(num_entries):
        team, word = input().split()
        word_to_team[word] = int(team)

    for team in word_to_team.values():
        team_points[team - 1] += 1

    return team_points


num_teams, num_entries = map(int, input().split())
print(*calculate_team_points(num_teams, num_entries))