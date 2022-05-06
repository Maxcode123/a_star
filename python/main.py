from a_star import AStarSearch
from heuristics import Chebysev, Manhattan, Euclidean
from board import Board, RandomBoard

board = RandomBoard()

chebysev = AStarSearch(board, Chebysev)
manhattan = AStarSearch(board, Manhattan)
euclidean = AStarSearch(board, Euclidean)

print(board)
for a_star in {chebysev, manhattan, euclidean}:
    path = a_star.find_path()
    print(f"{a_star} cost: {path.cost}")
