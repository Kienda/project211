#include "Person.h"
#include "Date.h"
#include "Student.h"

int main()
{
    Person person("Abdoulaye", "M.", "Doe");
    Date birthday("March", 2000, 15);
    Date graduationDate("May", 2025, 20);

    Student student(person, birthday, "Computer Science", graduationDate, 123456, 3.9, "123-45-6789");
    student.printStudentInfo();

    return 0;
}
