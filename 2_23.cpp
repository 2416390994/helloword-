#include<unordered_map>
#include<map>
#include<set>

#include<iostream>
#include<vector>
using namespace std;


int  main()
{

	/*unordered_map<int, int> mmap;
	
	mmap.insert(make_pair(9, 5));
	mmap.insert(make_pair(1, 2));
	mmap.insert(make_pair(3, 7));
	mmap.insert(make_pair(4, 9));
	mmap.insert(make_pair(4, 9));
	mmap.insert(make_pair(5, 6));*/


	/*map<int, int> mmap1;
	mmap1.insert(make_pair(9, 5));
	mmap1.insert(make_pair(1, 2));
	mmap1.insert(make_pair(1, 2));
	mmap1.insert(make_pair(3, 7));
	mmap1.insert(make_pair(4, 9));
	mmap1.insert(make_pair(5, 6));
	auto it = mmap1.find(1);
	cout << it->second << endl;
	cout << mmap1.begin()->first << endl;*/

	multimap<int, int> mmap1;
	mmap1.insert(make_pair(9, 5));
	mmap1.insert(make_pair(1, 2));
	mmap1.insert(make_pair(1, 2));
	mmap1.insert(make_pair(3, 7));
	mmap1.insert(make_pair(4, 9));
	mmap1.insert(make_pair(5, 6));
	/*auto it = mmap1.find(1);
	cout << it->second << endl;
	cout << mmap1.begin()->first << endl;
	cout << mmap1.count(1) << endl;*/
	for (auto e : mmap1)
		cout << e.second;
	mmap1.erase(1);
	mmap1.erase(9);
	mmap1.erase(3);
	mmap1.erase(4);

	for (auto e : mmap1)
		cout << e.second;

	/*multiset<int> mmap1;
	mmap1.insert(1);
	mmap1.insert(2);
	mmap1.insert(2);
	mmap1.insert(2);
	mmap1.insert(5);
	mmap1.insert(8);
	mmap1.insert(6);
	mmap1.insert(7);
	auto it = mmap1.find(1);
	cout << *it<< endl;
	
	cout << mmap1.erase(2) << endl;;
*/
	/*for (auto e : mmap1)
		cout << e;*/


	return 0;
}