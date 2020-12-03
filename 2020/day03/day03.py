import math

def count_trees(right, down):
    with open("input.txt", "r", encoding="utf-8") as f:
        board = f.readlines()
        board_len = len(board[0])

        x = 0
        y = 0
        num_trees = 0
        for i in range(len(board)):
            x = (x + right) % (board_len-1)
            y += down
            if y > len(board)-1: break
            if board[y][x] == "#":
                num_trees += 1

        print("trees: {}".format(num_trees))

    return num_trees


a = count_trees(1, 1)
b = count_trees(3, 1)
c = count_trees(5, 1)
d = count_trees(7, 1)
e = count_trees(1, 2)

print("sum: {}".format(a*b*c*d*e))
