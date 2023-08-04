import java.util.*;
import java.util.GregorianCalendar;

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
        System.out.println("\n" + "Name: " + name);
        System.out.println("Registration number: "+ regno);
        System.out.println("Date of joining: " + doj);
        System.out.println("Semester: "+ semester);
        System.out.println("GPA: " + GPA);
        System.out.println("CGPA: " + CGPA);
    }

    /*static void student(student[] s)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println()
    }*/
}

class q1
{
    public static void main(String[] args)
    {
        student[] s = new student[3];
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i<5; i++)
        {
            System.out.println("Enter the student details: ");
            System.out.println("Enter name: ");
            String n = sc.next();
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
            s[i] = new student(n, new GregorianCalendar(year, month, date), sem, gpa, cgpa);
            s[i].display();
        }
    }
}