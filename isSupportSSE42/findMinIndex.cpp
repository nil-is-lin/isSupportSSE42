// isSupportSSE42.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "findMinIndex.h"

using namespace std::chrono;

int main(int argc, char *argv[])
{
	unsigned int n = 0;
	if (atoi(argv[1]) <= UINT32_MAX && atoi(argv[1]) >= 0)
	{
		n = atoi(argv[1]);
	}
	
	int flag = findMinIndex(n);
    return flag;
}

int findMinIndex(const unsigned int n)
{
	if (0 == n)
	{
		return 0;
	}
	else 
	{
		high_resolution_clock::time_point start = high_resolution_clock::now();
		unsigned int sum_num = getSumIndex(n);
		unsigned int l_num = getMinIndex(n);
		if (sum_num == 1)
		{
			// make sure the ouput num is not less than n;
			l_num++;
		}

		high_resolution_clock::time_point end = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(end - start);

		std::cout << "The exponent for the smallest powers of 2 that satisfy 2^p >= " << n << " is "
			<< 32 - l_num << "(The num is " << pow(2, 32 - l_num) << ")" << std::endl;
		std::cout << "time is " << time_span.count() << "seconds." << std::endl;
		return 32 - l_num;
	}
	
}

int getMinIndex(const unsigned int n)
{
	return __lzcnt(n);
}

int getSumIndex(const unsigned int n)
{
	return _mm_popcnt_u32(n);
}