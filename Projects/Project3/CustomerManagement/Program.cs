using System;
using System.Collections.Generic;
using System.IO;

namespace CustomerDatabase
{
    public interface ICustomer
    {
        string GetFormattedString();
    }

    public class Customer : ICustomer, IComparable<Customer>
    {
        public string LastName { get; set; }
        public string FirstName { get; set; }
        public int CustomerId { get; set; }
        public string BusinessName { get; set; }
        public string PhoneNumber { get; set; }

        public Customer(string lastName, string firstName, int customerId, string businessName, string phoneNumber)
        {
            LastName = lastName;
            FirstName = firstName;
            CustomerId = customerId;
            BusinessName = businessName;
            PhoneNumber = phoneNumber;
        }

        public override string ToString()
        {
            return $"Last name: {LastName}\nFirst name: {FirstName}\nID: {CustomerId}\nBusiness: {BusinessName}\nPhone: {PhoneNumber}";
        }

        public string GetFormattedString()
        {
            return $"{LastName},{FirstName},{CustomerId},{BusinessName},{PhoneNumber}";
        }

        public int CompareTo(Customer other)
        {
            return string.Compare(LastName, other.LastName, StringComparison.Ordinal);
        }
    }

    public class Program
    {
        static void Main(string[] args)
        {
            string filePath = "customers.txt";

            List<Customer> customers = ReadCustomersFromFile(filePath);

            string outputFilePath = "formatted_customers.txt";
            WriteFormattedCustomersToFile(customers, outputFilePath);
            Console.WriteLine($"Formatted customer list has been written to '{outputFilePath}'.");

            Console.ReadLine();
        }

        static List<Customer> ReadCustomersFromFile(string filePath)
        {
            List<Customer> customers = new List<Customer>();
            try
            {
                string[] lines = File.ReadAllLines(filePath);
                foreach (string line in lines)
                {
                    string[] fields = line.Split(',');
                    if (fields.Length == 5)
                    {
                        string lastName = fields[0].Trim();
                        string firstName = fields[1].Trim();
                        int customerId = int.Parse(fields[2].Trim());
                        string businessName = fields[3].Trim();
                        string phoneNumber = fields[4].Trim();

                        Customer customer = new Customer(lastName, firstName, customerId, businessName, phoneNumber);
                        customers.Add(customer);
                    }
                }
            }
            catch (IOException ex)
            {
                Console.WriteLine($"Error reading from file: {ex.Message}");
            }

            return customers;
        }

        static void WriteFormattedCustomersToFile(List<Customer> customers, string filePath)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(filePath))
                {
                    foreach (Customer customer in customers)
                    {
                        writer.WriteLine("Last name: " + customer.LastName);
                        writer.WriteLine("First name: " + customer.FirstName);
                        writer.WriteLine("ID: " + customer.CustomerId);
                        writer.WriteLine("Business: " + customer.BusinessName);
                        writer.WriteLine("Phone: " + customer.PhoneNumber);
                        writer.WriteLine();
                    }
                }
            }
            catch (IOException ex)
            {
                Console.WriteLine($"Error writing to file: {ex.Message}");
            }
        }
    }
}