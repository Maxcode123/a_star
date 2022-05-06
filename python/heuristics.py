from abc import ABC, abstractmethod
import math

from position import Position


class Heuristic(ABC):
    @staticmethod
    @abstractmethod
    def get_distance(start: Position, goal: Position) -> int:
        pass


class Chebysev(Heuristic):
    @staticmethod
    def get_distance(start: Position, goal: Position) -> int:
        D = 1
        D2 = 1
        dx, dy = Position.diff(start, goal)
        distance = D * (dx + dy) + (D2 - 2 * D) * min(dx, dy)
        return distance

    def __str__(self) -> str:
        return "Chebysev distance heuristic"


class Manhattan(Heuristic):
    @staticmethod
    def get_distance(start: Position, goal: Position) -> int:
        D = 1
        dx, dy = Position.diff(start, goal)
        distance = D * (dx + dy)
        return distance
    
    def __str__(self) -> str:
        return "Manhattan distance heuristic"


class Euclidean(Heuristic):
    @staticmethod
    def get_distance(start: Position, goal: Position) -> int:
        D = 1
        dx, dy = Position.diff(start, goal)
        distance = D * math.sqrt(dx**2 + dy**2)
        return distance

    def __str__(self) -> str:
        return "Euclidean distance heuristic"

