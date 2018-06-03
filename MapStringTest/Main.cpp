#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

struct charbuf {
	charbuf();
	charbuf(charbuf const& cb);
	charbuf(char const* p);
	charbuf& operator=(charbuf const& rhs);
	charbuf& operator=(char const* rhs);
	bool operator==(charbuf const& that) const;
	bool operator<(charbuf const& that) const;
	char data_[10];
};

charbuf::charbuf()
{
}

charbuf::charbuf(charbuf const & cb)
{
	strcpy(data_, cb.data_);
}

charbuf::charbuf(char const * p)
{
	strcpy(data_, p);
}

charbuf & charbuf::operator=(charbuf const & rhs)
{
	strcpy(data_, rhs.data_);
	return *this;
}

charbuf & charbuf::operator=(char const * rhs)
{
	strcpy(data_, rhs);
	return *this;
}

bool charbuf::operator==(charbuf const & that) const
{
	return strcmp(data_, that.data_) == 0;
}

bool charbuf::operator<(charbuf const & that) const
{
	return strcmp(data_, that.data_) < 0;
}

struct kv { // (key, value) 対
	char const* key;
	unsigned value; // 何でもよい
};

bool operator==(kv const& n1, char const* key) {
	return strcmp(n1.key, key) == 0;
}


int main()
{
	constexpr int N = 100 * 1000; // ループ回数

	const std::map<std::string, unsigned> BaseTable{
		{ "alpha", 1 },{ "bravo", 2 },
		{ "charlie", 3 },{ "delta", 4 },
		{ "echo", 5 },{ "foxtrot", 6 },
		{ "golf", 7 },{ "hotel", 8 },
		{ "india", 9 },{ "juliet", 10 },
		{ "kilo", 11 },{ "lima", 12 },
		{ "mike", 13 },{ "november",14 },
		{ "oscar", 15 },{ "papa", 16 },
		{ "quebec", 17 },{ "romeo", 18 },
		{ "sierra", 19 },{ "tango", 20 },
		{ "uniform",21 },{ "victor", 22 },
		{ "whiskey",23 },{ "x-ray", 24 },
		{ "yankee", 25 },{ "zulu", 26 }
	};

	{
		const std::map<std::string, unsigned> table{
			{ "alpha", 1 },{ "bravo", 2 },
			{ "charlie", 3 },{ "delta", 4 },
			{ "echo", 5 },{ "foxtrot", 6 },
			{ "golf", 7 },{ "hotel", 8 },
			{ "india", 9 },{ "juliet", 10 },
			{ "kilo", 11 },{ "lima", 12 },
			{ "mike", 13 },{ "november",14 },
			{ "oscar", 15 },{ "papa", 16 },
			{ "quebec", 17 },{ "romeo", 18 },
			{ "sierra", 19 },{ "tango", 20 },
			{ "uniform",21 },{ "victor", 22 },
			{ "whiskey",23 },{ "x-ray", 24 },
			{ "yankee", 25 },{ "zulu", 26 }
		};

		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i < N; i++) {
			auto it = table.find("sierra");
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec(map & string) \n";
	}

	{
		const std::map<charbuf, unsigned> table{
			{ "alpha", 1 },{ "bravo", 2 },
			{ "charlie", 3 },{ "delta", 4 },
			{ "echo", 5 },{ "foxtrot", 6 },
			{ "golf", 7 },{ "hotel", 8 },
			{ "india", 9 },{ "juliet", 10 },
			{ "kilo", 11 },{ "lima", 12 },
			{ "mike", 13 },{ "november",14 },
			{ "oscar", 15 },{ "papa", 16 },
			{ "quebec", 17 },{ "romeo", 18 },
			{ "sierra", 19 },{ "tango", 20 },
			{ "uniform",21 },{ "victor", 22 },
			{ "whiskey",23 },{ "x-ray", 24 },
			{ "yankee", 25 },{ "zulu", 26 }
		};

		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i < N; i++) {
			auto it = table.find("sierra");
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec(map & charbuf) \n";
	}

	{
		auto comp = [](char const* p1, char const* p2) {
			return strcmp(p1, p2) < 0;
		};

		std::map<const char *, unsigned, decltype(comp)> table(comp);
		for (const auto& i : BaseTable) {
			table.emplace(i.first.c_str(), i.second);
		}


		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i < N; i++) {
			auto it = table.find("sierra");
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec(map & char*) \n";
	}


	{
		kv names[] = { // アルファベット順
			{ "alpha", 1 },{ "bravo", 2 },
			{ "charlie", 3 },{ "delta", 4 },
			{ "echo", 5 },{ "foxtrot", 6 },
			{ "golf", 7 },{ "hotel", 8 },
			{ "india", 9 },{ "juliet", 10 },
			{ "kilo", 11 },{ "lima", 12 },
			{ "mike", 13 },{ "november",14 },
			{ "oscar", 15 },{ "papa", 16 },
			{ "quebec", 17 },{ "romeo", 18 },
			{ "sierra", 19 },{ "tango", 20 },
			{ "uniform",21 },{ "victor", 22 },
			{ "whiskey",23 },{ "x-ray", 24 },
			{ "yankee", 25 },{ "zulu", 26 }
		};


		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i < N; i++) {
			kv* result = std::find(std::begin(names), std::end(names), "sierra");
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec(KeyValueStruct) \n";
	}

	{
		const std::unordered_map<std::string, unsigned> table{
			{ "alpha", 1 },{ "bravo", 2 },
			{ "charlie", 3 },{ "delta", 4 },
			{ "echo", 5 },{ "foxtrot", 6 },
			{ "golf", 7 },{ "hotel", 8 },
			{ "india", 9 },{ "juliet", 10 },
			{ "kilo", 11 },{ "lima", 12 },
			{ "mike", 13 },{ "november",14 },
			{ "oscar", 15 },{ "papa", 16 },
			{ "quebec", 17 },{ "romeo", 18 },
			{ "sierra", 19 },{ "tango", 20 },
			{ "uniform",21 },{ "victor", 22 },
			{ "whiskey",23 },{ "x-ray", 24 },
			{ "yankee", 25 },{ "zulu", 26 }
		};

		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i < N; i++) {
			auto it = table.find("sierra");
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		// 要した時間をミリ秒（1/1000秒）に変換して表示
		std::cout << msec << " milli sec(unordered_map) \n";
	}


	return 0;
}

