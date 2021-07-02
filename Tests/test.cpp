#include "pch.h"
#include "../Zaliczenie/Book.h"
#include "../Zaliczenie/Employee.h"
#include "../Zaliczenie/Student.h"
#include "../Zaliczenie/Employee.cpp"
#include "../Zaliczenie/Book.cpp"
#include "../Zaliczenie/Student.cpp"
#include "../Zaliczenie/Library1.cpp"
#include <list>


TEST(TestEmployee, can_call_add_user) {
    Employee S = Employee("Ela", "Wozniak");
    ASSERT_EQ(S.Name, "Ela");
    ASSERT_EQ(S.Surename, "Wozniak");
}
TEST(TestEmployee1, can_call_add_user) {
    Employee S = Employee("Michal", "Czaja");
    ASSERT_NE(S.Name, "Ela");
    ASSERT_NE(S.Surename, "Wozniak");

}
TEST(TestStudent, can_call_add_user) {
    Student S = Student("Michal", "Czaja", GetRandomNumber());
    ASSERT_NE(S.Name, "Ela");
    ASSERT_NE(S.Surename, "Wozniak");
}
TEST(TestStudent1, can_call_add_user) {
    Student S = Student("Ela", "Wozniak", GetRandomNumber());
    ASSERT_EQ(S.Name, "Ela");
    ASSERT_EQ(S.Surename, "Wozniak");
}

TEST(TestEditList, succes_if_can_rent_book) {
    
    Book book1 = Book("Ala ma kota", "Ala");
    Book book2 = Book("Kot ma Ale", "Kot");
    list<Book> newList;
    newList.push_back(book1);
    newList.push_back(book2);
    list<Book> editedList = EditList(newList,1);
    Book firstBook = editedList.front();
    ASSERT_EQ(firstBook.IsRent, true);
}
TEST(TestEditList, succes_if_cant_rent_book) {

    Book book1 = Book("Ala ma kota", "Ala");
    Book book2 = Book("Kot ma Ale", "Kot");
    list<Book> newList;
    newList.push_back(book1);
    newList.push_back(book2);
    list<Book> editedList = EditList(newList, 1);
    Book firstBook = editedList.front();
    ASSERT_NE(firstBook.IsRent, false);
}
TEST(TestEditList, succes_if_can_return_book) {

    Book book1 = Book("Ala ma kota", "Ala");
    Book book2 = Book("Kot ma Ale", "Kot");
    list<Book> newList;
    newList.push_back(book1);
    newList.push_back(book2);
    list<Book> editedList = EditList(newList, 1);
    Book firstBook = editedList.front();
    list<Book> returnedList = EditReturnList(editedList, 1);
    firstBook = returnedList.front();

    ASSERT_EQ(firstBook.IsRent, false);
}
TEST(TestEditList, succes_if_cant_return_book) {

    Book book1 = Book("Ala ma kota", "Ala");
    Book book2 = Book("Kot ma Ale", "Kot");
    list<Book> newList;
    newList.push_back(book1);
    newList.push_back(book2);
    list<Book> editedList = EditList(newList, 1);
    Book firstBook = editedList.front();
    list<Book> returnedList = EditReturnList(editedList, 1);
    firstBook = returnedList.front();

    ASSERT_NE(firstBook.IsRent, false);
}