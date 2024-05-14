def count_visited_cells(n, m, room_plan, start_row, start_col, actions):
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    curr_row, curr_col = start_row - 1, start_col - 1
    visited = {(curr_row, curr_col)}

    curr_direction = 0

    for action in actions:
        if action == 'R':
            curr_direction = (curr_direction + 1) % 4
        elif action == 'L':
            curr_direction = (curr_direction - 1) % 4
        else:  # action == 'M'
            next_row = curr_row + directions[curr_direction][0]
            next_col = curr_col + directions[curr_direction][1]

            if 0 <= next_row < n and 0 <= next_col < m and room_plan[next_row][next_col] == '.':
                curr_row, curr_col = next_row, next_col
                visited.add((curr_row, curr_col))

    return len(visited)


n, m = map(int, input().split())
room_plan = [input() for _ in range(n)]
start_row, start_col = map(int, input().split())
q = int(input())
actions = input()
result = count_visited_cells(n, m, room_plan, start_row, start_col, actions)
print(result)
