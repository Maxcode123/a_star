public class Board {
    private int[] rowBoundaries;
    private int[] columnBoundaries;
    private Position[] barriers;
    private Position start;
    private Position end;

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
        Position[] barriers;
        for (int i = 0; i < rows.length; i++) {
            barriers[i] = new Position(rows[i], columns[i]);
        }
        return barriers;
    }

    private void setStart() {
        this.start = new Position(0, 0);
    }

    public Position getStart() {
        return this.start;
    }

    private void setEnd() {
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

    }

    public int getCost(Position position) {
        for (Position b : barriers) {
            if (position == b) {
                return 100;
            }
        }
        return 1;
    }
}