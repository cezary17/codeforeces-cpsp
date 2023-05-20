import sys


def move_ball(grid, curr_pos, direction):
    dir_dict = {"DL": (1, -1), "DR": (1, 1), "UL": (-1, -1), "UR": (-1, 1)}
    new_y = curr_pos[0] + dir_dict[direction][0]
    new_x = curr_pos[1] + dir_dict[direction][1]
    if new_x > grid[1] or new_x < 1 or new_y > grid[0] or new_y < 1:
        return curr_pos
    return new_y, new_x


def change_dir(grid, curr_pos, direction):
    flip_dict = {"X": {"UL": "DL", "DL": "UL", "UR": "DR", "DR": "UR"},
                 "Y": {"UL": "UR", "DL": "DR", "UR": "UL", "DR": "DL"},
                 "XY": {"UL": "DR", "DL": "UR", "UR": "DL", "DR": "UL"}}
    grid_y, grid_x = (grid[0], grid[1])
    if curr_pos[0] == 1 and curr_pos[1] not in [1, grid_x]:  # X-axis top
        return flip_dict["X"][direction]
    elif curr_pos[1] == grid_x and curr_pos[0] not in [1, grid_y]:  # Y-axis right
        return flip_dict["Y"][direction]
    elif curr_pos[1] == 1 and curr_pos[0] not in [1, grid_y]:  # Y-axis left
        return flip_dict["Y"][direction]
    elif curr_pos[0] == grid_y and curr_pos[1] not in [1, grid_x]:  # X-axis bottom
        return flip_dict["X"][direction]
    elif curr_pos[0] == 1 and curr_pos[1] == 1:  # top left corner
        return flip_dict["XY"][direction]
    elif curr_pos[0] == 1 and curr_pos[1] == grid_x:  # top right corner
        return flip_dict["XY"][direction]
    elif curr_pos[0] == grid_y and curr_pos[1] == 1:  # bottom left corner
        return flip_dict["XY"][direction]
    elif curr_pos[0] == grid_y and curr_pos[1] == grid_x:  # bottom right corner
        return flip_dict["XY"][direction]
    else:
        print("Error: ", curr_pos, direction)


# ball: (y, x)  grid: (y, x)

no_test_cases = sys.stdin.readline()
data = []
for line in sys.stdin:
    data.append(line.strip())

for test_case in data:
    n, m, i1, j1, i2, j2, dirn = test_case.split(' ')
    grid_size = (int(n), int(m))
    ball_pos = (int(i1), int(j1))
    end_pos = (int(i2), int(j2))
    bounces = 0
    while ball_pos != end_pos:
        if bounces > 10000:  # TODO how to find if ball never reaches end_pos
            print(-1)
            break
        ball_pos = move_ball(grid_size, ball_pos, dirn)
        if ball_pos == end_pos:
            print(bounces)
            break
        if (ball_pos[0] == grid_size[0]) or (ball_pos[1] == grid_size[1]) or (ball_pos[0] == 1) or (ball_pos[1] == 1):
            bounces += 1
            dirn = change_dir(grid_size, ball_pos, dirn)
