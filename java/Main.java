import java.util.List;

public class Main {
    public static void main(String[] args) {
        Board board = new Board();
        Heuristic heuristic = new Chebysev();

        AStar aStar = new AStar(board, heuristic);
        List<Position> path = aStar.findPath();
        for (Position p: path) {
            System.out.println(p);
        }
    }        
} 