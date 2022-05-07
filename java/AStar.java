import java.util.Set;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

public class AStar {
    private Board board;
    private Heuristic heuristic;
    private Set<Position> openSet;
    private Set<Position> closedSet;
    private Map<Position, Position> cameFrom;
    private Map<Position, Integer> gScore;
    private Map<Position, Integer> fScore;

    public AStar(Board board, Heuristic heuristic) {
        this.board = board;
        this.heuristic = heuristic;
    }

    private void initAttrs(Position start, Position goal) {
        openSet.add(start);
        closedSet = new HashSet<Position>();
        cameFrom = new HashMap<Position, Position>();
        gScore = new HashMap<Position, Integer>();
        gScore.put(start, 0);
        fScore = new HashMap<Position, Integer>();
        fScore.put(start, this.heuristic.getDistance(start, goal));
    }

    public List<Position> findPath(Position start, Position goal) {
        initAttrs(start, goal);
        while (openSet.size() > 0) {
            Position current = findMinFPosition();

            if (current == goal) return reconstructPath(goal);
            openSet.remove(current);
            closedSet.add(current);

            for (Position n : board.getNeighbours(current)) {
                if (closedSet.contains(n)) continue;
                if (!openSet.contains(n)) openSet.add(n);
                appointFScore(current, n, goal);
            }
        }
        List<Position> emptyList = new ArrayList<Position>();
        return emptyList;
    }

    private Position findMinFPosition() {
        Position minFPos = openSet.toArray(new Position[openSet.size()])[0];
        int minFScore = fScore.get(minFPos);
        for (Position pos : openSet) {
            if (fScore.get(pos) < minFScore) {
                minFScore = fScore.get(pos);
                minFPos = pos;
            }
        }
        return minFPos;
    }

    private void appointFScore(Position current, Position neighbour, Position goal) {
        int tentativeGScore = gScore.get(current) + board.getCost(neighbour);
        cameFrom.put(neighbour, current);
        gScore.put(neighbour, tentativeGScore);
        fScore.put(neighbour, tentativeGScore + heuristic.getDistance(neighbour, goal));
    }

    private List<Position> reconstructPath(Position position) {
        List<Position> positions = new ArrayList<Position>();
        positions.add(position);
        // int cost = fScore.get(position);
        while (cameFrom.containsKey(position)) {
            position = cameFrom.get(position);
            positions.add(position);
        }
        return positions;
    }
}
