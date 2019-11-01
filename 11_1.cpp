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
* 为系统即将输入时，提供字符串打印说明
*
* @param message 输入说明
*/
void inputSystemMessage(const std::string &message) {
	std::cout << message;
}

/**
* 为系统即将输出时，提供字符串打印说明
*
* @param message 输出说明
*/
void outputSystemMessage(const std::string &message) {
	std::cout << message << std::endl;
}

/**
* 输入类
*/
class Scanner {
public:
	/**
	* 获得一个整数
	*
	* @return 一个整数
	*/
	int nextInt() {
		int data;
		std::cin >> data;
		return data;
	}

	/**
	* 获得一个字符串
	*
	* @return 一个字符串
	*/
	std::string next() {
		std::string data;
		std::cin >> data;
		return data;
	}

	/**
	* 获得一个实数
	*
	* @return 一个实数
	*/
	double nextDouble() {
		double data;
		std::cin >> data;
		return data;
	}
};

/**
* 图书信息类
*/
class BookInformation {
private:
	std::string bookId; // 图书编号
	std::string bookName; // 图书名称
	double price{}; // 图书价钱

public:
	/**
	* 默认构造函数
	*/
	BookInformation() = default;

	/**
	* 实例化构造函数
	*
	* @param bookId 图书编号
	* @param bookName 图书名称
	* @param price 图书价格
	*/
	BookInformation(std::string bookId, std::string bookName, double price) {
		this->bookId = std::move(bookId); // 利用 std::move 函数为 string 类赋值
		this->bookName = std::move(bookName);
		this->price = price;
	}

	/**
	* 获得图书价钱
	*
	* @return 图书价钱
	*/
	double getPrice() const {
		return price;
	}

	/**
	* 将图书信息格式化输出
	*
	* @return 格式化字符串
	*/
	std::string toString() const {
		std::stringstream stringStream; // 利用 stringstream 将数字转换为一个字符串
		stringStream << price;
		return std::string(
			"{ bookId: " + this->bookId + ", bookName: " + this->bookName + ", price: " + stringStream.str() +
			" }");
	}

	/**
	* 运算符重载，为输出提供便利
	*
	* @return 标准输出流
	*/
	friend std::ostream &operator<<(std::ostream &, const BookInformation &);
};

/**
* 运算符重载，为输出提供便利
*
* @param os 标准输出流
* @param book 输出图书对象
* @return 标准输出流
*/
std::ostream &operator<<(std::ostream &os, const BookInformation &book) {
	os << book.toString() << std::endl;
	return os;
}

/**
* 状态类，提供状态
*/
class Status {
public:
	static const status OK = 1;
	static const status ERROR = 0;
	static const status OVER = -1;

public:
	/**
	* 通过将析构函数设置为纯虚函数，代表 Status 类无法被实例化（无法产生对象)
	*/
	virtual ~Status() = 0;
};

/**
* 图书管理类
*/
class BookManagement {
private:
	std::vector<BookInformation> books; // 图书容器，使用方法类似数组，可直接下标访问元素
	int maxLength{}; // 最大长度
	int nowLength{}; // 即时长度

public:
	/**
	* 初始化顺序表
	*
	* @param booksMaxLength 规定最大长度
	* @return 状态值
	*/
	status initializeList(const int booksMaxLength) {
		if (booksMaxLength <= 0) {
			// 如果输入的最大长度小于0，则异常
			return Status::ERROR;
		}
		this->maxLength = booksMaxLength;
		nowLength = 0;
		return Status::OK;
	}

	/**
	* 从文件中读入信息
	*
	* @param filePath 文件路径
	* @return 状态值
	*/
	status readInformationByFile(const std::string &filePath) {
		std::fstream file; // 标准文件流

		file.open(filePath); // 打开文件

		if (!file) {
			// 若没有成功打开文件，则异常
			outputSystemMessage("Error ! Can not find " + filePath + " file !");
			return Status::ERROR;
		}

		std::string headerOne, headerTwo, headerThree; // 读入文件起始标题
		file >> headerOne >> headerTwo >> headerThree;

		std::string bookName, bookId;
		double bookPrice = 0;

		int count = 0; // 计数器

		while (!file.eof()) {
			// 当文件没有结束时，读取图书编号、图书名称、图书价钱
			file >> bookId >> bookName >> bookPrice;
			if (append(BookInformation(bookId, bookName, bookPrice)) == Status::OVER) {
				// 如果添加图书出现了溢出，则异常
				std::cout << "Overflow ! Just append " << count << " books !" << std::endl;
				return Status::OVER;
			}
			getline(file, bookId); // 读取无用换行
			count++; // 增加计数器，代表已经录入的图书数量
		}

		std::cout << "Success ! Total append " << count << " books !" << std::endl;
		file.close(); // 关闭标准文件流

		return Status::OK;
	}

