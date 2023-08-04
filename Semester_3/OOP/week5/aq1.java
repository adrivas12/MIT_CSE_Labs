import java.util.*;

//lab5 aq1
class p13
{
    static void pullout(String s1, String s2)
    {
        String result = s1.replace(String.valueOf(s2), " ");
        System.out.println("The final string is: " + result);
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string: ");
        String str1 = sc.next();
        System.out.println("Enter the substring: ");
        String str2 = sc.next();
        pullout(str1, str2);
    }

}
