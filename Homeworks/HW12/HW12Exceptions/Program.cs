using System;

namespace HW12Exceptions
{

    public class HW12Exceptions
    {
        public class CustomException : Exception
        {
            public CustomException(string message) : base(message)
            {
                
            }
        }
        static void Main(string[] args)
        {
           try
           {
                throw new CustomException("Custom Exception");
           }
           catch(Exception e)
           {
               Console.WriteLine("Custom Exception caught");
           }
        }   
    }
}