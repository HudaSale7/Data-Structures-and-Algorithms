import java.util.Scanner;

interface ILinkedList {
    public void add(int index, Object element);
    public void add(Object element);
    public Object get(int index);
    public void clear();
    public boolean isEmpty();
    public void set(int index, Object element);
    public void remove(int index);
    public int size();
    public ILinkedList sublist(int fromIndex, int toIndex);
    public boolean contains(Object o);
}
public class DoublyLinkedList implements ILinkedList {

    private DoublyNode head ;
    private DoublyNode current ;
    private int currentPos ;
    private int size ;

    class DoublyNode {
        Object data ;
        DoublyNode next ;
        DoublyNode prev ;

        DoublyNode(Object d ){
            data = d ;
            next = null ;
            prev = null;
        }
        DoublyNode(Object d, DoublyNode p, DoublyNode n ){
            data = d ;
            next = n ;
            prev = p;
        }
    }
    @Override
    public void add(int index, Object element) {
        DoublyNode newNode;
        if(index == 0){
            newNode = new DoublyNode(element);
            newNode.next = head;
            head = newNode ;
            current = head ;
            currentPos = 0 ;
        } else {
            if(index > currentPos) {
                while (currentPos != index) {
                    current = current.next;
                    currentPos++;
                }
            } else {
                while (currentPos != index) {
                    current = current.prev;
                    currentPos--;
                }
            }
            newNode = new DoublyNode(element, current.prev, current);
            current.prev.next = newNode;
            current.prev = newNode;
            currentPos++ ;
        }
        size++;
    }

    @Override
    public void add(Object element) {
        DoublyNode newNode;
        if(head == null){
            newNode = new DoublyNode(element);
            head = newNode ;
            current = newNode ;
            currentPos = 0 ;
        } else {
            while(current.next != null){
                current = current.next ;
                currentPos++ ;
            }
            newNode = new DoublyNode(element, current, null);
            current.next = newNode ;
        }
        size++ ;
    }

    @Override
    public Object get(int index) {
        if(index > currentPos) {
            while (currentPos != index) {
                current = current.next;
                currentPos++;
            }
        } else {
            while (currentPos != index) {
                current = current.prev;
                currentPos--;
            }
        }
        return current.data;
    }



    @Override
    public void clear() {
        if(head != null){
            current = head.next ;
            while(current != null){
                head.next = null ;
                head.prev = null;
                head = current;
                current = current.next ;
            }
            head = null ;
            current=null ;
            currentPos = 0 ;
            size = 0;
        }
    }

    @Override
    public boolean isEmpty() {
        if(size == 0)
            return true ;
        else
            return false ;
    }

    @Override
    public void set(int index, Object element) {
        if(currentPos < index){
            for(int i = currentPos ; i < index ; i++){
                current = current.next ;
                currentPos++ ;
            }
        }else{
            for(int i = currentPos ; i > index ; i--){
                current = current.prev ;
                currentPos-- ;
            }
        }

        current.data = element ;
    }

    @Override
    public void remove(int index) {
        if(index == 0){
            current = head;
            currentPos = 0 ;
            head = current.next ;
        }else{
            if(currentPos < index){
                for(int i = currentPos ; i < index ; i++){
                    current = current.next ;
                    currentPos++ ;
                }
            }else{
                for(int i = currentPos ; i > index ; i--){
                    current = current.prev ;
                    currentPos-- ;
                }
            }
            if(index == size - 1){
                current.prev.next = null ;
            }else{
                current.prev.next = current.next ;
                current.next.prev = current.prev ;
            }
        }
        current.next = null ;
        current.prev = null ;
        current = head ;
        currentPos = 0 ;
        size-- ;
    }

    @Override
    public int size() {
        return this.size;
    }

