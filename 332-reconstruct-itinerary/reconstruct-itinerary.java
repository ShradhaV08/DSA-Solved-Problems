import java.util.*;

class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, PriorityQueue<String>> graph = new HashMap<>();

        // build graph
        for (List<String> ticket : tickets) {
            graph
                .computeIfAbsent(ticket.get(0), k -> new PriorityQueue<>())
                .offer(ticket.get(1));
        }

        LinkedList<String> itinerary = new LinkedList<>();
        dfs("JFK", graph, itinerary);
        return itinerary;
    }

    private void dfs(String airport,
                     Map<String, PriorityQueue<String>> graph,
                     LinkedList<String> itinerary) {

        PriorityQueue<String> pq = graph.get(airport);
        while (pq != null && !pq.isEmpty()) {
            dfs(pq.poll(), graph, itinerary);
        }

        // add airport after visiting all outgoing edges
        itinerary.addFirst(airport);
    }
}
//DSA