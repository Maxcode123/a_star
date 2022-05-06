from typing import List

from position import Position


class Path:
    def __init__(self, positions: List[Position], cost: int) -> None:
        self.positions = positions
        self.cost = cost
