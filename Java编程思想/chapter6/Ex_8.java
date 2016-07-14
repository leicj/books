// access/ConnectionManage.java
package access;
class Connection {
  private static int count = 0;
  public static Connection makeConnection() {
    count++;
    return new Connection();
  }
  public String toString() {
    return ("connection:" + count);
  }
}

public class ConnectionManager {
  private static int len = 3;
  private static Connection[] arr = new Connection[]{
      Connection.makeConnection(),
      Connection.makeConnection(),
      Connection.makeConnection()
  };
  public static Connection access() {
    if (len > 0) {
      return arr[--len];
    } else {
      return null;
    }
  }

  public static void main(String[] args) {
    ConnectionManager m = new ConnectionManager();
    System.out.println(m.access());
    System.out.println(m.access());
    System.out.println(m.access());
    System.out.println(m.access());
  }
}
