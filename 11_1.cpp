#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

typedef int status;

/**
* Ϊϵͳ��������ʱ���ṩ�ַ�����ӡ˵��
*
* @param message ����˵��
*/
void inputSystemMessage(const std::string &message) {
	std::cout << message;
}

/**
* Ϊϵͳ�������ʱ���ṩ�ַ�����ӡ˵��
*
* @param message ���˵��
*/
void outputSystemMessage(const std::string &message) {
	std::cout << message << std::endl;
}

/**
* ������
*/
class Scanner {
public:
	/**
	* ���һ������
	*
	* @return һ������
	*/
	int nextInt() {
		int data;
		std::cin >> data;
		return data;
	}

	/**
	* ���һ���ַ���
	*
	* @return һ���ַ���
	*/
	std::string next() {
		std::string data;
		std::cin >> data;
		return data;
	}

	/**
	* ���һ��ʵ��
	*
	* @return һ��ʵ��
	*/
	double nextDouble() {
		double data;
		std::cin >> data;
		return data;
	}
};

/**
* ͼ����Ϣ��
*/
class BookInformation {
private:
	std::string bookId; // ͼ����
	std::string bookName; // ͼ������
	double price{}; // ͼ���Ǯ

public:
	/**
	* Ĭ�Ϲ��캯��
	*/
	BookInformation() = default;

	/**
	* ʵ�������캯��
	*
	* @param bookId ͼ����
	* @param bookName ͼ������
	* @param price ͼ��۸�
	*/
	BookInformation(std::string bookId, std::string bookName, double price) {
		this->bookId = std::move(bookId); // ���� std::move ����Ϊ string �ำֵ
		this->bookName = std::move(bookName);
		this->price = price;
	}

	/**
	* ���ͼ���Ǯ
	*
	* @return ͼ���Ǯ
	*/
	double getPrice() const {
		return price;
	}

	/**
	* ��ͼ����Ϣ��ʽ�����
	*
	* @return ��ʽ���ַ���
	*/
	std::string toString() const {
		std::stringstream stringStream; // ���� stringstream ������ת��Ϊһ���ַ���
		stringStream << price;
		return std::string(
			"{ bookId: " + this->bookId + ", bookName: " + this->bookName + ", price: " + stringStream.str() +
			" }");
	}

	/**
	* ��������أ�Ϊ����ṩ����
	*
	* @return ��׼�����
	*/
	friend std::ostream &operator<<(std::ostream &, const BookInformation &);
};

/**
* ��������أ�Ϊ����ṩ����
*
* @param os ��׼�����
* @param book ���ͼ�����
* @return ��׼�����
*/
std::ostream &operator<<(std::ostream &os, const BookInformation &book) {
	os << book.toString() << std::endl;
	return os;
}

/**
* ״̬�࣬�ṩ״̬
*/
class Status {
public:
	static const status OK = 1;
	static const status ERROR = 0;
	static const status OVER = -1;

public:
	/**
	* ͨ����������������Ϊ���麯�������� Status ���޷���ʵ�������޷���������)
	*/
	virtual ~Status() = 0;
};

/**
* ͼ�������
*/
class BookManagement {
private:
	std::vector<BookInformation> books; // ͼ��������ʹ�÷����������飬��ֱ���±����Ԫ��
	int maxLength{}; // ��󳤶�
	int nowLength{}; // ��ʱ����

public:
	/**
	* ��ʼ��˳���
	*
	* @param booksMaxLength �涨��󳤶�
	* @return ״ֵ̬
	*/
	status initializeList(const int booksMaxLength) {
		if (booksMaxLength <= 0) {
			// ����������󳤶�С��0�����쳣
			return Status::ERROR;
		}
		this->maxLength = booksMaxLength;
		nowLength = 0;
		return Status::OK;
	}

