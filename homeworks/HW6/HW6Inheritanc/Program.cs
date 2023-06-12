using System;


namespace HW6
{
    public class People
    {
        public string Name { get; set; }
    }
    
    public class Student : People
    {
        public void Study()
        {
            Console.WriteLine($"{Name} is studying.");
        }
    }
    
    public class Teacher : People
    {
        public void Teach()
        {
            Console.WriteLine($"{Name} is teaching.");
        }
    }
    
    public class HW6
    {
        public static void Main(string[] args)
        {
            Student student = new Student();
            student.Name = "John";
            student.Study();
    
            Teacher teacher = new Teacher();
            teacher.Name = "Mr. Smith";
            teacher.Teach();
        }
    }
}