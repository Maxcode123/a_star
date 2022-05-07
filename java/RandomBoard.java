import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class RandomBoard extends Board {
    public RandomBoard() {
        setRowBoundaries(generateRandomBoundaries());
        setColumnBoundaries(generateRandomBoundaries());
        setStart();
        setEnd();
        setBarriers(generateRandomBarriers());
    }

    private int[] generateRandomBoundaries() {
        int lower = 0;
        int upper = 0;
        Random rand = new Random();
        while (lower == upper) {
            upper = rand.nextInt(101);
        }
        int[] boundaries = new int[]{lower, upper};
        return boundaries;
    }

    private Position[] generateRandomBarriers() {
        int rows = rowBoundaries[1] - rowBoundaries[0];
        int columns = columnBoundaries[1] - columnBoundaries[0];
        int barriersLength = (int)(0.1875 * rows * columns);
        List<Position> barriers = new ArrayList<Position>();
        while (barriers.size() < barriersLength) {
            Position barrier = generateRandomPosition();
            if (barriers.contains(barrier)) continue;
            else {
                barriers.add(barrier);
            }
        }
        Position[] array = new Position[barriers.size()];
        barriers.toArray(array);
        return array;
    }

    private Position generateRandomPosition() {
        int row = (int) (Math.random() * rowBoundaries[1]);
        int column = (int) (Math.random() * columnBoundaries[1]);
        Position position = new Position(row, column);
        if (position.equals(start)) return generateRandomPosition();
        if (position.equals(end)) return generateRandomPosition();
        return position;
    }

}
