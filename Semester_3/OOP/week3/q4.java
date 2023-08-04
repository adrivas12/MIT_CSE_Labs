
class Stack
{
    int arr[]; 
    int tos;
    int n;

    Stack(int nn)
    {
        arr= new int[n];
        n = nn;
        tos = -1;
    }
    public void push(int x)
    {
        if(isFull())
        {
            System.out.println("Stack overflow");
            System.exit(1);
        }
        System.out.println("Inserting " + x);
        arr[++tos] = x;
    }
    public int pop()
    {
        if(isEmpty()){
            System.out.println("Stack underflow");
            System.exit(1);
        }
        return arr[tos--];
    }
    public int getSize(){
        return tos+1;
    }
    public boolean isFull(){
        return tos == n -1;
    }
    public boolean isEmpty(){
        return tos == -1;
    }
    public void display(){
        for(int i = 0; i<=tos; i++)
        {
            System.out.println(arr[i] + ", ");
        }
    }
}

class q4{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Stack stack = new Stack();
        stack.intialize(10);
        int choice;
        int temp;

        do
        {
            System.out.println("Enter the choice: 1. push 2. pop");
            choice = sc.nextInt();
            switch(choice)
            {
                case 1:
                System.out.println("Enter the element to push");
                temp = sc.nextInt();
                stack.push(temp);
                stack.display();
                break;
                case 2:
                int temp1 = stack.pop();
                System.out.println("The popped element is: " + temp1);
                stack.display();
                break;
            }
            System.out.println("1. continue 2.Exit");
            choice = sc.nextInt();
        } while(choice!=2);
}}