	/**
	* 根据下标查找图书（从 0 开始）
	*
	* @param book 图书引用，作为第二返回值
	* @param index 目标下标
	* @return 状态值
	*/
	status searchByIndex(BookInformation &book, const int index) {
		if (index < 0 || index >= nowLength) {
			// 如果下标小于 0 或下标比当前已有图书量还多，则异常
			return Status::ERROR;
		}
		book = books[index];
		return Status::OK;
	}

	/**
	* 根据价钱寻找图书，获得第一本满足该价钱的图书的下标
	*
	* @param index 结果下标，第二返回值
	* @param price 目标价格
	* @return 状态值
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
	* 在列表最后添加一本图书
	*
	* @param book 欲添加图书
	* @return 状态值
	*/
	status append(const BookInformation &book) {
		if (nowLength == maxLength) {
			// 如果表已经满了，则异常
			return Status::OVER;
		}
		books.push_back(book); // vector 容器自带方法，在最后添加一个元素
		nowLength += 1;
		return Status::OK;
	}

	/**
	* 在规定下标之前插入一本图书
	*
	* @param index 规定下标
	* @param book 欲插入图书
	* @return 状态值
	*/
	status insert(int index, const BookInformation &book) {
		if (index < 0 || index > nowLength) {
			// 如果规定下标小于 0 或大于当前最大下标，则异常
			return Status::ERROR;
		}
		if (nowLength == maxLength) {
			// 如果表已满，则溢出
			return Status::OVER;
		}
		books.push_back(books[nowLength - 1]); // vector 容器自带方法，在最后添加一个元素（防止下标越界）
		for (int i = nowLength - 1; i >= index; i--) {
			// 将目标下标后面的每一个元素都向后移动一位
			books[i + 1] = books[i];
		}
		// 在规定下标处的数据变为欲插入数据
		books[index] = book;
		nowLength += 1;
		return Status::OK;
	}

	/**
	* 根据下标删除数据
	*
	* @param index 欲删除下标
	* @return 状态值
	*/
	status deleteByIndex(const int index) {
		if (index < 0 || index >= nowLength) {
			// 如果规定下标小于 0 或大于当前最大下标，则异常
			return Status::ERROR;
		}
		if (nowLength == 0) {
			// 如果表为空，则溢出
			return Status::OVER;
		}
		// 将目标下标后面的每一个元素都向前移动一位
		for (int i = index; i < nowLength - 1; i++) {
			books[i] = books[i + 1];
		}
		books.erase(books.end() - 1); // 删除最后一位
		nowLength -= 1;
		return Status::OK;
	};

	/**
	* 打印整个列表
	*/
	void display() {
		for (int i = 0; i < nowLength; i++) {
			std::cout << books[i];
		}
	}
};

int main() {
	BookManagement management{}; // 实例化图书管理类

	const std::string filePath = "./book.txt"; // 规定文件路径
	Scanner sc; // 实例化输入类

	int selection = -1; // 输入选项

	// 中间数据
	std::string bookName, bookId;
	double bookPrice = 0;
	int index = -1;
	BookInformation tempBook;

	outputSystemMessage("1. Initialize"); // 初始化顺序表
	outputSystemMessage("2. Input New Book Information from file"); // 从文件读入数据
	outputSystemMessage("3. Get Book By Index"); // 根据下标获取图书
	outputSystemMessage("4. Search By Price"); // 根据价格获取图书
	outputSystemMessage("5. Insert New Book By Index"); // 将一本图书插入到指定位置
	outputSystemMessage("6. Delete Book By Index"); // 删除指定位置的图书
	outputSystemMessage("7. Display"); // 展示全部
	outputSystemMessage("0. Quit\n");

	while (selection != 0) {
		inputSystemMessage("Please select options: ");
		selection = sc.nextInt();
		switch (selection) {
		case 1:
			// 初始化顺序表
			inputSystemMessage("Please input max length: ");
			if (management.initializeList(sc.nextInt()) == Status::OK) {
				outputSystemMessage("Create list successful !");
			}
			else {
				outputSystemMessage("Error ! Error input data !");
			}
			break;
		case 2:
			// 从文件读入数据
			if (management.readInformationByFile(filePath) == Status::OK) {
				outputSystemMessage("Import successful !");
			}
			else {
				outputSystemMessage("Import failed !");
			}
			break;
		case 3:
			// 根据下标获取图书
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
			// 根据价格获取图书
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
			// 将一本图书插入到指定位置
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
			// 删除指定位置的图书
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
			// 展示全部
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