	/**
	* ���ļ��ж�����Ϣ
	*
	* @param filePath �ļ�·��
	* @return ״ֵ̬
	*/
	status readInformationByFile(const std::string &filePath) {
		std::fstream file; // ��׼�ļ���

		file.open(filePath); // ���ļ�

		if (!file) {
			// ��û�гɹ����ļ������쳣
			outputSystemMessage("Error ! Can not find " + filePath + " file !");
			return Status::ERROR;
		}

		std::string headerOne, headerTwo, headerThree; // �����ļ���ʼ����
		file >> headerOne >> headerTwo >> headerThree;

		std::string bookName, bookId;
		double bookPrice = 0;

		int count = 0; // ������

		while (!file.eof()) {
			// ���ļ�û�н���ʱ����ȡͼ���š�ͼ�����ơ�ͼ���Ǯ
			file >> bookId >> bookName >> bookPrice;
			if (append(BookInformation(bookId, bookName, bookPrice)) == Status::OVER) {
				// ������ͼ���������������쳣
				std::cout << "Overflow ! Just append " << count << " books !" << std::endl;
				return Status::OVER;
			}
			getline(file, bookId); // ��ȡ���û���
			count++; // ���Ӽ������������Ѿ�¼���ͼ������
		}

		std::cout << "Success ! Total append " << count << " books !" << std::endl;
		file.close(); // �رձ�׼�ļ���

		return Status::OK;
	}

	/**
	* �����±����ͼ�飨�� 0 ��ʼ��
	*
	* @param book ͼ�����ã���Ϊ�ڶ�����ֵ
	* @param index Ŀ���±�
	* @return ״ֵ̬
	*/
	status searchByIndex(BookInformation &book, const int index) {
		if (index < 0 || index >= nowLength) {
			// ����±�С�� 0 ���±�ȵ�ǰ����ͼ�������࣬���쳣
			return Status::ERROR;
		}
		book = books[index];
		return Status::OK;
	}

	/**
	* ���ݼ�ǮѰ��ͼ�飬��õ�һ������ü�Ǯ��ͼ����±�
	*
	* @param index ����±꣬�ڶ�����ֵ
	* @param price Ŀ��۸�
	* @return ״ֵ̬
	*/
	status searchIndexFromPrice(int &index, const double price) {
		for (int i = 0; i < nowLength; i++) {
			if (books[i].getPrice() == price) {
				index = i;
				return Status::OK;
			}
		}
		return Status::ERROR;
	}

	/**
	* ���б�������һ��ͼ��
	*
	* @param book �����ͼ��
	* @return ״ֵ̬
	*/
	status append(const BookInformation &book) {
		if (nowLength == maxLength) {
			// ������Ѿ����ˣ����쳣
			return Status::OVER;
		}
		books.push_back(book); // vector �����Դ���������������һ��Ԫ��
		nowLength += 1;
		return Status::OK;
	}

	/**
	* �ڹ涨�±�֮ǰ����һ��ͼ��
	*
	* @param index �涨�±�
	* @param book ������ͼ��
	* @return ״ֵ̬
	*/
	status insert(int index, const BookInformation &book) {
		if (index < 0 || index > nowLength) {
			// ����涨�±�С�� 0 ����ڵ�ǰ����±꣬���쳣
			return Status::ERROR;
		}
		if (nowLength == maxLength) {
			// ����������������
			return Status::OVER;
		}
		books.push_back(books[nowLength - 1]); // vector �����Դ���������������һ��Ԫ�أ���ֹ�±�Խ�磩
		for (int i = nowLength - 1; i >= index; i--) {
			// ��Ŀ���±�����ÿһ��Ԫ�ض�����ƶ�һλ
			books[i + 1] = books[i];
		}
		// �ڹ涨�±괦�����ݱ�Ϊ����������
		books[index] = book;
		nowLength += 1;
		return Status::OK;
	}

	/**
	* �����±�ɾ������
	*
	* @param index ��ɾ���±�
	* @return ״ֵ̬
	*/
	status deleteByIndex(const int index) {
		if (index < 0 || index >= nowLength) {
			// ����涨�±�С�� 0 ����ڵ�ǰ����±꣬���쳣
			return Status::ERROR;
		}
		if (nowLength == 0) {
			// �����Ϊ�գ������
			return Status::OVER;
		}
		// ��Ŀ���±�����ÿһ��Ԫ�ض���ǰ�ƶ�һλ
		for (int i = index; i < nowLength - 1; i++) {
			books[i] = books[i + 1];
		}
		books.erase(books.end() - 1); // ɾ�����һλ
		nowLength -= 1;
		return Status::OK;
	};

