public class Position {

    public int row;
    public int column;

    public Position(int row, int column) {
        this.row = row;
        this.column = column;
    }

    public static Position move(Position position, int dx, int dy) {
        int row = position.row + dx;
        int column = position.column + dy;
        Position pos = new Position(row, column);
        return pos;
    }

    public static int[] diff(Position position1, Position position2) {
        int dx = Math.abs(position1.row - position2.row);
        int dy = Math.abs(position1.column - position2.column);
        int[] diff = {dx, dy};
        return diff;
    }

    public boolean equals(Object o) {
        if (o == this) return true;
        if (!(o instanceof Position)) return false;
        Position pos = (Position)o;
        return pos.row == row && pos.column == column;
    }

    public int hashCode() {
        int result = 17;
        result = 37 * result + row;
        result = 37 * result + column;
        return result;
    }

    public String toString() {
        return "(" + row + ", " + column + ")";
    }
}
