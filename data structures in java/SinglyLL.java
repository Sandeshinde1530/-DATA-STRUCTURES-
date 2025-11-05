
class node
{
    int data;
    node next;

    node(int x)
    {
        data = x;
        next = null;
    }
}


class SinglyLinearLL
{
    public node head;
    public int iCount;

    public SinglyLinearLL()
    {
        head = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(head == null)
        {
            head = newn;
        }
        else 
        {
            newn.next  = head;
            head = newn;
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(head == null)
        {
            head = newn;
        }
        else 
        {
            node temp = head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    public void DeleteFirst()
    {
        if(head == null)
        {
            System.out.println("List is empty");
            return;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else
        {
            head = head.next;
            System.gc();
            iCount--;
        }
    }

   public  void DeleteLast()
    {
        if(head == null)
        {
            System.out.println("List is empty");
            return;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else
        {
            node temp = head;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
            System.gc();
            iCount--;
        }
    }

    public void InsertAtPos(int no , int ipos)
    {
        if(ipos < 1 || ipos > iCount + 1)
        {
            System.out.println("Invalid POsition");
            return;
        }
        else if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = new node(no);
            node temp = head;

            for(int i =1 ; i < ipos - 1 ; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
    }
    
    public void DeleteAtPos( int ipos)
    {
        if(ipos < 1 || ipos > iCount)
        {
            System.out.println("Invalid POsition");
            return;
        }
        else if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == iCount)
        {
            DeleteLast();
        }
        else
        {

            node temp = head;

            for(int i = 1 ; i < ipos - 1 ; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            System.gc();

            iCount--;
        }
    }

    public void Display()
    {
        node temp = head;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }
}


class SinglyLL
{
    public static void main(String ar[])
    {
        SinglyLinearLL sobj = new SinglyLinearLL();

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    sobj.Display();
    System.out.println("Count is : "+sobj.iCount);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    sobj.Display();
    System.out.println("Count is : "+sobj.iCount);

    sobj.InsertAtPos(75 , 4);
    sobj.Display();
    System.out.println("Count is : "+sobj.iCount);

    sobj.DeleteAtPos(4);
    sobj.Display();
    System.out.println("Count is : "+sobj.iCount);

     sobj.DeleteFirst();
    sobj.Display();
    System.out.println("Count is : "+sobj.iCount);

     sobj.DeleteLast();
    sobj.Display();
    System.out.println("Count is : "+sobj.iCount);
    }
}