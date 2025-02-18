using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;
using Ticket_10;
using static Ticket_10.Program;

namespace UnitTest
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestSerializeAndDeserializeSingleStudent()
        {
            string filePath = "test_student.json";
            JsonDataManager dataManager = new JsonDataManager(filePath);
            Student student = new Student { Id = 1, FirstName = "John", LastName = "Doe", Age = 20, Group = "A1" };

            dataManager.SerializeToJson(student);
            Student deserializedStudent = dataManager.DeserializeFromJson<Student>();

            Assert.IsNotNull(deserializedStudent);
            Assert.AreEqual(student.Id, deserializedStudent.Id);
            Assert.AreEqual(student.FirstName, deserializedStudent.FirstName);
            Assert.AreEqual(student.LastName, deserializedStudent.LastName);
            Assert.AreEqual(student.Age, deserializedStudent.Age);
            Assert.AreEqual(student.Group, deserializedStudent.Group);

            File.Delete(filePath);
        }

        [TestMethod]
        public void TestSerializeAndDeserializeListOfStudents()
        {
            string filePath = "test_students.json";
            JsonDataManager dataManager = new JsonDataManager(filePath);
            List<Student> students = new List<Student>
        {
            new Student { Id = 1, FirstName = "John", LastName = "Doe", Age = 20, Group = "A1" },
            new Student { Id = 2, FirstName = "Jane", LastName = "Smith", Age = 22, Group = "B2" }
        };

            dataManager.SerializeToJson(students);
            List<Student> deserializedStudents = dataManager.DeserializeFromJson<List<Student>>();

            Assert.IsNotNull(deserializedStudents);
            Assert.AreEqual(students.Count, deserializedStudents.Count);

            for (int i = 0; i < students.Count; i++)
            {
                Assert.AreEqual(students[i].Id, deserializedStudents[i].Id);
                Assert.AreEqual(students[i].FirstName, deserializedStudents[i].FirstName);
                Assert.AreEqual(students[i].LastName, deserializedStudents[i].LastName);
                Assert.AreEqual(students[i].Age, deserializedStudents[i].Age);
                Assert.AreEqual(students[i].Group, deserializedStudents[i].Group);
            }
            File.Delete(filePath);
        }

        [TestMethod]
        public void TestDeserializeEmptyFile()
        {
            string filePath = "empty_file.json";
            File.Create(filePath).Close();
            JsonDataManager dataManager = new JsonDataManager(filePath);
            Student deserializedStudent = dataManager.DeserializeFromJson<Student>();

            Assert.IsNull(deserializedStudent);

            File.Delete(filePath);
        }


        [TestMethod]
        public void TestSerializeWithInvalidFilePath()
        {
            string invalidFilePath = "/invalid/path/test_student.json";
            JsonDataManager dataManager = new JsonDataManager(invalidFilePath);
            Student student = new Student { Id = 1, FirstName = "John", LastName = "Doe", Age = 20, Group = "A1" };


            try
            {
                dataManager.SerializeToJson(student);
            }
            catch (Exception ex)
            {
                Assert.IsFalse(false);
            }
        }
    }
}
