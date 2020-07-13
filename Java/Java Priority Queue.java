import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
/*
 * Create the Student and Priorities classes here.
 */
import java.util.*;

class Student implements Comparable<Student>
{
    int id;
    String name;
    double cgpa;

    public Student(String name, double cgpa, int id)
    { 
        this.id = id;
        this.name = name; 
        this.cgpa = cgpa; 
    } 

    public int getID()
    {
        return id;
    }

    public String getName()
    {
        return name;
    }

    public double getCGPA()
    {
        return cgpa;
    }

    public int compareTo(Student b)
    {
        if(cgpa != b.getCGPA())
        {
            if(cgpa > b.getCGPA()) return -1;
            else return 1;
        }
        if(!name.equals(b.getName())) return name.compareTo(b.getName());
        return id - b.getID();
    }

}


class Priorities
{
    public static List<Student> getStudents(List<String> events)
    {
    PriorityQueue<Student> pq = new PriorityQueue<Student>();

    for (String event : events)
    {
        if(event.startsWith("SERVED"))
        {
            pq.poll();
            continue;
        }
        String[] input = event.split(" ");
        Student student = new Student(input[1], Double.parseDouble(input[2]),Integer.parseInt(input[3]));
        pq.add(student);
    }

    List<Student> ret = new ArrayList<>();

    while(!pq.isEmpty())
    {
        ret.add(pq.poll());
    }

    return ret;

    }
}


public class Solution {
    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();
    
    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());    
        List<String> events = new ArrayList<>();
        
        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }
        
        List<Student> students = priorities.getStudents(events);
        
        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st: students) {
                System.out.println(st.getName());
            }
        }
    }
}