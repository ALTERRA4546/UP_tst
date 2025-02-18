using Microsoft.VisualStudio.TestTools.UnitTesting;
using Newtonsoft.Json;
using System;
using Ticket_10_C_;
using System.IO;

namespace UnitTest
{
    [TestClass]
    public class UnitTest1
    {
        Program program = new Program();

        [TestMethod]
        public void ReadFromJsonFile_ShouldReturnValidObject()
        {
            var filePath = "test.json";
            var testJson = @"{
                ""fruit"": ""Apple"",
                ""size"": ""Large"",
                ""color"": ""Red""
            }";
            File.WriteAllText(filePath, testJson);

            var result = program.ReadFromJsonFile<dynamic>(filePath);

            Assert.IsNotNull(result);
            Assert.AreEqual("Apple", (string)result.fruit);
            Assert.AreEqual("Large", (string)result.size);
            Assert.AreEqual("Red", (string)result.color);

            File.Delete(filePath);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void ReadFromJsonFile_WithInvalidFilePath_ShouldThrowArgumentException()
        {
            var invalidFilePath = "";

            program.ReadFromJsonFile<dynamic>(invalidFilePath);
        }

        [TestMethod]
        [ExpectedException(typeof(FileNotFoundException))]
        public void ReadFromJsonFile_FileNotFound_ShouldThrowFileNotFoundException()
        {
            var nonExistentFilePath = "nonexistent.json";

            program.ReadFromJsonFile<dynamic>(nonExistentFilePath);
        }
    }
}
