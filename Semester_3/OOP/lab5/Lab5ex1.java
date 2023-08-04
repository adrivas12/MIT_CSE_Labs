import java.util.*; // * says that all the classes in java.util are imported

class student
{
int regno;
String name;
GregorianCalendar doj;
int semester;
double GPA;
double CGPA;
static int count=0; // counting the no of students = counting the no of objects. Hence, static member
student(String name,GregorianCalendar doj,int semester,double GPA,double CGPA)
{
count++;
this.name=name;
doj=doj;
int year = Integer.valueOf(doj.get(Calendar.YEAR)); //Calendar is abstract class and YEAR is the property
year = year%100;
regno = Integer.valueOf(""+year+String.format("%02d",count)); //
semester=semester;
GPA=GPA;
CGPA=CGPA;
}
void display()
{
System.out.println("name: "+name+"\n"+"regno: "+regno);
}
static void sort(student[] s)
{
Scanner sc =new Scanner(System.in);
System.out.println("Enter the choice 1. Sort by name 2. Sort by sem and CGPA");
int choice = sc.nextInt();
switch(choice)
{
case 1:
for(int i=0;i<count-1;i++)
{
for(int j=0;j<count-i-1;j++) // 2 for loops just for bubble sorting
{
//for(int k=0;k<s[j].name.length();k++)
//{
if(s[j].name.compareTo(s[j+1].name)>0)                    //.name.charAt(k) > s[j+1].name.charAt(k))
{
student temp;  // reference of the class student. 
temp=s[j];
s[j]=s[j+1];
s[j+1]=temp;
}}}
break;
case 2:
break;
}
}
}
class Lab5ex1
{
public static void main(String[] args)
{
student[] s = new student[3];
Scanner sc =new Scanner(System.in);
for(int i=0;i<3;i++)
{
System.out.println("Enter the student details");
s[i] = new student(sc.next(),new GregorianCalendar(sc.nextInt(),sc.nextInt(),sc.nextInt()),sc.nextInt(),sc.nextDouble(),sc.nextDouble());
s[i].display();
}
student.sort(s);
for(int i=0;i<3;i++)
s[i].display();
}
}