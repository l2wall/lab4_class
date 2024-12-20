
#include <iostream>
#include <vector>
#include <string>

class Document {
private:
    std::string title;         // Закрытое свойство
    std::string author;        // Закрытое свойство
    int pages;                 // Закрытое свойство

public:
    // Конструктор по умолчанию
    Document() : title("Untitled"), author("Unknown"), pages(0) {}
    
    // Конструктор с параметрами
    Document(std::string t, std::string a, int p) : title(t), author(a), pages(p) {}

    // Методы доступа (геттеры)
    std::string getTitle() const {
        return title;
    }
    
    std::string getAuthor() const {
        return author;
    }
    
    int getPages() const {
        return pages;
    }

    // Методы изменения (сеттеры)
    void setTitle(const std::string& t) {
        title = t;
    }
    
    void setAuthor(const std::string& a) {
        author = a;
    }
    
    void setPages(int p) {
        if (p >= 0) {
            pages = p;
        } else {
            std::cout << "Number of pages cannot be negative!" << std::endl;
        }
    }

    // Метод для вывода информации о документе
    void display() const {
        std::cout << "Document Title: " << title << ", Author: " << author << ", Pages: " << pages << std::endl;
    }
};

// Функции для выполнения заданий
Document createDocumentDefault() {
    return Document();
}

Document createDocumentWithParams(const std::string& title, const std::string& author, int pages) {
    return Document(title, author, pages);
}

std::vector<Document> createDocumentArray(int size) {
    std::vector<Document> docs;
    for (int i = 0; i < size; i++) {
        std::string title, author;
        int pages;
        
        std::cout << "Enter document title: ";
        std::getline(std::cin, title);
        std::cout << "Enter document author: ";
        std::getline(std::cin, author);
        std::cout << "Enter number of pages: ";
        std::cin >> pages;
        std::cin.ignore();  // Чтобы избежать проблемы с getline после cin
        
        docs.push_back(createDocumentWithParams(title, author, pages));
    }
    return docs;
}

void editDocument(Document& doc) {
    doc.display();
    
    std::string title;
    std::cout << "Enter new document title (or leave blank to keep current): ";
    std::getline(std::cin, title);
    if (!title.empty()) {
        doc.setTitle(title);
    }
    
    std::string author;
    std::cout << "Enter new document author (or leave blank to keep current): ";
    std::getline(std::cin, author);
    if (!author.empty()) {
        doc.setAuthor(author);
    }

    int pages;
    std::cout << "Enter new number of pages (or -1 to keep current): ";
    std::cin >> pages;
    if (pages != -1) {
        doc.setPages(pages);
    }
    
    std::cin.ignore();  // Чтобы избежать проблемы с getline после cin
    std::cout << "Updated document details: ";
    doc.display();
}

void processDocumentArray(std::vector<Document>& docs) {
    for (auto& doc : docs) {
        editDocument(doc);
    }
}

int main() {
    // 1. Создание объекта с помощью конструктора по умолчанию
    Document docDefault = createDocumentDefault();
    std::cout << "Default Document: ";
    docDefault.display();

    // 2. Создание объекта с помощью конструктора с параметрами
    Document docWithParams = createDocumentWithParams("My Document", "Alice", 100);
    std::cout << "Document with Parameters: ";
    docWithParams.display();

    // 3. Создание массива объектов
    int size;
    std::cout << "Enter the number of documents to create: ";
    std::cin >> size;
    std::cin.ignore(); // Чтобы избежать проблемы с getline после cin
    std::vector<Document> documentArray = createDocumentArray(size);

    // 4. Редактирование и просмотр свойств каждого объекта
    processDocumentArray(documentArray);

    return 0;
}