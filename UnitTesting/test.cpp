// Justin Vallia - SNHU - 4-2 Unit Testing
//  Uncomment the next line to use precompiled headers
// #include "pch.h"
// uncomment the next line if you do not use precompiled headers
#include "gtest/gtest.h"

//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
  ~Environment() override {}

  // Override this to define how to set up the environment.
  void SetUp() override
  {
    //  initialize random seed
    srand(time(nullptr));
  }

  // Override this to define how to tear down the environment.
  void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
  // create a smart point to hold our collection
  std::unique_ptr<std::vector<int>> collection;

  void SetUp() override
  { // create a new collection to be used in the test
    collection.reset( new std::vector<int>);
  }

  void TearDown() override
  { //  erase all elements in the collection, if any remain
    collection->clear();
    // free the pointer
    collection.reset(nullptr);
  }

  // helper function to add random values from 0 to 99 count times to the collection
  void add_entries(int count)
  {
    assert(count > 0);
    for (auto i = 0; i < count; ++i)
      collection->push_back(rand() % 100);
  }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
  // is the collection created
  ASSERT_TRUE(collection);

  // if empty, the size must be 0
  ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
  // is the collection empty?
  ASSERT_TRUE(collection->empty());

  // if empty, the size must be 0
  ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
  FAIL();
}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
  // is the collection empty?
  ASSERT_NE(collection.get(), nullptr);

  // if empty, the size must be 0
  ASSERT_EQ(collection->size(), 0);

  add_entries(1);

  // is the collection still empty?
  // if not empty, what must the size be?
  ASSERT_EQ(collection->size(), 1);
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
  // adding 5 entries
  add_entries(5);

  // size must be 5 now
  ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, HaveMaxSizeGreater)
{
  // check when size is 0
  ASSERT_TRUE(collection->max_size() >= collection->size());

  // adding 1 entry
  add_entries(1);
  
  // check when size is 1
  ASSERT_TRUE(collection->max_size() >= collection->size());

  // adding 4 entry
  add_entries(4);

  // check when size is 5
  ASSERT_TRUE(collection->max_size() >= collection->size());
  
  // adding 5 entry
  add_entries(5);
  
  // check when size is 10
  ASSERT_TRUE(collection->max_size() >= collection->size());

}


// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, HaveCapacityGreater)
{
    // check when size is 0
  ASSERT_TRUE(collection->capacity() >= collection->size());

  // adding 1 entry
  add_entries(1);
  
  // check when size is 1
  ASSERT_TRUE(collection->capacity() >= collection->size());

  // adding 4 entry
  add_entries(4);

  // check when size is 5
  ASSERT_TRUE(collection->capacity() >= collection->size());
  
  // adding 5 entry
  add_entries(5);
  
  // check when size is 10
  ASSERT_TRUE(collection->capacity() >= collection->size());
}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, VerifyResizingIncreases)
{
  // add 5 entries
  add_entries(5);

  // assert size of vector must be 5
  ASSERT_EQ(collection->size(), 5);

  // resize collection to 20
  collection->resize(20);

  // assert new size of vector must be 20
  ASSERT_EQ(collection->size(), 20);

}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, VerifyResizingDecreases)
{
  // add 5 entries
  add_entries(5);

  // assert size of vector must be 5
  ASSERT_EQ(collection->size(), 5);

  // resize collection to 2
  collection->resize(2);

  // assert new size of vector must be 20
  ASSERT_EQ(collection->size(), 2);

}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, VerifyResizingDecreasesToZero)
{
  // add 5 entries
  add_entries(5);

  // assert size of vector must be 5
  ASSERT_EQ(collection->size(), 5);

  // resize collection to 0
  collection->resize(0);

  // assert new size of vector must be 0
  ASSERT_EQ(collection->size(), 0);

}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, ClearErasesCollection)
{
  // add 5 entries
  add_entries(5);

  // assert size of vector must be 5
  ASSERT_EQ(collection->size(), 5);

  // clears the collection
  collection->clear();

  // assert collection must be empty
  ASSERT_NE(collection.get(), nullptr);

}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, EraseClearsCollection)
{
  // add 5 entries
  add_entries(5);

  // assert size of vector must be 5
  ASSERT_EQ(collection->size(), 5);

  // erase the collection from begin to end
  collection->erase(collection->begin(), collection->end());

  // assert collection must be empty
  ASSERT_NE(collection.get(), nullptr);

}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, ReserveIncreasesCapacityNotSize)
{
  // add 5 entries
  add_entries(5);

  // assert size of vector must be 5
  ASSERT_EQ(collection->size(), 5);

  // assert capacity of vector must be 8 as of now
  ASSERT_EQ(collection->capacity(), 8);

  // changes capacity to 12
  collection->reserve(20);

  // assert size of vector must be 5 only, it must not change
  ASSERT_EQ(collection->size(), 5);

  // assert capacity of vector must increase to 8 + 12 = 20
  ASSERT_EQ(collection->capacity(), 20);

}


// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, OutOfRangeExceptionVerify)
{
  // add 5 entries
  add_entries(5);

  try {
      collection->at(8);
      FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const & err) {
      EXPECT_EQ(err.what(),std::string("vector::_M_range_check: __n (which is 8) >= this->size() (which is 5)"));
  }
  catch(...) {
      FAIL() << "Expected std::out_of_range";
  }

}


// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative


// TODO: Create a test to remove entries from vector and check size
TEST_F(CollectionTest, PopReducedSize)
{
  // add 5 entries
  add_entries(5);

  // assert size of vector must be 5
  ASSERT_EQ(collection->size(), 5);

  // remove element from vector
  collection->pop_back();

  // remove element from vector
  collection->pop_back();

  // assert new size of vector must be 3
  ASSERT_EQ(collection->size(), 3);

}

// TODO: Create a test to accessing first element after clearing a vector
TEST_F(CollectionTest, NegativeTestForClearAndAt)
{
  // add 5 entries
  add_entries(5);

  // assert size of vector must be 5
  ASSERT_EQ(collection->size(), 5);

  // clears the collection
  collection->clear();

   try {
      collection->at(0);
      FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)"));
    }
    catch(...) {
        FAIL() << "Expected std::out_of_range";
    }

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv); 
  return RUN_ALL_TESTS();
}
