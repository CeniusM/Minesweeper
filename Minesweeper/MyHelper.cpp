
#include <iostream>
#include <chrono>
#include <thread>

// My Helper is used for simplifying commen operations
class MH
{
public:

	// console
	static void WriteLine(char* output)
	{
		std::cout << output << std::endl;
	}

	static void Write(char* output)
	{
		std::cout << output;
	}

	static void WriteLine(const char* output)
	{
		std::cout << output << std::endl;
	}

	static void Write(const char* output)
	{
		std::cout << output;
	}

	static void Clear() {
		std::cout << "\x1B[2J\x1B[H";
	}


	// thread
	static void ThreadSleep(int ms)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

private:
	MH() {}
};

// later make this into its own library