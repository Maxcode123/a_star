public class Euclidean implements Heuristic {
    @Override
    public int getDistance(Position start, Position goal) {
        int D = 1;
        int[] d = Position.diff(start, goal);
        double distance = D * Math.sqrt(Math.pow(d[0], 2) + Math.pow(d[1], 2));
        int intDistance = (int) distance;
        return intDistance;
    }
}