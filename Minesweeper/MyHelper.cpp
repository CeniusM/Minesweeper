
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <Windows.h>
#include <string>
#include <functional>

// My Helper is used for simplifying commen operations
class MH
{
public:

	// console
	static void WriteLine(char* output)
	{
		std::cout << output << std::endl;
	}

	static void WriteLine(const char* output)
	{
		std::cout << output << std::endl;
	}

	static void Write(char* output)
	{
		std::cout << output;
	}

	static void Write(const char* output)
	{
		std::cout << output;
	}
	
	static std::string ReadLine()
	{
		std::string str;
		std::getline(std::cin, str);
		return str;
	}

	// dosent quiet work currecktly but ow well
	static void Clear()
	{
		std::cout << "\x1B[2J\x1B[H";
	}

	static void gotoxy(int x, int y) {
		COORD pos = { x, y };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}

	// thread
	static void ThreadSleep(int ms)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	// time in milliseconds
	static std::string GetTimeOfAction(std::string actionsSTR, int reps, std::function<void()> action)
	{
		// warmup
		action();


		long long* arr = new long long[reps]; // dident wanna work on the stack, idk, probely my mistake
		
		for (int i = 0; i < reps; i++)
		{
			auto start = std::chrono::high_resolution_clock::now();



			auto finish = std::chrono::high_resolution_clock::now();

			auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
			arr[reps] = milliseconds.count(); // dont know why it complains
		}

		std::string result;
		result += actionsSTR;
		result += ". AVG = " + GetAverage(arr, reps);
		result += ". Heights = " + GetHeights(arr, reps);
		result += ". Heights = " + GetLowest(arr, reps);

		delete[] arr;
		return result;
	}

	// ish, if the values arent to heigh...
	static long long GetAverage(long long* arr, int length)
	{
		long long avg = 0;
		for (int i = 0; i < length; i++)
		{
			avg += arr[i];
		}
		return avg / length;
	}

	static long long GetHeights(long long* arr, int length)
	{
		long long Heights = arr[0];
		for (int i = 0; i < length; i++)
		{
			if (Heights > arr[i])
			Heights = arr[i];
		}
		return Heights;
	}

	static long long GetLowest(long long* arr, int length)
	{
		long long Lowest = arr[0];
		for (int i = 0; i < length; i++)
		{
			if (Lowest < arr[i])
				Lowest = arr[i];
		}
		return Lowest;
	}

private:
	MH() {}
};

// later make this into its own library
