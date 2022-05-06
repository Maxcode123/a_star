from __future__ import annotations
from typing import Tuple


class Position:
    def __init__(self, row: int, column: int) -> None:
        self.row = row
        self.column = column

    @classmethod
    def move(cls, position: Position, dx: int, dy: int) -> Position:
        row = position.row + dx
        column = position.column + dy
        pos = cls(row, column)
        return pos

    @staticmethod
    def diff(position_1: Position, position_2: Position) -> Tuple[int, int]:
        dx = abs(position_1.row - position_2.row)
        dy = abs(position_1.column - position_2.column)
        return dx, dy

    def __eq__(self, other: Position) -> bool:
        if self.row == other.row and self.column == other.column:
            return True
        return False

    def __hash__(self) -> int:
        return self.column + 7 * self.row

    def __str__(self) -> str:
        return f"({self.row}, {self.column})"

    def __repr__(self) -> str:
        return self.__str__()
