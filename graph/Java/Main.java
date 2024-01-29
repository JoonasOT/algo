import java.util.*;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        var N = 100;
        ArrayList<Node> nodes = new ArrayList<>(IntStream.range(0, N).mapToObj(Node::new).toList());
        for(int i : IntStream.range(0, N - 1).toArray()) {
            ArrayList<Node> adj = new ArrayList<Node>();
            adj.add(nodes.get(i + 1));
            nodes.get(i).connect(adj);
        }
        var node = nodes.get(0);
        while(true) {
            System.out.println(node.getVal());
            try { node = node.getAdj().get(0); }
            catch (NullPointerException e) { break; }
        }
        bfs(nodes, 0);
    }
    public static void bfs(ArrayList<Node> nodes, int start_index) {
        Node last_node_on_layer = nodes.get(start_index);
        Boolean[] done = new Boolean[nodes.size()];
        Arrays.fill(done, false);

        Deque<Node> Q = new ArrayDeque<>();
        Q.addFirst(last_node_on_layer);

        while (!Q.isEmpty()) {
            Node u = Q.pop();
            if( done[nodes.indexOf(u)] ) continue;
            done[nodes.indexOf(u)] = true;

            var adj = u.getAdj().stream().filter(x -> done[nodes.indexOf(x)]).toList();

            for(Node n : adj) {
                System.out.printf("%s ", n.getVal());
            }

            Q.addAll(adj);
            if(u == last_node_on_layer) {
                last_node_on_layer = adj.get(adj.size() - 1);
                System.out.println();
            }
        }
    }
}