    @Override
    public ILinkedList sublist(int fromIndex, int toIndex) {
        DoublyLinkedList newList = new DoublyLinkedList() ;
        if(currentPos < fromIndex){
            for(int i = currentPos ; i < fromIndex ; i++){
                current = current.next ;
                currentPos++ ;
            }
        }else{
            for(int i = currentPos ; i > fromIndex ; i--){
                current = current.prev ;
                currentPos-- ;
            }
        }
        for (int i = fromIndex ; i <= toIndex ; i++){
            newList.add(current.data);
            current = current.next ;
        }
        return newList ;
    }

    @Override
    public boolean contains(Object o) {
        current = head;
        for(int i = 0; i < size; i++) {
            if (current.data == o)
                return true;
            current = current.next;
            currentPos++;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String inputString = scan.nextLine().replace(" ", "").replace("[", "").replace("]", "");
        String fun = scan.nextLine();
        String[] inputData;
        if (inputString.isEmpty()) {
            //empty
            inputData = new String[0];
        } else if (inputString.contains(",") == false) {
            inputData = new String[1];
            inputData[0] = inputString;
        } else {
            inputData = inputString.split(",");
        }

        ILinkedList myList = new DoublyLinkedList();
        ILinkedList copyList = new DoublyLinkedList();
        for (int i = 0; i < inputData.length; i++) {
            myList.add(Integer.parseInt(inputData[i]));
        }
        int element;
        int index;
        switch (fun) {
            case "add":
                element = scan.nextInt();
                myList.add(element);
                System.out.print("[");
                for (int i = 0; i < myList.size(); i++) {
                    System.out.print(myList.get(i));
                    if (i != myList.size() - 1)
                        System.out.print(", ");
                }
                System.out.print("]");
                break;
            case "addToIndex":
                index = scan.nextInt();
                element = scan.nextInt();
                if (index > myList.size() || index < 0) {
                    System.out.print("Error");
                    break;
                }
                myList.add(index, element);
                System.out.print("[");
                for (int i = 0; i < myList.size(); i++) {
                    System.out.print(myList.get(i));
                    if (i != myList.size() - 1)
                        System.out.print(", ");
                }
                System.out.print("]");
                break;
            case "isEmpty":
                if (myList.isEmpty() == false)
                    System.out.print("False");
                else
                    System.out.print("True");
                break;
            case "set":
                index = scan.nextInt();
                if (index >= myList.size() || index < 0) {
                    System.out.print("Error");
                    break;
                }
                element = scan.nextInt();
                myList.set(index, element);
                System.out.print("[");
                for (int i = 0; i < myList.size(); i++) {
                    System.out.print(myList.get(i));
                    if (i != myList.size() - 1)
                        System.out.print(", ");
                }
                System.out.print("]");
                break;
            case "get":
                index = scan.nextInt();
                if (index >= myList.size() || index < 0) {
                    System.out.print("Error");
                    break;
                }
                System.out.print(myList.get(index));
                break;
            case "size":
                System.out.print(myList.size());
                break;
            case "contains":
                element = scan.nextInt();
                if (myList.contains(element) == false)
                    System.out.print("False");
                else
                    System.out.print("True");
                break;
            case "sublist":
                index = scan.nextInt();
                int index2 = scan.nextInt();
                if (index >= myList.size() || index2 >= myList.size() || index > index2 || index < 0 || index2 < 0) {
                    System.out.print("Error");
                    break;
                }
                copyList = myList.sublist(index, index2);
                System.out.print("[");
                for (int i = 0; i < copyList.size(); i++) {
                    System.out.print(copyList.get(i));
                    if (i != copyList.size() - 1)
                        System.out.print(", ");
                }
                System.out.print("]");
                break;
            case "clear":
                myList.clear();
                System.out.print("[]");
                break;
            case "remove":
                index = scan.nextInt();
                if (index >= myList.size() || index < 0) {
                    System.out.print("Error");
                    break;
                }
                myList.remove(index);
                System.out.print("[");
                for (int i = 0; i < myList.size(); i++) {
                    System.out.print(myList.get(i));
                    if (i != myList.size() - 1)
                        System.out.print(", ");
                }
                System.out.print("]");
                break;
        }
    }
}
