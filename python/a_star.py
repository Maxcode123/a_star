from typing import List, Optional

from board import Board
from position import Position
from heuristics import Heuristic
from path import Path


class AStarSearch:
    def __init__(self, board: Board, heuristic: Heuristic) -> None:
        self.board = board
        self.heuristic = heuristic

    def _init_attrs(self, start: Position, goal: Position) -> None:
        self._open_set = set([start])
        self._closed_set = set()
        self._came_from = {}
        self._g_score = {start: 0}
        self._f_score = {start: self.heuristic.get_distance(start, goal)}

    def find_path(
        self, start: Optional[Position] = None, goal: Optional[Position] = None
    ) -> Path:
        """Returns the path as a list of positions."""
        if start is None:
            start = self.board.get_start()
        if goal is None:
            goal = self.board.get_end()
        self._init_attrs(start, goal)

        while len(self._open_set) > 0:
            current = self._find_min_f_position()

            if current == goal:
                return self._reconstruct_path(goal)

            self._open_set.remove(current)
            self._closed_set.add(current)

            for neighbour in self.board.get_neighbours(current):
                if neighbour in self._closed_set:
                    continue
                if neighbour not in self._open_set:
                    self._open_set.add(neighbour)

                self._appoint_f_score(current, neighbour, goal)

    def _find_min_f_position(self) -> Position:
        min_f_pos = next(iter(self._open_set))
        min_f_score = self._f_score[min_f_pos]

        for pos in self._open_set:
            if self._f_score[pos] < min_f_score:
                min_f_score = self._f_score[pos]
                min_f_pos = pos
        return min_f_pos

    def _appoint_f_score(
        self, current: Position, neighbour: Position, goal: Position
    ) -> None:
        tentative_g_score = self._g_score[current] + self.board.get_cost(
            neighbour
        )
        self._came_from[neighbour] = current
        self._g_score[neighbour] = tentative_g_score
        self._f_score[
            neighbour
        ] = tentative_g_score + self.heuristic.get_distance(neighbour, goal)

    def _reconstruct_path(self, position: Position) -> Path:
        positions = [position]
        cost = self._f_score[position]
        while position in self._came_from:
            position = self._came_from[position]
            positions.insert(0, position)
        path = Path(positions, cost)
        return path

    def __str__(self) -> str:
        return f"A* search algorithm with {self.heuristic()}"
    