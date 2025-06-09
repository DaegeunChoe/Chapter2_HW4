#include <iostream>
#include <vector>
#include <string>
#include "BookManager.h"

using namespace std; // namespace std ���

int main() {
    BookManager manager;

    // �⺻ ���� ����
    manager.addBook("�𸮾�", "���Ȱ�����");
    manager.addBook("�Ҽ�1", "Alice");
    manager.addBook("�Ҽ�2", "Alice");
    manager.addBook("����", "Bob");
    manager.addBook("��", "Bob");
    manager.addBook("�̻��ѼҼ�", "Bob");

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �̸����� �˻�" << endl;
        cout << "4. ���� �̸����� �˻�" << endl;
        cout << "5. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            string query;
            cout << "ã�� å ����: ";
            cin.ignore();
            getline(cin, query);
            vector<Book*> result = manager.findByTitle(query);
            if (result.empty()) {
                cout << "�˻� ����� �����ϴ�." << endl;
            }
            else {
                for (Book* book : result) {
                    cout << "- " << *book << endl;
                }
            }
        }
        else if (choice == 4) {
            string query;
            cout << "ã�� ���� �̸�: ";
            cin.ignore();
            getline(cin, query);
            vector<Book*> result = manager.findByAuthor(query);
            if (result.empty()) {
                cout << "�˻� ����� �����ϴ�." << endl;
            }
            else {
                for (Book* book : result) {
                    cout << "- " << *book << endl;
                }
            }
        }
        else if (choice == 5) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
