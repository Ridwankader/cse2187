#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    bool isAvailable;

    Book(const std::string& title, const std::string& author)
        : title(title), author(author), isAvailable(true) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() {
        std::cout << "Books in the library:\n";
        for (const auto& book : books) {
            std::cout << "Title: " << book.title << ", Author: " << book.author;
            std::cout << ", Status: " << (book.isAvailable ? "Available" : "Not Available") << "\n";
        }
    }

    void borrowBook(int index) {
        if (index >= 0 && index < books.size()) {
            if (books[index].isAvailable) {
                books[index].isAvailable = false;
                std::cout << "Book " << books[index].title << " has been borrowed.\n";
            } else {
                std::cout << "Book " << books[index].title << " is not available for borrowing.\n";
            }
        } else {
            std::cout << "Invalid book index.\n";
        }
    }

    void returnBook(int index) {
        if (index >= 0 && index < books.size()) {
            if (!books[index].isAvailable) {
                books[index].isAvailable = true;
                std::cout << "Book " << books[index].title << " has been returned.\n";
            } else {
                std::cout << "Book " << books[index].title << " is already available.\n";
            }
        } else {
            std::cout << "Invalid book index.\n";
        }
    }
};

int main() {
    Library library;

    Book book1("The Great Gatsby", "F. Scott Fitzgerald");
    Book book2("To Kill a Mockingbird", "Harper Lee");
    Book book3("1984", "George Orwell");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.displayBooks();

    library.borrowBook(1);
    library.borrowBook(2);
    library.returnBook(1);
    library.borrowBook(3);
    library.borrowBook(4); // Invalid index

    library.displayBooks();

    return 0;
}
