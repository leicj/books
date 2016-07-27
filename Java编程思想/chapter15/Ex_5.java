public class LinkedStack<T> {
  private static class Node<T> {
    T item;
    Node<T> next;
    Node() { item = null; next = null; }
    Node(T item, Node<T> next) {
      this.item = item;
      this.next = next;
    }
    boolean end() { return item == null && next == null; }
  }
  private Node<T> top = new Node<>();
  public void push(T item) {
    top = new Node<>(item, top);
  }
  public T pop() {
    T result = top.item;
    if (!top.end()) {
      top = top.next;
    }
    return result;
  }

  public static void main(String[] args) {
    LinkedStack<String> lss = new LinkedStack<>();
    for (String s: "hello world Java".split(" ")) {
      lss.push(s);
    }
    String s;
    while ((s = lss.pop()) != null) {
      System.out.println(s);
    }
  }
}
