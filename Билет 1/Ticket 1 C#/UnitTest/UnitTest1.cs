using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Ticket_1_C_;

namespace UnitTest
{
    [TestClass]
    public class UnitTest1
    {
        Program program = new Program();

        [TestMethod]
        public async Task TestMethod1()
        {
            var filePath = "C:\\Users\\King Night\\Desktop\\test.txt";
            var expectedLines = new List<string> { "1", "2", "3", "4", "5" };

            var result = await program.ReadAllLinesAsync(filePath);

            CollectionAssert.AreEqual(expectedLines, result);
        }
    }
}
