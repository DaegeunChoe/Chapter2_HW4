#include <iostream>
#include <vector>
#include <string>
#include "BookManager.h"

using namespace std; // namespace std ���

void find(int choice, BookManager& manager, vector<BookQuery>& results) {

    string query;
    cout << "ã�� å ����: ";
    cin.ignore();
    getline(cin, query);
    if (choice == 1) {
        results = manager.findByTitle(query);
    }
    else {
        results = manager.findByAuthor(query);
    }
}

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
        cout << "3. ���� �˻�" << endl;
        cout << "4. ���� ����(�뿩 ���� ��)" << endl;
        cout << "5. ���� ����(�ݳ� ���� ��)" << endl;
        cout << "6. ����" << endl; // ���α׷� ����
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
            // �˻�
            vector<BookQuery> results;
            while (true) {
                cout << " - 1. å �������� �˻�" << endl;
                cout << " - 2. ���� �̸����� �˻�" << endl;
                cout << "����: ";
                cin >> choice;
                if (choice == 1 || choice == 2) {
                    find(choice, manager, results);
                    break;
                }
                else {
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
                    continue;
                }
            }
            if (results.empty()) {
                cout << "�˻� ����� �����ϴ�." << endl;
            }
            else {
                for (auto& result : results) {
                    cout << "- " << *(result.book) << endl;
                }
            }
        }
        else if (choice == 4) {
            // ����
            vector<BookQuery> results;
            while (true) {
                cout << " - 1. å �������� �˻�" << endl;
                cout << " - 2. ���� �̸����� �˻�" << endl;
                cout << "����: ";
                cin >> choice;
                if (choice == 1 || choice == 2) {
                    find(choice, manager, results);
                    break;
                }
                else {
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
                    continue;
                }
            }
            if (results.empty()) {
                cout << "�˻� ����� �����ϴ�." << endl;
            }
            else {
                for (int n = 0; n < results.size(); n++) {
                    cout << " [" << (n+1) << "] " << *(results[n].book) << endl;
                }
                cout << " [-1] ���" << endl;
                while (true) {
                    cout << "���� å ����: ";
                    cin >> choice;
                    if (choice == -1) {
                        break;
                    }
                    else if (choice <= 0 || choice > results.size()) {
                        cout << "�ùٸ� ��ȣ�� �Է����ּ���." << endl;
                        continue;
                    }
                    else {
                        if (manager.borrowBook(results[choice - 1].index)) {
                            cout << "å [" << results[choice - 1].book->title << "] ��/�� �����߽��ϴ�." << endl;
                        }
                        else {
                            cout << "�뿩�� �� �����ϴ�. (å�� �����մϴ�)" << endl;
                        }
                        break;
                    }
                }
            }
        }
        else if (choice == 5) {
            // ����
        }
        else if (choice == 6) {
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
