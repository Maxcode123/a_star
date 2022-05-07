public class Manhattan implements Heuristic {
    @Override
    public int getDistance(Position start, Position goal) {
        int D = 1;
        int d[] = Position.diff(start, goal);
        int distance = D * (d[0] + d[1]);
        return distance;
    }    
}
