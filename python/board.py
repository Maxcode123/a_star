from random import randint
from typing import List, Optional, Set, Tuple
from itertools import product

from position import Position


class Board:
    def __init__(self) -> None:
        self._row_boundaries = (0, 7)
        self._column_boundaries = (0, 7)
        self._barriers = [
            Position(x, y)
            for x, y in {
                (2, 4),
                (2, 5),
                (2, 6),
                (3, 6),
                (4, 6),
                (5, 6),
                (5, 5),
                (5, 4),
                (5, 3),
                (5, 2),
                (4, 2),
                (3, 2),
            }
        ]
        self._set_start()
        self._set_end()

    def _set_start(self) -> None:
        self._start = Position(0, 0)

    def get_start(self) -> Position:
        return self._start

    def _set_end(self) -> None:
        self._end = Position(
            self._row_boundaries[1], self._column_boundaries[1]
        )

    def get_end(self) -> Position:
        return self._end

    def set_row_boundaries(self, row_boundaries: Tuple[int, int]) -> None:
        self._row_boundaries = row_boundaries

    def set_column_boundaries(
        self, column_boundaries: Tuple[int, int]
    ) -> None:
        self._column_boundaries = column_boundaries

    def set_barriers(self, barriers: List[Position]) -> None:
        self._barriers = barriers

    def get_neighbours(self, position: Position) -> Set[Position]:
        return self._available_moves(position, distance=1)

    def get_cost(self, position: Position) -> int:
        if position in self._barriers:
            return 100
        return 1

    def _available_moves(
        self, position: Position, distance: int
    ) -> Set[Position]:
        available_moves = set()
        for (dx, dy) in product([-distance, 0, distance], repeat=2):
            pos = Position.move(position, dx, dy)
            if self._valid_position(pos) and (dx, dy) != (0, 0):
                available_moves.add(pos)
        return available_moves

    def _valid_position(self, position: Position) -> bool:
        if self._valid_row(position.row) and self._valid_column(
            position.column
        ):
            return True
        return False

    def _valid_row(self, row: int) -> bool:
        if self._row_boundaries[0] <= row <= self._row_boundaries[1]:
            return True
        return False

    def _valid_column(self, column: int) -> bool:
        if self._column_boundaries[0] <= column <= self._column_boundaries[1]:
            return True
        return False

    def __str__(self) -> str:
        return f"{self._row_boundaries[1]+1}x{self._column_boundaries[1]+1} Board"


class RandomBoard(Board):
    def __init__(self) -> None:
        self.set_row_boundaries(self._generate_random_boundaries())
        self.set_column_boundaries(self._generate_random_boundaries())
        self._set_start()
        self._set_end()
        self.set_barriers(self._generate_random_barriers())

    @staticmethod
    def _generate_random_boundaries() -> Tuple[int, int]:
        lower = upper = 0
        while lower == upper:
            upper = randint(1, 100)
        return (lower, upper)

    def _generate_random_barriers(self) -> List[Position]:
        rows = self._row_boundaries[1] - self._row_boundaries[0]
        columns = self._column_boundaries[1] - self._column_boundaries[0]
        barriers_len = int(0.1875 * rows * columns)
        barriers = []
        while len(barriers) < barriers_len:
            barrier = self._generate_random_position()
            if barrier in barriers:
                continue
            else:
                barriers.append(barrier)
        return barriers

    def _generate_random_position(self) -> Position:
        row = randint(*self._row_boundaries)
        column = randint(*self._column_boundaries)
        random_position = Position(row, column)
        if random_position == self._start:
            return self._generate_random_position()
        return random_position

