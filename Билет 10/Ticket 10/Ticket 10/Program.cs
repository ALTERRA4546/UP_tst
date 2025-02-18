using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ticket_10
{
    public class Program
    {
        public class Student
        {
            public int Id { get; set; } // Уникальный идентификатор
            public string FirstName { get; set; } // Имя
            public string LastName { get; set; } // Фамилия
            public int Age { get; set; } // Возраст
            public string Group { get; set; } // Группа

            // Переопределение метода ToString для удобного вывода информации
            public override string ToString()
            {
                return $"Id: {Id}, Name: {FirstName} {LastName}, Age: {Age}, Group: {Group}";
            }
        }

        // Класс для сериализации и десериализации данных в JSON
        public class JsonDataManager
        {
            private string _filePath;

            // Конструктор, принимающий путь к файлу
            public JsonDataManager(string filePath)
            {
                _filePath = filePath;

                // Создаем файл, если он не существует
                if (!File.Exists(_filePath))
                {
                    File.Create(_filePath).Close();
                }
            }

            // Сериализация объекта в JSON и сохранение в файл
            public void SerializeToJson<T>(T data)
            {
                try
                {
                    var options = new JsonSerializerOptions { WriteIndented = true }; // Для красивого форматирования JSON
                    string json = JsonSerializer.Serialize(data, options);
                    File.WriteAllText(_filePath, json);
                    Console.WriteLine("Data serialized and saved to file.");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error serializing {ex.Message}");
                }
            }

            // Десериализация объекта из JSON файла
            public T DeserializeFromJson<T>()
            {
                try
                {
                    string json = File.ReadAllText(_filePath);
                    if (string.IsNullOrEmpty(json))
                    {
                        return default(T); // Возвращаем значение по умолчанию для типа T, если файл пуст.
                    }
                    var options = new JsonSerializerOptions(); //Оставляем дефолтные настройки
                    T data = JsonSerializer.Deserialize<T>(json, options);
                    Console.WriteLine("Data deserialized from file.");
                    return data;
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error deserializing {ex.Message}");
                    return default(T); // Возвращаем значение по умолчанию в случае ошибки.
                }
            }
        }

        static void Main(string[] args)
        {

        }
    }
}
