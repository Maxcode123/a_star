import java.util.List;

public class Main {
    public static void main(String[] args) {
        Board board = new Board();
        Heuristic heuristic = new Chebysev();

        AStar aStar = new AStar(board, heuristic);
        Position start = new Position(0, 0);
        Position goal = new Position(7, 7);
        List<Position> path = aStar.findPath(start, goal);
        for (Position p: path) {
            System.out.println(p);
        }
    }        
} 