import java.util.*;

class student
{
    int regno;
    String name;
    GregorianCalendar doj;
    int semester;
    double GPA;
    double CGPA;
    static int count=0; 

    student(){}

    student(String name, GregorianCalendar dojo, int semester, double GPA, double CGPA)
    {
        count++;
        this.name=name;
        doj = dojo;
        int year = Integer.valueOf(doj.get(Calendar.YEAR));
        year = year%100;
        regno = Integer.valueOf(""+ year + String.format("%02d", count));
        this.semester=semester;
        this.GPA = GPA;
        this.CGPA = CGPA;
    }

    void display()
    {
        System.out.println("\nName: " + name +
                            "\nRegistration number: "+ regno +
                            "\nDate of joining(dd/mm/yyyy): " +""+ doj.get(Calendar.DATE)+ "/"+doj.get(Calendar.MONTH)+"/"+ doj.get(Calendar.YEAR) +
                            "\nSemester: "+ semester +
                            "\nGPA: " + GPA +
                            "\nCGPA: " + CGPA);
    }

    static void sort2(student[] s)
    {
        for(int i = 0; i<count-1; i++)
        {
            for(int j = 0; j<count -i -1; j++)
            {
                if(((s[j].semester)>(s[j+1].semester)) && ((s[j].CGPA)>(s[j+1].CGPA)));
                {
                       student temp;
                    temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;
                }
            }
        }
    }
    static void sort1(student[] s)
    {
        for(int i = 0; i<count-1; i++)
        {
            for(int j = 0; j<count - i -1; j++)
            {
                if(s[j].name.compareTo(s[j+1].name)>0)
                {
                    student temp; 
                    temp = s[j]; 
                    s[j] = s[j+1];
                    s[j+1] = temp;
                }
            }
        }
    }

    static void p3q1(int n, student s[])
    {
        Scanner sc2 = new Scanner(System.in);
        System.out.println("Enter a Character: ");
        char ch= sc2.next().charAt(0);
        System.out.println("Students whose name start with "+ch+" : \n");
        for (int i = 0 ; i<n; i++) 
        {
            if (s[i].name.indexOf(ch)==0)
            {
                s[i].display();
            }
        }
    }            
    static void p3q2(int n, student s[])
    {
        Scanner sc2 = new Scanner(System.in);
        System.out.println("\nEnter a String: ");
        String str = sc2.next();
        System.out.println("Students whose name has "+str+": \n");
        for (int i = 0; i<n; i++) 
        {
            if (s[i].name.contains(str))
            {
                s[i].display();
            }
        }
    }
    void p3q3(int n, student s[])
    {
        int flag=0;
        String temp="";
        char initial=' ';
        String out ="";
        for(int i=0;i<name.length();i++) {
            if (Character.isUpperCase(name.charAt(i)))
            {
                flag=1;
                initial=name.charAt(i);
            }
            if (flag == 1) 
            {
                temp = temp + name.charAt(i);
            }
            if (name.charAt(i) == ' ') 
            {
                flag = 0;
                out = out + initial + ". ";
                temp="";
            }
            if (i == name.length()-1) 
            {
                out = out + temp;
            }
        }
        System.out.println("Name: " + out +
                            "\nRegistration number: "+ regno +
                            "\nDate of joining(dd/mm/yyyy): " +""+ doj.get(Calendar.DATE)+ "/"+doj.get(Calendar.MONTH)+"/"+ doj.get(Calendar.YEAR) +
                            "\nSemester: "+ semester +
                            "\nGPA: " + GPA +
                            "\nCGPA: " + CGPA);
    }
}

class q2
{
    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of students: ");
        int n = sc.nextInt();
        student[] s = new student[n];

        for(int i = 0; i<n; i++)
        {
            System.out.println("Enter the student details ");
            System.out.println("Enter name: ");
            String n1 = sc.next();
            String n2 = sc.next();
            System.out.println("Enter date of joining: ");
            int year = sc.nextInt();
            int date =  sc.nextInt();
            int month = sc.nextInt();
            System.out.println("Enter the semester: ");
            int sem = sc.nextInt();
            System.out.println("Enter the GPA: ");
            double gpa = sc.nextDouble();
            System.out.println("Enter the cgpa: ");
            double cgpa = sc.nextDouble();      
            s[i] = new student((n1+" "+n2), new GregorianCalendar(year, month, date), sem, gpa, cgpa);
            s[i].display();
        }
        for(int k = 0; k<5; k++)
        {
            System.out.println("Enter \n1.Sort by name\n" +
                                "2.Sort by CGPA and semester\n"+
                                "3.List all students whose name starts with a particular character\n"+
                                "4.List all the student names containing a particular substring\n"+
                                "5.Change the full name in the object to name with just initials and family name\n");
            int choice = sc.nextInt();

            switch(choice)
            {
            case 1:
                student.sort1(s);
                for(int j=0; j<n; j++)
                    s[j].display();
                break;
            case 2:
                student.sort2(s);
                for(int j=0; j<n; j++)
                    s[j].display();
                break;
            case 3:
                student.p3q1(n,s);
                break;
            case 4:
                student.p3q2(n,s);
                break;
            case 5:
                //student.p3q3(n,s);
                for(int j=0; j<n; j++)
                {
                    s[j].p3q3(n,s);
                }
                break;
            default:
                System.out.println("Wrong choice");
            }
        }
    }
}