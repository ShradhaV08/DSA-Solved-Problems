import java.util.*;

public class NestedIterator implements Iterator<Integer> {

    private Deque<Iterator<NestedInteger>> stack = new ArrayDeque<>();
    private Integer nextVal = null;

    public NestedIterator(List<NestedInteger> nestedList) {
        stack.push(nestedList.iterator());
    }

    @Override
    public Integer next() {
        Integer res = nextVal;
        nextVal = null;
        return res;
    }

    @Override
    public boolean hasNext() {
        while (!stack.isEmpty()) {
            Iterator<NestedInteger> it = stack.peek();
            if (!it.hasNext()) {
                stack.pop();
                continue;
            }

            NestedInteger ni = it.next();
            if (ni.isInteger()) {
                nextVal = ni.getInteger();
                return true;
            } else {
                stack.push(ni.getList().iterator());
            }
        }
        return false;
    }
}
//DSA