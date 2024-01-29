import java.util.ArrayList;

public class Node {
    private int val;
    private ArrayList<Node> adj;
    public Node(int val) { this.val = val; }
    public void connect(ArrayList<Node> next) { adj = next; }
    public ArrayList<Node> getAdj() { return adj; }

    public int getVal() { return val; }
}