	/**
	* ��ӡ�����б�
	*/
	void display() {
		for (int i = 0; i < nowLength; i++) {
			std::cout << books[i];
		}
	}
};

int main() {
	BookManagement management{}; // ʵ����ͼ�������

	const std::string filePath = "./book.txt"; // �涨�ļ�·��
	Scanner sc; // ʵ����������

	int selection = -1; // ����ѡ��

	// �м�����
	std::string bookName, bookId;
	double bookPrice = 0;
	int index = -1;
	BookInformation tempBook;

	outputSystemMessage("1. Initialize"); // ��ʼ��˳���
	outputSystemMessage("2. Input New Book Information from file"); // ���ļ���������
	outputSystemMessage("3. Get Book By Index"); // �����±��ȡͼ��
	outputSystemMessage("4. Search By Price"); // ���ݼ۸��ȡͼ��
	outputSystemMessage("5. Insert New Book By Index"); // ��һ��ͼ����뵽ָ��λ��
	outputSystemMessage("6. Delete Book By Index"); // ɾ��ָ��λ�õ�ͼ��
	outputSystemMessage("7. Display"); // չʾȫ��
	outputSystemMessage("0. Quit\n");

	while (selection != 0) {
		inputSystemMessage("Please select options: ");
		selection = sc.nextInt();
		switch (selection) {
		case 1:
			// ��ʼ��˳���
			inputSystemMessage("Please input max length: ");
			if (management.initializeList(sc.nextInt()) == Status::OK) {
				outputSystemMessage("Create list successful !");
			}
			else {
				outputSystemMessage("Error ! Error input data !");
			}
			break;
		case 2:
			// ���ļ���������
			if (management.readInformationByFile(filePath) == Status::OK) {
				outputSystemMessage("Import successful !");
			}
			else {
				outputSystemMessage("Import failed !");
			}
			break;
		case 3:
			// �����±��ȡͼ��
			inputSystemMessage("Please input index:");
			if (management.searchByIndex(tempBook, sc.nextInt()) == Status::OK) {
				outputSystemMessage("Searched !");
				std::cout << "Index is : " << tempBook << std::endl;
			}
			else {
				outputSystemMessage("Search fail !");
			}
			break;
		case 4:
			// ���ݼ۸��ȡͼ��
			inputSystemMessage("Please input price:");
			if (management.searchIndexFromPrice(index, sc.nextDouble()) == Status::OK) {
				outputSystemMessage("Searched !");
				std::cout << index;
			}
			else {
				outputSystemMessage("Search fail !");
			}
			break;
		case 5:
			// ��һ��ͼ����뵽ָ��λ��
			inputSystemMessage("Please input new book\'s ID: ");
			bookId = sc.next();
			inputSystemMessage("Please input new book\'s Name: ");
			bookName = sc.next();
			inputSystemMessage("Please input new book\'s Price: ");
			bookPrice = sc.nextDouble();
			inputSystemMessage("Please input insert index: ");
			index = sc.nextInt();
			switch (management.insert(index, BookInformation(bookId, bookName, bookPrice))) {
			case Status::OK:
				outputSystemMessage("Insert successfully !");
				break;
			case Status::ERROR:
				outputSystemMessage("Error ! Error index format !");
				break;
			case Status::OVER:
				outputSystemMessage("List has Overflowed !");
				break;
			}
			break;
		case 6:
			// ɾ��ָ��λ�õ�ͼ��
			inputSystemMessage("Please input delete index: ");
			index = sc.nextInt();
			switch (management.deleteByIndex(index)) {
			case Status::OK:
				outputSystemMessage("Delete successfully !");
				break;
			case Status::ERROR:
				outputSystemMessage("Error ! Error index format !");
				break;
			case Status::OVER:
				outputSystemMessage("List has Empty !");
				break;
			}
			break;
		case 7:
			// չʾȫ��
			management.display();
			break;
		case 0:
			break;
		default:
			outputSystemMessage("Input error !");
		}
	}

	return 0;
}