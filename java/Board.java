import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Board {
    protected int[] rowBoundaries;
    protected int[] columnBoundaries;
    protected Position[] barriers;
    protected Position start;
    protected Position end;

    public Board() {
        this.rowBoundaries = new int[]{0, 7};
        this.columnBoundaries = new int[]{0, 7};
        this.barriers = this.createBarriers();
        this.setStart();
        this.setEnd();        
    }

    private Position[] createBarriers() {
        int[] rows = new int[]{2, 2, 2, 3, 4, 5, 5, 5, 5, 5, 4, 3};
        int[] columns = new int[]{4, 5, 6, 6, 6, 6, 5, 4, 3, 2, 2, 2};
        Position[] barriers = new Position[12];
        for (int i = 0; i < rows.length; i++) {
            barriers[i] = new Position(rows[i], columns[i]);
        }
        return barriers;
    }

    protected void setStart() {
        this.start = new Position(0, 0);
    }

    public Position getStart() {
        return this.start;
    }

    protected void setEnd() {
        this.end = new Position(this.rowBoundaries[1], this.columnBoundaries[1]);
    }

    public Position getEnd() {
        return this.end;
    }

    public void setRowBoundaries(int[] rowBoundaries) {
        this.rowBoundaries = rowBoundaries;
    }

    public void setColumnBoundaries(int[] columnBoundaries) {
        this.columnBoundaries = columnBoundaries;
    }

    public void setBarriers(Position[] barriers) {
        this.barriers = barriers;
    }

    public Position[] getNeighbours(Position position) {
        return availableMoves(position, 1);
    }

    public int getCost(Position position) {
        for (Position b : barriers) {
            if (position.equals(b)) {
                return 100;
            }
        }
        return 1;
    }

    private Position[] availableMoves(Position position, int distance) {
        int[] steps = new int[]{-distance, 0, distance};
        Set<int[]> s = new HashSet<int[]>();
        for (int i = 0; i < steps.length; i++) {
            for (int j = steps.length-1; j >= 0; j--) {
                if (steps[i] == 0 & steps[j] == 0) continue;
                s.add(new int[]{steps[i], steps[j]});
            }
        }
        List<Position> available = new ArrayList<Position>();
        for (int[] d: s) {
            Position pos = Position.move(position, d[0], d[1]);
            if (validPosition(pos) & !(d[0] == 0 & d[1] == 0)) {
                available.add(pos);
            }
        }
        Position[] array = new Position[available.size()];
        available.toArray(array);
        return array;
    }

    private boolean validPosition(Position position) {
        if (validRow(position.row) & validColumn(position.column)) return true;
        return false;
    }

    private boolean validRow(int row) {
        if (this.rowBoundaries[0] <= row & row <= this.rowBoundaries[1]) {
            return true;
        }
        return false;
    }

    private boolean validColumn(int column) {
        if (this.columnBoundaries[0] <= column & column <= this.columnBoundaries[1]) {
            return true;
        }
        return false;
    }
}