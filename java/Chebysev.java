public class Chebysev implements Heuristic {
    @Override
    public int getDistance(Position start, Position goal) {
        int D = 1;
        int D2 = 1;
        int[] d = Position.diff(start, goal);
        int distance = D * (d[0] + d[1]) + (D2 - 2 * D) * Math.min(d[0], d[1]);
        return distance;
    }    
}
