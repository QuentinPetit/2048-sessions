#include <gtest/gtest.h>

#include <vector>
#include <algorithm>


int sum(const std::vector<int>& values){
	int res = 0;
	for (int i = 0; i < values.size(); i++)
	{
		res += values[i];
	}
	return res;
}

// write the sum function
TEST(ex2, test1)
{
	{
		std::vector<int> values({0});
		EXPECT_EQ(sum(values),0);
	}
	{
		std::vector<int> values({4,1,3});
		EXPECT_EQ(sum(values),8);
	}
}

//***********************************************************

// sort integers
void sortFunction(
	std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{
	std::sort(begin, end);
}

// write the content of sort
TEST(ex2, test2)
{
	std::vector<int> values({4,8,10,6,1});
	std::vector<int> result({1,4,6,8,10});
	sortFunction(values.begin(),values.end());

	EXPECT_EQ(values,result);
}

//***********************************************************


class A
{
public:
	A(bool v): v_(v){}
	bool isValid()const { return v_; }
private:
	bool v_;
};

// sort integers
bool Delete(A a) { return !a.isValid(); }
void removeInvalid(
	std::vector<A> & array){
	std::vector<A>::iterator endRemove;

	endRemove = std::remove_if(array.begin(), array.end(), Delete);

	int d = std::distance(array.begin(), endRemove);
	array.resize(d);
	
}




// write the content of sort
TEST(ex2, test3)
{
	std::vector<A> array = { A(true), A(true) ,A(false) ,A(true) ,A(false) ,A(false) };

	EXPECT_EQ(6, array.size());
	removeInvalid(array);
	EXPECT_EQ(3, array.size());
}

//***********************************************************



int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
