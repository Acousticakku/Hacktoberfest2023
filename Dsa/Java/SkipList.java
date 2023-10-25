import java.util.Random;

class SkipNode {
    int value;
    SkipNode next;
    SkipNode down;

    public SkipNode(int value) {
        this.value = value;
        this.next = null;
        this.down = null;
    }
}

public class SkipList {
    private SkipNode head;
    private Random random;

    public SkipList() {
        this.head = new SkipNode(Integer.MIN_VALUE);
        this.random = new Random();
    }

    public void insert(int value) {
        SkipNode current = head;
        SkipNode insertAbove = null;

        while (current != null) {
            if (current.next == null || current.next.value > value) {
                if (insertAbove != null) {
                    SkipNode newNode = new SkipNode(value);
                    newNode.next = current.next;
                    current.next = newNode;
                    newNode.down = insertAbove;
                    insertAbove = newNode;
                } else {
                    insertAbove = new SkipNode(value);
                    insertAbove.down = head;
                    head = insertAbove;
                }
            }
            current = current.down;

            // Randomly decide whether to move to the next level
            if (random.nextDouble() < 0.5) {
                break;
            }
        }
    }

    public boolean search(int value) {
        SkipNode current = head;

        while (current != null) {
            if (current.next == null || current.next.value > value) {
                if (current.value == value) {
                    return true;
                }
                current = current.down;
            } else {
                current = current.next;
            }
        }

        return false;
    }

    public void display() {
        SkipNode current = head;
        while (current != null) {
            SkipNode temp = current;
            while (temp != null) {
                System.out.print(temp.value + " ");
                temp = temp.next;
            }
            System.out.println();
            current = current.down;
        }
    }

    public static void main(String[] args) {
        SkipList skipList = new SkipList();
        skipList.insert(1);
        skipList.insert(3);
        skipList.insert(5);
        skipList.insert(2);
        skipList.insert(4);

        System.out.println("Skip List:");
        skipList.display();

        int searchValue = 3;
        if (skipList.search(searchValue)) {
            System.out.println(searchValue + " found in the Skip List.");
        } else {
            System.out.println(searchValue + " not found in the Skip List.");
        }
    }
}
