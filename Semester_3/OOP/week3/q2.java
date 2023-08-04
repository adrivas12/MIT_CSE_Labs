class Time
{
    int hrs;
    int mins;
    int secs;

    //Time(){}
    void setvalues(int hours, int minutes, int seconds)
    {
        hrs = hours;
        mins = minutes;
        secs = seconds;
    }

    void display()
    {
        System.out.println("Time: "+ hrs+ ":"+mins+":"+secs);
    }

    Time sum(Time t1, Time t2)
    {
        Time temp = new Time();
        temp.hrs = t1.hrs + t2.hrs;
        temp.mins = t1.mins + t2.mins;
        temp.mins = t1.mins + t2.mins;
        return temp;
    }
    Time diff(Time t1, Time t2)
    {
        Time temp = new Time();
        temp.hrs = t1.hrs - t2.hrs;
        temp.mins = t1.mins - t2.mins;
        temp.secs = t1.secs - t2.secs;
        return temp;
    }
    Time compare(Time t1, Time t2)
    {
        Time temp = new Time();
        temp.hrs = 0;
        temp.mins = 0; 
        temp.secs = 0;
        if(t1.hrs == t2.hrs)
        {
            if(t1.mins>t2.mins)
                return t1;
            else if(t1.mins<t2.mins) 
                return t2;
            else if(t1.mins == t2.mins)
                {
                    if(t1.secs>t2.secs) 
                        return t1;
                    else if(t1.secs<t2.secs) 
                        return t2;
                    else if(t1.secs == t2.secs) {
                        return temp;
                    }
                }
        }
        else if(t1.hrs>t2.hrs)
        {
            return t1;
        }
        else if(t1.hrs<t2.hrs) 
        {
            return t2;
        }
        return temp;
    }
}

class q2
{
    public static void main(String[] args)
    {
        Time t1 = new Time();
        t1.setvalues(10, 20, 35);
        t1.display();

        Time t2 = new Time();
        t2.setvalues(9, 40, 15);
        t2.display();

        Time t3 = new Time();

        t3 = t3.sum(t1, t2);
        t3.display();

        t3 = t3.diff(t1, t2);
        t3.display();

        System.out.println("Comparison: ");
        t3 = t3.compare(t1, t2);
        t3.display();
        System.out.println("is greater");
    }
}